#### Algorytm wyszukiwania Silnych Spójnych składowych (strongly connected components)

1. Numerujemy wierzcholki po czasie wyjscia DFS w odwroconym grafie
2. Odwiedzamy nieodwiedzone wierzcholki w kolejnosci malejacej. Odwiedzajac wierzcholek odwiedzamy jednoczesnie wszytkie wierzcholki do ktorych mozemy dojsc od naszego rozpatrywanego wierzcholka.
3. Zbiór wierzchołków z kroku 2 to jedna spójna składowa.

http://www.algorytm.org/algorytmy-grafowe/silnie-spojne-skladowe.html 
