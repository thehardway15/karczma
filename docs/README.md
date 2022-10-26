# Karczma

## Struktura

**main.cpp** - główny plik

**config.h** - zawiera stałe kolorów, kody klawiszy oraz listę dostępnych stron

**utils.cpp** - plik z helperami

**views** - katalog zawierający definicje stron

**views/views.h** - plik z nagłówkami dla stron zawartych w katalogu **views**

## Utils

**getch_noneblock** - zastępuje *cin* oraz *getch*. Nasłuchuje na wciśnięcie klawiszy i zwraca kod ascii, nie zatrzymuje procesu.

**drawBox** - funkcja rysująca funkcja rysująca boks o określonych wymiarach przy użyciu przekazanego znaku.

**clearScreen** - przenosi kursor na początek.

**clearContent** - czyści białymi znakami obczar roboczy (pomniejszony o ramkę)

**gotoxy** - przenosi kursor w okreśolne koordynaty

**gotoCenter** - przenosi kursor na środek obczaru zdefiniowanego przez **COLS** i **ROWS** w **config.h**

**gotoNextLine** - przenosi do następnej linii na podstawie przekazanych koordynat

**gotoWriteCenter** - wyznacza położenie kursowa w przekazanych koordynatacha aby string wypisał się na środku.

**gotoRight** - przenosi kursor od przekazaną wartość w prawo (w lewo jeśli wartości będą minusowe)

## Main

 **main** odpala w osobnym wątku loop'a obsługującego rysowanie widoków. Aplikacja kończy działania po ustawieniu zmiennej **stop** na true.

**page** zawiera informacje która strona ma być aktualnie wyświetlana.

**loop** zawiera pętlę aplikacji, rysowanie box'a poza pętlą orac czyszczenie contnetu (wewnętrznej części) zapobiega przerysowywaniu całości, dodatkowo Sleep na 100ms w całości zapobiegają migotaniu ekranu podczas przerysowywania w każdej pętli.

switch page na podstawie enum'a z **config.h** wybiera który widok ma być rysowany, do widoku przekazywane są wciśnięte klawisze, tam dodajemy ich obsługe. Poza F4 który przypięty jest globalnie do zamykania palikacij.


