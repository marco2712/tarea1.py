/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: Mayo 3 de 2023
Proyecto Final
*/
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger{
  private:
    vector<int>vec_big;
    bool sign;
  public:
    /* constructores*/
    BigInteger(string cad);
    BigInteger();

    /*Modificadores*/

    bool isNegative();
    BigInteger abs() const;
    void add(BigInteger new_BigInteger);
    void substract(BigInteger new_BigInteger);
    void product(BigInteger new_BigInteger);
    string toString();
    void pow(int e);
    void quotient(BigInteger new_BigInteger);
    void remainder(BigInteger new_BigInteger);

    /*sobrecarga de operadores*/

    BigInteger operator+(BigInteger& new_BigInteger);
    BigInteger operator-(BigInteger& new_BigInteger);
    BigInteger operator*(BigInteger& new_BigInteger);
    bool operator<(BigInteger& new_BigInteger);
    bool operator==(BigInteger& new_BigInteger);
    bool operator<=(BigInteger& new_BigInteger);
    BigInteger operator/(BigInteger& new_BigInteger);
    BigInteger operator%(BigInteger& new_BigInteger);
    static BigInteger sumarListaValores(list<BigInteger>& lista);
    static BigInteger multiplicarListaValores(list<BigInteger>& lista);

};

#endif 