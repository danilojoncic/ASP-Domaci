#include <iostream>
#include <cmath>

int main() {
    int unos;
    std::cin>>unos;
    int hint;
    int iter = 2;
    int pokusaj  = round((1 + sqrt(1 + 8*unos)) / 2);
    int start = 0;
    while(pokusaj < unos){
        std::cout<<"? "<<pokusaj<<std::endl;
        std::cin>>hint;
        if(hint == 0){
            start = pokusaj;
            pokusaj += round((1 + sqrt(1 + 8*unos)) / 2) - iter;
            iter++;
        }else{
            break;
        }
        if(pokusaj+1 == unos){
            std::cout<<"! "<<unos<<std::endl;
            return 0;
        }
    }
    for(int i = start+1; i <= pokusaj;i++){
        std::cout<<"? "<<i<<std::endl;
        std::cin>>hint;
        if(hint == 0){
            if(i+1 == pokusaj){
                std::cout<<"! "<<pokusaj<<std::endl;
                return 0;
            }
            continue;
        }else{
            std::cout<<"! "<<i<<std::endl;
            return 0;
        }
    }
    return 0;
}
