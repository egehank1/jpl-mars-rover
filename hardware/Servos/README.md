## Bugs in der Ansteuerung der Servos
Dieses Verzeichnis dokumentiert die Fehlersuche an der Ansteuerung der Servos.
Das übergeordnete Ziel war es, die Probleme der vorherigen Projektteilnehmer zu beheben.

Speziell zunächst:

- Servo vorne links Austauschen
- Problem mit der Inpace Rotation verstehen und beseitigen, wenn Inplace Drehung gewollt
- Fixen der Inplace Rotation

Da die angegebenen Probleme nicht dokumentiert sind, versuchten wir diese zu reproduzieren und das System zu testen.

Wir haben die Servos mit dem `rover@marsrover:~/osr_ws/src/osr-rover-code/scripts/calibrate_servos.py` Script getestet und folgendes festgestellt:

1. Eingabe von Winkel entspricht nicht der darauf folgenden Umsetzung.
Bsp: Eine Eingabe von einer Veränderung um 45° enstspricht real einer Veränderung von ca. 30°.

2. Bewegungsbug. Servo hat nach Eingabe von bestimmten werten eine seltsame Reaktion.

Replizierung:
- Winkel von z.b. 140° einstellen (Funktionaler Bereich)
- Winkel von >189° einstellen, z.b. 190° (Fehlerhafter Bereich)

    ->Sollte sich nicht bewegen
- Winkel von <190° einstellen, z.b. wieder 140°

Egal wo der Servo sich befindet: sobald er einmal eine "fehlerhafte" (Winkel >190°) Stellung als Ziel erhält und danach eine "erreichbare" Lage, wird der Servo erstmal um ungefähr 15° in die falsche Richtung fahren und sich dann zur "erreichbaren" Position bewegen. Ist die Position nach der "fehlerhaften" Position größer als der "Jitter Winkel" (~15°), bewegt sich der Servo in eine Richtung und dann wieder in seine Ausgangsposition (wie eine Art Zucken).

Der Signalfluss von Rover bis zum Servo sieht wie folgt aus:

Die ServoWrapper Node ist Subscriber von /cmd_corner und lies Nachrichtentyp CommandCorner (Publisher ist die Rover Node) -> der dort gelesene Winkel wird wie folgt an den PCA9685 gesendet: `ROS/osr_control/osr_control/servo_control.py`: [self.kit.servo[ind].angle = angle # Zeile 77](https://git.fh-aachen.de/ip-marsrover-ws25/marsrover-ws25/-/blob/main/src/osr-rover-code/ROS/osr_control/osr_control/servo_control.py#:~:text=self.kit.servo%5Bind%5D.angle%20%3D%20angle)

Der ``@angle.setter`` des Servos übergibt den Wert als "fraction" (Normierung vom Bereich des Winkels auf einen Wert zwischen 0...1)
-> `adafruit_motor/servo.py: self.fraction = new_angle / self.actuation_range #Zeile 133` 


Der ``@fraction.setter`` des Servos addiert dann den gesetzten Duty Cycle auf den minimalen Duty Cycle.
Da die Abweichung proportional zur eingestellten Pulsweite ist, liegt der Fehler hier wahrscheinlich nicht. Die duty_range könnte eine Fehlerursache sein.
->`adafruit_motor/servo.py: duty_cycle = self._min_duty + int(value * self._duty_range) self._pwm_out.duty_cycle = duty_cycle #Zeile 68 + 69` 

-> ``adafruit_servokit.py: servo = adafruit_motor.servo.Servo(self.kit._pca.channels[servo_channel]) # Zeile 154``

Das ServoKit enthält einen `self._servo = _Servo(self)` und einen `self._pca = PCA9685(i2c, address=address, reference_clock_speed=reference_clock_speed)`. Nach meinem Verständnis repräsentiert jeder servo_channel einen PWM Ausgang am PCA9685. In ``adafruit_pca9685 # Ab Zeile 75`` wird der Duty Cycle in Register auf dem Treiberboard geschrieben. Diese Register werden als Endpunkt des Signalflusses betrachtet.
Hier fortfahren...


In ``adafruit_servokit.py # Zeile 60`` lässt sich nachlesen, dass die Clock des PCA9685 kalibriert werden kann. Möglicherweise lässt sich so das Problem des ungenauen DutyCycles lösen.


In der Datei [PWM_Analse.md](./PWM_Analyse.md) wird beschrieben, welches Signal vom Treiberboard an den Servo geschickt wird.
[I2C_Analse.md](./I2C_Analyse.md) beschäftigt sich mit dem Signal, welches vom Raspberry Pi zum PCA9685 gesendet wird.