#include <iostream>

using namespace std;


struct Cosa {
    int x;
};

int main() {
    Cosa* a = new Cosa {1};{
        Cosa* a = new Cosa {2};
    }
    
    cout << a->x << endl;
}