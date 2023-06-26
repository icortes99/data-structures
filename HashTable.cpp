#include "HashTable.h"
#include "NodoTH.h"

//Crear e inicializa la tabla
HashTable::HashTable() {
    tabla.resize(TTabla, nullptr);
    for (int i = 0; i < TTabla; ++i) {
        NodoTH* nodo = tabla[i];
        while (nodo != nullptr) {
            NodoTH* temp = nodo;
            nodo = nodo->Sig;
            delete temp;
        }
    }
}

HashTable::~HashTable() {

}
//Funcion para retornar segun la llave de la tabla
int HashTable::hashFunction(int llave) {
    return llave % TTabla;
}
//Insertar
void HashTable::insertar(int llave, int dato) {
    int index = hashFunction(llave);//Llama la posicion
    NodoTH* nodo = new NodoTH(llave, dato);//Define el nodo a insertar
    nodo->Sig = tabla[index];//Define la posicion del nodo
    tabla[index] = nodo;//Inserta el nodo
}
//Imprimir
int HashTable::imprimir(int llave) {

    int index = hashFunction(llave);//Busca la posicion
    NodoTH* nodo = tabla[index];//Define el nodo segun el index de la tabla
    while (nodo != nullptr) { //Se asegura que no este vacio
        if (nodo->llave == llave) {//Busca segun el parametro otorgado
            return nodo->dato; //Retorna el nodo cuando lo encuentre
        }
        nodo = nodo->Sig; //Si no lo encuentra rota al siguiente nodo
    }
    return -1;//Si no encunetra el nodo retorna "-1"
}
//TODO

void HashTable::borrar(int llave) {
    int index = hashFunction(llave);//Busca la posicion
    NodoTH* nodo = tabla[index];//Define el nodo segun el index de la tabla
    NodoTH* ant = nullptr;//Define un puntero anterior,este sera necesario para reorganizar los nodos
    while (nodo != nullptr) {//Recorrer hasta que el valor sea null
        if (nodo->llave == llave) {//Rotar hasta encontrar el valor
            if (ant == nullptr) {//El valor llave es el primer elemento
                tabla[index] = nodo->Sig;
            }
            else {//En caso contrario que tenga un valor antes, reorganiza los nodos
                ant->Sig = nodo->Sig;
            }
            delete nodo; //Borra el nodo
            return;
        }
        ant = nodo; //En caso contrario se mueve al siguiente nodo
        nodo = nodo->Sig;
    }
}