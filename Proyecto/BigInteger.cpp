/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: Mayo 3 de 2023
Proyecto Final
*/
#include "BigInteger.h"
#include <vector>

BigInteger:: BigInteger(string cad){
    for(int i = cad.size() - 1; i >= 0; i--) {
        vec_big.push_back(cad[i] - '0');
    }
}

BigInteger:: BigInteger(){
    vector<int>vec_big(0);
}

bool BigInteger::operator<(const BigInteger& new_BigInteger) const {
    bool ans = true;
    if(vec_big.size() > new_BigInteger.vec_big.size()) {
        ans = false;
    }
    else if (vec_big.size() < new_BigInteger.vec_big.size()) {
        ans = true;
    }
    else{
        int i = vec_big.size() - 1;
        while(i >= 0 && ans == true){
            if (vec_big[i] > new_BigInteger.vec_big[i]) {
                ans = false;
            }
            --i;
        }
    }
    return ans;
}

BigInteger BigInteger:: operator+(const BigInteger& new_BigInteger) const {
    BigInteger result(*this);
    int flag =0;
    if(result < new_BigInteger){
        int cero = result.vec_big.size();
        int otro = new_BigInteger.vec_big.size();
        while(cero < otro){
            result.vec_big.push_back(0);
            cero +=1;
        }
    }
        int carry = 0;
        for (int i = 0; i < result.vec_big.size(); i++){
            int suma = result.vec_big[i] + carry;
            if (i < new_BigInteger.vec_big.size()){
                suma += new_BigInteger.vec_big[i];
            }
            result.vec_big[i] = suma % 10;
            carry = suma / 10;
        }
        if (carry > 0){
            result.vec_big.push_back(carry);
        }
    return result;
}

BigInteger BigInteger:: operator-(const BigInteger& new_BigInteger) const {
    BigInteger result(*this);
    int carry = 0;
    int resta;
    for (int i = 0; i < result.vec_big.size(); i++) {
        if (i < new_BigInteger.vec_big.size()) {
            resta = result.vec_big[i] - new_BigInteger.vec_big[i] - carry;
            if (resta < 0) {
                resta += 10;
                carry = 1;
            } 
            else {
                carry = 0;
            }
            result.vec_big[i] = resta;
        }
        else if (carry > 0) {
            resta = result.vec_big[i] - carry;
            if (resta < 0) {
                resta += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.vec_big[i] = resta;
        }
    }
    while (result.vec_big.size() > 1 && result.vec_big[result.vec_big.size() - 1] == 0) {
        result.vec_big.pop_back();
    }
    return result;
}

void BigInteger::add(BigInteger new_BigInteger){
    *this = *this + new_BigInteger;
}

void BigInteger::substract(BigInteger new_BigInteger){
    *this = *this - new_BigInteger;
}

void BigInteger::product(const BigInteger new_BigInteger){
    *this = *this * new_BigInteger;
}

BigInteger BigInteger:: operator*(const BigInteger new_BigInteger) const {
    BigInteger result(*this);
    BigInteger result2 {};
    int mayor, menor;
    if(result < new_BigInteger){
        mayor = new_BigInteger.vec_big.size();
        menor = result.vec_big.size();
    }
    else{
        menor = new_BigInteger.vec_big.size();
        mayor = result.vec_big.size();
    }
    for (int i = 0; i < menor; i++){
        int suma = 0;
        int carry = 0;
        BigInteger product{};
        int ans = 0;
        for(int j = 0; j < mayor; ++j){
            while(ans < i){
                product.vec_big.push_back(0);
                ans += 1;
            }
            suma = new_BigInteger.vec_big[i] * result.vec_big[j] + carry;
            if(suma == 10){
                product.vec_big.push_back(0);
                carry = 1;
            }
            else if(suma > 10){
                product.vec_big.push_back(suma % 10);
                carry = suma / 10;
            }
            else{
                product.vec_big.push_back(suma);
                carry = 0;
            }
        }
        if (carry > 0) {
            product.vec_big.push_back(carry);
        }
        result2.add(product);
    }
    return result2;
}

