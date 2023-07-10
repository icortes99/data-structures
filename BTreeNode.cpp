#include "BTreeNode.h"
#include <iostream>
// Constructor para la clase BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1) {

    // Copie el grado mínimo dado y la propiedad de la hoja.
    t = t1;
    leaf = leaf1;

    // Asignar memoria para el número máximo de claves posibles
    // y punteros secundarios
    keys = new int[2 * t - 1]; // keys es un arreglo de enteros y tiene un tamaño de 2 * t - 1. Esto se debe a que un nodo puede tener como máximo 2t - 1 claves, según la definición de un árbol B. 
    C = new BTreeNode * [2 * t];//C es un arreglo de punteros a BTreeNode, y su tamaño también es 2 * t. Este arreglo almacena los punteros a los hijos del nodo actual. Como máximo, un nodo puede tener 2t hijos
    n = 0;
}

// Find the key
int BTreeNode::searchkey(int k) {
    int idx = 0;//Inicialice la variable idx a 0, que se usará como índice para iterar a través de las claves del nodo.
    while (idx < n && keys[idx] < k)// Ingrese un bucle while que continúe mientras el índice idx sea menor que el número de claves en el nodo (n) y el valor de la clave en el índice actual (claves[idx]) sea menor que la clave de destino k.
        ++idx;//Dentro del bucle, incremente el índice idx en 1 para pasar a la siguiente clave.
    return idx; //Una vez que finaliza el ciclo, devuelve el valor final del índice idx.Esto indica la posición en la que se debe insertar la clave de destino o la posición en la que se encontró la clave.
}

// Deletion operation
void BTreeNode::deletion(int k) {
    int idx = searchkey(k);//Primero, se llama al método searchkey(k) para obtener el índice idx donde se encuentra la clave k en el nodo.
    if (idx < n && keys[idx] == k) {//Se verifica si el índice idx es menor que el número de claves en el nodo (n) y si la clave en el índice idx es igual a k. Si se cumple esta condición, significa que la clave existe en el nodo y se procede a eliminarla.
        if (leaf)//Si el nodo es una hoja(leaf), se llama a la función remove_From_Leaf(idx) para eliminar la clave del nodo hoja.
            remove_From_Leaf(idx);
        else //Si el nodo no es una hoja, se llama a la función remove_From_Non_Leaf(idx) para eliminar la clave del nodo no hoja.
            remove_From_Non_Leaf(idx);
    }
    else {  // Si la clave no se encuentra en el nodo actual, se ejecuta el bloque else.

        if (leaf) {  //Si el nodo actual es una hoja, se muestra un mensaje indicando que la clave no existe en el árbol y se retorna.
            cout << "key " << k << " does not exist in the tree\n";
            return;
        }
        bool flag = ((idx == n) ? true : false); //Se verifica si el índice idx es igual al número de claves en el nodo (n). Si es así, se establece la variable flag en true, de lo contrario se establece en false.
        if (C[idx]->n < t)  //Se verifica si el número de claves en el hijo C[idx] es menor que el grado mínimo t del árbol. Si es así, se llama a la función fill(idx) para rellenar el hijo con claves adicionales.
            fill(idx);
        if (flag && idx > n)  //Si flag es true y el índice idx es mayor que n, se llama al método deletion(k) en el hijo anterior C[idx - 1].
            C[idx - 1]->deletion(k);
        else    //En caso contrario, se llama al método deletion(k) en el hijo siguiente C[idx].
            C[idx]->deletion(k);
    }
    return;
}

void BTreeNode::remove_From_Leaf(int idx) {
    // Recorre todas las claves a partir de idx + 1 hasta la última clave en el nodo
    for (int i = idx + 1; i < n; ++i) {
        // Mueve la clave en la posición i a la posición anterior i - 1
        keys[i - 1] = keys[i];
    }

    // Decrementa el número de claves en el nodo en una unidad, ya que se ha eliminado una clave
    n--;

    // Retorna del método
    return;
}



// Borrar de nodo No Hoja
void BTreeNode::remove_From_Non_Leaf(int idx) {
    // Obtiene la clave en la posición idx del nodo
    int k = keys[idx];

    if (C[idx]->n >= t) {
        // Si el hijo izquierdo tiene al menos t claves, encuentra el predecesor de k en ese hijo
        int pred = get_Predecessor(idx);

        // Reemplaza la clave en la posición idx con el predecesor encontrado
        keys[idx] = pred;

        // Elimina recursivamente el predecesor encontrado en el hijo izquierdo
        C[idx]->deletion(pred);
    }
    else if (C[idx + 1]->n >= t) {
        // Si el hijo derecho tiene al menos t claves, encuentra el sucesor de k en ese hijo
        int succ = get_Successor(idx);

        // Reemplaza la clave en la posición idx con el sucesor encontrado
        keys[idx] = succ;

        // Elimina recursivamente el sucesor encontrado en el hijo derecho
        C[idx + 1]->deletion(succ);
    }
    else {
        // Si tanto el hijo izquierdo como el hijo derecho tienen solo t-1 claves,
        // fusiona el hijo derecho con el hijo izquierdo en la posición idx
        merge(idx);

        // Elimina recursivamente la clave k del hijo fusionado
        C[idx]->deletion(k);
    }

    // Retorna del método
    return;
}

int BTreeNode::get_Predecessor(int idx) {
    // Obtiene el hijo más a la derecha del hijo izquierdo en la posición idx
    BTreeNode* cur = C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];

    // Retorna la clave más a la derecha del hijo más a la derecha
    return cur->keys[cur->n - 1];
}

int BTreeNode::get_Successor(int idx) {
    // Obtiene el hijo más a la izquierda del hijo derecho en la posición idx
    BTreeNode* cur = C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];

    // Retorna la clave más a la izquierda del hijo más a la izquierda
    return cur->keys[0];
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && C[idx - 1]->n >= t)
        // Si el hijo anterior tiene al menos t claves, realiza un préstamo desde el hijo anterior
        borrow_From_Prev(idx);
    else if (idx != n && C[idx + 1]->n >= t)
        // Si el siguiente hijo tiene al menos t claves, realiza un préstamo desde el siguiente hijo
        borrow_From_Next(idx);
    else {
        if (idx != n)
            // Si no es el último hijo, fusiona el hijo en la posición idx con el siguiente hijo
            merge(idx);
        else
            // Si es el último hijo, fusiona el hijo en la posición idx - 1 con el último hijo
            merge(idx - 1);
    }

    // Retorna del método
    return;
}

// Toma prestado del anterior
void BTreeNode::borrow_From_Prev(int idx) {
    // Obtiene el hijo en la posición idx y su hermano anterior
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx - 1];

    // Desplaza todas las claves en el hijo hacia la derecha para hacer espacio para la clave prestada
    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    // Si el hijo no es una hoja, también desplaza todos los punteros hacia la derecha
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    // Copia la clave en la posición idx - 1 del nodo actual al hijo en la posición idx
    child->keys[0] = keys[idx - 1];

    // Si el hijo no es una hoja, también copia el último puntero del hermano anterior al primer puntero del hijo
    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    // Reemplaza la clave en la posición idx - 1 del nodo actual con la última clave del hermano anterior
    keys[idx - 1] = sibling->keys[sibling->n - 1];

    // Incrementa el número de claves en el hijo y disminuye el número de claves en el hermano anterior
    child->n += 1;
    sibling->n -= 1;

    // Retorna del método
    return;
}




/// Borrow from the next
void BTreeNode::borrow_From_Next(int idx) {
    // Obtiene el hijo en la posición idx y su hermano siguiente
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    // Copia la clave en la posición idx del nodo actual al hijo en la posición child->n
    child->keys[(child->n)] = keys[idx];

    // Si el hijo no es una hoja, también copia el primer puntero del hermano siguiente al último puntero del hijo
    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];

    // Reemplaza la clave en la posición idx del nodo actual con la primera clave del hermano siguiente
    keys[idx] = sibling->keys[0];

    // Desplaza todas las claves en el hermano siguiente hacia la izquierda
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    // Si el hermano siguiente no es una hoja, también desplaza todos los punteros hacia la izquierda
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    // Incrementa el número de claves en el hijo y disminuye el número de claves en el hermano siguiente
    child->n += 1;
    sibling->n -= 1;

    // Retorna del método
    return;
}

// Merge
void BTreeNode::merge(int idx) {
    // Obtiene el hijo en la posición idx y su hermano siguiente
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    // Copia la clave en la posición idx del nodo actual al hijo en la posición t - 1
    child->keys[t - 1] = keys[idx];

    // Copia todas las claves del hermano siguiente al final del hijo
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + t] = sibling->keys[i];

    // Si el hijo no es una hoja, también copia todos los punteros del hermano siguiente al final del hijo
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }

    // Desplaza todas las claves en el nodo actual hacia la izquierda
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    // Desplaza todos los punteros en el nodo actual hacia la izquierda
    for (int i = idx + 2; i <= n; ++i)
        C[i - 1] = C[i];

    // Actualiza el número de claves en el hijo y en el nodo actual
    child->n += sibling->n + 1;
    n--;

    // Libera la memoria del hermano siguiente
    delete (sibling);

    // Retorna del método
    return;
}

// Insertar no lleno
void BTreeNode::insert_Non_Full(int k) {
    int i = n - 1;

    if (leaf == true) {
        // Si el nodo es una hoja, se busca la posición correcta para insertar la clave k
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        // Se inserta la clave k en la posición encontrada
        keys[i + 1] = k;
        n = n + 1;  // Se incrementa el contador de claves en el nodo
    }
    else {
        // Si el nodo no es una hoja, se busca el hijo adecuado para insertar la clave k
        while (i >= 0 && keys[i] > k)
            i--;

        // Verificar si el hijo seleccionado está lleno
        if (C[i + 1]->n == 2 * t - 1) {
            // Si el hijo está lleno, se realiza la división del hijo antes de insertar la clave
            split_Child(i + 1, C[i + 1]);

            // Determinar en qué subárbol insertar la clave después de la división
            if (keys[i + 1] < k)
                i++;
        }

        // Se realiza la llamada recursiva para insertar la clave en el subárbol correspondiente
        C[i + 1]->insert_Non_Full(k);
    }
}

// Dividir Hijo
void BTreeNode::split_Child(int i, BTreeNode* y) {
    // Crea un nuevo nodo z que será el hijo derecho de y
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copia las últimas t-1 claves de y a z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Si y no es una hoja, también copia los últimos t punteros de y a z
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce el número de claves en y
    y->n = t - 1;

    // Desplaza los punteros en el nodo actual hacia la derecha para hacer espacio para el nuevo hijo z
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // Inserta z como hijo del nodo actual
    C[i + 1] = z;

    // Desplaza las claves en el nodo actual hacia la derecha para hacer espacio para la clave mediana de y
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Copia la clave mediana de y al nodo actual
    keys[i] = y->keys[t - 1];

    // Incrementa el número de claves en el nodo actual
    n = n + 1;
}


// Traverse
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            // Si el nodo no es una hoja, recursivamente imprime las claves de los hijos
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        // Imprime las claves del último hijo si el nodo no es una hoja
        C[i]->traverse();
    cout << endl;
}