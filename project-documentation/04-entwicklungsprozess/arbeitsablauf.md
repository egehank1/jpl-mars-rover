# Arbeitsablauf

Dieses Dokument beschreibt den **praktischen Arbeitsablauf**, die **wöchentliche Struktur** sowie die **Kommunikations- und Abstimmungsprozesse** innerhalb der Projektgruppe Autofocus über den gesamten Projektzeitraum von zehn Wochen.

---

## Wie wir gearbeitet haben

Die Projektarbeit erfolgte **iterativ und parallelisiert**.

Alle Teammitglieder arbeiteten auf **eigenen Rechnern** und mit **eigenen Entwicklungsumgebungen**.

Es wurde **nicht** auf zentralen Rechnern (z. B. Temida-Rechnern der FH Aachen) gearbeitet.

Der Fokus lag darauf:

- unterschiedliche Konfigurationen parallel zu testen
- Fehler und Einschränkungen frühzeitig zu identifizieren
- funktionierende Ansätze gemeinsam zu konsolidieren

Insbesondere beim **automatisierten Ansatz mit Autofocus 3** wurde bewusst auf parallele Experimente gesetzt, da:

- Betriebssysteme
- ROS-Versionen
- Autofocus-Versionen
- Adapter

einen großen Einfluss auf das Ergebnis hatten.

---

## Typische Woche im Projekt

Eine typische Projektwoche bestand aus mehreren festen und flexiblen Elementen:

### Wöchentliches Gruppenmeeting

- **einmal pro Woche**, in der Regel **montags**
- Termin wurde bei Bedarf an **universitäre Verpflichtungen** angepasst
- Teilnahme aller vier Teammitglieder
- Inhalte:
    - Vorstellung des aktuellen Stands
    - Diskussion von Problemen
    - Abstimmung der nächsten Schritte

---

### Zusätzliche Meetings (Autofocus / automatisierter Ansatz)

Für die Arbeit am **automatisierten Ansatz mit Autofocus 3** fanden zusätzliche Meetings statt:

- meist **am Wochenende** (Samstag oder Sonntag)
- teilweise **mehrmals pro Woche** (2–3 Meetings), abhängig vom Problemstand
- Fokus auf:
    - Adapter-Probleme
    - Konfigurationsfehler
    - Versionskonflikte
    - Vergleich der Ergebnisse auf unterschiedlichen Systemen

Diese Meetings waren notwendig, da:

- jedes Teammitglied auf einem **anderen Rechner** arbeitete
- Fehler häufig **nicht reproduzierbar** waren
- Ergebnisse stark vom Setup abhingen

---

### Individuelle Arbeitsphasen

Zwischen den Meetings arbeiteten die Teammitglieder **eigenständig** an klar abgegrenzten Aufgaben, z. B.:

- Tests des **ROSCO-Adapters** auf:
    - Windows 11
    - Windows 10
- Vergleich unterschiedlicher:
    - ROS-Komponenten
    - Autofocus-Versionen (Developer vs. Stable)
- Erzeugung und Test eigener Autofocus-Modelle
- Analyse von FMU-Export und FMI-Adapter-Verhalten

Jede Person dokumentierte:

- was getestet wurde
- was funktioniert hat
- was **nicht** funktioniert hat

---

## Kommunikation und Abstimmung

### Discord als zentrale Plattform

Die gesamte Kommunikation lief über **Discord**:

- eigener **Projektserver**
- separate Kanäle für:
    - technische Probleme
    - Adapter & ROS
    - Autofocus
    - Präsentationen
    - Dokumentation

Über Discord wurden:

- Fehlerbeschreibungen geteilt
- Logs und Screenshots ausgetauscht
- Präsentationen hochgeladen
- spontane Abstimmungen durchgeführt

---

### Wissensaustausch und Entscheidungen

Wichtige Erkenntnisse wurden:

- direkt in Meetings besprochen
- anschließend schriftlich festgehalten
- in die Projektdokumentation übernommen

Ein typisches Beispiel:

- Mehrere Teammitglieder erstellten eigene Autofocus-Modelle
- FMU-Export funktionierte nicht zuverlässig
- In der gemeinsamen Analyse wurde erkannt:
    - FMU-Export funktioniert stabil mit einer **XML-Referenzdatei von fortiss**
- Entscheidung:
    - eigenes Modell verwerfen
    - Referenzmodell verwenden

Solche Entscheidungen wurden immer **transparent kommuniziert**.

---

## Präsentationen und Dokumentation

- Präsentationen wurden **wöchentlich rotiert**
- Jede Woche übernahm **eine andere Person**:
    - die Erstellung
    - und in der Regel auch die Präsentation
- Ziel:
    - gleichmäßige Verteilung der Aufgaben
    - gemeinsames Verständnis des Projektstands

Die Präsentationen dienten gleichzeitig als:

- Statusbericht
- Diskussionsgrundlage
- Basis für die spätere Dokumentation

---

## Zusammenfassung des Entwicklungsprozesses

Der Entwicklungsprozess war geprägt von:

- paralleler Arbeit auf unterschiedlichen Systemen
- häufigem Austausch und enger Abstimmung
- vielen Experimenten mit klarer Dokumentation von Fehlschlägen
- iterativer Annäherung an ein funktionierendes Modell

Durch diesen Ansatz konnte trotz zahlreicher technischer Einschränkungen innerhalb von **zehn Wochen ein testbares Modell** und eine umfassende Dokumentation erarbeitet werden.

# Entwicklungsprozess

Dieses Dokument beschreibt den **praktischen Arbeitsablauf**, die **wöchentliche Struktur** sowie die **Kommunikations- und Abstimmungsprozesse** innerhalb der Projektgruppe Autofocus über den gesamten Projektzeitraum von zehn Wochen.

---

## Wie wir gearbeitet haben

Die Projektarbeit erfolgte **iterativ und parallelisiert**.

Alle Teammitglieder arbeiteten auf **eigenen Rechnern** und mit **eigenen Entwicklungsumgebungen**.

Es wurde **nicht** auf zentralen Rechnern (z. B. Temida-Rechnern der FH Aachen) gearbeitet.

Der Fokus lag darauf:

- unterschiedliche Konfigurationen parallel zu testen
- Fehler und Einschränkungen frühzeitig zu identifizieren
- funktionierende Ansätze gemeinsam zu konsolidieren

Insbesondere beim **automatisierten Ansatz mit Autofocus 3** wurde bewusst auf parallele Experimente gesetzt, da:

- Betriebssysteme
- ROS-Versionen
- Autofocus-Versionen
- Adapter

einen großen Einfluss auf das Ergebnis hatten.

---

## Typische Woche im Projekt

Eine typische Projektwoche bestand aus mehreren festen und flexiblen Elementen:

### Wöchentliches Gruppenmeeting

- **einmal pro Woche**, in der Regel **montags**
- Termin wurde bei Bedarf an **universitäre Verpflichtungen** angepasst
- Teilnahme aller vier Teammitglieder
- Inhalte:
    - Vorstellung des aktuellen Stands
    - Diskussion von Problemen
    - Abstimmung der nächsten Schritte

---

### Zusätzliche Meetings (Autofocus / automatisierter Ansatz)

Für die Arbeit am **automatisierten Ansatz mit Autofocus 3** fanden zusätzliche Meetings statt:

- meist **am Wochenende** (Samstag oder Sonntag)
- teilweise **mehrmals pro Woche** (2–3 Meetings), abhängig vom Problemstand
- Fokus auf:
    - Adapter-Probleme
    - Konfigurationsfehler
    - Versionskonflikte
    - Vergleich der Ergebnisse auf unterschiedlichen Systemen

Diese Meetings waren notwendig, da:

- jedes Teammitglied auf einem **anderen Rechner** arbeitete
- Fehler häufig **nicht reproduzierbar** waren
- Ergebnisse stark vom Setup abhingen

---

### Individuelle Arbeitsphasen

Zwischen den Meetings arbeiteten die Teammitglieder **eigenständig** an klar abgegrenzten Aufgaben, z. B.:

- Tests des **ROSCO-Adapters** auf:
    - Windows 11
    - Windows 10
- Vergleich unterschiedlicher:
    - ROS-Komponenten
    - Autofocus-Versionen (Developer vs. Stable)
- Erzeugung und Test eigener Autofocus-Modelle
- Analyse von FMU-Export und FMI-Adapter-Verhalten

Jede Person dokumentierte:

- was getestet wurde
- was funktioniert hat
- was **nicht** funktioniert hat

---

## Kommunikation und Abstimmung

### Discord als zentrale Plattform

Die gesamte Kommunikation lief über **Discord**:

- eigener **Projektserver**
- separate Kanäle für:
    - technische Probleme
    - Adapter & ROS
    - Autofocus
    - Präsentationen
    - Dokumentation

Über Discord wurden:

- Fehlerbeschreibungen geteilt
- Logs und Screenshots ausgetauscht
- Präsentationen hochgeladen
- spontane Abstimmungen durchgeführt

---

### Wissensaustausch und Entscheidungen

Wichtige Erkenntnisse wurden:

- direkt in Meetings besprochen
- anschließend schriftlich festgehalten
- in die Projektdokumentation übernommen

Ein typisches Beispiel:

- Mehrere Teammitglieder erstellten eigene Autofocus-Modelle
- FMU-Export funktionierte nicht zuverlässig
- In der gemeinsamen Analyse wurde erkannt:
    - FMU-Export funktioniert stabil mit einer **XML-Referenzdatei von fortiss**
- Entscheidung:
    - eigenes Modell verwerfen
    - Referenzmodell verwenden

Solche Entscheidungen wurden immer **transparent kommuniziert**.

---

## Präsentationen und Dokumentation

- Präsentationen wurden **wöchentlich rotiert**
- Jede Woche übernahm **eine andere Person**:
    - die Erstellung
    - und in der Regel auch die Präsentation
- Ziel:
    - gleichmäßige Verteilung der Aufgaben
    - gemeinsames Verständnis des Projektstands

Die Präsentationen dienten gleichzeitig als:

- Statusbericht
- Diskussionsgrundlage
- Basis für die spätere Dokumentation

---

## Zusammenfassung des Entwicklungsprozesses

Der Entwicklungsprozess war geprägt von:

- paralleler Arbeit auf unterschiedlichen Systemen
- häufigem Austausch und enger Abstimmung
- vielen Experimenten mit klarer Dokumentation von Fehlschlägen
- iterativer Annäherung an ein funktionierendes Modell

Durch diesen Ansatz konnte trotz zahlreicher technischer Einschränkungen innerhalb von **zehn Wochen ein testbares Modell** und eine umfassende Dokumentation erarbeitet werden.