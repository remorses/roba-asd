#include <iostream>
#include <string>
#include <cstdlib>

using namespace std; 

// File header di job.cpp
// NON MODIFICARE QUESTO FILE

namespace job {

    struct Job {
        string	label;
        int	    executionTime;
    };
    
    const Job EmptyJob = {"empty", 0};
    
    // NON MODIFICARE i prototipi seguenti
    Job createJob(string, int); /* crea un Job formato da label e tempo di esecuzione */
    string labelOf(Job);        /* ritorna la label di un Job */
    int executionTimeOf(Job);   /* ritorna il tempo di esecuzione di un Job */
}

