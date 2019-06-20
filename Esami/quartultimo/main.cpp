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
bool getDataFromInput (graph::Graph &);
bool getDataFromFile (graph::Graph &);

bool test1(graph::Graph &);
bool test2(graph::Graph &);
bool test3(graph::Graph &);
bool test4(graph::Graph &);



int main () {

  int scelta;
  graph::Graph g;
  graph::Label l;
  unsigned int dist;
  int r;

  g = graph::createEmpty();

  while (true) {

    // Acquisizione della rete sociale da stdin o da file

    if ((scelta = menu1 ()) == 0) break;

    switch (scelta) {
      case 1:
        if (getDataFromInput (g))
          cout << "Acquisizione da stdin eseguita" << endl;
        else {
          cout << "Acquisizione da stdin fallita" << endl;
          continue;
        }
        break;
      case 2:
        if (getDataFromFile (g))
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

    if ((scelta = menu2 ()) == 0) break;

    switch (scelta) {
      case 1:
        // visualizza grafo
        graph::print (g);
        break;
      case 2:
        // eventuali test
        {
          graph::Graph g = graph::createEmpty();
          if (!test1(g))
            cout << "Test 1 fallito, Test 2 3 4 non eseguiti." << endl;
          else if (!test2(g))
            cout << "Test 1 OK, Test 2 fallito, Test 3 4 non eseguiti." << endl;
          else if (!test3(g))
            cout << "Test 1 2 OK, Test 3 fallito, Test 4 non eseguito." << endl;
          else if (!test4(g))
            cout << "Test 1 2 3 OK, Test 4 fallito." << endl;
          else
            cout << "Test superati con successo." << endl;
        }
        break;
      case 3:
        // conteggio amici diretti
        cout << "Nickname dell'utente: " << endl;
        cin >> l;
        r = graph::numFriendsDirect (g,l);
        if (r < 0)
          cout << "L'utente " << l << " non e' presente nella rete sociale." << endl;
        else
          cout << "L'utente " << l << " ha " << r << " amici diretti." << endl;
        break;
      case 4:
        // conteggio amici entro distanza prestabilita
        cout << "Nickname dell'utente: " << endl;
        cin >> l;
        cout << "Distanza dall'utente: " << endl;
        cin >> dist;
        if (dist == 0) {
          cout << "Distanza non valida." << endl;
          break;
        }
        r = graph::numFriendsAtDistance (g,l,dist);
        if (r < 0)
          cout << "L'utente " << l << " non e' presente nella rete sociale." << endl;
        else
          cout << "L'utente " << l << " ha " << r << " amici entro distanza " << dist << "." << endl;
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
      coutLine ();;
      cout <<
	"                                  MENU                                    \n";
      coutLine ();
      cout << "1. Inserimento rete sociale da standard input\n";
      cout << "2. Inserimento rete sociale da file\n";
      cout << "0. Uscita\n";
      cout << "\nImmetti la scelta e premi ENTER ---> ";
      cin >> scelta;
      cin.ignore ();
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
      cout << "1. Visualizzazione del grafo\n";
      cout << "2. Esecuzione test\n";
      cout << "3. Conteggio amici diretti\n";
      cout << "4. Conteggio entro distanza prestabilita\n";
      cout << "0. Uscita\n";
      cout << "\nImmetti la scelta e premi ENTER ---> ";
      cin >> scelta;
      cin.ignore ();
      coutLine ();
      if (cin.fail () || scelta < 0 || scelta > 4)
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


bool getDataFromInput (graph::Graph &g) {

  graph::Label v1, v2;

  cout << "Inserisci i dati seguendo il formato stabilito dal testo d'esame: " << endl;

  while (true) {
    cin >> v1;
    if (v1 == "0") break;
    cin >> v2;
    graph::addVertex(g,v1);
    graph::addVertex(g,v2);
    graph::addEdge(g,v1,v2);
  }

  return true;

}


bool getDataFromFile (graph::Graph &g) {

  string filename;
  graph::Label v1, v2;

  cout << "Inserisci il nome del file: " << endl;
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
    graph::addVertex(g,v1);
    graph::addVertex(g,v2);
    graph::addEdge(g,v1,v2);
  }

  return true;

}


bool test1 (graph::Graph &g) {

  // inserimento vertice: la prima volta deve essere OK,
  // ma se riprovo con stessa etichetta deve essere KO

  if (!graph::addVertex(g,"a"))
    return false;
  return !graph::addVertex(g,"a");

}


bool test2 (graph::Graph &g) {

  // inserimento arco: entrambi i vertici di incidenza devono esistere,
  // e inoltre non e' consentito l'arco che inizia su un vertice e termina
  // sullo stesso vertice

  graph::addVertex(g,"b");
  graph::addVertex(g,"c");
  if (!graph::addEdge(g,"b","c"))
    return false;
  if (graph::addEdge(g,"b","c"))
    return false;
  if (graph::addEdge(g,"b","d"))
    return false;
  if (graph::addEdge(g,"d","d"))
    return false;
  if (graph::addEdge(g,"b","b"))
    return false;
  return true;

}


bool test3 (graph::Graph &g) {

  // test sulla funzione numFriendsDirect()

  // su un vertice inesistente deve dare -1
  if (graph::numFriendsDirect(g,"d") != -1)
    return false;

  // su un vertice senza archi incidenti deve dare 0
  graph::addVertex(g,"d");
  if (graph::numFriendsDirect(g,"d") != 0)
    return false;

  // aggiungo 10 amici al vertice "d", che tra loro non si conoscono;
  // i loro nomi sono "e", "f", "g", ecc.
  string s = "e";
  for (int i=10; i; i--) {
    graph::addVertex(g,s);
    graph::addEdge(g,"d",s);
    s[0]++;
  }

  // a questo punto il vertice "e" deve avere solo 1 amico (sarebbe "d")...
  if (graph::numFriendsDirect(g,"e") != 1)
    return false;

  // ...e il vertice "d" deve avere 10 amici
  return graph::numFriendsDirect(g,"d") == 10;

}


bool test4 (graph::Graph &g) {

  // test sulla funzione numFriendsAtDistance()

  // su un vertice inesistente deve dare -1
  if (graph::numFriendsAtDistance(g,"A",100) != -1)
    return false;


  // aggiungo il vertice "A"
  string first = "A";
  graph::addVertex(g,first);

  // "A" non ha amici, dunque il numero di amici entro distanza 100
  // (ma anche a qualunque altra distanza in effetti)
  // deve essere 0
  if (graph::numFriendsAtDistance(g,first,100) != 0)
    return false;

  // aggiungo 10 vertici "B", "C", "D", ecc.
  // con amicizie "A"<-->"B", "B"<-->"C", "C"<-->"D", ecc.
  // formando in tal modo una catena di 10 archi tra 11 vertici consecutivi
  string second = "B";
  for (int i=10; i; i--) {
    graph::addVertex(g,second);
    graph::addEdge(g,first,second);
    second[0]++;
    first[0]++;
  }

  // a questo punto, contando gli amici di "A" a distanza 10, 9, 8, ...,1
  // si deve ottenere 10, 9, 8, ..., 1
  for (int i=10; i; i--)
    if (graph::numFriendsAtDistance(g,"A",i) != i)
      return false;

  // ...e il numero di amici di "A" entro distanza 100
  // (o qualunque distanza superiore a 10) deve essere 10
  return graph::numFriendsAtDistance(g,"A",100) == 10;

}
