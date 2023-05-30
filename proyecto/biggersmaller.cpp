/*
Autor: Marco Antonio Riascos Salguero
Fecha: 22 de Mayo de 2023
Codigo: 8952273
Bigger or Smaller
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
private:
    vector<int> vec_big;
    bool sign;
public:
    /* Constructores */
    BigInteger(string cad);
    BigInteger();

    /* Funciones */
    bool isNegative();
    string toString();
    bool operator<(BigInteger& new_BigInteger);
    bool operator==(BigInteger& new_BigInteger);
    int getSize();
    int getDigit(int posicion);
    bool vectorZero();
};

//Funcion que permite conocer el tamaño del vector
int BigInteger::getSize(){
    return vec_big.size();
}

// constrcutor que inicializa un vector 0
BigInteger::BigInteger() {
    vec_big = vector<int>(0);
    sign = true;
}

//Funcion que permite saber el signo del BigInteger
bool BigInteger::isNegative() {
    return !sign;
}

//constructor que recibe el string
BigInteger::BigInteger(string cad) {
  if (cad[0] == '-') {
      sign = false;
      for (int i = cad.size() - 1; i > 0; i--) {
        vec_big.push_back(cad[i] - '0');
      }
  } else {
      sign = true;
      for (int i = cad.size() - 1; i >= 0; i--) {
        vec_big.push_back(cad[i] - '0');
      }
  }
}

//Funcion que verifica si es vector de una sola pocicion y su posiscion es cero
bool BigInteger::vectorZero() {
   bool isSingleZero = (vec_big.size() == 1) && (vec_big[0] == 0);
    return isSingleZero;
}

//funcion que permte acceder a una posicion especifica del BigInteger
int BigInteger::getDigit(int position) {
  int ans;
  if (position >= 0 && position < vec_big.size()) {
    ans =vec_big[position];
  }
  return ans ;
}

//Funcion que convierte un BigInteger en string
string BigInteger::toString() {
    BigInteger result(*this);
    string cadena;
    if (result.sign == false)
        cadena.push_back('-'); //Agrega un - si el BigInteger es negativo

    int i = result.vec_big.size() - 1;
    while (i >= 0) {
        char character = result.vec_big[i] + '0';
        cadena.push_back(character);
        --i;
    }
    return cadena;
}

bool BigInteger::operator<(BigInteger& new_BigInteger){
  BigInteger result(*this);
  bool ans = true;
  if(!result.isNegative() && new_BigInteger.isNegative())//si el primero es positivo y el segund negativo
      ans = false;
  else if(result.isNegative() && !new_BigInteger.isNegative()){ // si el primero es negativo y el segundo positivo
      ans = true;
  }
  else if(!result.isNegative() && !new_BigInteger.isNegative()){  // amabos positivos
    if(result.vec_big.size() > new_BigInteger.vec_big.size()) {
        ans = false;
    }
    else if (result.vec_big.size() < new_BigInteger.vec_big.size()) {
        ans = true;
    }
    else if(result.vectorZero() && new_BigInteger.vectorZero()){ // verifica si ambos BigIntgers son ceros
      ans = false;
    }
    else if(result == new_BigInteger){ // si los BigIntegers son iguales, retorna falso ya que no es menor
        ans = false;
    }
    else{
      int i = result.vec_big.size() - 1;
      int flag = 0;
      while(i >= 0 && flag == 0){     // si enceuntra un numero menor de mayor significado
        if(result.vec_big[i] < new_BigInteger.vec_big[i]){
            flag = 1;
        }
        else if (result.vec_big[i] > new_BigInteger.vec_big[i]) {
            flag = 2;
        }
        --i;
      }
      if(flag == 2)
          ans = false;
    }
  }
  else if(result.isNegative() && new_BigInteger.isNegative()){ //ambos son negativos
    if (result.vec_big.size() > new_BigInteger.vec_big.size()) // verifica si el primer vector tiene mas digitos
        ans = true;
    else if(result.vec_big.size() < new_BigInteger.vec_big.size()) {
        ans = false;
    }
    else{
      int i = result.vec_big.size() - 1;
      while(i >= 0 && ans){
          if (result.vec_big[i] < new_BigInteger.vec_big[i]){
              ans = false;
          }
          --i;
      }
    }
    }
    return ans;
}

bool BigInteger:: operator==(BigInteger& new_BigInteger){
    BigInteger result(*this);
    bool ans = true;
    if(result.vec_big.size() < new_BigInteger.vec_big.size()) // compara si el primero es menor
        ans = false;
    else if(result.vec_big.size() > new_BigInteger.vec_big.size()){ // compara si el segundo es menor
        ans = false;
    }
    else{
        int i = result.vec_big.size() - 1;  //si ambos son del mismo tañano, itera hasta encontar algun digito diferente y 
        while(i >= 0 && ans){              // hacer la condicion falsa
            if(result.vec_big[i] != new_BigInteger.vec_big[i]){
                ans = false;
            }
            --i;    
        }
    }
    return ans;
}


int compararBigIntegers(BigInteger num1, BigInteger num1decimal, BigInteger num2, BigInteger num2decimal){
  int ans;
  bool flag = true;
  bool flag2 = true;
  if(num1 < num2){ // verifica si el primer entero es menor que el segundo
    ans = 1;
  }
  else if(num2 < num1){//verifica si el segundo es mayor,entonces no hay necesidad de verifciar los deciamales
    ans = 2;
  }
  else{
    if(num1 == num2){ //si los enteros son iguales verifica los decimales
      int i = num1decimal.getSize()-1;
      int j = num2decimal.getSize()-1;
      while(i >= 0 &&  j >= 0 && flag2){
        if(num1decimal.getDigit(i) < num2decimal.getDigit(j)){//ciclo que recorre el primer decimal, del primer entero
          ans = 1;
          flag2 = false;
          flag = false;
        }
        else if(num1decimal.getDigit(i) > num2decimal.getDigit(j)){//ciclo que recorre el decimal, del segundo entero
          ans =  2;
          flag2 = false;
          flag = false;
        }
        --i;
        --j;
      }
      if(i >= 0 && flag){ //ciclo que permite verificar si el primer deciaml es mas largo y tiene algun digito diferente de 0
        bool flag3 = true;
        while(i >= 0 && flag3){
          if(num1decimal.getDigit(i) != 0){
            ans = 2;
            flag3 = false;
            flag = false;
          }
          --i;
        }
      }
      else if(j >= 0 && flag){//ciclo que permite verificar si el segundo deciaml es mas largo y tiene algun digito diferente de 0
        bool flag3 = true;
        while(j >= 0 && flag3){
          if(num2decimal.getDigit(j) != 0){
            ans = 1;
            flag3 = false;
            flag = false;
          }
          --j;
        }
      }
      if(i == -1 && j == -1 && flag){ // en caso de que halla recorrido los dos decimales y aun la condicion sea verdad, entonces son iguales
        ans = 3;
      }
    }
  }
  return ans;
}


int main() {
  string bigCad;
  int cases = 0;
  getline(cin, bigCad);
  while (!bigCad.empty()){
    int ans;
    string vec1, vec2, vec3, vec4;
    BigInteger num1, num1decimal, num2, num2decimal;
    for (int i = 0; i < bigCad.size(); ++i){ //Incializa las cadenas como cadenas vacias 
      vec1 = "";
      vec2 = "";
      vec3 = "";
      vec4 = "";
      while (bigCad[i] != '.' && i < bigCad.size()) { // Cada while verifica si es un BigInterger diferente, sea decimal o entero
        vec1.push_back(bigCad[i]);
        ++i;
      }
      ++i;
      num1 = BigInteger(vec1);
      while (bigCad[i] != ' ' && i < bigCad.size()) {
        vec2.push_back(bigCad[i]);
        ++i;
      }
      num1decimal = BigInteger(vec2);
      ++i;
      while (bigCad[i] != '.' && i < bigCad.size()) {
        vec3.push_back(bigCad[i]);
        ++i;
      }
      ++i;
      num2 = BigInteger(vec3);
      while (bigCad[i] != ' ' && i < bigCad.size()) {
        vec4.push_back(bigCad[i]);
        ++i;
      }
      num2decimal = BigInteger(vec4);
    }
    ans = compararBigIntegers(num1,num1decimal,num2,num2decimal); // invoca la funcion que resuelve el problema
    ++cases;
    if(ans == 1){
      printf("Case %d: Smaller\n",cases);// impresion de solucion
    }
    else if(ans == 2){
      printf("Case %d: Bigger\n",cases);
    }
    else if(ans == 3){
      printf("Case %d: Same\n",cases);
    }
    getline(cin, bigCad);
  }
  return 0;
}