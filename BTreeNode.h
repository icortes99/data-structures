#pragma once
#include "Provincia.h"
using namespace std;


class BTreeNode {
    int* keys;  // Un array de llaves, valor almacenado en el nodo
    int t;      // Grado m�nimo (define el rango para el n�mero de claves)
    BTreeNode** C; // Un array de punteros children del nodo, osea los que van hacia abajo
    int n;     // Numero actual de llaves
    bool leaf; // Es verdadero cuando el nodo es hoja. De lo contrario falso

public:
    BTreeNode(int _t, bool _leaf);// Constructor
    void traverse();// Una funci�n para recorrer todos los nodos en un sub�rbol enraizado con este nodo
    int searchkey(int k);
    void insert_Non_Full(int k);// Una funci�n de utilidad para insertar una nueva clave en el sub�rbol enraizado con
    // este nodo. La suposici�n es que el nodo no debe estar lleno cuando esto
    // se llama a la funcion

    void split_Child(int i, BTreeNode* y);// Una funci�n de utilidad para dividir el hijo 'y' de este nodo. i es �ndice de 'y' en
    // matriz secundaria C[]. El ni�o y debe estar lleno cuando se llama a esta funci�n

    void deletion(int k);// borrar un valor del arbol
    void remove_From_Leaf(int idx); //borrar de una hoja
    void remove_From_Non_Leaf(int idx);//borrar de un nodo no hoja

    // Devuelve la clave del predecesor del �ndice idx dentro del nodo actual.
    int get_Predecessor(int idx);

    // Devuelve la clave del sucesor del �ndice idx dentro del nodo actual.
    int get_Successor(int idx);

    // Rellena el nodo hijo en el �ndice idx si tiene menos de t claves.
    void fill(int idx);

    // Toma prestada una clave del nodo hermano anterior en el �ndice idx si tiene m�s de t-1 claves.
    void borrow_From_Prev(int idx);

    // Toma prestada una clave del nodo hermano siguiente en el �ndice idx si tiene m�s de t-1 claves.
    void borrow_From_Next(int idx);

    // Fusiona el nodo hijo en el �ndice idx con su nodo hermano siguiente.
    void merge(int idx);


};