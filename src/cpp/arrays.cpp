
#include <iostream>

using namespace std;

const int MAX = 1000;
struct Array {
    int size;
    int elems [MAX];
};

void insertElem(Array& a, int position, int elem) {
    
    for (int i = a.size; i>position; i--) {
        a.elems[i] = a.elems[i-1];
    }
    a.size += 1;
    a.elems[position] = elem;
}

void deleteElem(Array& a, int position) {
    for (int i=position; i<a.size-1; i++) {
        a.elems[i] = a.elems[i + 1];
    }
    a.size -= 1;
}

void print(Array a) {
    for (int i = 0; i< a.size; i++) {
        cout << a.elems[i] << ", ";
    }
    cout << endl;
}

int main() {
    Array* arr = new Array {4, {1, 2, 3, 4}};
    print(*arr);
    insertElem(*arr, 2, 666);
    print(*arr);
    deleteElem(*arr, 2);
    print(*arr);
}