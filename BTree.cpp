#include "BTree.h"
#include <iostream>
// Insertion operation
void BTree::insertion(int k) {
    if (root == NULL) {
        // Si el �rbol est� vac�o, crea un nuevo nodo ra�z y agrega la clave k
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            // Si el nodo ra�z est� lleno, realiza una divisi�n del nodo ra�z
            BTreeNode* s = new BTreeNode(t, false);
            s->C[0] = root;
            s->split_Child(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;

            s->C[i]->insert_Non_Full(k);            // Determinar en qu� sub�rbol insertar la clave despu�s de la divisi�n
            root = s;       // Actualizar el nodo ra�z
        }
        else
            // Si el nodo ra�z no est� lleno, simplemente inserta la clave en el �rbol
            root->insert_Non_Full(k);
    }
}

// Delete Operation
void BTree::deletion(int k) {
    if (!root) {
        // Si el �rbol est� vac�o, no se puede realizar la eliminaci�n
        cout << "The tree is empty\n";
        return;
    }

    // Inicia la eliminaci�n desde el nodo ra�z
    root->deletion(k);

    if (root->n == 0) {
        // Si despu�s de la eliminaci�n el nodo ra�z queda vac�o, se actualiza la estructura del �rbol
        BTreeNode* tmp = root;// Se almacena el nodo ra�z en un puntero temporal
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];
        delete tmp;// Se libera la memoria del nodo ra�z original
    }
    return;
}