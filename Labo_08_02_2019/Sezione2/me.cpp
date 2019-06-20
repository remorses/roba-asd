#include <bits/stdc++.h>
#include "./cartoons.h"

using namespace std;

Cell * create(string myCharacter , string myAuthor , int myYear) {
    if (myCharacter.empty()) throw noNameError { "myCharacter" };
    if (myAuthor.empty()) throw noNameError { "myAuthor" };
    if (myYear < 1900) throw noNameError { "tooSmallError" };
    Cell* result = new Cell { { myCharacter, myAuthor, myYear } };
    result->next = nullptr;
    return result;
// se myCharacter stringa vuota , solleva eccezione di tipo noNameError ... //...con il campo element inizializzato a "myCharacter"
// se myAuthor stringa vuota , solleva eccezione di tipo noNameError ... //...con il campo element inizializzato a "myAuthor"
// se myYear minore di 1900, solleva eccezione di tipo tooSmallError //
// dichiara una variabile result di tipo puntatore a Cell inizializzata con nuovo spazio
/* per il campo payload della cella puntata da result, inizializza
(1) il campo author con myAuthor
(2) il campo character con myCharacter (3) il campo year con myYear
*/
// restituisci result 
}

 Cell* createCartoonList(vector <std::string > characters , vector <std::string > authors , vector<int>years) {
     
// dichiara una variabile dim di tipo intero inizializzata con la dimensione di characters // se la dimensione di authors differisce da dim solleva eccezione ...
//....di tipo differentSizeError con campi inizializzati a "characters" e "authors"
// se la dimensione di years differisce da dim solleva eccezione ...
//....di tipo differentSizeError con campi inizializzati a "characters" e "years" //
// se dim vale 0 restituisci il puntatore nullo //
// dichiara una variabile res di tipo puntatore a Cell inizializzato con ...
// ...la chiamata di create sui primi elementi di characters, authors, years
// dichiara una variabile last di tipo puntatore a Cell inizializzato con res
/* per tutti i valori di un indice i da 1 fino a dim escluso
- inizializza il campo next di last con ...
...la chiamata di create sugli elementi di characters, authors, years di indice i
- assegna a last il campo next di last */
// assegna il puntatore nullo al campo next di last
// restituisci res 
}
Cell* query(const Cell *const list, std::string theAuthor, int theYear) {
    return new Cell;
}