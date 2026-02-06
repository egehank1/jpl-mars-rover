# README – AutoFOCUS-generierter und manuell angepasster Code

## Überblick

Der in diesem Verzeichnis enthaltene Quellcode basiert **teilweise auf automatisch generiertem C-Code aus AutoFOCUS3**.

Die automatische Codegenerierung diente als Ausgangspunkt, um die im Modell beschriebenen Komponenten strukturell abzubilden.

Im weiteren Projektverlauf wurde der generierte Code **umfangreich manuell überarbeitet, erweitert und angepasst**, um ihn für den praktischen Einsatz sowie für die Integration in die restliche Systemumgebung nutzbar zu machen.

---

## Code-Herkunft und Anpassungen

Der Code lässt sich in zwei Kategorien einteilen:

### 1. AutoFOCUS-generierter Code

- Grundstruktur der Komponenten  
- Trennung in `.c`- und `.h`-Dateien  
- Port-basierte Ein- und Ausgabestrukturen  
- Initialisierungs-, Reset- und Step-Funktionen  

Diese Teile wurden direkt oder sinngemäß aus AutoFOCUS3 generiert und anschließend als Basis weiterverwendet.

### 2. Manuell angepasster und ergänzter Code

Ein wesentlicher Teil der Dateien wurde **nachträglich manuell angepasst**, darunter:

- Umstrukturierung und Vereinheitlichung von Schnittstellen  
- Ergänzung fehlender Logik für den praktischen Betrieb  
- Anpassung der internen Zustandsverwaltung  
- Korrekturen an Datentypen und Signalflüssen  
- Erweiterungen zur besseren Anbindung an externe Software (z. B. ROS 2 Wrapper)

Einige Dateien wurden dabei **stark modifiziert oder vollständig neu ergänzt**, da die automatische Codegenerierung allein nicht ausreichte, um die gewünschten Funktionalitäten korrekt abzubilden.

---

## Ziel der manuellen Anpassungen

Die manuellen Änderungen hatten insbesondere folgende Ziele:

- Erhöhung der Verständlichkeit und Nachvollziehbarkeit des Codes  
- Sicherstellung einer deterministischen und stabilen Laufzeit  
- Ermöglichung der Integration in eine ROS-basierte Umgebung  
- Praktische Nutzbarkeit über das reine Modell hinaus  

---

## Hinweis

Der vorliegende Code stellt daher **keinen rein automatisch generierten AutoFOCUS-Output** dar, sondern eine **kombinierte Lösung aus generiertem Grundgerüst und manueller Implementierung**.

Dies wurde bewusst so umgesetzt, um die Lücke zwischen Modellierung und lauffähigem System zu schließen.

---

