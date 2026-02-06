

**Manuelle Anbindung einer Ultraschall-Sensor-Logik an ROS 2**

Dieses Verzeichnis enthält die manuelle Integration einer Ultraschall-Sensor-Logik in ROS 2.
Die Ultraschall-Codebase wurde manuell mit ROS 2 verbunden, um Sensordaten aus einem Modell in eine ROS-basierte Laufzeitumgebung zu integrieren. Diese Anbindung dient als Vorbereitung für eine spätere Ausführung in der Simulation sowie auf realer Hardware (Mars Rover).
Der zugrunde liegende Code wird mit dem Tool AutoFOCUS generiert und anschließend manuell erweitert.

**Tests**

Zur Überprüfung der Korrektheit des Codes wurden zwei manuelle Tests durchgeführt:
1.	Test ohne ROS 2
Direkte Ausführung des generierten Codes zur funktionalen Verifikation.
2.	Test mit ROS 2
Integration der Sensorlogik in ROS 2 mittels Publisher- und Subscriber-Nodes.

**Ordnerstruktur**

   **Top-Level**

   -  package.xml
   
   Definiert das ROS-2-Package.
   Enthält Metadaten (Name, Version, Maintainer) sowie Build- und Laufzeit-Dependencies.

   -  CMakeLists.txt

   Konfiguriert den Build-Prozess.
   Definiert die Nodes als Executables und bindet notwendige Dependencies ein (z. B. rclcpp, std_msgs).


   - Makefile

   Dient als Bindeglied zwischen der bestehenden Projektstruktur und dem ROS-2-Build-System.
   Stellt sicher, dass relevante Quellcodedateien korrekt eingebunden sind und der Build-Prozess reproduzierbar ausgeführt wird.

   - inc-gen/

   Automatisch generierte Header-Dateien (AutoFOCUS).

   - src-gen/

   Automatisch generierte Source-Dateien (AutoFOCUS).

   - src/

   Manuell erstellte Dateien zur Testdurchführung und zur ROS-2-Anbindung.
   

**Ausführen**

Nach dem Klonen (Pull) des Repositories gehen Sie bitte wie folgt vor:

1.	Wechseln Sie in die Top-Level-Ebene des ROS-2-Workspaces.
2.	Bauen Sie das Projekt mit:
colcon build --symlink-install
3.	Starten Sie im ersten Terminal den Publisher:
ros2 run mars_rover_projekt_1 mars_rover_node_1
4.	Starten Sie im zweiten Terminal den Subscriber:
   ros2 run mars_rover_projekt_1 mars_rover_listener
Nach dem Start sollten in den Terminals die entsprechenden Ausgaben der Publisher- und Subscriber-Nodes sichtbar sein.

**Zentrale Quelldateien**

•	mars_rover_node1.cpp:Implementiert einen ROS-2-Publisher.
Publiziert Ultraschall-Messdaten als Nachrichten vom Typ Boolean über ein ROS-Topic (z. B. Topic 10).

•	mars_rover_listener.cpp:
Implementiert einen ROS-2-Subscriber.
Abonniert dasselbe Topic, empfängt die publizierten Daten und gibt diese aus.

**Modellbasierte Ausführung und Zeitdiskretisierung**

In mars_rover_node1.cpp ist ein Test implementiert, der folgende Aspekte abbildet:

•	Das Modell erhält Takte, die die Echtzeit-Ausführung des Codes auf dem Rover repräsentieren.

•	Jeder Takt entspricht einem Ausführungsschritt des Systems.

•	Je weiter ein Objekt vom Rover entfernt ist, desto mehr Takte werden benötigt.

•	Eine größere Anzahl an Takten führt zu einer größeren berechneten Entfernung im Modell.


**Zeitdiskretisierung**

Die StepTime des Modells wurde gemäß Best Practices auf 10 µs festgelegt.
Bedeutung:
Ein einzelner Verarbeitungsschritt (Input → Verarbeitung → Output) dauert 10 µs.

**Empfehlung**

den Code zu pullen , um das Zusammenspiel von Publisher und Subscriber im Modellkontext besser zu verstehen.
Die Codebasis ist modular aufgebaut und eignet sich gut für eine Weiterentwicklung und Erweiterung, falls dies erforderlich sind.
