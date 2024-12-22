Mai întâi, vom fixa numărul de factori din produs. Fie acesta $i$. Putem observa că $i$ este mai mic sau egal cu suma exponenților din descompunerea în factori primi a lui $x$ (să notăm această sumă cu $S$). Noi nu putem să ne asigurăm ca fiecare număr va fi mai mare ca $1$ decât dacă ne asigurăm că fiecare număr are toate numerele prime din descompunerea lui $x$ în descompunerea lui.

Noi vrem ca exact $0$ din cele $i$ elemente să fie egale cu $1$. Pentru a calcula acest număr, putem aplica PINEX în funcție de câte elemente am fixat să fie egale cu $1$.

Fie $f(n, i)$ numărul de moduri de a împărți numărul $n$ în produs de $i$ elemente, care pot fi și egale cu $1$.

Răspunsul va fi $\sum _{i=1} ^S \sum _{j=0} ^i \ (-1)^j \cdot C _i ^j \cdot f(x, i-j)$, deoarece putem alege cele $j$ elemente care vor fi egale cu $1$ în $C _i ^j$ moduri.

Să calculam $f(n, i)$. Fie $k$ numărul de factori primi ai lui $n$ și fie $exp_k$ exponentul al celui de-al $k$-lea factor prim în $n$. Pentru a afla numărul, putem să ne legăm de fiecare factor prim. Noi trebuie sa vedem câți vectori (tablouri unidimensionale) de lungime $i$ cu elemente posibil nule au suma elementelor egală cu $exp_K$. Această formulă se cheamă [Stars and Bars](https://edu.roalgo.ro/mediu/intro-combinatorics/?h=stars#stars-and-bars). Așa că, numărul căutat va fi $\prod _{j=1} ^k C _{exp_k+i-1} ^{i-1}$.

Descompunerea în factori primi va fi făcută folosind numerele prime, pe care le vom precalcula folosind [ciurul lui Eratostene](https://edu.roalgo.ro/usor/sieve/).

Unele calcule pot fi foarte mari, mai mari decât poate stoca tipul **long long**. De aceea, vom folosi [tipul __int128](https://edu.roalgo.ro/cppintro/data-types/#tipul-__int128).
