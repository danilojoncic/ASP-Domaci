#include <iostream>

void binarniPokusajCplusplus(int dno, int vrh) {
    int mid;
    while (dno <= vrh) {
        mid = dno + (vrh - dno) / 2;
        std::cout << "? " << mid << std::endl;
        int hint;
        std::cin >> hint;
        if (hint == 1) {
            vrh = mid - 1;
        } else if (hint == 0) {
            dno = mid + 1;
        }
    }

    if (dno - vrh > 1) {
        if (mid - vrh < dno - mid) {
            std::cout << "! " << vrh << std::endl;
        } else {
            std::cout << "! " << dno << std::endl;
        }
    } else {
        std::cout << "! " << dno << std::endl;
    }
}

int main() {
    int spratovi;
    std::cin >> spratovi;
    int dno = 0;
    int vrh = spratovi;
    binarniPokusajCplusplus(dno, vrh);
    return 0;
}
