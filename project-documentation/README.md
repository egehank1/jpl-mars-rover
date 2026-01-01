# Projekt­dokumentation – IP Mars Rover / Autofocus 3

## Kurzbeschreibung

Dieses Dokument fasst die Arbeit eines **dreimonatigen universitären Projekts** an der *FH Aachen University of Applied Sciences* im Rahmen des **interdisziplinären Projekts IP Mars Rover** zusammen.

Der Schwerpunkt des Projekts lag auf der Integration und Konfiguration von Autofocus 3 (Developer-Version) sowie auf dem Versuch der Code-Erzeugung aus Autofocus-Modellen.
Dabei wurde versucht, den generierten Code sowohl automatisiert als auch manuell in ROS-Code umzuwandeln und in das bestehende System zu integrieren.

Die Dokumentation dient als **Übergabe- und Referenzdokument** für **zukünftige Projektgruppen**, die mit **Autofocus** weiterarbeiten. Sie beschreibt nicht nur die umgesetzten Schritte, sondern legt bewusst auch **Probleme, Fehlversuche, Einschränkungen, Konfigurationsfallen und nicht funktionierende Ansätze** offen, um Wiederholungen derselben Fehler zu vermeiden.

---

## Zielgruppe

- **Zukünftige Projektgruppen**, insbesondere
    - Teams mit Fokus auf **Autofocus 3 (Developer-Version)**
    - Studierende, die bestehende Konfigurationen übernehmen oder erweitern

---

## Zweck der Dokumentation

Diese Dokumentation soll:

- einen **schnellen und realistischen Einstieg** in das Projekt ermöglichen
- **relevante technische Entscheidungen nachvollziehbar machen**
- aufzeigen, **warum bestimmte Ansätze nicht funktioniert haben**
- als **praktische Arbeitsgrundlage** für Weiterentwicklung dienen
- Zeit sparen, indem bekannte Probleme und Sackgassen transparent gemacht werden

---

## Was ihr in diesem Dokument findet

### 1. Setup & Installation (Autofocus 3 – Developer-Version)

- Voraussetzungen (System, Abhängigkeiten, Versionen)
- Installation von **Autofocus 3 (Developer-Version)**
- Unterschiede zur Stable-Version
- notwendige Umgebungsvariablen und Startparameter
- bekannte Installationsprobleme und deren Ursachen

### 2. Plugins, Extensions & Zusatzkomponenten

- verwendete **Plugins und Extensions**
- Versionen und Kompatibilität
- Abhängigkeiten zwischen Plugins
- Konfigurationsdateien und deren Speicherorte
- Hinweise zu nicht funktionierenden oder instabilen Erweiterungen

### 3. Dateien & Projektstruktur

- relevante Projektverzeichnisse
- Konfigurationsdateien (inkl. Zweck und kritischer Parameter)
- Referenzdateien
- Testdateien und deren Verwendung
- Dateien, die **nicht gelöscht oder verändert werden sollten**

### 4. Architektur & Systemübersicht

- grober Architekturüberblick
- Einbettung von Autofocus in das Gesamtsystem
- verwendete Versionen (Autofocus, Plugins, Abhängigkeiten)
- Schnittstellen und Datenflüsse
- bekannte strukturelle Einschränkungen

### 5. Zentrale Probleme & Fehlerquellen

- Probleme bei Installation und Initialisierung
- typische Konfigurationsfehler
- Versionskonflikte
- unerwartetes Verhalten von Autofocus
- Limitierungen der Developer-Version
- Fehler, die mehrfach aufgetreten sind

### 6. Getroffene Entscheidungen

- warum bestimmte Tools / Versionen gewählt wurden
- warum Alternativen verworfen wurden
- Kompromisse zwischen Stabilität und Funktionalität
- bewusste Workarounds

### 7. Empfehlungen & klare Hinweise zur Weiterarbeit

- **Was funktioniert zuverlässig**
- **Was nur eingeschränkt funktioniert**
- **Was aktuell nicht funktioniert und warum**
- empfohlene nächste Schritte für Folgeteams
- Dinge, die man **nicht erneut ausprobieren sollte**
- Vorschläge für strukturelle oder technische Verbesserungen

---

## Wichtiger Hinweis

Diese Dokumentation erhebt **keinen Anspruch auf Vollständigkeit oder Perfektion**, sondern ist bewusst **praxisnah** gehalten.

Insbesondere die Beschreibung von **Fehlern, Sackgassen und Problemen** ist ein zentraler Bestandteil und soll zukünftigen Gruppen helfen, **informierte Entscheidungen** zu treffen.