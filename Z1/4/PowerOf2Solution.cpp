#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int pok = 0;
    int input = 0;
    int start;
    int end;
    int sredina;

    while(input != 1){
        cout<<"? "<<pow(2,pok)<<endl;
        cin>>input;
        if(input == 0){
            pok++;
        }
    }
    start = pow(2,pok-1);
    end = pow(2,pok);
    sredina = start + (end - start)/2;
    while(start < end){
        //cout<<"start :  "<<start<<endl;
        //cout<<"end : "<<end<<endl;
        //cout<<"sredina : "<<sredina<<endl;
        cout<<"? "<<sredina<<endl;
        cin>>input;
        if(input == 0 ){
            start = sredina+1;
            sredina = start + (end - start)/2;
        }else{
            end = sredina;
            sredina = start + (end - start)/2;
        }

    }
    if(start == end){
        cout<<"! "<<end;
    }


    return 0;
}
