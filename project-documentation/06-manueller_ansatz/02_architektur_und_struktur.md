# Architektur und Gesamtstruktur

## Gesamtidee

Die Architektur folgt einer klaren Schichtenaufteilung:

```text
AutoFOCUS Modell
        ↓
Generierter C-Code (zustandsbasiert)
        ↓
ROS2 Wrapper / Adapter (C++)
        ↓
ROS2 Topics
        ↓
Status-LED Node


---

Vorteile dieser Struktur
	•	Trennung von Logik und Middleware
	•	Wiederverwendbarkeit des generierten Codes
	•	ROS-unabhängige Kernlogik
	•	Klare Verantwortlichkeiten