# Projekt: IP Mars Rover / Gruppe AutoFOCUS

Dieses Repository enthält Arbeiten rund um **Autofocus** und **ROS**.  
Es existieren **zwei zentrale Branches**, die **nicht** mit main gemerged werden dürfen.

---

## Wichtige Branches

### `autofocus_main`
- Hauptbranch für **Dokumentation**
- Enthält alle wichtigen, abgestimmten Inhalte
- Dient als Referenzstand des Projekts

### `autofocus_erfolg_manueller_ansatz`
- Branch für den **funktionierenden manuellen Ansatz**
- In diesem Branch kann das **Build ausgeführt** werden
- Fokus auf **Entwicklung rund um Autofocus und ROS**

---

## Wichtiger Hinweis: Keine Merges

Es dürfen **keine Merges** durchgeführt werden:
- Kein Merge von `autofocus_erfolg_manueller_ansatz` nach `autofocus_main`
- Kein Merge von `autofocus_main` nach `autofocus_erfolg_manueller_ansatz`
- Kein Merge in einen möglichen `main`-Branch

**Grund:** Ein Merge führt zu Problemen (z. B. Build- oder ROS-Konflikte).  
Die Branches müssen **strikt isoliert** bleiben.

---

## Empfohlener Workflow

### Dokumentation
- Arbeit ausschließlich in `autofocus_main`
- Inhalte: README, Beschreibungen, Anleitungen, Architekturübersichten

### Entwicklung
- Arbeit ausschließlich in `autofocus_erfolg_manueller_ansatz`
- Inhalte: Code, ROS-Integration, Autofocus-Logik, Build-Konfiguration

Falls Erkenntnisse aus der Entwicklung dokumentiert werden sollen:
- Inhalte **manuell übertragen**
- **Kein Merge durchführen**

---

## Build ausführen (manueller Ansatz)

Der Build funktioniert im Branch `autofocus_erfolg_manueller_ansatz`.

Beispiel:
```bash
git checkout autofocus_erfolg_manueller_ansatz
# Build-Befehl je nach Projekt, z. B.:
# colcon build
# oder catkin_make
