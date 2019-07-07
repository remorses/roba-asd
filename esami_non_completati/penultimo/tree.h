////////////////////////////////////////////////////////////////////////
// Alberi binari
////////////////////////////////////////////////////////////////////////

/*******************************************************************************************************/
// tree.h

// --- NON MODIFICARE QUESTO FILE ---

using namespace std;

namespace tree {

typedef string Label;   

struct Nodo; // definita nel file tree.cpp

typedef Nodo* Tree; // un albero e' identificato dal puntatore alla sua radice

const Tree alberoVuoto = NULL; 

// Costruisce albero vuoto
Tree creaAlberoVuoto();

// Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
bool vuoto(const Tree& t);

// Aggiunge nodo radice, fallisce se l'albero e' non vuoto
bool inserisciRadice(const Label l, Tree& t); 

// Aggiunge nuovo nodo sinistro di un nodo esistente. Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_sx" e' gia' presente nell'albero
bool inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t);

// Aggiunge nuovo nodo destro di un nodo esistente. Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_dx" e' gia' presente nell'albero
bool inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t);
    
// Stampa l'albero usando lo stesso formato di input. Se l'albero e' vuoto stampa "Albero vuoto"
void print(const Tree& t);

// Ritorna il numero di terminali isolati. Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cioè il genitore della foglia non ha altri figli)
int contaNumeroTerminaliIsolati(const Tree& t);

// Data una label, stampa il cammino dal nodo con quella label fino ad arrivare alla radice. Altrimenti stampa che non esiste
void stampaCammino(Label labek, const Tree& t);
}

