# Gra w sapera

Zagrajmy w sapera! Gra odbywa się na prostokątnej planszy $n \times m$, gdzie pod niektórymi polami ukryte są miny.
Gracz wykonuje kolejne kliknięcia w poszczególne jeszcze nieujawnione komórki planszy, odkrywając je. Jeśli:

- kliknięte pole **zawiera minę**, gra kończy się natychmiastową przegraną — nie jest możliwe wykonanie żadnych
  kolejnych kliknięć, a odkryta mina wybucha,
- kliknięte pole nie zawiera miny, ale **któreś z ośmiu przylegających pól zawiera minę**, w miejscu odkrytej komórki
  pojawia się liczba od 1 do 8 symbolizująca, ile min znajduje się dookoła,
- kliknięte pole nie zawiera miny i **przylegające osiem pól również nie zawiera miny**, to w miejscu odkrytej komórki
  pojawia się liczba 0, a następnie automatyczne odkrywane jest osiem pól dookoła miejsca kliknięcia i procedura
  powtarza się rekurencyjnie dla każdego z nich.

Kliknięcie w już odkryte pole nie zmienia stanu rozgrywki.

## Plansza

Zakładamy, że w lewym górnym rogu znajduje się komórka o współrzędnych $(1, 1)$, a w prawym dolnym rogu — $(n, m)$.

Wypisywanie przez program planszy powinno trzymać się następującej specyfikacji: w każdym z kolejnych $n$ wierszy
wyjścia należy wypisać $m$ znaków, zgodnie z legendą:

- `.` oznacza **nieodkryte pole**
- `0, 1, 2, ..., 8` oznacza **pole odkryte**, dookoła którego znajduje się **odpowiadająca liczba min**
- `X` oznacza **odkryte pole z miną**, która wybuchła

Domyślnie wszystkie nieujawnione miny są ukryte pod kropkami, ale za pomocą odpowiedniej komendy można je *odkryć*
(pokazać). W takim przypadku nieodkryte pola z minami są oznaczane za pomocą znaku `M`.

## Wejście i wyjście

Program powinien obsługiwać następujące komendy ze standardowego wejścia:

- `start n m b`, gdzie $n$, $m$ i $b$ to liczby naturalne ($1 \leq n, m \leq 1000$, $1 \leq b \leq n \cdot m$). Po
  wykonaniu tej komendy program powinien wygenerować nową planszę rozmiaru $n \times m$ i umieścić na niej w losowych
  miejscach $b$ min, a następnie wypisać aktualny stan planszy na standardowe wyjście.
- `show` powinno wypisać na standardowe wyjście obecny stan planszy lub, jeśli plansza nie została jeszcze wygenerowana,
  odpowiedni komunikat błędu.
- `click x y`, gdzie $x$ i $y$ to liczby naturalne ($1 \leq x \leq n$, $1 \leq y \leq m$) oznaczające współrzędne
  kliknięcia. Po wykonaniu tej komendy program powinien zasymulować kliknięcie w odpowiednią komórkę, zmienić stan
  planszy zgodnie z zasadami gry w sapera oraz wypisać zaktualizowany stan planszy na standardowe wyjście.
- `cheat` powinno przełączyć tryb programu w taki, w którym przy każdym wypisywaniu planszy nieodkryte miny są widoczne.
  Ponowne wykonanie tej samej komendy przywraca domyślne zachowanie (miny są ukryte).
- `help` powinno wypisać na standardowe wyjście listę dostępnych komend oraz ich krótki opis.

Po wczytaniu nieistniejącej komendy program powinien wypisać na standardowe wyjście stosowny komunikat z błędem.

## Przykładowe wykonanie programu

```
> start 4 4 3
. . . .
. . . .
. . . .
. . . .

> click 3 3
. . . .
. . . .
. . 2 .
. . . .

> click 4 1
. . . .
1 1 . .
0 1 2 .
0 1 . .

> click 2 2
. . . .
1 1 . .
0 1 2 .
0 1 . .

> click 4 3
. . . .
1 1 . .
0 1 2 .
0 1 X .

> click 1 3
. . . .
1 1 . .
0 1 2 .
0 1 X .

> cheat
Miny są teraz widoczne.

> show
M . . .
1 1 . .
0 1 2 M
0 1 X .

> start 2 2 1
. .
. M
```
