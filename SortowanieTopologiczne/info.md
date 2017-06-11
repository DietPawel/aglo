#### Sortowanie topologiczne _DAG_

1. Tworzymy graf skierowany gdzie krawędź z __A__ do __B__ oznacza, że __A__ będzie posortowane przed __B__
2. Przechodzimy algorytmem __DFS__ po grafie i wrzucamy na stos krawędzie przy wyjści z krawędzi 
3. na stosie mamy wierzcholki posortowane topologicznie

###### NOTE:
_Działa tylko dla grafów skierowanych ACYKLICZNYCH_
