#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int k) {
    int prvi = 1;
    int drugi = 1;
    int fib;

    if(k == 1 || k == 2) {
        return 1;
    }

    for(int i = 3; i <= k; i++) {
        fib = prvi + drugi;
        prvi = drugi;
        drugi = fib;
    }

    return fib;
}

int main() {
    int poslednji;
    int prizemlje;
    int jaje = 0;
    int fib = 2;
    int trenutno;

    while(jaje == 0) {
        cout<< "? " << fibonacci(fib)<< endl;
        cin >> jaje;

        if(jaje == 0)
            fib++;
    }

    poslednji = fibonacci(fib);
    prizemlje = fibonacci(fib-1);

    while(prizemlje < poslednji) {
        trenutno = (poslednji + prizemlje) / 2;
        cout <<"? "<<trenutno <<endl;
        cin >> jaje;
        if(jaje == 1) {
            poslednji = trenutno;
        }
        else {
            prizemlje = trenutno + 1;
        }
    }
    if(poslednji == prizemlje)
        cout <<"! "<<poslednji <<endl;
    return 0;
}
