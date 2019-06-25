#include "multiLevelFeedbackQueue.h" // che a sua volta include queue.h e job.h

// Implementa le funzioni relative alla Multi level Feddback queue

using namespace multilevelqueue;

/*******************************************************************************************************/
// Funzioni ausiliarie
/*******************************************************************************************************/

// INSERIRE qui eventuali funzioni ausiliarie usate solo in MultiLevelFeedbackQueue.cpp

/*******************************************************************************************************/
// Funzioni relative alla MLFQ - TUTTE LE FUNZIONI SONO DA MODIFICARE
/*******************************************************************************************************/


/* restituisce la MLFQ vuota */
MultiLevelQueue multilevelqueue::createEmptyMLQ(){
    return EmptyMLFQ;
}

/* verifica se la MLFQ e' vuota */                 
bool multilevelqueue::isEmpty(const MultiLevelQueue& mlfq){
    return true; // segnaposto MODIFICARE
}

/* inserisce il Job nella MLFQ. L'inserimento va a buon fine solo se non esiste nella MLFQ un Job con la stessa label. In questo caso la funzione restituisce true; false se l'inserimento non va a buon fine */           
bool multilevelqueue::insertJobInMLFQ(Job job, MultiLevelQueue& mlfq){
    return true; // segnaposto MODIFICARE
}       

/* simula l'esecuzione di un Job. La funzione preleva il Job a priorita' maggiore, aggiorna il tempo di esecuzione del Job e lo restituisce. Se il Job non e' terminato viene re-inserito nella coda successiva a priorità minore oppure nella stessa se il Job era gia' nella coda a priorità minima. Se la MLFQ e' vuota la funzione ritorna EmptyJob (potremmo in alternativa sollevare un'eccezione) */ 
Job multilevelqueue::executeJobInMLFQ(MultiLevelQueue& mlfq){
    return EmptyJob; // segnaposto MODIFICARE
}

/* esegue tutti i Job presenti nella MLFQ finchè la MLFQ non rimane vuota. In pratica si tratta di simulare il comportamento di esecuzione di una MLFQ fino al completamento. Tale funzione deve stampare la label dei Job terminati */          
void multilevelqueue::executeAllJobsinMLFQ(MultiLevelQueue& mlfq){  
    // MODIFICARE
}

/* restituisce il numero di Job contenuti nella Queue '1', '2' o '3' che costituiscono la MLFQ; restituisce -1 nel caso venga richiesto un numero di coda non esistente (ad esempio 4)*/           
int multilevelqueue::numberOfJobsInQueueN(int i, const MultiLevelQueue& mlfq) {
    return 0;  // segnaposto MODIFICARE
}

/* visualizza la MLFQ */
/* un esempio di stampa della MLFQ con tre Job all'interno - uno nella prima coda e due nella seconda - potrebbe essere il seguente:
   (Coda 1): [b, 10]
   (Coda 2): [a, 3] [c, 4]
   (Coda 3):
*/
void multilevelqueue::printMLFQ(const MultiLevelQueue& mlfq) {
    // MODIFICARE
}
