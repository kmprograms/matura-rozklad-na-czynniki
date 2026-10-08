from collections import Counter

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


def czy_pierwsza(n: int) -> bool:
    if n < 2:
        return False
    
    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True              


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


def main() -> None:
    n = 420
    czynniki_1 = rozklad_naiwny(n)
    czynniki_2 = rozklad(n)
    print(f"Rozklad naiwny: {czynniki_1}")
    print(f"Rozklad       : {czynniki_2}")
    print(f"Czy pierwsza: 97 = {czy_pierwsza(97)}")
    print(f"Czy pierwsza: 91 = {czy_pierwsza(91)}")
    print(postac_potegowa(n))
    print(postac_potegowa(99792))


if __name__ == "__main__":
    main()