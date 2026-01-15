# README – AutoFOCUS3-generierter und manuell angepasster Code

## Überblick

Der in diesem Verzeichnis enthaltene Quellcode basiert **teilweise auf automatisch generiertem C-Code aus AutoFOCUS3**.

Die automatische Codegenerierung wurde verwendet, um die im AutoFOCUS-Modell beschriebenen Komponenten, Ports und Abläufe strukturell in C-Code abzubilden. Der generierte Code stellt dabei ein **Grundgerüst** dar, das die Modellstruktur widerspiegelt, jedoch noch keine vollständige lauffähige oder integrierte Systemlösung darstellt.

Im weiteren Projektverlauf wurde dieser generierte Code **umfangreich manuell überarbeitet, erweitert und angepasst**, um ihn für den praktischen Einsatz, reale Laufzeitbedingungen sowie für die Integration in die restliche Systemumgebung nutzbar zu machen.

---

## Motivation für die Codeanpassungen

AutoFOCUS3 eignet sich hervorragend zur modellbasierten Entwicklung und zur formalen Beschreibung von Systemarchitekturen. Die automatisch erzeugten Codeartefakte sind jedoch primär auf **Strukturabbildung und Simulation** ausgelegt.

Für den Einsatz in einem realen Softwaresystem waren daher zusätzliche Maßnahmen erforderlich, unter anderem:

- Anpassung an reale Ausführungsumgebungen  
- Ergänzung fehlender funktionaler Logik  
- Vereinheitlichung von Schnittstellen über Komponenten hinweg  
- Verbesserung von Lesbarkeit, Wartbarkeit und Erweiterbarkeit  

---

## Code-Herkunft und Anpassungen

Der Code lässt sich in zwei Hauptkategorien einteilen:

### 1. AutoFOCUS3-generierter Code

Der automatisch generierte Anteil umfasst insbesondere:

- Grundstruktur der Komponenten gemäß Modellhierarchie  
- Trennung in `.c`- und `.h`-Dateien  
- Port-basierte Ein- und Ausgabestrukturen  
- Datentypdefinitionen entsprechend des Modells  
- Standardisierte Funktionen wie:
  - Initialisierung (`init`)
  - Reset (`reset`)
  - Zyklische Ausführung (`step`)

Diese Teile wurden direkt oder sinngemäß aus AutoFOCUS3 generiert und anschließend als **technische Basis** für die weitere Entwicklung verwendet.

---

### 2. Manuell angepasster und ergänzter Code

Ein wesentlicher Teil des Codes wurde **nachträglich manuell angepasst oder ergänzt**, darunter unter anderem:

- Umstrukturierung und Vereinheitlichung von Schnittstellen  
- Ergänzung fehlender oder unvollständiger Logik für den praktischen Betrieb  
- Anpassung und Vereinfachung der internen Zustandsverwaltung  
- Korrekturen an Datentypen, Signalflüssen und Initialwerten  
- Fehlerbehebungen und Robustheitsverbesserungen  
- Erweiterungen zur besseren Anbindung an externe Software  
  (z. B. ROS-2 Wrapper, Kommunikationsschnittstellen, Laufzeitumgebung)

Einige Dateien wurden dabei **stark modifiziert oder vollständig neu erstellt**, da die automatische Codegenerierung allein nicht ausreichte, um die gewünschte Funktionalität korrekt, stabil und nachvollziehbar abzubilden.

---

## Abweichungen vom ursprünglichen Modell

Durch die manuellen Anpassungen kann es vorkommen, dass der finale Code **nicht mehr in allen Details 1:1 dem ursprünglichen AutoFOCUS3-Modell entspricht**.

Diese Abweichungen sind bewusst in Kauf genommen worden, um:

- reale Systemanforderungen zu erfüllen  
- technische Einschränkungen der Zielplattform zu berücksichtigen  
- eine saubere Integration in bestehende Softwarearchitekturen zu ermöglichen  

Das AutoFOCUS3-Modell dient weiterhin als **konzeptionelle und architektonische Referenz**, während der Code die **praxisnahe Implementierung** darstellt.

---

## Ziel der manuellen Anpassungen

Die manuellen Änderungen verfolgten insbesondere folgende Ziele:

- Erhöhung der Verständlichkeit und Nachvollziehbarkeit des Codes  
- Verbesserung der Wartbarkeit und Erweiterbarkeit  
- Sicherstellung einer deterministischen und stabilen Laufzeit  
- Ermöglichung der Integration in eine ROS-basierte Umgebung  
- Praktische Nutzbarkeit über das reine Modell hinaus  

---

## Hinweise zur Weiterentwicklung

Bei zukünftigen Änderungen oder Erweiterungen sollte beachtet werden:

- Neuer AutoFOCUS-Code sollte **nicht blind überschrieben** werden  
- Manuelle Anpassungen sind klar von generierten Teilen zu trennen  
- Eine erneute Codegenerierung erfordert ggf. eine manuelle Nachpflege  
- Kommentare im Code geben Hinweise auf ursprünglich generierte Bereiche  

---

