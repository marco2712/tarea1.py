/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: Mayo 3 de 2023
Proyecto Final
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger{
  public:
      vector<int>vec_big;

    /* constructores*/
    BigInteger(string cad);
    BigInteger();

    /*Modificadores*/

    void add(const BigInteger new_BigInteger);
    void substract(const BigInteger new_BigInteger);
    void product(const BigInteger new_BigInteger);
    /*
    void quotient(const BigInteger new_BigInteger);
    void remainder(const BigInteger new_BigInteger);
    void pow(const BigInteger new_BigInteger);
    string toString();
    */

    /*sobrecarga de operadores*/

    BigInteger operator+(const BigInteger& new_BigInteger) const;
    BigInteger operator-(const BigInteger& new_BigInteger) const;
    BigInteger operator*(const BigInteger new_BigInteger) const;
    bool operator<(const BigInteger& new_BigInteger) const;
     /*
    BigInteger operator/(const BigInteger& new_BigInteger) const;
    BigInteger operator%(const BigInteger& new_BigInteger) const;
    bool operator==(const BigInteger& new_BigInteger) const;
    bool operator<=(const BigInteger& new_BigInteger) const;
    */

};

#endif 