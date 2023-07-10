#pragma once
using namespace std;


class BTreeNode {
    int* keys;  // Un array de llaves, valor almacenado en el nodo
    int t;      // Grado mínimo (define el rango para el número de claves)
    BTreeNode** C; // Un array de punteros children del nodo, osea los que van hacia abajo
    int n;     // Numero actual de llaves
    bool leaf; // Es verdadero cuando el nodo es hoja. De lo contrario falso
public:
    BTreeNode(int _t, bool _leaf);// Constructor
    void traverse();// Una función para recorrer todos los nodos en un subárbol enraizado con este nodo
    int searchkey(int k);
    void insert_Non_Full(int k);// Una función de utilidad para insertar una nueva clave en el subárbol enraizado con
    // este nodo. La suposición es que el nodo no debe estar lleno cuando esto
    // se llama a la funcion

    void split_Child(int i, BTreeNode* y);// Una función de utilidad para dividir el hijo 'y' de este nodo. i es índice de 'y' en
    // matriz secundaria C[]. El niño y debe estar lleno cuando se llama a esta función

    void deletion(int k);// borrar un valor del arbol
    void remove_From_Leaf(int idx); //borrar de una hoja
    void remove_From_Non_Leaf(int idx);//borrar de un nodo no hoja

    // Devuelve la clave del predecesor del índice idx dentro del nodo actual.
    int get_Predecessor(int idx);

    // Devuelve la clave del sucesor del índice idx dentro del nodo actual.
    int get_Successor(int idx);

    // Rellena el nodo hijo en el índice idx si tiene menos de t claves.
    void fill(int idx);

    // Toma prestada una clave del nodo hermano anterior en el índice idx si tiene más de t-1 claves.
    void borrow_From_Prev(int idx);

    // Toma prestada una clave del nodo hermano siguiente en el índice idx si tiene más de t-1 claves.
    void borrow_From_Next(int idx);

    // Fusiona el nodo hijo en el índice idx con su nodo hermano siguiente.
    void merge(int idx);

    // Permite que la clase BTree acceda a los miembros privados de la clase BTreeNode.
    friend class BTree;
};