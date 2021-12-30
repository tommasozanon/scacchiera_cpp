# scacchiera_cpp

## Da fare:

- rappresentazione visiva di board

## Fatti:

- pieces/Rook.h
- pieces/Rook.cpp
- pieces/Bishop.h
- pieces/Bishop.cpp
- pieces/Queen.h
- pieces/Queen.cpp
- pieces/Knight.h
- pieces/Knight.cpp
- pieces/King.h
- pieces/King.cpp

## Idee di Tommaso

I pezzi devono essere il più generali possibile. L'unico metodo importante che richiede un po' di tempo per essere scritto è "get_allowed_moves()" che ritorna tutte le mosse che quella pedina potrebbe fare in una scacchiera senza altri pezzi. Sarà poi compito di Board decidere queli mosse sono accettabili, valutando se ci sono altri pezzi in mezzo.

Board quindi dovrà gestire diversi casi.

Una volta finiti i pezzi comincerei a scrivere Board.

Per ora mi immagino un vector white e uno black che contengono i puntatori(che probabilmente diventeranno shared) alle pedine dei giocatori.
Poi ci sara una matrice 8x8 che rappresenterà l'esatta situazione di gioco
