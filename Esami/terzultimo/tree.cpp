////////////////////////////////////////////////////////////////////////
// Alberi binari
////////////////////////////////////////////////////////////////////////

/*******************************************************************************************************/
// tree.cpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "tree.h"

using namespace std;
using namespace tree;

// il nodo di un albero e' caratterizzato dall'etichetta (il nome), 
// il puntatore al figlio sinistro e il puntatore al figlio destro

// --- INSERIRE QUI LA struct Nodo ---

struct tree::Nodo {
        string label;
        Tree dx;
        Tree sx;
};
/*******************************************************************************************************/
// funzioni ausiliarie
/*******************************************************************************************************/

// --- INSERIRE QUI LE EVENTUALI FUNZIONI AUSILIARIE ---

/*******************************************************************************************************/
// funzioni relative all'albero binario
/*******************************************************************************************************/

// Costruisce l'albero vuoto
Tree tree::creaAlberoVuoto() {
    return NULL;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
bool tree::vuoto(const Tree& t) { 
    if (!t) return true;
    return false;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Aggiunge il nodo radice, fallisce se l'albero e' non vuoto
bool tree::inserisciRadice(const Label l, Tree& t) {
    if (t) return false;
    t = new Nodo {l, nullptr, nullptr};
    return true;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}


// Aggiunge nuovo nodo sinistro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_sx" e' gia' presente nell'albero
bool tree::inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t) {
   Tree padre;
    queue<Tree> q;
    q.push(t);
    while(!q.empty()) {
        Tree aux = q.front();
        q.pop();
        if (aux->label == questo) {
            padre = aux;
        }
        if (aux->label == nome_figlio_sx) {
            return false;
        }
        if (aux->sx) q.push(aux->sx);
        if (aux->dx) q.push(aux->dx);
    }
    if (!padre) return false;
    Tree sx;
    Tree dx;
    if (padre->sx) {
        sx = padre->sx->sx; 
        dx = padre->sx->dx; 
    } else {
        sx = nullptr; 
        dx = nullptr; 
    }
    padre->sx = new Nodo {nome_figlio_sx, sx, dx};
    return true;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Aggiunge nuovo nodo destro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero se la label "nome_figlio_dx" e' gia' presente nell'albero
bool tree::inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t) {
   Tree padre;
    queue<Tree> q;
    q.push(t);
    while(!q.empty()) {
        Tree aux = q.front();
        q.pop();
        if (aux->label == questo) {
            padre = aux;
        }
        if (aux->label == nome_figlio_dx) {
            return false;
        }
        if (aux->sx) q.push(aux->sx);
        if (aux->dx) q.push(aux->dx);
    }
    if (!padre) return false;
    Tree sx;
    Tree dx;
    if (padre->dx) {
        sx = padre->sx->sx; 
        dx = padre->sx->dx; 
    } else {
        sx = nullptr; 
        dx = nullptr; 
    }
    padre->dx = new Nodo {nome_figlio_dx, sx, dx};
    return true;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Stampa l'albero usando lo stesso formato di input. Se l'albero e' vuoto stampa "Albero vuoto"
void tree::print(const Tree& t) {
    if (!t) {cout << "Albero vuoto" << endl; return;}    // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
    queue<Tree> q;
    q.push(t);
    Tree previous = t;
    while(!q.empty()) {
        Tree aux = q.front();
        q.pop();
        if (aux->sx) cout << "S " << aux->label << " " << aux->sx->label << endl;
        if (aux->dx) cout << "D " << aux->label << " " << aux->dx->label << endl;
        if (aux->sx) q.push(aux->sx);
        if (aux->dx) q.push(aux->dx);
        previous = aux;
    }
    cout << 0 << endl;
}

// Ritorna il numero di terminali isolati. Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cio� il genitore della foglia non ha altri figli)
int tree::contaNumeroTerminaliIsolati(const Tree& t) {
    if (!t) return 0;
    int count = 0;
    queue<Tree> q;
    q.push(t);
    while(!q.empty()) {
        Tree aux = q.front();
        q.pop();
        if (aux->sx && !aux->dx) count += 1;
        if (aux->dx && !aux->sx) count += 1;
        if (aux->sx) q.push(aux->sx);
        if (aux->dx) q.push(aux->dx);
    }
    return count;
}

Tree find(const Tree& t, string target, Tree& previous) {
    stack<Tree> q;
    q.push(t);
    previous = t;
    while(!q.empty()) {
        Tree aux = q.top();
        q.pop();
        if (aux->sx && aux->sx->label == target){
            q.push(aux->sx);
            previous = aux;
            return aux->sx;
        } 
        if (aux->dx && aux->dx->label == target){
            q.push(aux->dx);
            previous = aux;
            return aux->dx;
        }
        if(aux->sx) q.push(aux->sx);
        if(aux->dx) q.push(aux->dx);
    }
    return nullptr;
}

// Data una label, stampa il cammino dal nodo con quella label fino ad arrivare alla radice. Altrimenti stampa che non esiste
void tree::stampaCammino(Label l, const Tree& t) {
    if (!t) return;
    Tree previous;
    Tree found = find(t, l, previous);
    if (!found) cout << "Non esiste cammino" << endl;     // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
    cout << found->label << ", ";
    while (previous->label!=t->label) {
        cout << previous->label << ", ";
        find(t, previous->label, previous);
    }
    cout << t->label << endl;
}
