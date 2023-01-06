#include <iostream>
#include <cmath>
#include <time.h>
#include <climits>
using namespace std;


int main() {
    srand(time(NULL));
    int input = 0;
    int vrh = INT_MAX;
    int dno = 1;
    int brojRand = rand();

    while(1) {
        brojRand = rand() % ((vrh-dno)+1)+dno;
        cout<<"? "<<brojRand<<endl;
        cin>>input;
        if(input == 0) {
            //cout<<"DNO prije : "<<dno<<endl;
            dno = brojRand + 1;
            //cout<<"DNO poslije : "<<dno<<endl;
            //brojRand = rand() % ((vrh-dno)+1);
        }
        if(input == 1){
            //cout<<"VRH prije : "<<vrh<<endl;
            vrh = brojRand;
            //cout<<"VRH poslije : "<<vrh<<endl;
            //brojRand = rand() % ((vrh-dno)+1);
        }
        cout<<"DNO poslije : "<<dno<<endl;
        cout<<"VRH poslije : "<<vrh<<endl;
        if(vrh == dno){
            cout<<"! "<<vrh<<endl;
            return 0;
        }
    }


    return 0;
}
