# Feladat

A reverse parancs megvalósítása
Ebben a feladatban megvalósítjuk a reverse parancsot: az argumentumként kapott fájlok tartalmát, vagy a konzolról beolvasott sorokat sorszámozva vagy sorszámozás nélkül, fordított sorrendben, és a sorokat megfordítva (tükrözve) írjuk ki a standard outputra. Pl. ha a test.txt tartalma a következő, és sorszámozást is kérünk:

alma
barack
szilva

…akkor a reverse parancs eredménye a következő:

3 avlizs
2 kcarab
1 amla

Példa több fájl feldolgozására: ha a test.txt fájlt kétszer adjuk meg paraméterül, és nem kérünk sorszámozást, akkor a kimenet a következő:

avlizs
kcarab
amla
avlizs
kcarab
amla

A beolvasandó fájlok nevét további parancssori argumentumokként adjuk meg a programnak, és olvassuk be egyenként a fájlok tartalmát. Ha az aktuális argumentum hibát okoz (a fájlt nem sikerült megnyitni), írjunk hibaüzenetet a standard error outputra, és folytassuk a végrehajtást a következő argumentummal. A hibaüzenet legyen: File opening unsuccessful: &lt;fájl neve&gt;. Ha a fájl egy sora hosszabb, mint a maximális sorhossz, a fennmaradó karaktereket hagyjuk figyelmen kívül!
Ha a felhasználó nem adott meg egy fájlnevet sem, olvassunk be sorokat a standard inputról, amelyek legfeljebb a megadott maximális számú karakterből állnak! Ebben az esetben ne írjunk a konzolra semmit, csak várjunk a felhasználó inputjára.
A sorok tárolásához használjunk dinamikus tömböt! A tömb létrehozásakor a mérete legyen egy előre rögzített érték (pl. 8). Ha a memóriafoglalás sikertelen, írjunk ki hibaüzenetet (Memory allocation failed!), és fejezzük be valamilyen hibakóddal a végrehajtást. (Ugyanez vonatkozik a tömb méretének megváltoztatására.) Ne számoljuk meg előre az aktuális fájl sorait, hanem duplázzuk meg a tömb méretét, amennyiben a sorok száma túllépi az aktuális méretet!
A megoldást bontsd több fordítási egységre! A main függvény kerüljön a main.c fájlba, minden más függvényimplementáció kerüljön külön fordítási egységbe, amelyhez készüljön el egy header állomány. A header állományt védd header guarddal.