# Team und Rollen – IP Mars Rover

## Projektgruppe Autofocus

## Teammitglieder

Das Projekt **IP Mars Rover – Projektgruppe Autofocus** wurde von folgendem Team bearbeitet:

- **Egehan Kilic**
- **Enis Cobanoglu**
- **Ahmet Taha Topal**
- **Abdulrahman Omar Saeed Al-Qathmi**

---

## Rollenverteilung

Die Rollenverteilung im Projekt war **flexibel** und wurde im Verlauf der Projektarbeit an technische Anforderungen und Projektfortschritt angepasst. Es gab keine strikt getrennten Rollen, jedoch klare fachliche Schwerpunkte.

### Automatisierter Ansatz (Plugin-basierte Codeumwandlung)

**Egehan Kilic, Ahmet Taha Topal und Enis Cobanoglu**

konzentrierten sich überwiegend auf den **automatisierten Ansatz**.

Schwerpunkte:

- Modellierung von Rover-Funktionalitäten in **Autofocus 3**
- automatische **Generierung von C-Code** aus Autofocus
- Nutzung eines **Plugins der fortiss GmbH** (Entwickler von Autofocus),
    
    um den generierten C-Code **automatisch in Python- bzw. ROS-Code zu überführen**
    
- Tests auf unterschiedlichen Betriebssystemen:
    - Windows 10
    - Windows 11
    - macOS
- Analyse von Plugin-Verhalten, Kompatibilität und Einschränkungen
- Analyse des von Autofocus erzeugten C-Codes
- händische Anpassung und Umwandlung in Python-/ROS-kompatiblen Code
- Push des Codes in das Repository (Testen)
- Vergleich manueller und automatisierter Vorgehensweisen

Ziel war die Umsetzung eines möglichst **durchgängigen, automatisierten Workflows**.

---

### Manueller Ansatz (ohne Plugin)

**Abdulrahman Omar Saeed Al-Qathmi**

fokussierte sich primär auf den **manuellen Ansatz**.

---

## Änderungen während des Projekts

### Übergang vom manuellen zum automatisierten Fokus

Zu Beginn des Projekts testeten **alle Teammitglieder** zunächst den **manuellen Ansatz**.

Dabei traten früh wiederkehrende Probleme auf, unter anderem:

- nicht kompatible Codekonstrukte wie z. B. `GenTrueBoolean`
- C-Code-Zeilen und Funktionsaufrufe, die sich nicht direkt in Python/ROS übertragen ließen
- notwendige manuelle Umbenennungen von Variablen und Funktionen
- erhöhte Fehleranfälligkeit und hoher Zeitaufwand

Aufgrund dieser Erfahrungen entschieden sich **Egehan Kilic, Ahmet Taha Topal und Enis Cobanoglu**, den Schwerpunkt auf den **automatisierten Plugin-Ansatz** zu legen, während **Abdulrahman** den manuellen Ansatz weiterverfolgte.

---

## Präsentationen und Dokumentation

Seit Projektbeginn wurden **Präsentationen und Dokumentationsaufgaben regelmäßig rotiert**:

- Jede Woche übernahm **ein anderes Teammitglied** die Präsentation
- Ziel war eine gleichmäßige Verteilung der Aufgaben
- Bei keinen Ausfällen oder Verspätungen präsentierte jede Person einmal pro Zyklus

Dieses Vorgehen stellte sicher, dass alle Teammitglieder kontinuierlich in den Projektfortschritt eingebunden waren.

---

## Hinweis

Die dargestellte Rollenverteilung reflektiert den **tatsächlichen Projektverlauf**.

Viele Aufgaben wurden gemeinschaftlich bearbeitet, insbesondere in frühen Projektphasen und bei der Problemanalyse.