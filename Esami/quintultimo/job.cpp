#include "job.h"

using namespace job;

// Implementazione di un Job
// NON MODIFICARE QUESTO FILE

/****************************************************************/

/* crea un Job formato da label e tempo di esecuzione */
Job job::createJob(string s, int e) {
    return {s, e};
}

/****************************************************************/

/* ritorna la label di un Job */
string job::labelOf(Job j) {
    return j.label; 
}

/****************************************************************/

/* ritorna il tempo di esecuzione di un Job */
int job::executionTimeOf(Job j) {
    return j.executionTime; 
}


