
Description in readme
Zadanie domowe z JIPP2 - zadanie udostepnione za zgodą prowadzącego otrzymana przez teams
Zakres:

    operatory
    funkcje zaprzyjaźnione
    operacja na ciągach znakowych

Treść

Stwórz klasę przechowującą ścieżkę do pliku. Przechowywana jest tylko ścieżka nie ma sprawdzania, czy istnieje takowy plik, takowa ścieżka, czy jest możliwa do odczytu/zapisu. Ustalamy, że są to ścieżki w systemie unixowym i wykorzystywany jest tylko / do rozdzielania katalogów.

Klasa musi posiadać funkcjonalności:

    konstruktor bezparametryczny (jest ustawiana ścieżka "/")
    konstruktor przyjmujący string, który jest ścieżką, w przypadku błędnej ścieżki ustaw ""
    void setPath(string) - ustawianie ścieżki, jeżeli błędna, to ustaw ""
    string getPath() - pobieranie ścieżki, bez znaku / na końcu
    operator + string - dodawanie do ścieżki pojedynczej kolejnej jej części (folderu), jeżeli jest błędne nie dodawaj nic. Przekazywana ścieżka może się kończyć, albo zaczynać znakiem /
    operator += string - dodawanie do ścieżki kolejnego pojedynczego elementu, jeżeli jest błędne nie dodawaj nic. Przekazywana ścieżka może się kończyć, albo zaczynać znakiem /
    operator -- - skracanie ścieżki, usuwanie ostatniego folderu z niej
    operatory == i != - porównywanie dwóch ścieżek
    operator <= - sprawdza, czy ścieżka po prawej stronie (cała) zawiera się w ścieżce po lewej stronie, jeżeli są takie same, to nadal się zawiera
    operator << - wypisania na ekran, do strumienia wpisujesz tylko ścieżkę

Doprecyzowania

Klasa będzie posługiwać się na ścieżkach tylko w formacie /mnt/c, a nie w c:/. Nazwy katalogów mogą składać się z dowolnych znaków, za wyjątkiem znaku /.

Wykonanie operacji + na ścieżce "" pozostawia dalej ścieżkę o wartości "".

Jeżeli użyjemy operatora -- na ścieżce /, to pozostajemy w /.

Błędna ścieżka to, taka, która nie zaczyna się od znaku /, albo posiada pustą nazwę katalogu (np. //).
