# AutoFOCUS-Modell (konzeptionell)

## Modellierte Komponente: StatusController

### Eingänge
- `cmd` (Enum / Integer)
- `tick` (zyklisches Ereignis)

### Ausgänge
- `status`

### Zustände
- IDLE
- DRIVING
- ERROR
- MANUAL
- AUTONOMY

## Verhalten
- Bei jedem Tick wird der interne Zustand
  anhand von `cmd` aktualisiert
- Der Zustand wird am Ausgang `status` ausgegeben

Das Modell entspricht einem klassischen,
tick-basierten AutoFOCUS-Zustandsautomaten.