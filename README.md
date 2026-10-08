**Polski** · [English](README.en.md)

---

# Matura z informatyki, poziom rozszerzony - "Rozkład na czynniki pierwsze"

> ### 🎬 Wideo z omówieniem
> Pełne omówienie tego tematu krok po kroku znajdziesz na moim kanale YouTube:
> **[Link do filmu na YouTube](https://youtu.be/st6_Vgkmarw)**
>
> Na filmie omawiam teorię i rozpisuję krok po kroku prostą i szybką wersję algorytmu dla liczby 420. Potem implementuję i uruchamiam oba algorytmy w Pythonie i w C++.

---

## Opis

Materiały do nagrania o rozkładzie liczby na czynniki pierwsze. To jeden z podstawowych algorytmów na liczbach całkowitych, które pojawiają się na maturze z informatyki.

Rozkład na czynniki pierwsze to zapis liczby jako iloczynu liczb pierwszych, na przykład `420 = 2 · 2 · 3 · 5 · 7`.

W repozytorium znajdziesz:

- notatki teoretyczne z definicjami, trzema własnościami dzielników i pseudokodem obu wersji algorytmu,
- prostą wersję algorytmu, która dzieli n przez kolejne liczby, dopóki n jest większe od 1 (`rozklad_naiwny`),
- szybką wersję algorytmu, która szuka dzielników tylko do pierwiastka z n (`rozklad`),
- funkcję sprawdzającą, czy liczba jest pierwsza, opartą na tym samym mechanizmie (`czy_pierwsza`),
- funkcję zapisującą rozkład w postaci potęgowej (`postac_potegowa`).

Wszystkie funkcje są zaimplementowane w Pythonie i w C++.

## Wymagania

- Python 3.9 lub nowszy, bo kod używa adnotacji typów w postaci `list[int]`
- Kompilator C++ obsługujący standard C++11 lub nowszy
- Brak zewnętrznych zależności, w Pythonie wykorzystano wyłącznie bibliotekę standardową (`collections.Counter`)

## Uruchomienie

Pobranie repozytorium:

```bash
git clone https://github.com/kmprograms/matura-rozklad-na-czynniki
cd matura-rozklad-na-czynniki
```

Wersja w Pythonie:

```bash
python app.py
```

Wersja w C++:

```bash
g++ -std=c++17 -O2 -o app app.cpp
./app
```

Oba programy rozkładają liczbę 420 obiema wersjami algorytmu i sprawdzają, czy liczby 97 i 91 są pierwsze. Na koniec wypisują postać potęgową liczb 420 i 99792.

## Struktura projektu

| Plik | Opis |
| --- | --- |
| `app.cpp` | Implementacja w języku C++: `rozklad_naiwny`, `rozklad`, `czy_pierwsza`, `postac_potegowa` oraz funkcja pomocnicza `pokaz` do wypisywania wektora |
| `app.py` | Implementacja w języku Python: `rozklad_naiwny`, `rozklad`, `czy_pierwsza`, `postac_potegowa` |
| `TEORIA.txt` | Definicje, trzy własności, na których opiera się algorytm, oraz pseudokod obu wersji z rozpiską krok po kroku dla liczby 420 |

## Teoria i sposób rozwiązania

### Pojęcia

Liczba pierwsza to liczba naturalna większa od 1, która ma dokładnie dwa dzielniki naturalne: 1 i samą siebie. Przykładem jest 13.

Liczba złożona to liczba naturalna większa od 1, która ma więcej niż dwa dzielniki naturalne. Przykładem jest 12, które dzieli się przez 1, 2, 3, 4, 6 i 12.

Liczba 1 nie jest ani pierwsza, ani złożona, bo ma tylko jeden dzielnik naturalny.

Rozkład liczby 420 to `420 = 2 · 2 · 3 · 5 · 7`, a w postaci potęgowej `420 = 2² · 3 · 5 · 7`. Wszystkich czynników jest 5 (2, 2, 3, 5, 7), bo liczymy każde wystąpienie dwójki. Różnych czynników są 4 (2, 3, 5, 7).

Każda liczba naturalna większa od 1 ma dokładnie jeden rozkład na czynniki pierwsze, jeśli nie liczymy kolejności czynników. To podstawowe twierdzenie arytmetyki. Dlatego mówimy "rozkład liczby", a nie "jeden z rozkładów".

### Trzy własności, na których opiera się algorytm

1. Najmniejszy dzielnik liczby n większy od 1 jest liczbą pierwszą. Dla n = 105 liczba 2 nie jest dzielnikiem, ale 3 już tak. 3 to najmniejszy dzielnik i jest to liczba pierwsza. 15 też dzieli 105, ale 15 = 3 · 5. Skoro 3 dzieli 15, a 15 dzieli 105, to 3 również dzieli 105 i jest mniejsze od 15.
2. Jeśli n = a · b oraz a ≤ b, to a ≤ √n. Dla n = 36 mamy pary 1 · 36, 2 · 18, 3 · 12, 4 · 9 i 6 · 6. Mniejsza liczba z pary nigdy nie przekracza √36 = 6. Dwie liczby większe od 6 dają iloczyn większy od 36, na przykład 7 · 7 = 49.
3. Jeśli n ≥ 2 i żadna liczba od 2 do √n nie dzieli n, to n jest liczbą pierwszą. Dla n = 97 (√97 ≈ 9,8) żadna z liczb od 2 do 9 nie dzieli 97, więc 97 jest liczbą pierwszą. Dla n = 91 (√91 ≈ 9,5) dzielnikiem okazuje się 7, bo 91 = 7 · 13.

Dzielniki liczby układają się w pary, których iloczyn daje n. Jeśli między 2 a √n nie ma mniejszej liczby z żadnej pary, to nie ma też większej. Intuicyjnie można by szukać dzielników aż do połowy liczby. Dla n = 1 000 000 oznacza to sprawdzanie aż do 500 000 zamiast do 1000. Dlatego wystarczy szukać dzielników do pierwiastka z n.

### Prosta wersja algorytmu (rozkład naiwny)

Na wejściu jest liczba naturalna n większa od 1. Na wyjściu są jej czynniki pierwsze od najmniejszego do największego.

Pseudokod z pliku `TEORIA.txt`:

```
d ← 2
dopóki n > 1 wykonuj
    jeżeli n mod d = 0
        wypisz d
        n ← n div d
    w przeciwnym razie
        d ← d + 1
```

Dopóki n dzieli się przez d, algorytm wypisuje d i dzieli przez nie n. Gdy n przestaje dzielić się przez d, d rośnie o 1. Pętla kończy się, gdy n spadnie do 1.

Rozpiska dla n = 420:

| Krok | n | d | n mod d | Operacja |
| --- | --- | --- | --- | --- |
| 1 | 420 | 2 | 0 | wypisz 2, n ← 210 |
| 2 | 210 | 2 | 0 | wypisz 2, n ← 105 |
| 3 | 105 | 2 | 1 | d ← 3 |
| 4 | 105 | 3 | 0 | wypisz 3, n ← 35 |
| 5 | 35 | 3 | 2 | d ← 4 |
| 6 | 35 | 4 | 3 | d ← 5 |
| 7 | 35 | 5 | 0 | wypisz 5, n ← 7 |
| 8 | 7 | 5 | 2 | d ← 6 |
| 9 | 7 | 6 | 1 | d ← 7 |
| 10 | 7 | 7 | 0 | wypisz 7, n ← 1 |

Po kroku 10 mamy n = 1 i pętla się kończy. Wynik to 2, 2, 3, 5, 7.

Ta wersja ma wadę. Dla liczby pierwszej pętla dochodzi aż do samego n. Dla 97 wykonuje 96 obrotów, a dla liczby pierwszej 1 000 000 007 ponad miliard obrotów. Pokazuję ją, żeby przećwiczyć pracę z pseudokodem. Jeśli na maturze dostaniesz podobny algorytm, od razu rozpoznasz, co robi, i będziesz gotowy na jego modyfikację.

Implementacja w Pythonie:

```python
def rozklad_naiwny(n: int) -> list[int]:
    czynniki = []
    d = 2
    while n > 1:
        if n % d == 0:
            czynniki.append(d)
            n //= d
        else:
            d += 1
    return czynniki
```

### Szybka wersja algorytmu (dzielenie do pierwiastka)

Pseudokod z pliku `TEORIA.txt`:

```
d ← 2
dopóki d · d ≤ n wykonuj
    dopóki n mod d = 0 wykonuj
        wypisz d
        n ← n div d
    d ← d + 1
jeżeli n > 1
    wypisz n
```

Pętla zewnętrzna działa, dopóki d · d ≤ n, czyli dopóki d nie przekroczy pierwiastka z n. Pętla wewnętrzna dzieli n przez d tyle razy, ile się da, i za każdym razem wypisuje d. Jeżeli po zakończeniu pętli n jest większe od 1, to n jest ostatnim czynnikiem pierwszym i trafia do wyniku.

Rozpiska dla n = 420:

| d | d · d | n przed | Dzielenia | n po |
| --- | --- | --- | --- | --- |
| 2 | 4 | 420 | wypisz 2, 2 | 105 |
| 3 | 9 | 105 | wypisz 3 | 35 |
| 4 | 16 | 35 | - | 35 |
| 5 | 25 | 35 | wypisz 5 | 7 |
| 6 | 36 | 7 | 36 > 7, koniec pętli | |

Po pętli n = 7 > 1, więc algorytm wypisuje 7. Wynik to 2, 2, 3, 5, 7, ten sam co w wersji prostej.

Skąd pewność, że to, co zostało po pętli, jest liczbą pierwszą? Wszystkie czynniki mniejsze od d zostały już wydzielone. Pętla skończyła się, bo d · d przekroczyło n. Zatem n nie ma żadnego dzielnika od 2 do swojego pierwiastka i z trzeciej własności wynika, że jest liczbą pierwszą.

Warunek ma postać `d * d <= n`, a nie d ≤ √n. To ta sama nierówność po podniesieniu obu stron do kwadratu. Warunek z pierwiastkiem wymagałby liczenia pierwiastka w każdym obrocie od nowa, a mnożenie jest prostsze i szybsze.

Implementacja w Pythonie:

```python
def rozklad(n: int) -> list[int]:
    czynniki = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            czynniki.append(d)
            n //= d
        d += 1
    if n > 1:
        czynniki.append(n)
    return czynniki
```

Implementacja w C++:

```cpp
vector<long long> rozklad(long long n) {
    vector<long long> czynniki;
    long long d = 2;
    while (d * d <= n) {
        while (n % d == 0) {
            czynniki.push_back(d);
            n /= d;
        }
        ++d;
    }

    if (n > 1) {
        czynniki.push_back(n);
    }

    return czynniki;
}
```

### Sprawdzanie, czy liczba jest pierwsza

Funkcja `czy_pierwsza` korzysta z tego samego mechanizmu co szybki rozkład. Dla n mniejszego od 2 zwraca fałsz. Potem sprawdza kolejne wartości d od 2, dopóki `d * d <= n`. Jeśli któreś d dzieli n, liczba jest złożona. Jeśli pętla dobiegnie końca bez znalezienia dzielnika, liczba jest pierwsza.

```python
def czy_pierwsza(n: int) -> bool:
    if n < 2:
        return False

    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True
```

Sposobów sprawdzania, czy liczba jest pierwsza, jest kilka. Ten traktuję jako ćwiczenie z wykorzystania rozkładu na czynniki pierwsze, a nie jako optymalną metodę.

### Postać potęgowa

Funkcja `postac_potegowa` zwraca napis w postaci `420 = 2^2 * 3 * 5 * 7`.

W Pythonie zliczanie wystąpień czynników załatwia `Counter` z modułu `collections`. Wystarczy przekazać mu listę zwróconą przez `rozklad(n)`, a widok `items()` daje pary czynnik i wykładnik. Czynnik z wykładnikiem 1 jest zapisywany bez potęgi, a pozostałe w postaci `p^k`. Części łączy `" * ".join(...)`. Dla n mniejszego od 2 funkcja rzuca `ValueError`, żeby nie zwracać napisu ze znakiem równości, po którym nic nie ma.

```python
def postac_potegowa(n: int) -> str:
    if n < 2:
        raise ValueError("n musi być >= 2")

    czesci = []

    # for czynnik, wykladnik in Counter(rozklad(n)).items():
    #     if wykladnik == 1:
    #         czesci.append(str(czynnik))
    #     else:
    #         czesci.append(f"{czynnik}^{wykladnik}")
    czesci = [str(p) if k == 1 else f"{p}^{k}" for p, k in Counter(rozklad(n)).items()]
    return f"{n} = " + " * ".join(czesci)
```

Zakomentowana pętla `for` to pierwsza wersja z nagrania. Wyrażenie listowe (list comprehension) robi to samo w jednej linii.

W C++ funkcja `postac_potegowa` buduje napis bez dodatkowych struktur danych. Dla każdego d liczy, ile razy n dzieli się przez d, czyli wykładnik. Jeśli wykładnik jest większy od 0, dopisuje separator i czynnik, a przy wykładniku większym od 1 także `^` i wykładnik. Po pierwszym czynniku separator zmienia się z pustego napisu na `" * "`. Na końcu dopisuje pozostałe n, jeśli jest większe od 1.

Alternatywą jest zwracanie słownika (w Pythonie `dict`, w C++ `map`), w którym kluczem jest czynnik, a wartością wykładnik. W Pythonie sprowadza się to do zamiany obiektu `Counter` na `dict`. Zostawiam to jako ćwiczenie.

## Wyniki

Program w Pythonie wypisuje:

```
Rozklad naiwny: [2, 2, 3, 5, 7]
Rozklad       : [2, 2, 3, 5, 7]
Czy pierwsza: 97 = True
Czy pierwsza: 91 = False
420 = 2^2 * 3 * 5 * 7
99792 = 2^4 * 3^4 * 7 * 11
```

Program w C++ wypisuje:

```
2	2	3	5	7
2	2	3	5	7
Czy pierwsza: 97 = 1
Czy pierwsza: 91 = 0
420 = 2^2 * 3 * 5 * 7
99792 = 2^4 * 3^4 * 7 * 11
```

W C++ funkcja `pokaz` oddziela czynniki tabulatorem, a wartości typu `bool` trafiają do `cout` jako `1` i `0`.

| Wywołanie | Wynik |
| --- | --- |
| `rozklad_naiwny(420)` | 2, 2, 3, 5, 7 |
| `rozklad(420)` | 2, 2, 3, 5, 7 |
| `czy_pierwsza(97)` | prawda |
| `czy_pierwsza(91)` | fałsz, bo 91 = 7 · 13 |
| `postac_potegowa(420)` | 420 = 2^2 * 3 * 5 * 7 |
| `postac_potegowa(99792)` | 99792 = 2^4 * 3^4 * 7 * 11 |

Rozkład liczby 420 zgadza się z rozpiskami krok po kroku z części teoretycznej.

## Uwagi implementacyjne

Logika jest podzielona na osobne funkcje, a wywołania testowe znajdują się w funkcji `main`. Dzięki temu funkcje łatwo przenieść do innego programu albo przetestować osobno.

W C++ liczba n, dzielnik d i czynniki mają typ `long long`, żeby kod poradził sobie także z dużymi liczbami. Dotyczy to również pętli w funkcji `pokaz`. W nagraniu najpierw użyłem tam typu `int` i poprawiłem go na `long long`, bo przy dużych liczbach mogłoby dojść do obcięcia danych.

W funkcji `czy_pierwsza` łatwo zapomnieć o zwiększaniu d. W nagraniu pominąłem `++d` w wersji C++, pętla nigdy się nie kończyła i program się zawiesił.

W wersji C++ funkcja `postac_potegowa` celowo nie używa `map`. Nagranie jest kierowane do maturzystów, więc napis składam wyłącznie z doklejanych fragmentów. Jeśli znasz `map`, możesz najpierw zapisać pary czynnik i wykładnik, a potem zamienić je na napis.

Wersja w Pythonie sprawdza warunek n ≥ 2 i rzuca `ValueError`. Wersja w C++ tego nie sprawdza, więc dla n mniejszego od 2 zwraca sam początek napisu, na przykład `1 = `.

Dzielenie całkowite to w Pythonie `//=`, a w C++ `/=` na liczbach typu `long long`.