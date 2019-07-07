#ifndef _MAP_H_
#define _MAP_H_

#include <string>


namespace graph {

  // numero massimo di localita' della rete di trasporti
  #define NMAX 1000

  // le etichette dei vertici sono semplici stringhe: i nomi delle localita'

  typedef std::string Vlabel;

  // le etichette degli archi sono semplici caratteri che denotano il tipo
  // di tratta disponibile: 'f' per ferrovia, 's' per strada, 'e' per entrambi

  typedef char Elabel;

  // dichiarazione anticipata (da definire poi in graph.cpp):
  // il grafo sara' implementato da una struct, contenente i vari ingredienti
  // (matrice di adiacenza, vettore etichette,
  // num. attuale di nodi e num. max di nodi).

  struct graph_ingredients;

  // il grafo e' denotato dal puntatore alla struct
  // che racchiude i suoi ingredienti.

  typedef graph_ingredients *Graph;

  // creazione di un grafo vuoto, con un numero massimo prefissato di possibili
  // vertici indicato dalla costante NMAX (vedi sopra)

  Graph createEmpty ();

  // inserimento di un vertice la cui etichetta e' passata come parametro.
  // restituisce false se l'etichetta e' gia' presente nel grafo, e in tal caso
  // nessun nuovo vertice deve essere inserito; altrimenti restituisce true
  // ad inserimento avvenuto.

  bool addVertex (Graph &, Vlabel);

  // inserimento di un arco non orientato tra due vertici esistenti e distinti.
  // il parametro di tipo Elabel rappresenta il tipo di tratta (ferrovia,
  // strada, o entrambi).
  // restituisce false se i due vertici sono gia' collegati da un arco avente
  // la stessa etichetta, oppure se uno dei due vertici non e' presente nel
  // grafo, oppure se i due vertici coincidono; in tali casi nessun nuovo arco
  // deve essere inserito. altrimenti restituisce true ad inserimento avvenuto.
  // se tra i due vertici esisteva gia' un arco di tipo diverso da quello
  // specificato nel parametro, allora questo viene sovrascritto con 'e',
  // altrimenti sara' impostato al valore indicato nel parametro.

  bool addEdge (Graph &, Vlabel, Vlabel, Elabel);

  // visualizzazione del grafo, elencando, in corrispondenza dell'etichetta di
  // ciascun vertice, l'elenco delle etichette dei vertici ad esso adiacenti,
  // ciascuno contraddistinto dal tipo di tratta di collegamento
  // ('f' oppure 's' oppure 'e')

  void print (const Graph &);

  // restituisce true se esiste un cammino qualunque tra i vertici indicati dai
  // due parametri, false altrimenti.  si suggerisce un approccio ricorsivo e
  // l'impiego di opportuni accorgimenti per evitare che il cammino passi piu'
  // volte attraverso uno stesso vertice (nel grafo possono esistere cicli).
  // la visualizzazione del cammino trovato non e' richiesta.

  bool connected (const Graph &, Vlabel, Vlabel);

  // immersione di un grafo entro un altro.  i due grafi da immergere sono
  // denotati dai primi due parametri, mentre il terzo parametro indica il
  // grafo di destinazione.  quest'ultimo viene creato vuoto dal chiamante,
  // che lo passa alla funzione, la quale lo svuota se non risulta vuoto
  // e poi lo riempie con il merge dei primi due grafi.
  // l'operazione deve evitare la creazione di doppioni di vertici e/o archi.
  // la funzione restituisce false se la capienza del grafo di destinazione
  // risulta insufficiente, altrimenti restituisce true a immersione effettuata.

  bool merge (const Graph &, const Graph &, Graph &);

}

#endif // _MAP_H_
