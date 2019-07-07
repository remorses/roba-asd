#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"

////////////////////////////////////////////////////////////////////////
// COMPILAZIONE:
// g++ -std=c++11 -Wall *cpp
////////////////////////////////////////////////////////////////////////


using namespace std;

int menu1 ();
int menu2 ();
void coutLine ();
bool getDataFromInput (graph::Graph &, unsigned int);
bool getDataFromFile (graph::Graph &, unsigned int);



int main () {

  int scelta, i, j, k;
  bool r;
  graph::Graph g[3];
  graph::Vlabel l1, l2;

  for (i=0; i<3; i++)
    g[i] = graph::createEmpty ();

  while (true) {

    // Acquisizione di due reti di trasporto da stdin o da file

    scelta = menu1 ();

    switch (scelta) {
      case 1:
        if (getDataFromInput (g[0],1) && getDataFromInput (g[1],2))
          cout << "Acquisizione da stdin eseguita" << endl;
        else {
          cout << "Acquisizione da stdin fallita" << endl;
          continue;
        }
        break;
      case 2:
        if (getDataFromFile (g[0],1) && getDataFromFile (g[1],2))
          cout << "Acquisizione da file eseguita" << endl;
        else {
          cout << "Acquisizione da file fallita" << endl;
          continue;
        }
        break;
      default:
        return 0;
    }

    break;

  }


  while (true) {

    // Operazioni sulle reti di trasporto acquisite

    scelta = menu2 ();

    switch (scelta) {
      case 1:
        // visualizza grafo
        cout << "Scegli la rete da considerare (1, 2 o 3): " << endl;
        cin >> i;
        graph::print (g[i-1]);
        break;
      case 2:
        // esistenza cammino
        cout << "Scegli la rete da considerare (1, 2 o 3): " << endl;
        cin >> i;
        cout << "Nome della prima localita': " << endl;
        cin >> l1;
        cout << "Nome della seconda localita': " << endl;
        cin >> l2;
        r = graph::connected (g[i-1],l1,l2);
        if (!r)
          cout << "Nessun cammino tra " << l1 << " e " << l2 << " sulla mappa " << i << "." << endl;
        else
          cout << "Esiste un cammino tra " << l1 << " e " << l2 << " sulla mappa " << i << "." << endl;
        break;
      case 3:
        // merge tra due reti di trasporto
        cout << "Scegli la prima rete da immergere (1, 2 o 3): " << endl;
        cin >> i;
        cout << "Scegli la seconda rete da immergere (1, 2 o 3): " << endl;
        cin >> j;
        k = 6-i-j;
        r = graph::merge (g[i-1],g[j-1],g[k-1]);
        if (r)
          cout << "Operazione eseguita." << endl;
        else
          cout << "Operazione fallita." << endl;
        break;
      default:
        return 0;
    }

  }

}


void coutLine () {
  cout <<
    "--------------------------------------------------------------------------"
    << endl;
}


int menu1 () {

  int scelta = -1;
  while (true) {
      coutLine ();
      cout <<
	"                                  MENU                                    \n";
      coutLine ();
      cout << "1. Inserimento reti di trasporto da standard input\n";
      cout << "2. Inserimento reti di trasporti da file\n";
      cout << "0. Uscita\n";
      cout << "\nImmetti la scelta e premi ENTER ---> ";
      cin >> scelta;
//      cin.ignore ();
      coutLine ();
      if (cin.fail () || scelta < 0 || scelta > 2)
	{
	  cout << "\nScelta non valida\n";
	  cin.clear ();
	  cin.ignore ();
	  clearerr (stdin);
	  continue;
	}
      return scelta;
    }

}


int menu2 () {

  int scelta = -1;
  while (true) {
      coutLine ();;
      cout <<
	"                                  MENU                                    \n";
      coutLine ();
      cout << "1. Visualizzazione di una rete di trasporto\n";
      cout << "2. Controllo esistenza cammini in una rete\n";
      cout << "3. Immersione tra due reti di trasporto\n";
      cout << "0. Uscita\n";
      cout << "\nImmetti la scelta e premi ENTER ---> ";
      cin >> scelta;
//      cin.ignore ();
      coutLine ();
      if (cin.fail () || scelta < 0 || scelta > 3)
	{
	  cout << "\nScelta non valida\n";
	  cin.clear ();
	  cin.ignore ();
	  clearerr (stdin);
	  continue;
	}
      return scelta;
    }

}


bool getDataFromInput (graph::Graph &g, unsigned int n) {

  graph::Vlabel v1, v2;
  graph::Elabel t;

  cout << "Rete di trasporto " << n << ":  Inserisci i dati seguendo il formato stabilito dal testo d'esame: " << endl;

  while (true) {
    cin >> v1;
    if (v1 == "0") break;
    cin >> v2;
    cin >> t;
    graph::addVertex(g,v1);
    graph::addVertex(g,v2);
    graph::addEdge(g,v1,v2,t);
  }

  return true;

}


bool getDataFromFile (graph::Graph &g, unsigned int n) {

  string filename;
  graph::Vlabel v1, v2;
  graph::Elabel t;

  cout << "Rete di trasporto " << n << ":  Inserisci il nome del file: " << endl;
  cin >> filename;

  ifstream ifs(filename.c_str());
  if (!ifs) {
    cout << "File non esistente o non leggibile" << endl;
    return false;
  }

  while (true) {
    ifs >> v1;
    if (v1 == "0") break;
    ifs >> v2;
    ifs >> t;
    graph::addVertex(g,v1);
    graph::addVertex(g,v2);
    graph::addEdge(g,v1,v2,t);
  }

  return true;

}
