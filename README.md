### Documentation

# hashFunction
Die Funktion hashFunction berechnet einen numerischen Index aus einem String (in der Regel dem Aktien-Kürzel),<br>
um entweder einen Speicherplatz zu finden oder nach einem existierenden Kürzel zu suchen(suche hat O(1) best case).<br>

FunktionalitätHash-Berechnung:<br>
    Die Funktion nutzt die ersten 4 Zeichen des Eingabestrings für die Berechnung.Es wird ein gewichteter Polynomial-Hash verwendet.<br>
    Normalisierung:<br>
        Der berechnete Wert wird mittels Modulo-Operation (% hash_table_size) auf die Größe der Tabelle begrenzt.<br>
    Kollisionsmanagement:<br>
        Das Ergebnis wird an die collisionFunction weitergegeben, um sicherzustellen,<br> 
        dass entweder ein freier Platz gefunden oder das gesuchte Element (bei einer Suche) lokalisiert wird.<br>

Parameter<br>
    aktieArray:<br>
        Die Hash-Tabelle, in der gearbeitet wird.<br>
    str:<br>
        Der Eingabestring (Kürzel), der in einen Index umgewandelt werden soll.<br>
    hash_table_size:<br>
        Die maximale Kapazität der Hash-Tabelle.<br>
    search_flag:<br>
        Ganzzahl, die steuert, ob nach einem freien Platz (0) oder einem existierenden Kürzel (1) gesucht wird.<br>

# collisionFunction
Die Funktion collisionFunction implementiert die Strategie zur Auflösung von Kollisionen,<br> 
falls der durch den Hash berechnete Index bereits belegt oder nicht das gesuchte Element ist.<br>

Funktionalität<br>
    Element suche:<br>
        Wenn der search_flag parameter 1 is dann sucht die function den gegebenen Kuerzel.<br>
    Sondierungs-Algorithmus:<br>
        Die Function such nach einen freien index oder ein Kuerzel mit hilfe eines sondierungs Algorithmus.<br>
        Die Suche endet erfolgreich, wenn ein lehrer Index gefunden wird oder bie suche der Kuerzel gefundet.<br>
        Erreicht die Sondierung die Array-Grenzen, wird -1 zurückgegeben.<br>

Parameter<br>
    aktieArray:<br> 
        Die Hash-Tabelle, die auf Kollisionen geprüft wird.<br>
    str:<br>
        Das Kuerzel der Aktie, nach dem gesucht wird.<br>
    index:<br>
        Der ursprünglich durch die hashFunction berechnete Startindex.<br>
    search_flag:<br>
        Steuert, ob nach einem spezifischen Kuerzel oder einem leeren Slot gesucht wird.<br>

# add
Die Funktion add dient dazu,<br>
eine neue Aktie manuell über Benutzereingaben zu erstellen und an der entsprechenden Position in der Hash-Tabelle zu speichern.<br>

Funktionalität<br>
    Benutzereingabe:<br>
        Über die Konsole werden Name, WKN und das Kürzel der Aktie abgefragt.<br>
    Objekterzeugung:<br>
        Aus den eingegebenen Daten wird ein neues Objekt der Klasse Aktie instanziiert.<br>
    Index-Berechnung:<br>
        Die Funktion hashFunction berechnet anhand des Kürzels den Ziel-Index in der Hash-Tabelle.<br>
    Speicherung:<br>
        Falls der berechnete Index gültig ist, wird das neue Aktien-Objekt an der Stelle aktien[aktie_index] abgelegt.<br>

Parameter<br>
    aktien:<br>
        Die Hash-Tabelle (Array/Struktur), in der die Aktiendaten gespeichert werden.<br>

# deleteAktie
Die Funktion deleteAktie ermöglicht das Entfernen einer Aktie aus der Hash-Tabelle,<br> 
wobei der Nutzer zwischen der Identifikation per Kürzel oder Name wählen kann.<br>
    
Funktionalität<br>
    Suchmodus-Auswahl:<br>
        Der Nutzer wählt per Eingabe den Suchmodus ('a' für Kürzel, 'b' für Name).<br> 
        Eine Validierungsschleife stellt sicher, dass nur korrekte Optionen akzeptiert werden.<br>
    Suche:<br>
        Kürzel: Nutzt die hashFunction, um den Index direkt über den Hash-Algorithmus zu finden (O(1) im Bestcase).<br>
        Name: Ruft searchWithName auf, was in der Regel eine lineare Suche (O(n)) erfordert.<br>
    Speicherbereinigung:<br>
        Die Methode freeAktData() wird aufgerufen, um den dynamisch reservierten Speicher der zugehörigen Kursdaten freizugeben.<br>
    Fehlerbehandlung:<br>
        Falls die Aktie nicht gefunden wird (result == -1), wird der Vorgang mit einer Information an den Nutzer abgebrochen.<br>

Parameter<br>
    aktien:<br>
        Die Hash-Tabelle (Array/Struktur), in der die Aktiendaten gespeichert werden.<br>

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

# search
Die Funktion search dient dazu, eine spezifische Aktie in der Hash-Tabelle zu finden<br> 
und deren aktuellste Kurseintrag auf der Konsole auszugeben.<br>

Funktionalität<br>
    Suchmodus-Auswahl:<br>
        Der Nutzer wählt zwischen der Suche per Kürzel ('a') oder Name ('b').<br>
    SuchMethode:<br>
        Kürzel: Nutzt die hashFunction, um den Index direkt über den Hash-Wert des Kürzels zu ermitteln((O(1) im Bestcase)).<br>
        Name: Ruft die Hilfsfunktion searchWithName auf, um die Tabelle nach dem Klarnamen zu durchsuchen(O(n)).<br>

Parameter<br>
    aktien:<br>
        Die Hash-Tabelle (Array/Struktur), in der die Aktiendaten gespeichert werden.<br>

# searchWithName
Die Funktion searchWithName ist eine Hilfsfunktion,<br> 
die eine lineare Suche in der Hash-Tabelle durchführt,<br> 
um ein Aktien-Objekt anhand seines Namens zu finden.<br>

Funktionalität<br>
    Lineares Durchsuchen:<br>
        Die Funktion iteriert in einer Schleife über alle Einträge der Hash-Tabelle.<br>

Parameter<br>
    aktieArray:<br>
        Die Hash-Tabelle (Array/Struktur), in der die Aktiendaten gespeichert werden.<br>
    name:<br>
        Der String (als Referenz), der den gesuchten Namen der Aktie repräsentiert.<br>

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