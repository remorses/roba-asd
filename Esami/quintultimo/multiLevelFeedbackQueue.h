#include "queue.h" // che a sua volta include job.h

using namespace std;
using namespace job;
 
namespace multilevelqueue {

    // segnaposto MODIFICARE la struct
    struct MultiLevelQueue {
        int firstQueue;  
        int secondQueue; 
        int thirdQueue; 
    };
    
    // segnaposto MODIFICARE la const seguente
    const MultiLevelQueue EmptyMLFQ = {0, 0, 0};
    
    // NON MODIFICARE i prototipi seguenti
    MultiLevelQueue createEmptyMLQ();                      /* restituisce la MLFQ vuota */
    bool isEmpty(const MultiLevelQueue&);                  /* verifica se la MLFQ e' vuota */
    bool insertJobInMLFQ(Job, MultiLevelQueue&);           /* inserisce il Job nella MLFQ. L'inserimento va a buon fine solo se non esiste nella MLFQ un Job con la stessa label. In questo caso la funzione restituisce true; false se l'inserimento non va a buon fine */      
    Job executeJobInMLFQ(MultiLevelQueue&);                /* simula l'esecuzione di un Job. La funzione preleva il Job a priorita' maggiore, aggiorna il tempo di esecuzione del Job e lo restituisce. Se il Job non e' terminato viene re-inserito nella coda successiva a priorità minore oppure nella stessa se il Job era gia' nella coda a priorità minima. Se la MLFQ e' vuota la funzione ritorna EmptyJob (potremmo in alternativa sollevare un'eccezione) */   
    void executeAllJobsinMLFQ(MultiLevelQueue&);           /* esegue tutti i Job presenti nella MLFQ finchè la MLFQ non rimane vuota. In pratica si tratta di simulare il comportamento di esecuzione di una MLFQ fino al completamento. Tale funzione deve stampare la label dei Job terminati */  
    int numberOfJobsInQueueN(int, const MultiLevelQueue&); /* restituisce il numero di Job contenuti nella Queue '1', '2' o '3' che costituiscono la MLFQ; restituisce -1 nel caso venga richiesto un numero di coda non esistente (ad esempio 4)*/
    void printMLFQ(const MultiLevelQueue&);                /* visualizza la MLFQ */
}


