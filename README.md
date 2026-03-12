### Documentation

# import
Die Funktion importAktie dient dazu,<br> 
Kursdaten für eine spezifische Aktie aus einer CSV-Datei einzulesen und in einer Hash-Tabelle zu speichern.<br>

Funktionalität<br>
    Index-Berechnung:<br> 
        Über eine Hash-Funktion wird anhand des Aktiennamens die Position (aktie_index) in der Hash-Tabelle bestimmt.<br>
    Speicherallokation:<br> 
        Es wird dynamisch Speicher für die Kursdaten (AktieData) reserviert, basierend auf der Anzahl der einzulesenden Datensätze.<br>
    Dateizugriff:<br> 
        Die Funktion öffnet eine CSV-Datei, deren Pfad aus einem Standardpfad und dem Aktiennamen konstruiert wird.<br>
    Datenverarbeitung:<br>
        Der Header der CSV-Datei wird übersprungen.<br>
        In einer Schleife werden die Daten zeilenweise eingelesen und über initAktie im Speicher abgelegt.<br>
        Die Zeitkomplexität für das Einlesen beträgt O(n), wobei n die Anzahl der Datensätze (num_of_aktien) ist.<br>

Parameter<br>
    aktien:<br> 
        Die Hash-Tabelle (Array/Struktur), in der die Aktiendaten gespeichert werden.<br>
    aktie_name:<br> 
        String, der den Namen der Aktie (z. B. "AMAZON") repräsentiert. Dient als Schlüssel für den Hash und als Dateiname.<br>
    num_of_aktien:<br> 
        Ganzzahl, die angibt, wie viele Datensätze (Zeilen) aus der Datei gelesen werden sollen.<br>

# Plot 
Diese Funktion generiert ein textbasiertes ASCII-Streudiagramm in der Konsole,<br> 
um den Kursverlauf einer Aktie über die letzten 30 Tage zu visualisieren.<br>

Parameter:<br>
    aktData:<br> 
        Ein Pointer auf ein Array von AktieData-Strukturen (erwartet mindestens 30 Datensätze).<br>
    aktie_name:<br> 
        Der Name der Aktie (wird aktuell im Funktionskörper nicht aktiv für die Anzeige genutzt).<br>
    num_of_aktien:<br> 
        Die Anzahl der zu verarbeitenden Datensätze (die Logik ist fest auf 30 Tage ausgelegt).<br>

Funktionalität<br>
    Vorbereitung:<br> 
        Der Bildschirm wird gelöscht und der Cursor zurückgesetzt. Die Fließkommaausgabe wird auf zwei Nachkommastellen fixiert.<br>
    Skalierung:<br> 
        Die Schlusskurse der letzten 30 Tage werden extrahiert und sortiert, um die Y-Achse (Preise) dynamisch zu skalieren.<br>
    Y-Achse:<br> 
        Gibt die sortierten Preise vertikal aus und rückt diese optisch ein.<br>
    X-Achse & Plotting:<br>
        Gibt das Datum (Tag-Teil) horizontal am unteren Rand aus.<br>
        Nutzt ANSI-Escape-Sequenzen (\x1b[...H), um den Cursor direkt an die Positionen zu bewegen, die dem Preiswert entsprechen.<br>
        Zeichnet ein Balken-/Punkt-Diagramm mit *-Symbolen von unten nach oben bis zum jeweiligen Kurswert.<br>
    Interaktion:<br> 
        Versteckt den Cursor und wartet auf Benutzereingaben (getchar), bevor der Bildschirm final gelöscht wird.<br>

Voraussetzungen<br>
    Header:<br> 
        <iostream>, <iomanip>, <string>, <algorithm> (für Sortierung).<br>
    Helfer:<br> 
        Benötigt die Funktionen clearScreen() und sortFloatArray(), sowie die Konstante CURSOR_HOME.<br>
    Terminal:<br> 
        Erfordert ein Terminal, das ANSI-Escape-Codes zur Cursorsteuerung unterstützt.<br>

# save
Die Funktion save serialisiert Daten aus einem Array von Aktie-Objekten (Hash-Tabelle) und schreibt diese in eine Datei.<br> 
Dabei wird der Dateiname um einen vordefinierten Pfad (AKTIEN_PATH) ergänzt.<br> 
Vor dem Schreiben wird der bestehende Inhalt der Datei gelöscht.<br>

Parameter<br>
    aktien (Aktie):*<br> 
        Ein Pointer auf das Array (die Hash-Tabelle), das die Aktie-Objekte enthält.<br>
    hash_table_size (const int):<br> 
        Die Größe des Arrays. Hinweis: Im aktuellen Code wird stattdessen die globale Konstante HASH_TABLE_SIZE in der Schleife verwendet.<br>
    file_name (std::string):<br> 
        Der Name der Ziel-Datei (ohne Pfadangabe).<br>

Funktionsweise<br>
    Pfad-Konstruktion:<br> 
        Der file_name wird durch Voranstellen von AKTIEN_PATH modifiziert.<br>
    Datei-Modus:<br> 
        Die Datei wird mit std::ios::trunc geöffnet, wodurch ein etwaiger alter Inhalt überschrieben wird.<br>
    Serialisierung:<br> 
        In einer Schleife werden für jedes Element der Hash-Tabelle der Name, das Kürzel und die WKN nacheinander als Binärdaten/Strings geschrieben.<br>
    Abschluss:<br> 
        Der Stream wird explizit geschlossen.<br>

# load
Die Funktion lädt Aktiendaten aus einer Textdatei und speichert diese in einer bereitgestellten Hash-Tabelle (Array).<br>

Parameter:<br>
    aktien (Aktie*):<br>
        Pointer auf das Array (Hash-Tabelle), in das die Daten geladen werden sollen.<br>
    hash_table_size (const int):<br> 
        Die Anzahl der Einträge, die aus der Datei gelesen werden sollen<br>
    aktien_days (const int):<br> 
        Die Anzahl der Einträge, die die Täglichen Werte einer Aktie bestimmen<br>

Funktionsweise:<br>
    Benutzereingabe:<br> 
        Die Funktion fragt über die Konsole nach einem Dateinamen.<br>
    Pfad-Konstruktion:<br> 
        Der eingegebene Name wird mit dem Präfix DATABASE_PATH ergänzt.<br>
    Fehlerbehandlung:<br> 
        Falls die Datei nicht geöffnet werden kann, wird eine Fehlermeldung ausgegeben und die Funktion abgebrochen.<br>
    Einlesen:<br> 
        Die Funktion iteriert über die Größe der Hash-Tabelle und liest pro Eintrag die Felder name, kuerzel und wkn ein.<br>
    Abschluss:<br> 
        Die Datei wird nach dem Lesevorgang geschlossen.<br>