/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: Mayo 3 de 2023
Proyecto Final
*/

#include "BigInteger.h"

int main() {
    BigInteger num1("156234");
    BigInteger num2("2652");
    num1.add(num2);
    for (int i = num1.vec_big.size() - 1; i >= 0; --i) {
        cout << num1.vec_big[i];
    }
    std::cout << std::endl;
    num1.substract(num2);
    for(int i = num1.vec_big.size()-1; i >= 0; --i) {
        std::cout << num1.vec_big[i];
    }
    std::cout << std::endl;
    num1.product(num2);
    for(int i = num1.vec_big.size()-1; i >= 0; --i) {
        std::cout << num1.vec_big[i];
    }
    std::cout << std::endl;
    return 0;
}
