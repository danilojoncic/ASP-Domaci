#include <iostream>

int main() {
    int input;
    int dno = 1;
    int vrh;
    std::cin >> vrh;
    int sredina;
    while (dno <= vrh) {
        //sredina = (dno + (vrh - dno) / 3);
        sredina = dno+(vrh-dno)/3;
        std::cout << "? " << sredina << std::endl;
        std::cin >> input;
        if (input == 0) {
            dno = sredina + 1;
        } else {
            vrh = sredina - 1;
            break;

        }
        if(dno == vrh){
            std::cout <<"! " << vrh << std::endl;
            return 0;
        }
    }
    if(dno == sredina){
        std::cout <<"! " << sredina << std::endl;
        return 0;
    }
    std::cout <<"? " << dno << std::endl;
    std::cin >> input;
    if (input == 1){
        std::cout <<"! " << dno << std::endl;
    }else{
        for(int i = dno+1; i <= sredina;i++){
            std::cout <<"? " << i << std::endl;
            std::cin >> input;
            if(input == 1){
                std::cout <<"! " << i << std::endl;
                return 0;
            }else{
                if(i+1 == sredina){
                    std::cout <<"! " << sredina << std::endl;
                    return 0;
                }else{
                    continue;
                }
            }
        }
    }
    return 0;
}
