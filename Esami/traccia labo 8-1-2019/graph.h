// FILE DA NON MODIFICARE

#include <iostream>
#include <sstream>
#include <string>         
#include <cstdlib> // serve per poter utilizzare la funzione di libreria atoi() che converte una c-stringa in int

using namespace std; 

namespace graph {

typedef string Label;

struct vertexNode; // definita nel file graph.cpp

typedef vertexNode* Graph; // un grafo e' identificato dal puntatore al primo nodo inserito

const Graph emptyGraph = NULL; 

// createEmptyGraph restituisce il grafo vuoto 
Graph createEmptyGraph();

// Aggiunge nuovo nodo con etichetta la stringa. Fallisce se il nodo e' gia' presente
bool addVertex(Label, Graph&);

// Aggiunge nuovo arco tra i due nodi con etichette le due stringhe . 
// Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente.
bool addEdge(Label, Label, Graph&);

// Restituisce true se il grafo e' vuoto, false altrimenti
bool isEmpty(const Graph&);

// Verifica che tutti i nodi del grafo siano formati da una lettera MAIUSCOLA (semplificazione di un elemento chimico) seguito da un numero intero maggiore di zero
// Ritorna true in caso affermativo, false altrimenti
bool areAllNodeNamesWellFormed(const Graph&);

// Verifica che il grafo e' connesso
bool connected(const Graph&);

// Verifica che non esistono cappi (cappio = arco che parte e arriva sullo stesso nodo)
bool noLoops(const Graph&);

// Calcola il numero di atomi di un dato elemento (es. H) preso in input
int computeAtomNumber(char, const Graph&);
}

// Funzioni che non caratterizzano il TDD Graph, ma che servono per input/output 
void printGraph(const graph::Graph&);





