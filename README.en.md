[Polski](README.md) · **English**

---

# Matura in Computer Science, extended level - "Prime factorization"

> ### 🎬 Video walkthrough
> You can find a full step-by-step walkthrough of this topic on my YouTube channel:
> **[Link to the YouTube video](https://youtu.be/st6_Vgkmarw)**
>
> In the video I go through the theory and trace the simple and the fast version of the algorithm step by step for the number 420. Then I implement and run both algorithms in Python and C++.

---

## Description

Materials for the recording on prime factorization. It is one of the basic integer algorithms that appear in the Matura exam in computer science.

Prime factorization means writing a number as a product of prime numbers, for example `420 = 2 · 2 · 3 · 5 · 7`.

In this repository you will find:

- theory notes with definitions, three properties of divisors and pseudocode for both versions of the algorithm,
- the simple version of the algorithm, which divides n by consecutive numbers as long as n is greater than 1 (`rozklad_naiwny`),
- the fast version of the algorithm, which looks for divisors only up to the square root of n (`rozklad`),
- a function that checks whether a number is prime, based on the same mechanism (`czy_pierwsza`),
- a function that writes the factorization in power notation (`postac_potegowa`).

All functions are implemented in both Python and C++.

## Requirements

- Python 3.9 or newer, because the code uses type annotations of the form `list[int]`
- A C++ compiler supporting C++11 or newer
- No external dependencies, the Python version uses only the standard library (`collections.Counter`)

## Running

Clone the repository:

```bash
git clone https://github.com/kmprograms/matura-rozklad-na-czynniki
cd matura-rozklad-na-czynniki
```

Python version:

```bash
python app.py
```

C++ version:

```bash
g++ -std=c++17 -O2 -o app app.cpp
./app
```

Both programs factorize 420 with both versions of the algorithm and check whether 97 and 91 are prime. Finally, they print the power notation of 420 and 99792.

## Project structure

| File | Description |
| --- | --- |
| `app.cpp` | C++ implementation: `rozklad_naiwny`, `rozklad`, `czy_pierwsza`, `postac_potegowa` and the helper function `pokaz` that prints a vector |
| `app.py` | Python implementation: `rozklad_naiwny`, `rozklad`, `czy_pierwsza`, `postac_potegowa` |
| `TEORIA.txt` | Definitions, the three properties the algorithm relies on, and pseudocode for both versions with a step-by-step trace for 420 |

## Theory and solution approach

### Key concepts

A prime number is a natural number greater than 1 that has exactly two natural divisors: 1 and itself. An example is 13.

A composite number is a natural number greater than 1 that has more than two natural divisors. An example is 12, which is divisible by 1, 2, 3, 4, 6 and 12.

The number 1 is neither prime nor composite, because it has only one natural divisor.

The factorization of 420 is `420 = 2 · 2 · 3 · 5 · 7`, and in power notation `420 = 2² · 3 · 5 · 7`. There are 5 factors in total (2, 2, 3, 5, 7), because every occurrence of 2 is counted. There are 4 distinct factors (2, 3, 5, 7).

Every natural number greater than 1 has exactly one prime factorization, ignoring the order of the factors. This is the fundamental theorem of arithmetic. That is why we say "the factorization of a number" rather than "one of its factorizations".

### Three properties the algorithm relies on

1. The smallest divisor of n greater than 1 is a prime number. For n = 105, 2 is not a divisor, but 3 is. 3 is the smallest divisor and it is prime. 15 also divides 105, but 15 = 3 · 5. Since 3 divides 15 and 15 divides 105, 3 also divides 105 and is smaller than 15.
2. If n = a · b and a ≤ b, then a ≤ √n. For n = 36 the pairs are 1 · 36, 2 · 18, 3 · 12, 4 · 9 and 6 · 6. The smaller number in a pair never exceeds √36 = 6. Two numbers greater than 6 give a product greater than 36, for example 7 · 7 = 49.
3. If n ≥ 2 and no number from 2 to √n divides n, then n is prime. For n = 97 (√97 ≈ 9.8) none of the numbers from 2 to 9 divides 97, so 97 is prime. For n = 91 (√91 ≈ 9.5) the number 7 turns out to be a divisor, because 91 = 7 · 13.

The divisors of a number form pairs whose product is n. If there is no smaller number of any pair between 2 and √n, there is no larger one either. Intuitively, you might search for divisors up to half of the number. For n = 1,000,000 that means checking up to 500,000 instead of up to 1,000. That is why it is enough to look for divisors up to the square root of n.

### Simple version of the algorithm (naive factorization)

The input is a natural number n greater than 1. The output is its prime factors from smallest to largest.

Pseudocode from `TEORIA.txt`, kept in Polish as in the file (`dopóki` means while, `wykonuj` do, `jeżeli` if, `w przeciwnym razie` otherwise, `wypisz` output, `mod` remainder, `div` integer division):

```
d ← 2
dopóki n > 1 wykonuj
    jeżeli n mod d = 0
        wypisz d
        n ← n div d
    w przeciwnym razie
        d ← d + 1
```

As long as n is divisible by d, the algorithm outputs d and divides n by it. When n is no longer divisible by d, d is increased by 1. The loop ends when n drops to 1.

Trace for n = 420:

| Step | n | d | n mod d | Operation |
| --- | --- | --- | --- | --- |
| 1 | 420 | 2 | 0 | output 2, n ← 210 |
| 2 | 210 | 2 | 0 | output 2, n ← 105 |
| 3 | 105 | 2 | 1 | d ← 3 |
| 4 | 105 | 3 | 0 | output 3, n ← 35 |
| 5 | 35 | 3 | 2 | d ← 4 |
| 6 | 35 | 4 | 3 | d ← 5 |
| 7 | 35 | 5 | 0 | output 5, n ← 7 |
| 8 | 7 | 5 | 2 | d ← 6 |
| 9 | 7 | 6 | 1 | d ← 7 |
| 10 | 7 | 7 | 0 | output 7, n ← 1 |

After step 10 we have n = 1 and the loop ends. The result is 2, 2, 3, 5, 7.

This version has a drawback. For a prime number the loop goes all the way up to n itself. For 97 it makes 96 iterations, and for the prime 1,000,000,007 more than a billion. I show it to practise working with pseudocode. If you get a similar algorithm in the exam, you will immediately recognise what it does and be ready to modify it.

Python implementation:

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

### Fast version of the algorithm (trial division up to the square root)

Pseudocode from `TEORIA.txt`:

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

The outer loop runs as long as d · d ≤ n, that is, as long as d does not exceed the square root of n. The inner loop divides n by d as many times as possible and outputs d each time. If n is greater than 1 after the loop, then n is the last prime factor and is added to the result.

Trace for n = 420:

| d | d · d | n before | Divisions | n after |
| --- | --- | --- | --- | --- |
| 2 | 4 | 420 | output 2, 2 | 105 |
| 3 | 9 | 105 | output 3 | 35 |
| 4 | 16 | 35 | - | 35 |
| 5 | 25 | 35 | output 5 | 7 |
| 6 | 36 | 7 | 36 > 7, end of loop | |

After the loop n = 7 > 1, so the algorithm outputs 7. The result is 2, 2, 3, 5, 7, the same as in the simple version.

How can we be sure that what remains after the loop is prime? All factors smaller than d have already been divided out. The loop ended because d · d exceeded n. So n has no divisor between 2 and its square root, and by the third property it is prime.

The condition is written as `d * d <= n` rather than d ≤ √n. It is the same inequality with both sides squared. The square root condition would require computing the square root again in every iteration, while multiplication is simpler and faster.

Python implementation:

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

C++ implementation:

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

### Checking whether a number is prime

The `czy_pierwsza` function uses the same mechanism as the fast factorization. For n smaller than 2 it returns false. Then it checks consecutive values of d starting from 2 as long as `d * d <= n`. If any d divides n, the number is composite. If the loop finishes without finding a divisor, the number is prime.

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

There are several ways to check whether a number is prime. I treat this one as an exercise in using prime factorization, not as the optimal method.

### Power notation

The `postac_potegowa` function returns a string such as `420 = 2^2 * 3 * 5 * 7`.

In Python, counting factor occurrences is handled by `Counter` from the `collections` module. You pass it the list returned by `rozklad(n)`, and the `items()` view gives pairs of factor and exponent. A factor with exponent 1 is written without a power, and the others in the form `p^k`. The parts are joined with `" * ".join(...)`. For n smaller than 2 the function raises `ValueError`, so it never returns a string with an equals sign followed by nothing.

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

The commented-out `for` loop is the first version from the recording. The list comprehension does the same in a single line.

In C++, `postac_potegowa` builds the string without any additional data structures. For each d it counts how many times n is divisible by d, which gives the exponent. If the exponent is greater than 0, it appends the separator and the factor, and if the exponent is greater than 1, also `^` and the exponent. After the first factor the separator changes from an empty string to `" * "`. Finally, it appends the remaining n if it is greater than 1.

An alternative is to return a dictionary (`dict` in Python, `map` in C++) where the key is the factor and the value is the exponent. In Python this comes down to converting the `Counter` object to a `dict`. I leave this as an exercise.

## Results

The Python program prints:

```
Rozklad naiwny: [2, 2, 3, 5, 7]
Rozklad       : [2, 2, 3, 5, 7]
Czy pierwsza: 97 = True
Czy pierwsza: 91 = False
420 = 2^2 * 3 * 5 * 7
99792 = 2^4 * 3^4 * 7 * 11
```

The C++ program prints:

```
2	2	3	5	7
2	2	3	5	7
Czy pierwsza: 97 = 1
Czy pierwsza: 91 = 0
420 = 2^2 * 3 * 5 * 7
99792 = 2^4 * 3^4 * 7 * 11
```

In C++ the `pokaz` function separates the factors with a tab, and `bool` values are sent to `cout` as `1` and `0`.

| Call | Result |
| --- | --- |
| `rozklad_naiwny(420)` | 2, 2, 3, 5, 7 |
| `rozklad(420)` | 2, 2, 3, 5, 7 |
| `czy_pierwsza(97)` | true |
| `czy_pierwsza(91)` | false, because 91 = 7 · 13 |
| `postac_potegowa(420)` | 420 = 2^2 * 3 * 5 * 7 |
| `postac_potegowa(99792)` | 99792 = 2^4 * 3^4 * 7 * 11 |

The factorization of 420 matches the step-by-step traces in the theory section.

## Implementation notes

The logic is split into separate functions, and the test calls are in the `main` function. This makes it easy to move the functions to another program or test them separately.

In C++ the number n, the divisor d and the factors use the `long long` type, so the code also handles large numbers. This also applies to the loop in the `pokaz` function. In the recording I first used `int` there and changed it to `long long`, because with large numbers the data could be truncated.

It is easy to forget to increment d in `czy_pierwsza`. In the recording I left out `++d` in the C++ version, the loop never ended and the program hung.

In the C++ version `postac_potegowa` deliberately does not use `map`. The recording is aimed at Matura students, so I build the string only by appending fragments. If you know `map`, you can first store pairs of factor and exponent and then convert them to a string.

The Python version checks the condition n ≥ 2 and raises `ValueError`. The C++ version does not check it, so for n smaller than 2 it returns only the beginning of the string, for example `1 = `.

Integer division is `//=` in Python and `/=` on `long long` values in C++.