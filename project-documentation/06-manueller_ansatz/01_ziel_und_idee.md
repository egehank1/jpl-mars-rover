# Ziel und Motivation

## Zielsetzung

Ziel dieses Arbeitsschrittes war es, **einen modellbasierten Entwicklungsansatz im Stil von AutoFOCUS 3**
in ein bestehendes ROS2-System einzubetten.

Dabei sollte:

- modellierte Logik von ROS entkoppelt bleiben
- der generierte Code möglichst **plattformneutral (C)** sein
- die ROS-Schnittstelle ausschließlich über einen **Wrapper** erfolgen

## Motivation

AutoFOCUS 3 wird häufig in frühen Entwicklungsphasen eingesetzt, um:

- Zustandsautomaten
- Systemlogik
- deterministisches Verhalten

modellbasiert zu entwerfen und anschließend automatisch Code zu erzeugen.

Da eine vollständige Tool-Chain-Integration (AF → ROS2) sehr komplex ist, wurde hier ein **bewusst manueller Ansatz** gewählt,
der den **grundsätzlichen Workflow realistisch abbildet**:

1. Modellierung in AutoFOCUS
2. Codegenerierung
3. Manuelle Anpassung
4. ROS2-Integration über Wrapper

Dieser Ansatz erlaubt es, **Konzept, Struktur und Grenzen** der Integration nachvollziehbar darzustellen.