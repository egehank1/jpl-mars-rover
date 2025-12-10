# Ziel und Motivation

Ziel dieses Arbeitspakets war es, eine **schnelle Funktion**
in die Rover-Simulation zu integrieren.

Dabei sollte bewusst **keine Sensorik** und **keine physikalische Modellierung**
verwendet werden, sondern eine reine Systemzustandsanzeige.

## Ziele
- Anzeige des Rover-Zustands (IDLE, DRIVING, ERROR, …)
- Nutzung einer klaren ROS2-Schnittstelle (`/rover/status`)
- Visualisierung in RViz über Marker
- Vorbereitung einer AutoFOCUS-Integration

Die Status-LED dient damit sowohl als **Debug-Werkzeug**
als auch als **Demonstrator für modellbasierte Entwicklung**.