#include "BTree.h"
#include <iostream>
// Insertion operation
void BTree::insertion(int k) {
    if (root == NULL) {
        // Si el árbol está vacío, crea un nuevo nodo raíz y agrega la clave k
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            // Si el nodo raíz está lleno, realiza una división del nodo raíz
            BTreeNode* s = new BTreeNode(t, false);
            s->C[0] = root;
            s->split_Child(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;

            s->C[i]->insert_Non_Full(k);            // Determinar en qué subárbol insertar la clave después de la división
            root = s;       // Actualizar el nodo raíz
        }
        else
            // Si el nodo raíz no está lleno, simplemente inserta la clave en el árbol
            root->insert_Non_Full(k);
    }
}

// Delete Operation
void BTree::deletion(int k) {
    if (!root) {
        // Si el árbol está vacío, no se puede realizar la eliminación
        cout << "The tree is empty\n";
        return;
    }

    // Inicia la eliminación desde el nodo raíz
    root->deletion(k);

    if (root->n == 0) {
        // Si después de la eliminación el nodo raíz queda vacío, se actualiza la estructura del árbol
        BTreeNode* tmp = root;// Se almacena el nodo raíz en un puntero temporal
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];
        delete tmp;// Se libera la memoria del nodo raíz original
    }
    return;
}