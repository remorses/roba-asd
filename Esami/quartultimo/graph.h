#ifndef _SOCIAL_H_
#define _SOCIAL_H_

#include <string>


namespace graph {

  // numero massimo di utenti della rete sociale
  #define NMAX 1000

  // le etichette nel grafo sono semplici stringhe: i nickname degli utenti

  typedef std::string Label;

  // dichiarazione anticipata (da definire poi in graph.cpp):
  // il grafo sara' implementato da una struct, contenente i vari ingredienti
  // (matrice di adiacenza, vettore etichette,
  // num. attuale e num. max elementi).

  struct graph_ingredients;

  // il grafo e' denotato dal puntatore alla struct
  // che racchiude i suoi ingredienti.

  typedef graph_ingredients *Graph;

  // creazione di un grafo vuoto, con un numero massimo prefissato di possibili
  // vertici indicato dalla costante NMAX (vedi sopra)

  Graph createEmpty();

  // inserimento di un vertice la cui etichetta e' passata come parametro.
  // restituisce false se l'etichetta e' gia' presente nel grafo, e in tal caso
  // nessun nuovo vertice deve essere inserito; altrimenti restituisce true
  // ad inserimento avvenuto.

  bool addVertex(Graph &, Label);

  // inserimento di un arco non orientato tra due vertici esistenti e distinti.
  // restituisce false se i due vertici sono gia' collegati da un arco,
  // oppure se uno dei due vertici non e' presente nel grafo, oppure se
  // i due vertici coincidono; in tali casi nessun nuovo arco deve essere
  // inserito.  altrimenti restituisce true ad inserimento avvenuto.

  bool addEdge(Graph &, Label, Label);

  // visualizzazione del grafo, elencando, in corrispondenza dell'etichetta di
  // ciascun vertice, l'elenco delle etichette dei vertici ad esso adiacenti.

  void print(const Graph &);

  // conteggio degli amici diretti.
  // si tratta in pratica di calcolare il grado di un vertice
  // identificato dalla sua etichetta, e restituirlo come risultato.
  // se il vertice non e' presente nel grafo, la funzione restituisce -1.

  int numFriendsDirect(const Graph &, Label);

  // conteggio dei vertici entro la distanza specificata dal parametro.
  // la funzione dovrebbe evitare di contare uno stesso vertice per due o piu'
  // volte ed evitare di contare il vertice di partenza.
  // se il vertice di partenza non e' presente nel grafo, la funzione
  // restituisce -1.
  // se la distanza e' zero, il comportamento non e' specificato.

  int numFriendsAtDistance(const Graph &, Label, unsigned int);

}

#endif // _SOCIAL_H_
