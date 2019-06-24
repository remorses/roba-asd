////////////////////////////////////////////////////////////////////////
// MAIN del software per la simulazione 
// dell'accettazione di pazienti al pronto soccorso
////////////////////////////////////////////////////////////////////////

// NON MODIFICARE QUESTO FILE!

#include "priorityQueue.h"

using namespace priorityQueue;

int main() {

  int startTime = 0, option = 0;
  string fileName;
  PriorityQ pq;
  cout << "---------------------------" << endl;
  cout << "Pazienti in pronto soccorso" << endl;
  cout << "---------------------------" << endl;
  
  while (option != 4) {
   cout << "\n --> Cosa si vuole fare?\n0 = comportamento normale del programma;\n1 = test di createEmptyPQ, isEmpty, insert;\n2 = test di findMax e deleteMax;\n3 = test della stampa;\n4 = terminare\n> ";
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
    case 4 : cout << "\nArrivederci\n";
             break;
     }
  }
  return 0;
}

