#pragma once
#include "BTreeNode.h"
#include <cstddef>
using namespace std;
// Un BTree
class BTree {
    BTreeNode* root;// Puntero al nodo raiz
    int t;// Grado minimo - Numero minimo de claves permitidas en un nodo
public:
    // Constructor (Inicializa arbol vacio)
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    // funcion para atravesar el arbol
    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    // La funcion principal que inserta una nueva llave en el  B-Tree
    void insertion(int k);

    // La funcion para borrar un nodo del  B-Tree
    void deletion(int k);

    //devuelve el Grado minimo - Numero minimo de claves permitidas en un nodo
    int getT() {
        return t;
    }
};

