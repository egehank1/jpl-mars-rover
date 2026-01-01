# Umfang und Abgrenzung

Dieses Dokument beschreibt den **inhaltlichen und technischen Umfang** des Projekts sowie bewusste **Abgrenzungen**, Entscheidungen und Einschränkungen, die sich aus zeitlichen, technischen und toolbedingten Rahmenbedingungen ergeben haben.

---

## Was Teil des Projekts war

Folgende Punkte waren explizit Bestandteil des Projekts:

- Nutzung von **Autofocus 3 (Developer-Version)** zur modellbasierten Entwicklung
- Modellierung **eines kleinen, klar abgegrenzten Teils des Rovers**, konkret:
    - **Ultraschallsensor**
- Test und Validierung des Modells innerhalb von Autofocus
- Automatische **Codegenerierung (C-Code)** aus Autofocus
- Fokus auf **automatisierte Umwandlung** des generierten C-Codes in **Python-/ROS-Code**
- Evaluation von **Plugins und Adaptern**, insbesondere **FMI-Adaptern**
- Nutzung des **FMU-Exports** zur Weiterverarbeitung
- Integration des erzeugten Codes in ein Repository
- Ausführung und Simulation in einer **ROS-2-Umgebung**
- Visualisierung und Simulation mit **RViz** und **Gazebo**

Der Schwerpunkt lag auf der **Toolchain und Integration**, nicht auf einer vollständigen funktionalen Abbildung des Rovers.

---

## Was bewusst nicht umgesetzt wurde

### Stable-Version von Autofocus 3

- Es wurde **nicht** mit der regulären Stable-Version von Autofocus 3 gearbeitet
- Stattdessen wurde gezielt die **Developer-Version** verwendet, da:
    - benötigte Plugins und der **FMI-Adapter** dort verfügbar waren
    - Startmechanismen und Plugin-Integration in der Stable-Version eingeschränkt sind

---

### Containerisierung und Virtualisierung

- Es wurde **keine Containerisierung** (z. B. Docker) eingesetzt
- Es wurden **keine virtuellen Maschinen** verwendet
- Stattdessen wurde bewusst eine **native Ubuntu-LTS-Installation (22.04.5)** genutzt,
    
    um ROS-Integration und Build-Prozesse zu vereinfachen
    

---

### macOS als Zielplattform

- Eine vollständige ROS-Integration unter **macOS** wurde nicht weiterverfolgt
- Gründe:
    - eingeschränkter ROS-Support
    - instabile Build-Prozesse
    - hoher Konfigurationsaufwand

---

### Vollständige Rover-Modellierung

- Es wurde **nicht versucht**, den gesamten Rover zu modellieren
- Aufgrund der hohen Systemkomplexität und der begrenzten Projektlaufzeit
- Fokus lag bewusst auf einem **einzelnen Subsystem (Ultraschallsensor)**

---

### Manueller Codeansatz

- Der **manuelle Ansatz zur Umwandlung von C-Code** wurde nur in einer frühen Projektphase verfolgt
- Gründe für den Abbruch:
    - zahlreiche Kompilierungsfehler im generierten C-Code
    - komplexe Abhängigkeiten zwischen Header- und C-Dateien
    - notwendige manuelle Umbenennungen und Anpassungen
- Nach kurzer Zeit wurde der manuelle Ansatz von
    
    **Egehan Kilic, Enis Cobanoglu und Ahmet Taha Topal** bewusst verworfen
    
- Der Fokus lag anschließend vollständig auf **automatisierten Lösungen**

---

## Zeitliche und technische Grenzen

### Developer-Versionen von Autofocus 3

- Es existieren **zwei Developer-Versionen** von Autofocus 3
- Die **ältere Developer-Version**:
    - benötigt **JDK 11**
    - erfordert **Eclipse 2019**
    - verursachte zahlreiche:
        - Kompilierungsfehler
        - Konfigurationsprobleme
    - war insbesondere unter macOS kaum nutzbar
- Diese Version wurde nach ersten Tests **nicht weiterverfolgt**
- Verwendet wurde ausschließlich die **neuere Developer-Version** aus dem fortiss-Repository

---

### FMU-Export und FMI-Adapter

- Es wurde ein **FMU-Export** in Kombination mit einem **FMI-Adapter** verwendet
- Es wurde **kein eigenes FMU-Modell** entwickelt
- Stattdessen wurde:
    - ein **XML-Basismodell von der fortiss-Website** genutzt
    - dieses Modell als **FMU** exportiert

Wichtige Einschränkungen:

- Der FMU-Export funktioniert **nur auf Top-Level-Komponenten**
- Exporte aus verschachtelten Architekturen waren nicht erfolgreich
- Für den FMU-Export ist ein **installierter GCC-Compiler zwingend erforderlich**

---

### ROS-Versionen und Adapter-Kompatibilität

- Es wurde ausschließlich mit **ROS 2** gearbeitet
- Adapter für **ROS 1** erwiesen sich als inkompatibel und wurden verworfen
- Es wurden mehrere **ROS-2-Adapter** getestet:
    - unterschiedliche Build-Systeme (**catkin** und **ament**)
- Wichtig:
    - ROS-Version, Adapter und Build-System müssen exakt zusammenpassen
- Der **ROSCO-Adapter** wurde getestet, war jedoch:
    - inkompatibel mit der eingesetzten ROS-2-Version
    - daher nicht weiterverfolgt

---

## Zusammenfassung

Der Projektumfang wurde bewusst **klar begrenzt**, um:

- technische Risiken zu reduzieren
- den Fokus auf **Automatisierung, FMU-/FMI-Integration und Toolchain-Evaluation** zu legen
- innerhalb der verfügbaren Zeit ein **reproduzierbares Ergebnis** zu erzielen

Bewusst nicht umgesetzte Ansätze sind integraler Bestandteil der Projekterfahrung und sollen zukünftigen Projektgruppen als Orientierung dienen.