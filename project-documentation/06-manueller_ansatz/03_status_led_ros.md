# ROS2 Status-LED

## Zweck
Visualisierung des Rover-Zustands in RViz als farbige, blinkende LED.

## ROS2-Schnittstellen
- Subscribe: `/rover/status` (`std_msgs/String`)
- Publish: `/rover/status_led/marker` (`visualization_msgs/Marker`)

## Status-Mapping

| Status     | Farbe   | Verhalten  |
|-----------|---------|------------|
| IDLE      | Blau    | konstant   |
| DRIVING   | Grün    | konstant   |
| ERROR     | Rot     | blinkend   |
| MANUAL    | Gelb    | blinkend   |
| AUTONOMY  | Cyan    | konstant   |

## Ergebnis
- Node startet korrekt
- Status wird verarbeitet
- Marker wird publiziert
- Sichtbarkeit abhängig von TF / RViz-Konfiguration