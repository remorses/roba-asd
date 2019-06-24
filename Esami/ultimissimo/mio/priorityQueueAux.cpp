////////////////////////////////////////////////////////////////////////
// Una possibile soluzione per la simulazione 
// dell'accettazione di pazienti al pronto soccorso
////////////////////////////////////////////////////////////////////////

// FILE DA MODIFICARE

#include "priorityQueue.h"

using namespace priorityQueue;

// Funzioni ausiliarie che non appartengono al TDD 

   // --> INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE

// Funzioni del TDD PriorityQ

   // --> MODIFICARE LE FUNZIONI DEL TDD

PriorityQ priorityQueue::createEmptyPQ() {
  return {5, NULL}; // segnaposto
}


bool priorityQueue::isEmpty(const PriorityQ& pq) {
  return true; // segnaposto
} 


void priorityQueue::insert(PriorityQ& pq, const Patient &p) {

}


bool priorityQueue::findMax(const PriorityQ& pq, Patient &res) {
  return true; // segnaposto
}


bool priorityQueue::deleteMax(PriorityQ& pq) {  
  return true; // segnaposto
}


// Funzioni presenti nell'header ma non definite nel TDD 


void prettyPrint(Patient p, int startAidTime, int endAidTime) {
   cout << "Il paziente " << p.name << " (" << p.age << " anni, registrato a t_reg=" << p.registrationTime << " con codice ";
   switch(p.triage) {
    case W : cout << "bianco";
             break;       
    case G : cout << "verde";
             break;
    case Y : cout << "giallo";
             break;
    case R : cout << "rosso";
             break;
    }
    cout << ") entra a t_in=" << startAidTime << " ed esce a t_out=" << endAidTime << endl;
}
 
// FUNZIONE DA IMPLEMENTARE
void printAidOrder(PriorityQ pq, int startTime) {}


PriorityQ readFromFile(string fileName, int& startTime){
  int n;
  string inputString;
  Patient p;
  char triage;
  PriorityQ pq = createEmptyPQ();
  ifstream ifs(fileName.c_str()); // apertura di uno stream associato ad un file, in lettura
   if (!ifs) 
    {
    cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\nLa priority queue restituita e' vuota\n"; 
    return pq;
    }  
  
  getline(ifs, inputString);
  stringstream s(inputString);
  if (!(s >> startTime)) 
    {
    cout << "\nErrore lettura istante in cui il medico inizia a medicare i pazienti\nLa priority queue restituita e' vuota\n"; 
    return pq;
    } 

  if (!(s >> n)) 
    {
    cout << "\nErrore lettura numero pazienti da medicare\nLa priority queue restituita e' vuota\n"; 
    return pq;
    } 

  for(int i=1; i<=n; ++i) {
    getline(ifs, inputString); 
    stringstream s(inputString); 
    s >> p.name; 
    s >> p.age; 
    s >> triage; 
    switch(triage) {
    case 'W' : p.triage = W;
               break;       
    case 'G' : p.triage = G;
               break;
    case 'Y' : p.triage = Y;
               break;
    case 'R' : p.triage = R;
               break;
    }
    s >> p.registrationTime;
    s >> p.requiredAidTime;
    insert(pq, p);
    }  
   return pq;
}

// Casi di Test

void testCreateEmpty() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test createEmptyPQ" << endl;
    if (pq.size == 0)
      cout << "passato" << endl;
    else
      cout << "fallito" << endl;
}

void testIsEmpty() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test isEmptyPQ" << endl;
    if ( isEmpty(pq) ) {
      // simulo l'inserimeto di un valore (senza usare insert() che potrebbe non esistere ancora)
      pq.size=1;
      pq.list=NULL;
      if ( !isEmpty(pq) ) 
        cout << "passato" << endl;
      else
        cout << "fallito" << endl;
    }
    else
      cout << "fallito" << endl;
}

void testInsert() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test insertPQ" << endl;
    
    // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=37; 
    p1.triage = W;
    p1.registrationTime=100;
    p1.requiredAidTime=50;
    insert(pq, p1);
    if (pq.size != 1) {cout << "fallito_1a" << endl; return;}
    if (((pq.list)->info).name != "rossi") {cout << "fallito_1b" << endl; return;}
    
    // creo P2
    Patient p2;
    p2.name="bianchi"; 
    p2.age=22;
    p2.triage = R; 
    p2.registrationTime=100;
    p2.requiredAidTime=50;
    insert(pq, p2);
    if (pq.size != 2 ) {cout << "fallito2" << endl; return;}
    if (((pq.list)->info).name != "bianchi") {cout << "fallito2" << endl; return;}
    
    // creo P3
    Patient p3;
    p3.name="neri"; 
    p3.age=16;
    p3.triage = R; 
    p3.registrationTime=100;
    p3.requiredAidTime=50;
    insert(pq, p3);
    if (pq.size != 3 ) {cout << "fallito3" << endl; return;}
    if (((pq.list)->info).name != "neri") {cout << "fallito3" << endl; return;}
    
    // creo P4
    Patient p4;
    p4.name="marrone"; 
    p4.age=16;
    p4.triage = R; 
    p4.registrationTime=110;
    p4.requiredAidTime=50;
    insert(pq, p4);
    if (pq.size != 4 ) {cout << "fallito4" << endl; return;}
    if (((pq.list)->info).name != "neri") {cout << "fallito4" << endl; return;}
    
    // creo P5
    Patient p5;
    p5.name="giallo"; 
    p5.age=8;
    p5.triage = R; 
    p5.registrationTime=110;
    p5.requiredAidTime=50;
    insert(pq, p5);
    if (pq.size != 5 ) {cout << "fallito5" << endl; return;}
    if (((pq.list)->info).name != "giallo") {cout << "fallito5" << endl; return;}
    
    // se arriva qui ha passato tutto i controlli prima
    cout << "passato" << endl;
    return;
}

void testFindMax() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test FindMax" << endl;
    
    // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=37; 
    p1.triage = W;
    p1.registrationTime=100;
    p1.requiredAidTime=50;
    insert(pq, p1);
    
    // creo P2
    Patient p2;
    p2.name="bianchi"; 
    p2.age=22;
    p2.triage = R; 
    p2.registrationTime=100;
    p2.requiredAidTime=50;
    insert(pq, p2);
    Patient res;
    if (findMax(pq, res)==false) {cout << "fallito1" << endl; return;}
    if (res.name != "bianchi") {cout << "fallito2" << endl; return;}
    
    // se arriva qui ha passato tutto i controlli prima
    cout << "passato" << endl;
    return;
}

void testDeleteMax() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test DeleteMax" << endl;
    
    // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=37; 
    p1.triage = W;
    p1.registrationTime=100;
    p1.requiredAidTime=50;
    insert(pq, p1);
    
    // creo P2
    Patient p2;
    p2.name="bianchi"; 
    p2.age=22;
    p2.triage = R; 
    p2.registrationTime=100;
    p2.requiredAidTime=50;
    insert(pq, p2);
    
    // creo P3
    Patient p3;
    p3.name="neri"; 
    p3.age=16;
    p3.triage = R; 
    p3.registrationTime=100;
    p3.requiredAidTime=50;
    insert(pq, p3);
    
    if (deleteMax(pq)==false) {cout << "fallito1" << endl; return;}
    Patient res;
    findMax(pq, res);
    if (res.name != "bianchi") {cout << "fallito2" << endl; return;}
    if (pq.size != 2 ) {cout << "fallito3" << endl; return;}
    
    // se arriva qui ha passato tutto i controlli prima
    cout << "passato" << endl;
    return;
}

void testPrint() {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "caso di test Stampa della coda" << endl;
    
     // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=37; 
    p1.triage = W;
    p1.registrationTime=100;
    p1.requiredAidTime=50;
    insert(pq, p1);
    
    // creo P2
    Patient p2;
    p2.name="bianchi"; 
    p2.age=22;
    p2.triage = R; 
    p2.registrationTime=100;
    p2.requiredAidTime=50;
    insert(pq, p2);
    
    // creo P3
    Patient p3;
    p3.name="neri"; 
    p3.age=16;
    p3.triage = R; 
    p3.registrationTime=100;
    p3.requiredAidTime=50;
    insert(pq, p3);
    
    cout << "il test e' passato se: " << endl;
    cout<<endl;
    printAidOrder(pq, 10);
    cout<<endl;
    cout << "e' uguale a: " << endl;
    cout<<endl;
    cout << "Il medico inizia a visitare all'istante 10" << endl;
    cout << "Il paziente neri (16 anni, registrato a t_reg=100 con codice rosso) entra a t_in=10 ed esce a t_out=60" << endl;
    cout << "Il paziente bianchi (22 anni, registrato a t_reg=100 con codice rosso) entra a t_in=61 ed esce a t_out=111" << endl;
    cout << "Il paziente rossi (37 anni, registrato a t_reg=100 con codice bianco) entra a t_in=112 ed esce a t_out=162" << endl;
}

void test1() {testCreateEmpty(); testIsEmpty(); testInsert(); return;}
void test2() {testFindMax(); testDeleteMax(); return;}
void test3() {testPrint(); return;}
