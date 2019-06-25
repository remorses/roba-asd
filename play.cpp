




// struct Node {
//     string info;
//     Node* next;
//     Node* children;
// };
 
const int NMAX = 20; // max children per node

struct Node {
    int info;
    int childrenCount;
    Node* children [NMAX];
};

