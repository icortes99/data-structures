#include <vector>
#include "NodoTH.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
private:
    static const int TTabla = 10;

    std::vector<NodoTH*> tabla;

public:
    //Constructores
    HashTable();
    ~HashTable();
    //Buscar posicion
    int hashFunction(int llave);
    //Insertar en la tabla
    void insertar(int llave, int dato);
    //Buscar valor segun llave de referencia
    int imprimir(int llave);
    //Borrar un valor segun llave
    void borrar(int llave);
};

#endif