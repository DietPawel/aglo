#### Drzewo przedział-przedział.

1. Wierzchołki drzewa są tworzone dynamicznie.
2. Domyślnie typ danych __int__ oraz zwracana wartość to __min__.
3. Domyślna wartość w wierzchołkach to 0.

###### Implementacja:
``` c++
//Tworzy drzewo o przedziale od 0 do 1000000.
dtree::Tree tree(0,1000000);
//zwieksz przedzial <2,7> o 100.
tree.add(2,7,100);
//ustawia wartość w 4 na 50.
tree.set(4,50);
//zapytaj sie o minimum na <2,6>
int a = tree.ask(2,6);
//a=50
```
