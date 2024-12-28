#include <bits/stdc++.h>

using namespace std;

const int vmax = 1e6, nmax = 2e5;
int a[5 + nmax], ciur[5 + vmax], urmator[5 + vmax], frecv[5 + vmax], curent[5 + vmax];
int divizibile; // divizibile = pentru cate numere curent[i] >= frecv[i]

// returnez cate numere prime sunt
int calculeazaCiur()
{
    // ciur[i] = cel mai mic factor prim al lui i
    for (int i = 2; i <= vmax; i++)
        if (ciur[i] == 0) // daca nu am ajuns la i, i e prim
            for (int j = i; j <= vmax; j += i) // merg la toti multipli lui i
                if (ciur[j] == 0) // daca nu am gasit pana acum un divizor prim
                    ciur[j] = i; // setez divizorul prim la i
    
    // ca sa nu mai fac atatea impartiri, precalculez i / ciur[i]
    for (int i = 2; i <= vmax; i++)
        urmator[i] = i / ciur[i];
    
    int prime = 0;
    for (int i = 2; i <= vmax; i++)
        if (ciur[i] == 0)
            prime++;
    return prime;
}

// descompun numar si adaug la frecventa numerelor din factorial
void adaugaFactorial(int numar)
{
    while (numar > 1)
    {
        frecv[ciur[numar]]++;
        
        numar = urmator[numar]; // echivalent cu numar = numar / ciur[numar]
    }
}

// descompun numar si adaug la frecventa curenta
void adaugaNumar(int numar)
{
    while (numar > 1)
    {
        curent[ciur[numar]]++;
        if (curent[ciur[numar]] == frecv[ciur[numar]])
            divizibile++; // tocmai am reusit curent[ciur[numar]] >= frecv[ciur[numar]]
        
        numar = urmator[numar];
    }
}

// descompun un numar si scot din frecventa curenta
void scoateNumar(int numar)
{
    while (numar > 1)
    {
        if (curent[ciur[numar]] == frecv[ciur[numar]])
            divizibile--; // aveam curent[ciur[numar]] >= frecv[ciur[numar]], acum nu
        curent[ciur[numar]]--;
        
        numar = urmator[numar];
    }
}

int main()
{
	ifstream cin("factoria.in");
	ofstream cout("factoria.out");
	
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    calculeazaCiur();
    
    // adaug factorii primi din factoriale
    for (int i = 1; i <= k; i++)
        adaugaFactorial(i);
    
    for (int i = 1; i <= vmax; i++)
        if (frecv[i] == 0)
            divizibile++;
    
    // two pointers:
    int dr = 1; // capatul dreapta
    long long ans = 0; // va reprezenta raspunsul
    for (int st = 1; st <= n; st++) // capatul stanga
    {
        // adaug cate am nevoie, dar am grija sa nu ies din vector
        while (dr <= n && divizibile < vmax)
        {
            adaugaNumar(a[dr]);
            dr++; // urmatorul element
        }
        
        if (divizibile == vmax)
            ans += n - dr + 2;
        
        scoateNumar(a[st]);
    }
    
    cout << ans << '\n';
}
