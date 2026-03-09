### Documentation

# Plot 
Diese Funktion generiert ein textbasiertes ASCII-Streudiagramm in der Konsole, 
um den Kursverlauf einer Aktie über die letzten 30 Tage zu visualisieren.

Parameter:
    aktData: 
        Ein Pointer auf ein Array von AktieData-Strukturen (erwartet mindestens 30 Datensätze).
    aktie_name: 
        Der Name der Aktie (wird aktuell im Funktionskörper nicht aktiv für die Anzeige genutzt).
    num_of_aktien: 
        Die Anzahl der zu verarbeitenden Datensätze (die Logik ist fest auf 30 Tage ausgelegt).

Funktionalität
    Vorbereitung: 
        Der Bildschirm wird gelöscht und der Cursor zurückgesetzt. Die Fließkommaausgabe wird auf zwei Nachkommastellen fixiert.
    Skalierung: 
        Die Schlusskurse der letzten 30 Tage werden extrahiert und sortiert, um die Y-Achse (Preise) dynamisch zu skalieren.
    Y-Achse: 
        Gibt die sortierten Preise vertikal aus und rückt diese optisch ein.
    X-Achse & Plotting:
        Gibt das Datum (Tag-Teil) horizontal am unteren Rand aus.
        Nutzt ANSI-Escape-Sequenzen (\x1b[...H), um den Cursor direkt an die Positionen zu bewegen, die dem Preiswert entsprechen.
        Zeichnet ein Balken-/Punkt-Diagramm mit *-Symbolen von unten nach oben bis zum jeweiligen Kurswert.
    Interaktion: 
        Versteckt den Cursor und wartet auf Benutzereingaben (getchar), bevor der Bildschirm final gelöscht wird.

Voraussetzungen
    Header: 
        <iostream>, <iomanip>, <string>, <algorithm> (für Sortierung).
    Helfer: 
        Benötigt die Funktionen clearScreen() und sortFloatArray(), sowie die Konstante CURSOR_HOME.
    Terminal: 
        Erfordert ein Terminal, das ANSI-Escape-Codes zur Cursorsteuerung unterstützt.