# Feladat

Egy kétdimenziós, táblás amőba játékot kell implementálni. A játékban két játékos vehet részt, akik felváltva dobnak egy-egy különböző színű korongot a táblába. A korongok leesnek a tábla adott oszlopában lévő legmélyebb szabad helyére. A játékosok közül az nyer, akinek legalább három korongja vízszintesen vagy függőlegesen egymás mellé vagy alá kerül.
Az oszlopokat nagybetűkkel azonosítjuk: A, B, C, D, E, F, G. Végig ugyanarról az oldalról nézzük a táblát. A korongok száma nincs limitálva, de 6 * 7-nél nincs többet nem lehet legálisan elhelyezni. A játékmenetet egy C-string írja le, pl. “ABDCAGEEE”, amit azt jelenti, hogy a kezdőjátékos először a baloldali oszlopba dobott, erre válaszként a második játékos eggyel mellé. Ezután megint a kezdőjátékos jön, aki a D oszlophoz dobja a korongot. Tehát a stringben két karakterenként írhatunk le egy kört.
A programot teszteljük több különböző játékmenettel, pl.

“ABDCAGEEE” (döntetlen játék)
“ABDCAEEEEEEFFFAC” (az 1. játékos győz)
“ABDCAEEEEEEFFG” (a 2. játékos győz)
“AAAAAAABBBBBBBCCCCCCCDDDDDDDEEEEEEEFFFFFFFGGGGGG” (döntetlen játék 6 hibás lépéssel)

A programot egyetlen c kiterjesztésű fájlban kell megírni.
