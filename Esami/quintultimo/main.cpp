// Per compilare utilizzare il flag -std=c++11

#include "multiLevelFeedbackQueue.h" // che a sua volta include queue.h e job.h

////////////////////////////////////////////////////////////////////////
// Programma che simula una Multi level Feedback queue (MLFQ)
////////////////////////////////////////////////////////////////////////

/*******************************************************************************************************/
// Funzioni di test
/*******************************************************************************************************/

// ATTENZIONE: per poter utilizzare le funzioni di test occorre avere gia' implementato la funzione numberOfJobsInQueueN() perche' i tre casi di test si basano su questa funzione.  


// Test funzione inserimento in MLFQ 
void test1(multilevelqueue::MultiLevelQueue& mlfq) {
    mlfq = multilevelqueue::createEmptyMLQ(); // creo una nuova MLFQ vuota
    cout << "- testo MLFQ vuota" << endl;
    if (numberOfJobsInQueueN(1, mlfq)!= 0 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Appena creata la MLFQ dovrebbe essere vuota. Ci potrebbero essere problemi nella funzione numberOfJobsInQueueN()" << endl; return;}
    // inserisco un job nella MLFQ
    cout << "- inserisco un Job nella MLFQ" << endl;
    insertJobInMLFQ(job::createJob("a", 5), mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=1 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Il Job dovrebbe essere inserito nella prima coda. Ci potrebbero essere problemi nella funzione insertJobInMLFQ() o nell'implementazione della coda" << endl; return;}
    // inserisco un'altro job nella MLFQ
    cout << "- inserisco un'altro Job nella MLFQ" << endl;
    insertJobInMLFQ(job::createJob("b", 10), mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=2 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: I due Job dovrebbero essere inseriti nella prima coda. Ci potrebbero essere problemi nella funzione insertJobInMLFQ() o nell'implementazione della coda" << endl; return;}   
    cout << "TEST PASSATO" << endl;
}

// Test esegui un Job in MLFQ
void test2(multilevelqueue::MultiLevelQueue& mlfq) {
    mlfq = multilevelqueue::createEmptyMLQ(); // creo una nuova MLFQ vuota
    if (numberOfJobsInQueueN(1, mlfq)!= 0 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Appena creata la MLFQ dovrebbe essere vuota. Ci potrebbero essere problemi nella funzione numberOfJobsInQueueN()" << endl; return;}
    // inserisco il job ('a', 7) nella MLFQ
    cout << "- inserisco il job ('a', 7) nella MLFQ" << endl;
    insertJobInMLFQ(job::createJob("a", 7), mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=1 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Il Job dovrebbe essere inserito nella prima coda. Ci potrebbero essere problemi nella funzione insertJobInMLFQ() o nell'implementazione della coda" << endl; return;}
    // eseguo un job nella MLFQ
    cout << "- eseguo un job" << endl;
    Job job = executeJobInMLFQ(mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=0 || numberOfJobsInQueueN(2, mlfq)!=1 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Il Job non e' stato spostato nella seconda coda. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    if (executionTimeOf(job)!=5)
        {cout << "TEST FALLITO: Il tempo di esecuzione del Job non e' stato aggiornato in modo corretto. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    // eseguo un job nella MLFQ
    cout << "- eseguo un altra volta un job" << endl;
    job = executeJobInMLFQ(mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=0 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=1)
        {cout << "TEST FALLITO: Il Job non e' stato spostato nella terza coda. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    if (executionTimeOf(job)!=1)
        {cout << "TEST FALLITO: Il tempo di esecuzione del Job non e' stato aggiornato in modo corretto. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    // eseguo un job nella MLFQ
    cout << "- eseguo un altra volta un job" << endl;
    job = executeJobInMLFQ(mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=0 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Il Job doveva lasciare il sistema. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    if (executionTimeOf(job)!=0)
        {cout << "TEST FALLITO: Il tempo di esecuzione del Job non e' stato aggiornato in modo corretto. Ci potrebbero essere problemi nella funzione executeJobInMLFQ()" << endl; return;}
    cout << "TEST PASSATO" << endl;
}

// Test esegui tutti i Job in MLFQ
void test3(multilevelqueue::MultiLevelQueue& mlfq) {
    mlfq = multilevelqueue::createEmptyMLQ(); // creo una nuova MLFQ vuota
    // inserisco i job: ('a', 7), ('b', 2), ('d', 15) e ('c', 2) nella MLFQ
    cout << "inserisco i job ['a', 7], ['b', 2], ['d', 15] e ['c', 2] nella MLFQ" << endl;
    insertJobInMLFQ(job::createJob("a", 7), mlfq);
    insertJobInMLFQ(job::createJob("b", 2), mlfq);
    insertJobInMLFQ(job::createJob("d", 15), mlfq);
    insertJobInMLFQ(job::createJob("c", 2), mlfq);
    if (numberOfJobsInQueueN(1, mlfq)!=4 || numberOfJobsInQueueN(2, mlfq)!=0 || numberOfJobsInQueueN(3, mlfq)!=0)
        {cout << "TEST FALLITO: Nella MLFQ ci dovrebbero essere 4 Job. Ci potrebbero essere problemi nella funzione insertJobInMLFQ()" << endl; return;}
    // eseguo tutti i Job
    cout << "eseguo tutti i Job " << endl;
    cout << "il test e' PASSATO se viene stampato il seguente ordine di Job 'b c a d' dopo la linea tratteggiata. E' FALLITO altrimenti." << endl;
    cout << "-----" << endl;
    executeAllJobsinMLFQ(mlfq);
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
    cout << "1. Inserisci Job nella Multi-level queue\n";
    cout << "2. Simula esecuzione di un Job nella Multi-level queue\n";
    cout << "3. Visualizza il numero di Job presenti nelle code della Multi-level queue\n";
    cout << "4. Simula esecuzione di tutti i Job presenti nella Multi-level queue\n";
    cout << "5. Visualizza Multi-level queue\n";
    cout << "6. Test inserisci Job\n";
    cout << "7. Test esegui un Job\n";
    cout << "8. Test esegui tutti i Job\n";
    cout << "0. Uscita\n";
    cout << "\nFornisci la tua scelta ---> ";
    cin >> scelta;
    cout << "--------------------------------------------------------------------------\n";
    if (!cin) {cout << "Hai inserito una stringa al posto di un numero\n"; return 0;}
    if ((scelta>=0)&&(scelta<=8)) return scelta;
      cout << "\nScelta non valida\n";
  }
  return -1;
}


int main() {

  multilevelqueue::MultiLevelQueue mlfq = multilevelqueue::createEmptyMLQ();  
  string l;
  int time;
  Job job;
  
  string nomefile;
  int scelta = 0;

  // Visualizzazione menu e acquisizione scelta
  scelta = visualizzaMenu();

  //Ciclo su scelta
  // si interrompe quando l'utente sceglie di uscire (scelta==0)
  while (scelta) {
    
    switch (scelta)
    {
      // Inserisci Job nella Multi-level queue
      case 1: {
         cout << "\nInserisci label e tempo di esecuzione del Job da inserire nella MLFQ: label tempo [invio] \n";
         cin >> l;
         cin >> time;
         if (insertJobInMLFQ(job::createJob(l, time), mlfq))
            cout << "Job inserito" << endl;
         else
            cout << "Job NON inserito" << endl;
       } 
      break;
      
      // Esegui Job nella Multi-level queue
      case 2: {
         job = executeJobInMLFQ(mlfq);
         if (labelOf(job) == "empty")
            {cout << "\nNon ci sono Job da eseguire nella MLFQ" << endl; break;}
         if (executionTimeOf(job) == 0)
            cout << "\nIl Job: " << labelOf(job) << " e' terminato" << endl;
         else
            cout << "\nIl Job: " << labelOf(job) << " NON e' terminato e sara' inserito nella coda successiva" << endl;
      }  
      break;
      
      // Visualizza numero di Job presenti nella coda 'n' nella Multi-level queue
      case 3: {
          cout << "Il numero di Job presenti nelle code e' rispettivamente: " << numberOfJobsInQueueN(1, mlfq) << " " << numberOfJobsInQueueN(2 , mlfq) << " " << numberOfJobsInQueueN(3 , mlfq) << endl;  
      }  
      break;
      
      // Esegui tutti i Job presenti nella Multi-level queue
      case 4: 
        cout << "La lista dei Job terminati e' la seguente: " << endl;
        executeAllJobsinMLFQ(mlfq);
      break;
      
      // Stampa Multi-level queue
      case 5: 
        printMLFQ(mlfq);
      break;
      
      // Test funzione inserimento in MLFQ 
      case 6: 
        test1(mlfq);
      break;
      
      // Test esegui un Job in MLFQ
      case 7: 
        test2(mlfq);
      break;
      
      // Test esegui tutti i Job in MLFQ
      case 8: 
        test3(mlfq);
      break;
    }
    // Visualizzazione del menu e acquisizione della prossima scelta
    scelta = visualizzaMenu();
  }
  return 0;
}





