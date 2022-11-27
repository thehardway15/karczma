# Karczma

## Ogólne

Aplikacja konsolowa stworzona jest pod system Windows. Minimalna wymagana wersja kompilatora co C++14.

## Struktura

**main.cpp** - główny plik

**config.h** - zawiera stałe kolorów, kody klawiszy oraz listę dostępnych stron

**utils.cpp** - plik z helperami

**i18n.cpp** - zawiera wszystkie komunikaty i treści wykorzystywane a aplikacji

**views** - katalog zawierający definicje stron

**views/views.h** - plik z nagłówkami dla stron zawartych w katalogu **views**

**static** - pliki w formacie json zaweirające dane ładowane do programu

**models** - struktury danych

**include** - dodatkowe bibliteki np. lib do pardowania json'a.

**docs** - dokumentacja projektu

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

**readOrderItems** - wczytuje pozycje menu do zamówień z pliku json

**readRestaurantDetails** - wczytuje dane o restauracji

## Main

 **main** odpala w osobnym wątku loop'a obsługującego rysowanie widoków. Aplikacja kończy działania po ustawieniu zmiennej **stop** na true.

**page** zawiera informacje która strona ma być aktualnie wyświetlana.

**loop** zawiera pętlę aplikacji, rysowanie box'a poza pętlą orac czyszczenie contnetu (wewnętrznej części) zapobiega przerysowywaniu całości, dodatkowo Sleep na 100ms w całości zapobiegają migotaniu ekranu podczas przerysowywania w każdej pętli.

switch page na podstawie enum'a z **config.h** wybiera który widok ma być rysowany, do widoku przekazywane są wciśnięte klawisze, tam dodajemy ich obsługe. Poza F4 który przypięty jest globalnie do zamykania palikacij.

Wszystkie dane które mają być zachowane podczas działania **loop'a** należy zadeklarować poza pętlą *while* i przekazać przez referencje do **page**

## Page

### Obsługa klawiatury

w głownej pętli programu przechwytywane są wszystkie wciśnięte klawisze. Przekazywane są one do wybranego **page** na podstawie ustawionej zmiennej. Dzięki czemu nie ma potrzeby używania np *cin* wewnątrz widoków co skutkowało by zablokowaniem programu w tym miejscu i oczekiwaniem na klawisz.

### Dodawanie nowego widoku

1. Dodajemy unikalną wartość do enum'a `Page` znajdującego się w **config.h**
2. Tworzymy plik z widokiem w katalogu *views* jego definicję do *views/views.h*
3. Dodajemy kolejny `case` w głównej pętli programu znajdującego się wewnątrz pliku **main.cpp**

Podstawowe parametry przekazywane do widoku:

- `hConsole` potrzebne do manipulowania kursoerm na konsli (ustawianie pozycji, zmiana koloru)
- `key` kod ASCII wciśniętego klawisza przez użytkownika
- `page` referencja do zmiennej przechowującej aktualnie wyświetlany widok, potrzebne do przechodzenia między widokami. 