////////////////////////////////////////////////////////////////////////
// Alberi binari
////////////////////////////////////////////////////////////////////////

/*******************************************************************************************************/
// tree.cpp

#include <iostream>
#include <string>
#include "tree.h"

using namespace std;
using namespace tree;

// il nodo di un albero e' caratterizzato dall'etichetta (il nome), 
// il puntatore al figlio sinistro e il puntatore al figlio destro

// --- INSERIRE QUI LA struct Nodo ---


/*******************************************************************************************************/
// funzioni ausiliarie
/*******************************************************************************************************/

// --- INSERIRE QUI LE EVENTUALI FUNZIONI AUSILIARIE ---

/*******************************************************************************************************/
// funzioni relative all'albero binario
/*******************************************************************************************************/

// Costruisce l'albero vuoto
Tree tree::creaAlberoVuoto() {
   return NULL;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
bool tree::vuoto(const Tree& t) { 
   return true;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Aggiunge il nodo radice, fallisce se l'albero e' non vuoto
bool tree::inserisciRadice(const Label l, Tree& t) {
  return true;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Aggiunge nuovo nodo sinistro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_sx" e' gia' presente nell'albero
bool tree::inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t) {
  return true;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Aggiunge nuovo nodo destro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero se la label "nome_figlio_dx" e' gia' presente nell'albero
bool tree::inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t) {
  return true;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Stampa l'albero usando lo stesso formato di input. Se l'albero e' vuoto stampa "Albero vuoto"
void tree::print(const Tree& t) {
  cout << "Albero vuoto" << endl;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Ritorna il numero di terminali isolati. Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cioè il genitore della foglia non ha altri figli)
int tree::contaNumeroTerminaliIsolati(const Tree& t) {
  return 0;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
}

// Data una label, stampa il cammino dal nodo con quella label fino ad arrivare alla radice. Altrimenti stampa che non esiste
void tree::stampaCammino(Label l, const Tree& t) {
  cout << "Non esiste cammino" << endl;   // --- MODIFICARE IL CORPO DELLA FUNZIONE ---
 
}
