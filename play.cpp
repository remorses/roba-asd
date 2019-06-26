
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// struct Node {
//     string info;
//     Node* next;
//     Node* children;
// };

const int NMAX = 20; // max children per node

struct Node {
    int info;
    int size = 0;
    Node* children [NMAX];
};

typedef Node* Tree;

void print(Tree t, string indent="") {
    if (!t) return;
    cout << "\n" + indent << t->info << ":" << endl;
    for (int i = 0; i<t->size; i++) {
        print(t->children[i], indent + "\t");
    }
}


Tree insert(Tree t, Node e) {
    if (!t && e.size == 0) return new Node {e.info, 1, };
    if (!t) {
        t = new Node {e.info, 1};
        for (int i = 0; i<e.size; i++) {
            insert(t, *(e.children[i]));
            t->size += 1;
        }
        return t;
    }
    Tree aux = new Node {e.info, 1};
    for (int i = 0; i<e.size; i++) {
        insert(t, *(e.children[i]));
        t->size += 1;
    }
    t->children[t->size] = aux;
    t->size += 1;
    return t;
}

Tree insert(Tree t, vector<Node> trees) {
    for (auto x : trees) {
        t = insert(t, x);
    }
    return t;
}


int main() {
    Tree t = nullptr;
    Tree x = insert(nullptr, {
            Node {4},
            Node {5},
            Node {6}
    });

    t = insert(t, {
        Node {1},
        Node {2},
        *x
    });
    print(t);
}

