// FILE DA NON MODIFICARE

#include <cstdlib>
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

// Visualizza menu' con le scelte possibili e chiede
// all'utente di immetterne una. 
// Continua a ripresentare il menu' finche' l'utente non
// immette una scelta valida. Ritorna la scelta fatta.
int visualizzaMenu() 
{
  int scelta = -1;
  while ((scelta<0)||(scelta>4))
  { 
    cout << "--------------------------------------------------------------------------\n";
    cout << "                                  MENU                                    \n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "1. Inserimento del grafo molecolare da tastiera\n";
    cout << "2. Visualizzazione del grafo\n";
    cout << "3. Verifica nome dei nodi\n";
    cout << "4. Verifica che il grafo e' connesso\n";
    cout << "5. Verifica che non esistono cappi\n";
    cout << "6. Calcolo del numero di atomi di un elemento chimico\n";
    cout << "7. Test verifica nome dei nodi\n";
    cout << "8. Test connessione\n";
    cout << "9. Test esistenza cappi\n";
    cout << "10. Test calcolo del numero di atomi\n";
    cout << "0. Uscita\n";
    cout << "\nFornisci la tua scelta ---> ";
    cin >> scelta;
    cout << "--------------------------------------------------------------------------\n";
    if (!cin) {cout << "Hai inserito una stringa al posto di un numero\n"; return 0;}
    if ((scelta>=0)&&(scelta<=10)) return scelta;
      cout << "\nScelta non valida\n";
  }
  return -1;
}


int main() {
  graph::Graph g = graph::createEmptyGraph();  
  char elemento;
  string nodo;
  int scelta = 0;

  // Visualizzazione menu e acquisizione scelta
  scelta = visualizzaMenu();

  // Ciclo su scelta,
  // si interrompe quando l'utente sceglie di uscire (scelta==0)
  while (scelta) {

    graph::Label s1,s2;

    switch (scelta)
    {
      // Lettura del grafo molecolare
      case 1: 
        g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
        cout << "\nInserisci gli archi del grafo molecolare: origine destinazione [invio] (0 per terminare)\n";
        for(;;) {
          cin >> s1;
          if (s1 == "0") break;
          cin >> s2;
          if (s2 == "0") break;
          graph::addVertex(s1, g);
          graph::addVertex(s2, g);
          graph::addEdge(s1, s2, g);
        }
      break;

      // Visualizzazione del grafo  
      case 2: 
        cout << "\n\nGrafo:\n";
        printGraph(g);
      break;
      
      // Verifica che tutti i nodi del grafo siano formati da una lettera MAIUSCOLA (elemento chimico) seguito da un numero  
      case 3: 
        cout << "Verifica nomi dei nodi\n";
        if(areAllNodeNamesWellFormed(g)) 
            cout << "Tutti i nodi sono OK\n";
        else
            cout << "Esiste almeno un nodo che non e' OK\n";
      break;
      
      // Verifica che il grafo e' connesso
      case 4: 
        cout << "Verifica che il grafo e' connesso\n";
        if(connected(g)) 
            cout << "Il grafo e' connesso\n";
        else
            cout << "Il grafo NON e' connesso\n";
      break;
      
       // Verifica che non esistono capppi
      case 5: 
        cout << " Verifica che non esistono cappi\n";
        if(noLoops(g)) 
            cout << "Il grafo non contiene cappi\n";
        else
            cout << "Il grafo contiene almeno un cappio\n";
      break;
      
      // Calcolo del numero di atomi di un elemento chimico
      case 6: 
        cout << "Inserisci l'elemento chimico (ad esempio H): \n";
        cin >> elemento;
        cout << "il numero di atomi dell'elemento " << elemento << " e' " << computeAtomNumber(elemento, g) << endl;
      break;
      
      // Test verifica nome dei nodi
       case 7: 
        cout << "*** Test verifica nome dei nodi\n";
        cout << "* Il seguente grafo molecolare e' stato inserito\n";
        cout << "H2 C2\n";
        cout << "C2 C1\n";
        cout << "C2 H4\n";
        g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
        graph::addVertex("H2", g);
        graph::addVertex("C1", g);
        graph::addVertex("C2", g);
        graph::addVertex("H4", g);
        graph::addEdge("H2", "C2", g);
        graph::addEdge("C2", "C1", g);
        graph::addEdge("C2", "H4", g);
        cout << "* Verifico che tutti i nodi del grafo sono ben formati\n";
        if (areAllNodeNamesWellFormed(g)) 
          cout << "TEST 1 PASSATO\n";
        else 
          cout << "TEST 1 FALLITO\n";
        cout << "* Aggiungo il nodo Ba12 che non e' ben formato \n";
        cout << "* Verifico che il grafo NON ha tutti i nodi ben formati\n";
        graph::addVertex("Ba12", g);
        if (!areAllNodeNamesWellFormed(g)) 
          cout << "TEST 2 PASSATO\n";
        else 
          cout << "TEST 2 FALLITO\n";
        cout << "*** FINE Test verifica nome dei nodi\n";
      break;
      
      // Test connessione
      case 8: 
       cout << "*** Test connessione \n";
       cout << "* Il seguente grafo molecolare e' stato inserito\n";
       cout << "H2 C2\n";
       cout << "C2 C1\n";
       cout << "C2 H4\n";
       g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
       graph::addVertex("H2", g);
       graph::addVertex("C1", g);
       graph::addVertex("C2", g);
       graph::addVertex("H4", g);
       graph::addEdge("H2", "C2", g);
       graph::addEdge("C2", "C1", g);
       graph::addEdge("C2", "H4", g);
       cout << "* Verifico che il grafo e' connesso \n";
       if (connected(g)) 
          cout << "TEST 3 PASSATO\n";
        else 
          cout << "TEST 3 FALLITO\n";
       cout << "* Il seguente grafo molecolare e' stato inserito\n";
       cout << "H2 C2\n";
       cout << "C1 H4\n";
       g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
       graph::addVertex("H2", g);
       graph::addVertex("C1", g);
       graph::addVertex("C2", g);
       graph::addVertex("H4", g);
       graph::addEdge("H2", "C2", g);
       graph::addEdge("C1", "H4", g);
       cout << "* Verifico che il grafo NON e' connesso \n";
       if (!connected(g)) 
          cout << "TEST 4 PASSATO\n";
        else 
          cout << "TEST 4 FALLITO\n";      
      break;
      
      // Test esistenza cappi
      case 9: 
       cout << "*** Test esistenza cappi \n";
       cout << "* Il seguente grafo molecolare e' stato inserito\n";
       cout << "H2 C2\n";
       cout << "C2 C1\n";
       cout << "C2 H4\n";
       g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
       graph::addVertex("H2", g);
       graph::addVertex("C1", g);
       graph::addVertex("C2", g);
       graph::addVertex("H4", g);
       graph::addEdge("H2", "C2", g);
       graph::addEdge("C2", "C1", g);
       graph::addEdge("C2", "H4", g);
       cout << "* Verifico che il grafo NON contiene cappi \n";
       if (noLoops(g)) 
          cout << "TEST 5 PASSATO\n";
        else 
          cout << "TEST 5 FALLITO\n";
       cout << "* Aggiungo il cappio C2 --> C2 \n";
       graph::addEdge("C2", "C2", g);
       cout << "* Verifico che il grafo contiene almeno un cappio\n";
       if (!noLoops(g)) 
          cout << "TEST 6 PASSATO\n";
        else 
          cout << "TEST 6 FALLITO\n";
      break;
      
      // Test calcolo del numero di atomi
       case 10: 
        cout << "*** Test calcolo del numero di nodi\n";
        cout << "* Il seguente grafo molecolare e' stato inserito\n";
        cout << "H2 C1\n";
        cout << "C2 C1\n";
        cout << "C2 H4\n";
        g = graph::createEmptyGraph(); // serve nel caso in cui il grafo g e' gia' stato inserito (ri-inserimento)
                                       // occorrerebbe fare anche un destroy, cosi' si ha memory leak!
        graph::addVertex("H2", g);
        graph::addVertex("C1", g);
        graph::addVertex("C2", g);
        graph::addVertex("H4", g);
        graph::addEdge("H2", "C2", g);
        graph::addEdge("C2", "C1", g);
        graph::addEdge("C2", "H4", g);
        cout << "* Verifico che il numero di atomi dell'elemento H sono 6 e dell'elemento C sono 3\n";
        if (computeAtomNumber('H', g)==6 && computeAtomNumber('C', g)==3) 
          cout << "TEST 7 PASSATO\n";
        else 
          cout << "TEST 7 FALLITO\n";
        cout << "*** FINE Test calcolo del numero di nodi\n";
      break;
    }
    // Visualizzazione del menu e acquisizione della prossima scelta
    scelta = visualizzaMenu();
  }
  return 0;
}




