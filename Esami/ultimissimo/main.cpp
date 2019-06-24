////////////////////////////////////////////////////////////////////////
// MAIN del software per la simulazione 
// dell'accettazione di pazienti al pronto soccorso
////////////////////////////////////////////////////////////////////////

// NON MODIFICARE QUESTO FILE!

#include "priorityQueue.h"

using namespace priorityQueue;

void testMainCreateEmpty(double &totale) {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "--> caso di test createEmptyPQ" << endl;
    if ((pq.size == 0) and (pq.list==NULL)) { 
      totale = totale + 1;
      cout << "passato" << endl;
    }
    else
      cout << "fallito" << endl;
}

void testMainIsEmpty(double &totale) {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "--> caso di test isEmptyPQ" << endl;
    if ( isEmpty(pq) ) {
      // simulo l'inserimeto di un valore (senza usare insert() che potrebbe non esistere ancora)
      pq.size=1;
      pq.list=NULL;
      if ( !isEmpty(pq) ) 
        {cout << "passato" << endl; totale = totale + 1;}
      else
        cout << "fallito" << endl;
    }
    else
      cout << "fallito" << endl;
}

void testMainInsert(double &totale) {
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
    cout << "--> caso di test insertPQ" << endl;
    
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
    p2.age=37;
    p2.triage = W; 
    p2.registrationTime=110;
    p2.requiredAidTime=50;
    insert(pq, p2);
    if (pq.size != 2 ) {cout << "fallito2" << endl; return;}
    if (((pq.list)->info).name != "rossi") {cout << "fallito2" << endl; return;}
    
    // creo P3
    Patient p3;
    p3.name="neri"; 
    p3.age=24;
    p3.triage = W; 
    p3.registrationTime=120;
    p3.requiredAidTime=50;
    insert(pq, p3);
    if (pq.size != 3 ) {cout << "fallito3" << endl; return;}
    if (((pq.list)->info).name != "neri") {cout << "fallito3" << endl; return;}
    
    // creo P4
    Patient p4;
    p4.name="marrone"; 
    p4.age=16;
    p4.triage = G; 
    p4.registrationTime=130;
    p4.requiredAidTime=50;
    insert(pq, p4);
    if (pq.size != 4 ) {cout << "fallito4" << endl; return;}
    if (((pq.list)->info).name != "marrone") {cout << "fallito4" << endl; return;}
    
    // creo P5
    Patient p5;
    p5.name="giallo"; 
    p5.age=8;
    p5.triage = Y; 
    p5.registrationTime=140;
    p5.requiredAidTime=50;
    insert(pq, p5);
    if (pq.size != 5 ) {cout << "fallito5" << endl; return;}
    if (((pq.list)->info).name != "giallo") {cout << "fallito5" << endl; return;}
    
    // creo P6
    Patient p6;
    p6.name="rosso"; 
    p6.age=8;
    p6.triage = R; 
    p6.registrationTime=150;
    p6.requiredAidTime=50;
    insert(pq, p6);
    if (pq.size != 6 ) {cout << "fallito6a" << endl; return;}
    if (((pq.list)->info).name != "rosso") {cout << "fallito6b" << endl; return;}
    
    // creo P7
    Patient p7;
    p7.name="gino"; 
    p7.age=8;
    p7.triage = R; 
    p7.registrationTime=160;
    p7.requiredAidTime=50;
    insert(pq, p7);
    if (pq.size != 7 ) {cout << "fallito7a" << endl; return;}
    if (((pq.list)->info).name != "rosso") {cout << "fallito7b" << endl; return;}
    
    // se arriva qui ha passato tutto i controlli prima
    cout << "passato" << endl;
    totale = totale + 5;
    return;
}

void testDeleteMax_void(double &totale) {
   PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
   if (deleteMax(pq)) {cout << "fallito DeleteMax vuoto" << endl; return;}
   cout << "passato DeleteMax vuoto" << endl;
   totale = totale + 0.5;
}

void testDeleteMax_full(double &totale) {
   PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
   
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
    p2.registrationTime=110;
    p2.requiredAidTime=50;
    insert(pq, p2);
    
    if (deleteMax(pq)==false) {cout << "fallito DeleteMax piena" << endl; return;}
    if (pq.size != 1 ) {cout << "fallito DeleteMax piena" << endl; return;}
    
   cout << "passato DeleteMax piena" << endl;
   totale = totale + 1;
}

void testDeleteMax(double &totale) {
    cout << "--> caso di test deleteMax" << endl;
    testDeleteMax_void(totale);
    testDeleteMax_full(totale);
}

void testFindMax_void(double &totale) {
   PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
   Patient res;
   if (findMax(pq, res)) {cout << "fallito DeleteMax vuoto" << endl; return;}
   cout << "passato FindMax vuoto" << endl;
   totale = totale + 0.5;
}

void testFindMax_full(double &totale) {
   PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
   
   // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=22; 
    p1.triage = R;
    p1.registrationTime=90;
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
    if (findMax(pq, res)==false) {cout << "fallito FindMax piena" << endl; return;}
    if (pq.size != 2 ) {cout << "fallito FindMax piena" << endl; return;}
    if (res.name != "rossi") {cout << "fallito2" << endl; return;}
    
   cout << "passato DeleteMax piena" << endl;
   totale = totale + 1;
}

void testFindMax(double &totale) {
    cout << "--> caso di test FindMax" << endl;
    testFindMax_void(totale);
    testFindMax_full(totale);
}

void testPrint(double &totale) {
    int val;
    std::ostringstream buffer;
    PriorityQ pq = createEmptyPQ(); // creo priorityQ vuota
   
   // creo P1
    Patient p1;
    p1.name="rossi"; 
    p1.age=22; 
    p1.triage = R;
    p1.registrationTime=90;
    p1.requiredAidTime=50;
    insert(pq, p1);
    
    // creo P2
    Patient p2;
    p2.name="bianchi"; 
    p2.age=5;
    p2.triage = R; 
    p2.registrationTime=100;
    p2.requiredAidTime=65;
    insert(pq, p2);
    
     // creo P3
    Patient p3;
    p3.name="neri"; 
    p3.age=16;
    p3.triage = R; 
    p3.registrationTime=110;
    p3.requiredAidTime=50;
    insert(pq, p3);
    cout << "Se le stampe sono uguali: " << endl;
    cout << "---------------------------" << endl;
    printAidOrder(pq, 10);
    cout << "---------------------------" << endl;
    cout << "Il medico inizia a visitare all'istante 10" << endl;
    cout << "Il paziente bianchi (5 anni, registrato a t_reg=100 con codice rosso) entra a t_in=10 ed esce a t_out=75" << endl;
    cout << "Il paziente neri (16 anni, registrato a t_reg=110 con codice rosso) entra a t_in=76 ed esce a t_out=126" << endl;
    cout << "Il paziente rossi (22 anni, registrato a t_reg=90 con codice rosso) entra a t_in=127 ed esce a t_out=177" << endl;
    cout << "---------------------------" << endl;
    cout << "inserisci 1 se il test e' passato, 0 altrimenti)" << endl;
    cin >> val;
     
    if (val == 1) totale = totale + 4;
}


int main() {
  
  double totale=0;
  int startTime = 0, option = 0;
  string fileName;
  PriorityQ pq;
  cout << "---------------------------" << endl;
  cout << "Pazienti in pronto soccorso" << endl;
  cout << "---------------------------" << endl;
  
  while (option != 5) {
   cout << "\n --> Cosa si vuole fare?\n0 = comportamento normale del programma;\n1 = test di createEmptyPQ, isEmpty, insert;\n2 = test di findMax e deleteMax;\n3 = test della stampa;\n4 = valuta labo \n5 = terminare\n> ";
   cin >> option; 
   switch(option) {
    case 0 : cout << "Inserire il nome del file da cui leggere i dati\n";  
             cin >> fileName;
             pq = readFromFile(fileName, startTime);  
             printAidOrder(pq, startTime); 
             break;       
    case 1 : test1();
             break;
    case 2 : test2();
             break;
    case 3 : test3();
             break;
    case 4 : cout << "---------------------------" << endl;
             testMainCreateEmpty(totale);
             testMainIsEmpty(totale);
             testMainInsert(totale);
             testDeleteMax(totale);
             testFindMax(totale);
             testPrint(totale);
             cout << "il voto dello studente e': " << totale << endl;
             cout << "---------------------------" << endl;
             break;         
    case 5 : cout << "\nArrivederci\n";
             break;
     }
  }
  return 0;
}

