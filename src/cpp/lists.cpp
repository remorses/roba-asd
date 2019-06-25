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

template <class F>
List removeIf(List l, F function) {
    auto begin = l;
    auto previous = l;
    int i = 0;
    while (l) {
        if (function(l->info, i)) {
            if (begin==l) {
                auto toDelete = l;
                l = l->next;
                begin = l;
                delete toDelete;
            } else {
                auto toDelete = l;
                previous->next = l->next;
                l = l->next;
                delete toDelete;
            }
        }   
        i += 1;
        previous = l;
        if (l) l = l->next;
    }
    return begin;
    // throw "not found";
}



void print(List l) {
    while(l) {
        cout << l->info << ", ";
        l = l->next;
    }
    cout << endl;
}


bool deleter(int e, int i) {
    return e == 666;
}


int length(List l) {
    int i = 0;
    while (l) {
        i += 1;
        l = l->next;
    }
    return i;
}

int main() {
    List list = nullptr;
    for (int i = 0; i<20; i++) {
        list = insertAt(list, i, i);
    }
    // list = insertAt(list, 4, 666);
    // list = insertAt(list, 16, 666);
    list = insertAt(list, length(list), 666);
    print(list);
    list = removeIf(list, deleter);
    print(list);
    // cout << length(list) << endl;
}