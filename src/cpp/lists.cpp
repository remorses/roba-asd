#include <string>
#include <iostream>

using namespace std;





struct Node {
    int info;
    Node* next;
};

typedef  Node* List;


List insertAt(List list, int position, int e) {
    if (!list && position == 0) {
        list = new Node {e, nullptr};
        return list;
    }
    if (list && position == 0) {
        list = new Node {e, list};
        return list;
    }
    int count = 0;
    auto current = list;
    auto previous = list;
    while (current && count < position) {
        count += 1;
        previous = current;
        current = current->next;
    }
    if (count == position) {
        previous->next = new Node {e, current};
        return list;
    }
    throw "";

}

void print(List l) {
    while(l) {
        cout << l->info << ", ";
        l = l->next;
    }
    cout << endl;
}


int main() {
    List list = nullptr;
    for (int i = 0; i<20; i++) {
        list = insertAt(list, i, i);
    }
    list = insertAt(list, 4, 666);
    list = insertAt(list, 16, 666);
    list = insertAt(list, 0, 666);
    print(list);
}