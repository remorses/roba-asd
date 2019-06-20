#include "graph.h"
#include <iostream>
#include <vector>

using namespace graph;
using namespace std;


// il tipo Graph e' stato definito come puntatore al seguente struct,
// che contiene gli ingredienti che formano il grafo.

struct graph::graph_ingredients {

    unsigned int size = 0;        // numero attuale di vertici, inizialmente zero
    Label vertices[NMAX];         // tabella etichette, dimensione massima
    int adj[NMAX][NMAX];            // matrice di adiacenza

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
    for (int i = 0; i<g->size; i++) {
        if (g->vertices[i] == l) {
            return i;
        }
    }
    return -1;
}


// creazione di un grafo vuoto con un numero massimo prefissato di possibili
// vertici; il numero massimo e' indicato dalla costante NMAX.

Graph graph::createEmpty() {
    // DA IMPLEMENTARE; questa qui sotto serve solo come segnaposto ma non funziona
    Graph g = new graph::graph_ingredients;
    g->size = 0;
    return g;
};


// inserimento di un vertice la cui etichetta e' passata come parametro.
// restituisce false se l'etichetta e' gia' presente nel grafo, e in tal caso
// nessun nuovo vertice deve essere inserito; altrimenti restituisce true
// ad inserimento avvenuto.

bool graph::addVertex(Graph &g, Label l) {
    // DA IMPLEMENTARE
    if(lookup(g, l) != -1) return false;
    g->vertices[g->size] = l;
    g->size += 1;
    return true;
}


// inserimento di un arco non orientato tra due vertici esistenti e distinti.
// restituisce false se i due vertici sono gia' collegati da un arco,
// oppure se uno dei due vertici non e' presente nel grafo, oppure se
// i due vertici coincidono; in tali casi nessun nuovo arco deve essere
// inserito.    altrimenti restituisce true ad inserimento avvenuto.

bool graph::addEdge(Graph &g, Label l1, Label l2) {
    // DA IMPLEMENTARE
    int i1 = lookup(g, l1), i2 = lookup(g, l2);

    if(i1 == -1 || i2 == -1 || i1 == i2) {
        return false;
    }
    if (g->adj[i1][i2] != 0 || g->adj[i2][i1] != 0) {
        return false;
    }
    g->adj[i1][i2] = 1;
    g->adj[i2][i1] = 1;
    return true;
}

// qui

// visualizzazione del grafo, elencando, in corrispondenza dell'etichetta di
// ciascun vertice, l'elenco delle etichette dei vertici ad esso adiacenti.

void graph::print(const Graph &g) {
    // DA IMPLEMENTARE
    for(int i = 0; i < g->size; i++) {
	cout << g->vertices[i] << ": ";
	for (int j=0; j < g->size; j++) {
		int value = g->adj[i][j];
		if (value!=0) cout << g->vertices[j] << ", ";
	}
	cout << endl;
    }
    return;
}

// conteggio degli amici diretti.
// si tratta in pratica di calcolare il grado di un vertice
// identificato dalla sua etichetta, e restituirlo come risultato.
// se il vertice non e' presente nel grafo, la funzione restituisce -1.



int graph::numFriendsDirect(const Graph &g, Label l) {
    // DA IMPLEMENTARE
    int count = 0;
    int index = lookup(g, l);
    if (index == -1) return 0;
    for (int i=0; i < g->size; i++) {
	if (g->adj[index][i] != 0) {
		count += 1;
	}
    }
    return count;
}

// conteggio dei vertici entro la distanza specificata dal parametro.
// la funzione dovrebbe evitare di contare uno stesso vertice per due o piu'
// volte ed evitare di contare il vertice di partenza.
// se il vertice di partenza non e' presente nel grafo, la funzione
// restituisce -1.

bool contains(vector<int> v, int i) {
	for (int a : v) {
		if (a==i) return true;
	}
	return false;
}

int aux(Graph g, int index, unsigned int distance, int count, vector<int> &visited) {
	if (distance > 0) {
		if(contains(visited, index)) return count - 1;
		visited.push_back(index);
		for (int i=0; i < g->size; i++) {
			if (g->adj[index][i] != 0 && !contains(visited, i)) {
				count = aux(g, i, distance - 1, count + 1, visited);
			}
		}
		return count;
	} else {
		return count;
	}
}

int graph::numFriendsAtDistance(const Graph &g, Label l, unsigned int distance) {
    // DA IMPLEMENTARE
    
    int index = lookup(g, l);
    if (index == -1) return -1;
    vector<int> visited;
    return aux(g, index, distance, 0, visited);
}
