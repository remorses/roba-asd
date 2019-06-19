// FILE DA MODIFICARE
// E' possibile aggiungere funzioni ausiliarie e modificare le funzioni fornite e le struct (se occorre)

#include "graph.h"
#include <regex>
#include <iostream>
using namespace graph;
using namespace std;

/*******************************************************************************************************/
// Struct
/*******************************************************************************************************/

// Mezzo arco, non memorizza il nodo sorgente
struct halfEdgeNode {
  Label label;
  halfEdgeNode* next; // puntatore al mezzo arco successivo
};

// Un nodo e' caratterizzato dall'etichetta, il puntatore alla lista dei nodi adiacenti, il puntatore al prossimo nodo 
struct graph::vertexNode {
    Label label;    
    halfEdgeNode *adjList;
    vertexNode *next;
};


/*********************************/
// Funzioni ausiliarie
/*********************************/

// METTERE QUI EVENTUALI FUNZIONI AUSILIARIE GENERICHE

/*********************************/
// Funzioni ausiliarie del Grafo
/*********************************/

// Ritorna il puntatore al nodo avente label "l" (se esiste)
vertexNode* getVertex(Label l, const Graph& g) {
  for (graph::Graph v = g; v != nullptr; v = v->next) {
   if (v->label == l) return  v; // trovato, esco
  }
  return NULL; // non trovato
}

// Ritorna true se il nodo e' presente nel grafo
bool isVertexInGraph(Label l, const Graph& g) {
  return (getVertex(l, g)!=NULL);
}

// Ritorna true se l'arco e' presente nel grafo
bool isEdgeInGraph(Label from, Label to, const Graph& g) {
 vertexNode* vNode = getVertex(from, g);
 if (vNode == NULL) return false;
 for (halfEdgeNode* n = vNode->adjList; n != NULL; n = n->next) {
    if (n->label == to ) return true;
  }
 return false;
}

// Aggiunge il "mezzo edge" alla lista di adiacenza
// Da usare solo se i vertici "from" e "to" sono presenti nel grafo
void addHalfEdge(Label from, Label to, Graph& g) {
  halfEdgeNode *e = new halfEdgeNode;
  e->label = to;
  vertexNode* vNode = getVertex(from, g);

  if (vNode->adjList == NULL) {
    vNode->adjList = e;
    e->next = NULL;
  } else {
    e->next = vNode->adjList;
    vNode->adjList = e;
  }
}

// Stampa la lista di adiacenza
void printAdjList(Label l, const Graph& g) {
 vertexNode* vNode = getVertex(l, g);
 if (vNode==NULL) return;
 for (halfEdgeNode* n = vNode->adjList; n != NULL; n = n->next) {
    cout << n->label << ", ";
  }
 cout << endl; 
}

// METTERE QUI EVENTUALI FUNZIONI AUSILIARIE DEL GRAFO

void print(vector<string> v) {
    cout << "printing" << endl;
    for (auto x : v) {
        cout << x << ",\n";
    }
    cout << endl;
}

vector<string> allVertexes(const Graph g) {
    vector<string> result;
    for (auto n = g; n != nullptr; n = n->next) {
        result.push_back(n->label);
    }
    return result;
}

void print(string x) {
    cout << x << endl;
}

bool contains(vector<string> v, string elem) {
    for (auto x : v) {
        if (x == elem) {
            return true;
        }
    }
    return false;
}

vector<string> dfs(const Graph g, Graph node, vector<string> visited) {
    if (node == nullptr) {
        return visited;
    }
    if(!contains(visited, node->label)) {
        visited.push_back(node->label);
        
        for(auto edge = node->adjList; edge != nullptr; edge = edge->next) {
            auto next = getVertex(string(edge->label), g);
            // print(allVertexes(g));
            // print(next->label);
            if(!contains(visited, next->label)) {
                visited = dfs(g, next, visited);
            }
        }
    }
    return visited;
}

/*******************************************************************************************************/
// Grafo
/*******************************************************************************************************/

// Restituisce il grafo vuoto
Graph graph::createEmptyGraph()
{
  return emptyGraph;
}

// Aggiunge nuovo nodo con etichetta la stringa. Fallisce se gia' presente
bool graph::addVertex(Label l, Graph& g) {
  if (isVertexInGraph(l, g))
    return false;  // etichetta gia' presente
  // aggiungi nuovo vertice (in testa per comodita')
  Graph v = new vertexNode;
  v->label = l;
  v->adjList = NULL;
  if (isEmpty(g)) {
    g = v;
    v->next = NULL;
  } else {
    v->next = g;
    g = v;
  }
  return true;
}

// Aggiunge un arco tra i nodi con etichetta "from" e "to"
bool graph::addEdge(Label from, Label to, Graph& g) {
  // entrambi i nodi devono gia' esistere nel grafo
  if (!isVertexInGraph(from, g) || !isVertexInGraph(to, g))
    return false;
  // tra i due nodi non deve gia' esserci un arco
  if (isEdgeInGraph(from,to,g) || isEdgeInGraph(to,from,g))
    return false;
  // aggiungo i 'mezzi edge'
  addHalfEdge(from, to, g);
  if (from != to) addHalfEdge(to, from, g);
  return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){ 
   return (g==emptyGraph);
}

// Verifica che tutti i nodi del grafo siano formati da una lettera MAIUSCOLA (semplificazione di un elemento chimico) seguito da un numero intero maggiore di zero 
// Ritorna true in caso affermativo, false altrimenti 
bool graph::areAllNodeNamesWellFormed(const Graph& g) {
    // COMPLETARE
    
    for (vertexNode* node = g; node!= NULL; node = node->next) {
        smatch m;
        regex rx("[A-Z][1-9]\\d*");
        if (!regex_match(node->label, m, rx)) {
            return false;
        }
    }
    
    return true;   // segnaposto
}


// Verifica che il grafo e' connesso
bool graph::connected(const Graph& g) {
    // COMPLETARE
    vector<string> visited = dfs(g, g, {});
    
    auto all = allVertexes(g);
    // print(all);
    // print(visited);
    if (visited.size() < all.size())
        return false;
    // print(x);
    return true;    // segnaposto
}

// Verifica che non esistono cappi (cappio = arco che parte e arriva sullo stesso nodo)
bool graph::noLoops(const Graph& g) {
    for (auto n = g; n != nullptr; n = n->next) {
        auto edges = n->adjList;
        for(auto e = edges; e != nullptr; e = e->next) {
            if (e->label == n->label) return false;
        }
    }
    return true;    // segnaposto
}

string getRegexGroup(string s, string pattern);

// Calcola il numero di atomi di un dato elemento 'c' preso in input
int graph::computeAtomNumber(char c, const Graph& g) {
    // COMPLETARE
    int count = 0;
    for (auto n = g; n != nullptr; n = n->next) {
        if (n->label[0] == c) count += 1;
    }
    return count;    // segnaposto
}

/*******************************************************************************************************/
// Stampa il grafo
void printGraph(const graph::Graph& g) {
  for (graph::Graph v = g; v != NULL; v = v->next) {
    cout << v->label << ": ";
    printAdjList(v->label, g);
  }
}

