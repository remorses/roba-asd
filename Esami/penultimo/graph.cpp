#include "graph.h"
#include <iostream>
#include <set>
using namespace graph;
using namespace std;  // cout


// il tipo Graph e' stato definito come puntatore al seguente struct,
// che contiene gli ingredienti che formano il grafo.

struct graph::graph_ingredients {

  unsigned int size = 0;    // numero attuale di vertici, inizialmente zero
  Vlabel vertices[NMAX];    // tabella etichette vertici, dimensione massima
  Elabel adj[NMAX][NMAX];   // matrice di adiacenza, contenente l'etichetta
                            // di ciascun arco ('f' oppure 's' oppure 'e')
                            // oppure 0 se arco non presente.

  // e' possibile aggiungere ulteriori ingredienti se ritenuti utili.

};


// funzione ausiliaria molto utile, per convertire l'etichetta di un vertice
// in indice del vertice (un intero da 0 a NMAX-1) mediante la
// tabella etichette;
// gli indici numerici cosi' ottenuti permetteranno di trovare velocemente
// le informazioni nella matrice di adiacenza.
// se l'etichetta non e' in tabella, la funzione restituisce -1.

int lookup (const Graph &g, Vlabel l) {
  // DA IMPLEMENTARE (possibilmente in modo furbo)
  for (int i = 0; i < g->size; i++) {
      if (g->vertices[i] == l) {
          return i;
      }
  }
  return -1;
}


// creazione di un grafo vuoto con un numero massimo prefissato di possibili
// vertici; il numero massimo e' indicato dalla costante NMAX.

Graph graph::createEmpty () {
  // DA IMPLEMENTARE; questa serve solo come segnaposto ma non funziona
  // auto vertices = new Vlabel[NMAX];
  // auto edges = new Elabel[NMAX][NMAX];
  Graph g = new graph_ingredients;
  // g->vertices = new Vlabel[NMAX];
  g->size = 0;

  for (int i = 0; i < NMAX; i++) {
    for (int j = 0; j < NMAX; j++) {
      g->adj[i][j] = 0;
    }
  }
  // cout << g->vertices[30] << endl;
  return g;
};
// Graph graph::createEmpty () {
//   // DA IMPLEMENTARE; questa serve solo come segnaposto ma non funziona
//   auto vertices = new Vlabel[NMAX];
//   auto edges = new Elabel[NMAX][NMAX];
//   Graph g = new graph::graph_ingredients {0, *vertices, *edges};
//   return g;
// };


// inserimento di un vertice la cui etichetta e' passata come parametro.
// restituisce false se l'etichetta e' gia' presente nel grafo, e in tal caso
// nessun nuovo vertice deve essere inserito; altrimenti restituisce true
// ad inserimento avvenuto.

bool graph::addVertex (Graph &g, Vlabel l) {
  // DA IMPLEMENTARE
  if(lookup(g, l) != -1) {
      return false;
  }
  g->vertices[g->size] = l;
  g->size += 1;
  return true;
}


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

bool graph::addEdge (Graph &g, Vlabel l1, Vlabel l2, Elabel t) {
  // DA IMPLEMENTARE
  int i1 = lookup(g, l1);
  int i2 = lookup(g, l2);
  if (i1 == -1 || i2 == -1 || l1 == l2) {
      return false;
  } 
  if (g->adj[i1][i2] == t && g->adj[i2][i1] == t) {
    return false;
  }
  if (g->adj[i1][i2] == 0 && g->adj[i2][i1] == 0) {
    g->adj[i1][i2] = t;
    g->adj[i2][i1] = t;
    return true;
  }
  if (g->adj[i1][i2] != 0 && g->adj[i2][i1] != 0) {
    g->adj[i1][i2] = 'e';
    g->adj[i2][i1] = 'e';
    return true;
  }

  return true;
}


// visualizzazione del grafo, elencando, in corrispondenza dell'etichetta di
// ciascun vertice, l'elenco delle etichette dei vertici ad esso adiacenti,
// ciascuno contraddistinto dal tipo di tratta di collegamento
// ('f' oppure 's' oppure 'e')

void graph::print (const Graph &g) {
  // DA IMPLEMENTARE
  for (int i = 0; i != g->size; i++) {
    string edges;
    for (int j = 0; j != g->size; j++) {
      char t = g->adj[i][j];
      if (t != 0) {
        edges += g->vertices[j] + " - " + t + ", ";
      }
    }
    cout << g->vertices[i] << ": " << edges << endl;
  }
  return;
}


// restituisce true se esiste un cammino qualunque tra i vertici indicati dai
// due parametri, false altrimenti.  si suggerisce un approccio ricorsivo e
// l'impiego di opportuni accorgimenti per evitare che il cammino passi piu'
// volte attraverso uno stesso vertice (nel grafo possono esistere cicli).
// la visualizzazione del cammino trovato non e' richiesta.

set<int> dfs(Graph g, int from, set<int> visited) {
  if (from == -1) throw "dfs fail";
  if (visited.count(from)) return visited;
  visited.insert(from);
  for (int i = 0; i != g->size; i++) {
    if (g->adj[from][i] != 0) {
      visited = dfs(g, i, visited);
    }
  }
  return visited;
}

bool graph::connected (const Graph &g, Vlabel l1, Vlabel l2) {
  // DA IMPLEMENTARE
  int i1 = lookup(g, l1);
  int i2 = lookup(g, l2);
  if (i1 == -1 || i2 == -1) throw "nodi non presenti";
  auto visited = dfs(g, i1, {});
  if (visited.count(i2))
    return true;
  else
    return false;
}


// immersione di un grafo entro un altro.  i due grafi da immergere sono
// denotati dai primi due parametri, mentre il terzo parametro indica il
// grafo di destinazione.  quest'ultimo viene creato vuoto dal chiamante,
// che lo passa alla funzione, la quale lo svuota se non risulta vuoto
// e poi lo riempie con il merge dei primi due grafi.
// l'operazione deve evitare la creazione di doppioni di vertici e/o archi.
// la funzione restituisce false se la capienza del grafo di destinazione
// risulta insufficiente, altrimenti restituisce true a immersione effettuata.

// void addEdge(Graph& g, string from, string to, char value) {
//     if (lookup(g, from) != -1) {

//     }
// }

void empty(Graph& g) {
  for (int i = 0; i < g->size; i++) {
      g->vertices[i] = "";
      for (int j=0; j<g->size; j++) {
          g->vertices[i][j] = 0;
      }
  }
  g->size = 0;
}


bool merge2(Graph& res, Graph g1) {
    for (int i = 0; i < g1->size; i++) {
        for (int j=0; j<g1->size; j++) {
            if (j!=0) {
                if(g1->size - 2 >= NMAX) {
                    return false;
                }
                addVertex(res, g1->vertices[i]);
                addVertex(res, g1->vertices[j]);
                addEdge(res, g1->vertices[i], g1->vertices[j], g1->adj[i][j]);
            }
        }
  }
  return true;
}


bool graph::merge (const Graph &g1, const Graph &g2, Graph &res) {
  // DA IMPLEMENTARE
  empty(res);
  bool ok = true;
  ok = merge2(res, g1);
  ok = merge2(res, g2);
  return ok;
}
