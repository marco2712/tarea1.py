/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: Mayo 3 de 2023
Proyecto Final BigInteger
*/
#include "BigInteger.h"
#include <vector>

/*
Constructor: BigInteger(sring cad)
ENTRADA: Recibi una cadena de tipo stirng 
SALIDA: un vecto de numeros enteros y una variable buleana que defien el signo de la clase
DESCRIPCION: Este constructor recibe una cadena, y recorre la cadena usando el codigo ascci para convertir cada caracter
a un valor entero; despues los dígitos se almacenan en orden, de manera que el dígito de menor peso (menos significativo) 
se encuentra en la posición 0 del vector, y los dígitos siguientes se almacenan en posiciones sucesivas.
la complejidad de este constrcutor es O(N) amortizada, ya que se usa la funcion push_back de la libreria de vectores
*/

BigInteger:: BigInteger(string cad){
    if(cad[0] == '-'){
        sign = false;
        for(int i = cad.size()-1; i > 0; i--) {
            vec_big.push_back(cad[i] - '0');
        }
    }
    else{
        sign = true;
         for(int i = cad.size() - 1; i >= 0; i--) {
            vec_big.push_back(cad[i] - '0');
        }
    }
}

/*
Constructor: BigInteger
ENTRADA: No recibe ningun parametro
SALIDA: un vector con un unico valor entero 0 y una variable buleana que defien el signo de la clase
DESCRIPCION: Este constructor no recibe niingun parametro y lo que hace es crear un vector de tamaño 1 con un unico
digito 0; por lo que la complejidad de este constrcutor es O(1), se realiza en tiempo constante
*/
BigInteger:: BigInteger(){
    vector<int>vec_big(0); // crea un vector cero
    sign = true;
}

/*
FUNCION: isNegative
ENTRADA: No recibe ningun parametro, sino que se invoca con la clase a traves del (.)
SALIDA: retorna un buleano verdadero si el BigInteger es negativo
DESCRIPCION: Esta funcion solo verifica un atributo de la clase; por lo que la complejidad 
de esta funcion es O(1), se realiza en tiempo constante
*/
bool BigInteger::isNegative(){
    return !sign;  // retorna verdadero si el BigInteger es negativo
}

/*
FUNCION: abs
ENTRADA: No recibe ningun parametro, sino que se invoca con la clase a traves del (.)
SALIDA: retorna un objeto de clase BigInteger simpre con signo positivo
DESCRIPCION: Esta funcion recibe un BigInteger, lo copia y realiza cambia su signo a positivo para determianrlo
como un valor absoluto, para eso modidfica un atributo privado de clase; su complejidad es lienal O(N), porque depende
del tamaño del vector y cambiarlo de signo se hace en tiempo constante O(1)
*/
BigInteger BigInteger::abs()const{
    BigInteger resultAbs(*this);
    if (resultAbs.isNegative())
        resultAbs.sign = true;  // hace una copia del vector positivo
    return resultAbs;
}

/*
FUNCION: toStirng
ENTRADA: No recibe ningun parametro, sino que se invoca con la clase a traves del (.)
SALIDA: retorna una cadena del tipo string
DESCRIPCION: Esta funcion recibe un BigInteger, verifica en el atributo de la clasde si es negativo y le agrega un (-), o si 
es positivo nada, despues usando el codigo ascci, convirente los valores del vector desde el mas significativo al menos signiticativo
en chars, y usando push_back se crea string que retorna. Su complejidad es lienal O(n), ya que debe recorrer todo el objeto
*/
string BigInteger::toString(){
    BigInteger result(*this);
    string cadena;
    if(result.sign == false)
        cadena.push_back('-');
        
    int i = result.vec_big.size() - 1;
    while(i >= 0){
        char character = result.vec_big[i] + '0';
        cadena.push_back(character);
        --i;
    }
    return cadena;
}

/*
FUNCION: operator==
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: retorna un valor buleano
DESCRIPCION: Esta funcion compara dos bigIntegers, si es el caso de que sean iguales retorna verdadero, de lo contrario retorna falso;
su complejidad en el mejor de los casos es consatnte, ya que verifica su longitud y si son diferentes retorna falso y termina la ejecicion;
el peor caso es cuando son iguales, ya que su complejidad lienal O(n), asi que dependera del tamaño del objeto
*/
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
/*
FUNCION: operator<=
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: retorna un valor buleano
DESCRIPCION: Esta funcion compara dos bigIntegers, si es el caso de que el primero sea menor o igual al segundo
retorna verdadero, de lo contrario retorna falso; su complejidad en el mejor de los casos es consatnte, ya que verifica su longitud y si 
son diferentes retorna falso y termina la ejecicion; el peor caso es cuando son iguales, ya que su complejidad lienal O(n), 
asi que dependera del tamaño del objeto y tiempo de ejecucion depende de los otros dos operadores que se llaman en esta funcion como son == y <
*/
bool BigInteger::operator<=(BigInteger& new_BigInteger) {  // verifica si es menor o es igual y devulve true en cualquier caso
    bool ans = false;
    BigInteger result(*this);
    if((result < new_BigInteger)||(result == new_BigInteger))
        ans = true;
    return ans;
}

/*
FUNCION: operator<
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: retorna un valor buleano
DESCRIPCION: Esta funcion compara dos bigIntegers, verifica si el primer objeto es menor que el segundo, entonces
retorna verdadero, de lo contrario retorna falso.
Su complejidad en el mejor de los casos es consatnte, ya que verifica su longitud y si son diferentes retorna falso y termina la ejecicion;
el peor caso es cuando son iguales, ya que su complejidad lienal O(n), asi que dependera del tamaño del objeto, tambien verifica los 
signos de los objetos que es muy imporante al momento de evaluar quien es mayor o menor
*/
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

/*
FUNCION: operator+
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: retorna un objeto del tipo BigInteger.
DESCRIPCION: Esta funcion suma dos objetos, verificando su atributo sign para saber si son numeros negativos, esta fucnion utiliza 
recursion en algunos casos, para sumar dos numeros negativos, y que queden con signo negativo, esta funcion en todos los casos es O(n);
ya que debe recorre ambos vectores por completos y agregar al final el acarreo que lleva, debido a que se trabaja con vectores almacenados
al reves se pueded utilizar la operacion push_back que su complejidad es amortizada
*/
BigInteger BigInteger:: operator+(BigInteger& new_BigInteger){
    BigInteger result(*this);
    if(!result.isNegative() && !new_BigInteger.isNegative()){
        if(result.vec_big.size() < new_BigInteger.vec_big.size()){
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
    }
    else if(result.isNegative() && new_BigInteger.isNegative()){
        BigInteger tmp = result.abs();
        BigInteger tmp2 = new_BigInteger.abs();
        result = tmp + tmp2;
        result.sign = false;
    }
    else if(result.isNegative() && !new_BigInteger.isNegative()){
        result.add(new_BigInteger);
    }
    else if(!result.isNegative() && new_BigInteger.isNegative()){
        result.add(new_BigInteger);
    }

    return result;
}

/*
FUNCION: operator-
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: retorna un objeto del tipo BigInteger.
DESCRIPCION: Esta funcion tiene como objetivo restar dos objetos en el caso que se deban restar, porque tambien existe el caso que deba
hacer uso de una funcion auxiliar anteriormente declara, y en algunos casos se utiliza recusrion para resolver varias operaciones;
su complejidad podria decirse que es lienal O(n), claro que habria que sumar la complegida de otras funciones que se necesitan en dicho
algoritmo; basicamente lo que hace es restar posisicon a posicion del vector los valores hasta recorrelo por completo
*/
BigInteger BigInteger:: operator-(BigInteger& new_BigInteger){
    BigInteger result(*this);
    BigInteger tmp2, tmp;
    if(result.isNegative() && !new_BigInteger.isNegative()){ // Primero negativo y seguno positivo
        tmp = new_BigInteger.abs();
        tmp2 = result.abs();
        result = tmp + tmp2; // se suman porque el segundo termino es negativo pero tiene signo negativo
        result.sign = false;
    }
    else if(!result.isNegative() && !new_BigInteger.isNegative()){ // Ambos positivos
        if(!(result < new_BigInteger)|| (result == new_BigInteger)){
            int carry = 0;  // Primero mayor que el segundo
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
                result.vec_big.pop_back(); // elimina los ceros de mas al fianl del vector
            }
        }
        else{ // Ambos positivos, segundo mayor que el primero
            result = new_BigInteger - result;
            result.sign = false;
        }
    }
    else if(result.isNegative() && new_BigInteger.isNegative()){ // Ambos negativos
        result.substract(new_BigInteger);
    }
    else if(!result.isNegative() && new_BigInteger.isNegative()){ // primero positivo, segundo negativo
        tmp = new_BigInteger.abs();
        tmp2 = result.abs();
        result = tmp + tmp2;
        result.sign = true;
    }
    return result;
}

/*
FUNCION: add
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion tiene como objetivo modificar el primer objeto sumandole el que se pasa como parametro, para ello se vale de 
sobrecargas de operadores como + y - en caso de que se reuqiere por los signos de los objetos; su complejidad podria decirse que es lienal
O(n), aunque se le debe tener en cuenta las funciones que se llaman en ella y un poco por el tema de la recusrividad podria llegar a se cuadrarica en algun caso
*/
void BigInteger::add(BigInteger new_BigInteger){
    BigInteger result(*this);
    if(result.isNegative() && new_BigInteger.isNegative()){ // Ambos valores negativos
        result = result + new_BigInteger;
        result.sign = false;
    }
    else if(!result.isNegative() && !new_BigInteger.isNegative()){ //Ambos valores posistivos
        result = result + new_BigInteger;
        result.sign = true;
    }
    else if(result.isNegative() && !new_BigInteger.isNegative()){ // Primero negativo, segundo positivo
        BigInteger tmp = result.abs();
        if(tmp < new_BigInteger){
            result = new_BigInteger - tmp;  // le resta el valor absoluto
            result.sign = false;
        }
        else{
            result = tmp - new_BigInteger;
            result.sign = true;
        }
    }
    else if(!result.isNegative() && new_BigInteger.isNegative()){
        BigInteger tmp2 = new_BigInteger.abs();
        if(result < tmp2){
            result = tmp2 - result;
            result.sign = false;
        }
        else{
            result = result - tmp2;
            result.sign = true;
        }
    }
    *this = result;
}

/*
FUNCION: substract
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion tiene como objetivo modificar el primer objeto restandole el que se pasa como parametro, para ello se vale de 
sobrecargas de operadores como + y - en caso de que se requira por los signos de los objetos; su complejidad podria decirse que es lienal
O(n), aunque se le debe tener en cuenta las funciones que se llaman en ella y un poco por el tema de la recusrividad podria llegar a se cuadrarica en algun caso
*/
void BigInteger::substract(BigInteger new_BigInteger){
    BigInteger result(*this);
    if(result.isNegative() && new_BigInteger.isNegative()){
        BigInteger tmp = new_BigInteger.abs();
        BigInteger tmp2 = result.abs();
        result = result + tmp;
        if(tmp2 < tmp)
            result.sign = true;
        else{
            result.sign = false;
        }    
    }
    else{
        result = result - new_BigInteger;
    }
    *this = result;
}

/*
FUNCION: product
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion tiene como objetivo modificar el primer objeto multiplicanolo por el segundo; su complejidad se basa en 
la operacion que sobrecarga el operador *, y se basa en el uso de las sumas, las veces que sea necesaria, depedneindo de los digitos del
vector que este multiplicando
*/
void BigInteger::product(BigInteger new_BigInteger){
    *this = *this * new_BigInteger;
}

/*
FUNCION: quotient
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion tiene como objetivo modificar el primer objeto dividiendolo por el segundo; su complejidad se basa en 
la operacion que sobrecarga el operador /, funciona a traves de restas, esta codificado de tal manera que su comlegidad es lo mas 
optima posible; se podria decir que tiene complejidad logaritmica, ya que no necesita hacer todas las restas de la forma larga 
*/
void BigInteger::quotient(BigInteger new_BigInteger){
    *this = *this / new_BigInteger;
}

/*
FUNCION: remainder
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion permite asignar a un elemento de la clase el residuo de la division entre dos objetos, por lo que su complejidad
esta basada en la ejecucion de la funcion que divide mas algunas sumas y restas que debe hacer para obtener dicho, se podria pensar que 
su complejidad es lienal por el hecho de las operacioens adjuntas
*/
void BigInteger::remainder(BigInteger new_BigInteger){
    *this = *this % new_BigInteger;
}

/*
FUNCION: operator*
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: Retorna un objeto de la clase BigInteger
DESCRIPCION: Esta funcion opera posicion a posicion dos objetos de la clase, para lo cual utiliza dos ciclos, como subindices para acceder
a una poscicion especifica de cada objeto,multiplica una posccion por todas las posciciones del otro ciclo y lurgo mientras se mueve,
va suamndo los productos llamando la funcion add; por lo que su complejidad podria ser cuadratica, ya que usa una funcion lineal dentro de otra
*/
BigInteger BigInteger:: operator*(BigInteger& new_BigInteger){
    BigInteger result(*this);
    BigInteger result2 {};
    for (int i = 0; i < new_BigInteger.vec_big.size(); i++){
        int suma = 0;
        int carry = 0;
        BigInteger product{};
        int ans = 0;
        for(int j = 0; j < result.vec_big.size(); ++j){
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
    // verifica si son signos distintos y le agrega el menos
    if((result.isNegative() && !new_BigInteger.isNegative()) ||(!result.isNegative() && new_BigInteger.isNegative())){
        result2.sign = false;
    }
    return result2;
}

/*
FUNCION: pow
ENTRADA: Recibe como parametro un objeto y se accede a el por (.)
SALIDA: No retorna nada, sino que modifica el objeto que se paso por la invocaion (.)
DESCRIPCION: Esta funcion utiliza el operador * para elevar un obejto de clase,sin embargo esta codificada de tal manera que su comlegida 
es O(log n), debido a que no necesita multiplicar el objeto el numero total de veces que el entero meustra, sino que va creceindo expoencialmente
el que multiplica como el que debe ser multiplicado; para ello usa una pila que le permite saber hasta cuadno debe ser multiplicada,
ya que se verifica si hay modulo en exponente, lo que lo divide en la mitad y reduce el proceo, convietriendolo en funcion logaritmica,
tambien verifica en tiempo constantesi es par o impar para asignar el signo
*/
void BigInteger::pow(int e){
    BigInteger result(*this);
    if(result.isNegative()){
        if(e % 2 == 1)   // si el exponente es impar, el resultado debe ser negativo
            result.sign = false;
    }
    if(e == 0){
        result = BigInteger("1"); // si la potencia es 0, el resultado siempre es 1
    }
    else{
        stack<BigInteger>miPila;
        BigInteger copy = result;
        miPila.push(copy);
        BigInteger inPila{};
        result = BigInteger("1");
        while(!miPila.empty()){
            if(inPila == miPila.top()) //  verifica que BigInteger sea diferente a lo que esta en la pila para no hacer una reasignacion 
                miPila.pop();         // del mismo numero; sino que solo lo ellimina     
            else{
                inPila = miPila.top();
                miPila.pop();
            };
            if(e % 2 == 1){ //verifica si hay residuo con el modulo
                result = result * inPila;
            }
            inPila = inPila * inPila;
            e = e / 2;
            if(e > 0)
                miPila.push(inPila);
        }
    }
    *this = result;
}

/*
FUNCION: operator/
ENTRADA: Recibe un numero entero y se accede a la clase a el por (.)
SALIDA: Retorna un objeto de clase BigInteger.
DESCRIPCION: Esta funcion utiliza el operador / para dividir dos objetos de la clase BigInteger, utilizando un algoritmo en el que verifica
si el divisor es muy pequeño, lo que le permite agregar ceros al final del numero a fin de que la operacion al invovcar resta, haga menos 
trabajo y se convierta su complejidad logaritmica, ya que no tiene que restar el numero de veces que se haria por el metodo tradicional
de la division usando restas.
*/
BigInteger BigInteger::operator/(BigInteger& divisor) {
    BigInteger dividendo(*this);
    BigInteger cociente;
    BigInteger cero("0");
    BigInteger uno("1");
    BigInteger multiTen("10");
    int numberZeros = 0;
    
    // Tomar el valor absoluto de los BigIntegers
    BigInteger absDividendo = dividendo.abs();
    BigInteger absDivisor = divisor.abs();
    
    //si el divisor es menor que el divisor
    if(absDividendo < absDivisor){
        cociente = cero; // El cociente es cero
    }
    else if(absDividendo == absDivisor){ // si son iguales 
        cociente = uno;
    }
    // Agregar ceros al divisor si es muy pequeño
    while ((absDivisor * multiTen) <= absDividendo) {
        absDivisor.vec_big.insert(absDivisor.vec_big.begin(), 0);
        ++numberZeros;

    }
    while (absDivisor <= absDividendo){
        int count = 0;
        while (absDivisor <= absDividendo) {
            absDividendo = absDividendo - absDivisor;
            ++count;
        }
        cociente.vec_big.insert(cociente.vec_big.begin(), count);
        numberZeros = numberZeros -1;
        if(numberZeros >= 0){  // elimina los ceros extras para hacer las diviones 
            absDivisor.vec_big.erase(absDivisor.vec_big.begin());
        }
        if(absDividendo < absDivisor && numberZeros >= 0){
            cociente.vec_big.insert(cociente.vec_big.begin(), 0);
            numberZeros = numberZeros -1;
            if(numberZeros >= 0){
                absDivisor.vec_big.erase(absDivisor.vec_big.begin());
            }
        }
    }
    // verifica si son signos distintos y le agrega el menos
    if((dividendo.isNegative() && !divisor.isNegative()) ||(!dividendo.isNegative() && divisor.isNegative())){
        cociente.sign = false;
    } 
    return cociente;
}

/*
FUNCION: operator%(
ENTRADA: Recibe un objeto de la clase BigInteger y se accede a la clase a el por (.)
SALIDA: Retorna un objeto de clase BigInteger.
DESCRIPCION: Esta funcion utiliza el operador / para dividir dos objetos de la clase BigInteger, utilizando un algoritmo en el que verifica
si el divisor es muy pequeño, lo que le permite agregar ceros al final del numero a fin de que la operacion al invovcar resta, haga menos 
trabajo y se convierta su complejidad logaritmica, despues de obtener el cociente, se multiplica para el divisor para obtener el valor 
faltante a la divion para que sea una divison exacta. obtenido el residuo que es el modulo
*/
BigInteger BigInteger::operator%( BigInteger& new_BigInteger){
    BigInteger dividendo(*this);
    BigInteger cociente;
    BigInteger residuo;// incializa los objetos de la clase
    BigInteger valorFaltante;
    cociente = dividendo / new_BigInteger;  
    valorFaltante = new_BigInteger * cociente; 
    residuo = dividendo - valorFaltante;  // Restar el dividendo inicial con el valor parcial
    return residuo;  // Retornar el residuo como resultado del operador %
}

/*
FUNCION: sumarListaValores
ENTRADA: Recibe una lista de tipo objetos BiIntegers
SALIDA: Retorna un objeto de clase BigInteger con la suma de todos los objetos
DESCRIPCION: Esta funcion recorre una lista que contiene varias objetos de la clase, mientras lo vas suamndo con el primer objeto, que se 
inicializa con cero, ya que es el modulo de la suma y no afecta en el resultado, para ello usa un iterrador que se mueve desde el comienzo de 
la lista hasta llegar al final; por lo que su complejidad es lienal O(n), ya que debe recorrer toda la lista
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>& lista){
    BigInteger resultado; // BigInteger inicializado como un vector de cero
    list<BigInteger>::iterator itSuma;
    for (itSuma = lista.begin(); itSuma != lista.end(); ++itSuma) {
        resultado = resultado + *itSuma; // Suma el bigIntger al que apunta el iterador
    }
    return resultado;
}

/*
FUNCION: sumarListaValores
ENTRADA: Recibe una lista de tipo objetos BiIntegers
SALIDA: Retorna un objeto de clase BigInteger con la multiplicacion de todos los objetos
DESCRIPCION: Esta funcion recorre una lista que contiene varios objetos de la clase, mientras lo vas multiplicando con el primer objeto, que se 
inicializa con en uno, ya que es el modulo de la multiplicacion y no afecta en el resultado, para ello usa un iterrador que se mueve desde el comienzo de 
la lista hasta llegar al final; por lo que su complejidad podria ser cuadratica O(n**2), debido a que la multiplicaion funciona a traves
de sumas que son otros ciclos anidados, asi que habria que sumar sus complejidades al algoritmo.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& lista){
    BigInteger resultado("1"); // BigInteger inicializado como el numero 1, ya que es el modulo de la multiplicaion y afecta el resultado
    list<BigInteger>::iterator itMulti;
    for (itMulti = lista.begin(); itMulti != lista.end(); ++itMulti) {
        resultado = resultado * *itMulti; // Multiplica cada valor al que apunta el iterador
    }
    return resultado;
}