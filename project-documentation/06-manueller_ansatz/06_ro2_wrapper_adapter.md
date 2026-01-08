# 06 – ROS2 Wrapper/Adapter (AutoFOCUS → ROS2)

## Ziel des Wrappers
Der AutoFOCUS-orientierte Teil (Statusmodell) liefert eine **plattformunabhängige Statuslogik**.
Damit diese Logik im ROS2-System nutzbar wird, benötigt man einen **Wrapper/Adapter**, der:

- zyklisch (tick-basiert) die Modell-Logik ausführt
- Modell-Ausgabe in ein ROS2-Format übersetzt
- den Status auf einem ROS2-Topic publisht

## Schnittstellen-Design
Für die Kopplung wurde eine einfache ROS2-Schnittstelle gewählt:

- Publish: `/rover/status` (`std_msgs/String`)
- Werte: `IDLE`, `DRIVING`, `ERROR`, `MANUAL`, `AUTONOMY`

Diese Werte werden vom Status-LED Node genutzt, um Farbe/Blinken zu bestimmen.

## Konzept: Trennung in 3 Ebenen
1. **Modellebene** (AutoFOCUS-Logik)
   - Zustandsautomat / Step-Funktion (tick-basiert)
2. **Adapterebene** (Wrapper)
   - “Glue Code” zwischen Modell und ROS2
3. **Visualisierungsebene**
   - RViz Marker Node (Status-LED)

Dadurch bleibt die Modelllogik unabhängig von ROS2 und kann später ggf. durch echten generierten Code ersetzt werden.

---

## Implementierung im Repository (high level)
Im Projekt wurde die Adapterebene als separates ROS2-Paket vorgesehen
(z. B. `osr_af_status_adapter`), um die Trennung sauber zu halten.

> Screenshot-Stelle:
> - **[SCREENSHOT: Ordnerstruktur des Wrapper-Packages im Repo]**
> - **[SCREENSHOT: Hauptdatei des Wrapper-Nodes (C++/Python) geöffnet in VS Code]**

---

## Mapping-Logik (Modell → ROS2 String)
Der interne Modellstatus (Enum oder Integer) wird auf Strings gemappt:

- 0 → `IDLE`
- 1 → `DRIVING`
- 2 → `ERROR`
- 3 → `MANUAL`
- 4 → `AUTONOMY`

> Screenshot-Stelle:
> - **[SCREENSHOT: Mapping-Funktion im Wrapper-Code]**

---

## Erwartetes Ergebnis
Wenn der Wrapper läuft, soll in ROS2 sichtbar sein:

- Topic `/rover/status` existiert
- Publisher count > 0 (weil der Wrapper sendet)
- Der Status-LED Node reagiert auf die Statuswerte

> Screenshot-Stelle:
> - **[SCREENSHOT: `ros2 topic info /rover/status` mit Publisher count]**