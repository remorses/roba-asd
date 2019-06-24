// NON MODIFICARE QUESTO FILE!

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

/*******************************************************************************/
/*          Coda con priorita' implementata come lista ordinata                */
/*******************************************************************************/

namespace priorityQueue{

// Il codice assegnato con il triage puo' essere white (W), green (G), yellow (Y), red (R)
enum code {W, G, Y, R}; // per come sono stati definiti, W < G < Y < R

// Ciascun paziente e' descritto da una serie di informazioni: codice assegnato con il triage, ora di accettazione, 
// tempo necessario a prestargli il servizio, cognome ed eta'
struct Patient {
  string name;
  int age; 
  code triage;     
  int registrationTime;  // istante in cui il paziente viene registrato al pronto soccorso
  int requiredAidTime;   // quantita' di tempo necessaria a prestare il soccorso al paziente 
};

// un nodo e' costituito da un paziente e da un puntatore al nodo successivo
struct Node {   
    Patient info;
    Node *next;
};

typedef Node* List;

// la coppia: size e lista di nodi
struct Couple {   
    int size; 
    List list;
};

// una coda con priorita' realizzata come coppia: 'size' e 'lista di pazienti'
typedef Couple PriorityQ; 

const PriorityQ EMPTYPriorityQ = {0, NULL}; // la size della coda e' zero

// operazioni standard del TDD PriorityQ
PriorityQ createEmptyPQ();                // 1 punto       
bool isEmpty(const PriorityQ&);           // 1
void insert(PriorityQ&, const Patient&);  // 5
bool deleteMax(PriorityQ&);               // 1.5
bool findMax(const PriorityQ&, Patient&); // 1.5
} // fine namespace

void printAidOrder(priorityQueue::PriorityQ, int startTime);  // 4 punti
priorityQueue::PriorityQ readFromFile(string fileName, int& startTime);
void test1();
void test2();
void test3();
