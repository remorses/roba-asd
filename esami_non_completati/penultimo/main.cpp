////////////////////////////////////////////////////////////////////////
// Alberi binari
////////////////////////////////////////////////////////////////////////

// Compilare con g++ -Wall *.cpp

/*******************************************************************************************************/
// main.cpp

// --- NON MODIFICARE QUESTO FILE ---

#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"

using namespace std;
using namespace tree;

// Funzione di test che stampa un albero binario
void test1(Tree& t) {
    cout << "IL TEST E' CORRETTO SE LE DUE STAMPE SONO UGUALI (A MENO DI PERMUTAZIONI DEGLI ARCHI)" << endl;
    cout << "--- risultato corretto" << endl;
    cout << "gigi" << endl;
    cout << "S gigi anna" << endl;
    cout << "D gigi giovanni" << endl;
    cout << "S anna laura" << endl;
    cout << "D anna marco" << endl;
    cout << "S marco luisa" << endl;
    cout << "0" << endl;
    cout << "--- stampa della vostra funzione" << endl;
    print(t);
}

// Funzione di test della funzione contaNumeroTerminaliIsolati()
void test2(Tree& t) {
    if (contaNumeroTerminaliIsolati(t)==1)
        cout << "TEST PASSATO" << endl;
    else
        cout << "TEST FALLITO; il numero di terminali isolati dovrebbe essere 1 e non " << contaNumeroTerminaliIsolati(t) << endl;
}

// Funzione di test della funzione stampaCammino()
void test3(Tree& t) {
    cout << "IL TEST E' CORRETTO SE LE DUE STAMPE SONO UGUALI" << endl;
    cout << "--- risultato corretto" << endl;
    cout << "luisa, marco, anna, gigi" << endl;
    cout << "--- stampa della vostra funzione" << endl;
    stampaCammino("luisa", t);
}

// Questa funzione assume che il formato dell'input sia corretto e che sia presente almeno la radice dell'albero
bool leggiAlberoDaFile(Tree& t)
{
  t = creaAlberoVuoto(); // in caso l'operazione di lettura sia eseguita più volte (abbiamo memory leak)
  string nome_file, nome, nome1, keyw;
  cout << "Inserisci nome file" << endl;
  cin >> nome_file;
  if (!cin) cout << "Errore inserimento nome file\n" << endl;
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return false;} 
  ifs >> nome;
  inserisciRadice(nome, t); // inseriamo la radice
  ifs >> keyw;
  // keyw e' di tipo string, keyw[0] e' di tipo char, il primo carattere
  // di keyw, che se l'input e' giusto sara' anche l'unico carattere
  while (keyw[0]!='0') {
    ifs >> nome >> nome1;
    switch (keyw[0]) // valori possibili sono solo 'S' e 'D'
    {
      case 'S': inserisciFiglioSX(nome, nome1, t); break; // inseriamo il padre
      case 'D': inserisciFiglioDX(nome, nome1, t); break; // inseriamo la madre
      default: cout << "errore" << endl; return false;
    }
    ifs >> keyw;
  }
  return true;
}

// Visualizza menu' con le scelte possibili e chiede
// all'utente di inserirne una. 
// Continua a ri-presentare il menu' finche' l'utente non
// inserisce una scelta valida. Ritorna la scelta fatta
int visualizzaMenu() {
  int scelta = -1;
  while ((scelta<0)||(scelta>5)) { 
    cout << "--------------------------------------------------------------------------\n";
    cout << "                                  MENU                                    \n";
    cout << "--------------------------------------------------------------------------\n";
    cout << "1. Inserisci albero da file\n";
    cout << "2. Visualizza albero\n";
    cout << "3. Conta il numero di terminali isolati\n";
    cout << "4. Visualizza cammino a partire dalla label inserita fino ad arrivare alla radice\n";
    cout << "5. Test Stampa - Inserire prima albero di esempio (esempio.txt)\n";
    cout << "6. Test terminali isolati - Inserire prima albero di esempio (esempio.txt)\n";
    cout << "7. Test cammino - Inserire prima albero di esempio (esempio.txt)\n";
    cout << "0. Uscita\n";
    cout << "\nFornisci la tua scelta ---> ";
    cin >> scelta;
    cout << "--------------------------------------------------------------------------\n";
    // OLD WAY
    // if (!cin) {cout << "Hai inserito una stringa al posto di un numero\n"; return 0;}
    // if ((scelta>=0)&&(scelta<=7)) return scelta;
      //cout << "\nScelta non valida\n";
    /*cin.ignore ();*/
    if (cin.fail () || scelta < 0 || scelta > 7)
	{
	  cout << "\nScelta non valida\n";
	  cin.clear ();
	  cin.ignore ();
	  clearerr (stdin);
	  continue;
	}
      return scelta;
  }
  return -1;
}


int main() {

  Tree t = creaAlberoVuoto();  
  int scelta = 0;

  // Visualizzazione menu e acquisizione scelta
  scelta = visualizzaMenu();

  //Ciclo su scelta
  // si interrompe quando l'utente sceglie di uscire (scelta==0)
  while (scelta) {
    
    switch (scelta)
    {
      // Legge albero da file
      case 1:
         if (leggiAlberoDaFile(t))
            cout << "ALBERO LETTO IN MODO CORRETTO\n";
      break;
      
      // Visualizza albero
      case 2:  
        cout << "STAMPA ALBERO LETTO" << endl;
        print(t);   
      break;
      
      // Conta il numero di terminali isolati
      case 3: 
         cout << "IL NUMERO DI TERMINALI ISOLATI E': " << contaNumeroTerminaliIsolati(t) << endl;   
      break;
      
      // Visualizza cammino a partire dalla label inserita fino ad arrivare alla radice
      case 4: {
        string l;
        cout << "INSERISCI LA LABEL\n";
        cin >> l;
        stampaCammino(l, t);
      }  
        
      break;
      
      // Test 1 - stampa
      case 5: 
        test1(t);
      break;
      
      // Test 2 - conta terminali isolati
      case 6: 
        test2(t);
      break;
      
      // Test 3 - visualizza cammino
      case 7: 
        test3(t);
      break;
      
    }
    // Visualizzazione del menu e acquisizione della prossima scelta
    scelta = visualizzaMenu();
  }
  return 0;
}

