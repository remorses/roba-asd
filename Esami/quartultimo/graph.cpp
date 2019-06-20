#include "graph.h"
#include <iostream>

using namespace graph;


// il tipo Graph e' stato definito come puntatore al seguente struct,
// che contiene gli ingredienti che formano il grafo.

struct graph::graph_ingredients {

  unsigned int size = 0;    // numero attuale di vertici, inizialmente zero
  Label vertices[NMAX];     // tabella etichette, dimensione massima
  int adj[NMAX][NMAX];      // matrice di adiacenza

  // e' possibile aggiungere ulteriori ingredienti se ritenuti utili.

};


// funzione ausiliaria molto utile, per convertire l'etichetta di un vertice
// in indice del vertice (un intero da 0 a NMAX-1) mediante la
// tabella etichette;
// gli indici numerici cosi' ottenuti permetteranno di trovare velocemente
// le informazioni nella matrice di adiacenza.
// se l'etichetta non e' in tabella, la funzione restituisce -1.

int lookup(const Graph &g, Label l) {
  // DA IMPLEMENTARE (possibilmente in modo furbo)
  return 0;
}


// creazione di un grafo vuoto con un numero massimo prefissato di possibili
// vertici; il numero massimo e' indicato dalla costante NMAX.

Graph graph::createEmpty() {
  // DA IMPLEMENTARE; questa qui sotto serve solo come segnaposto ma non funziona
  return (Graph)nullptr;
};


// inserimento di un vertice la cui etichetta e' passata come parametro.
// restituisce false se l'etichetta e' gia' presente nel grafo, e in tal caso
// nessun nuovo vertice deve essere inserito; altrimenti restituisce true
// ad inserimento avvenuto.

bool graph::addVertex(Graph &g, Label l) {
  // DA IMPLEMENTARE
  return true;
}


// inserimento di un arco non orientato tra due vertici esistenti e distinti.
// restituisce false se i due vertici sono gia' collegati da un arco,
// oppure se uno dei due vertici non e' presente nel grafo, oppure se
// i due vertici coincidono; in tali casi nessun nuovo arco deve essere
// inserito.  altrimenti restituisce true ad inserimento avvenuto.

bool graph::addEdge(Graph &g, Label l1, Label l2) {
  // DA IMPLEMENTARE
  return true;
}


// visualizzazione del grafo, elencando, in corrispondenza dell'etichetta di
// ciascun vertice, l'elenco delle etichette dei vertici ad esso adiacenti.

void graph::print(const Graph &g) {
  // DA IMPLEMENTARE
  return;
}

// conteggio degli amici diretti.
// si tratta in pratica di calcolare il grado di un vertice
// identificato dalla sua etichetta, e restituirlo come risultato.
// se il vertice non e' presente nel grafo, la funzione restituisce -1.

int graph::numFriendsDirect(const Graph &g, Label l) {
  // DA IMPLEMENTARE
  return 0;
}

// conteggio dei vertici entro la distanza specificata dal parametro.
// la funzione dovrebbe evitare di contare uno stesso vertice per due o piu'
// volte ed evitare di contare il vertice di partenza.
// se il vertice di partenza non e' presente nel grafo, la funzione
// restituisce -1.

int graph::numFriendsAtDistance
(const Graph &g, Label l, unsigned int distance)
{
  // DA IMPLEMENTARE
  return 0;
}
