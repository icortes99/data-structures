#include "BTree.h"
#include <iostream>
// Insertion operation
BTree::BTree(int _t) : root(nullptr), t(_t) {}

BTree::BTree()
{
    root = NULL;
}

BTreeNode* BTree::getRoot() {
    return root;
}

void BTree::traverse()
{
    if (root != nullptr)
       // root->traverse();
        root->inOrderTraversalDesc();
}

void BTree::traverseCantProvPoblacionRefe(int poblacionReferencia)
{
    if (root != nullptr) {
        printHelper("San Jose");
        root->traverseCantProvPoblacionRefe(1, poblacionReferencia);
        cout << endl;

        printHelper("Alajuela");
        root->traverseCantProvPoblacionRefe(2, poblacionReferencia);
        cout << endl;

        printHelper("Cartago");
        root->traverseCantProvPoblacionRefe(3, poblacionReferencia);
        cout << endl;

        printHelper("Heredia");
        root->traverseCantProvPoblacionRefe(4, poblacionReferencia);
        cout << endl;

        printHelper("Guanacaste");
        root->traverseCantProvPoblacionRefe(5, poblacionReferencia);

        printHelper("Puntarenas");
        root->traverseCantProvPoblacionRefe(6, poblacionReferencia);
        cout << endl;

        printHelper("Limon");
        root->traverseCantProvPoblacionRefe(7, poblacionReferencia);
        cout << endl;
    }
}

void BTree::traverseCantProvPoblacion()
{
    if (root != nullptr) {
        printHelper("San Jose");
        root->traverseCantProvPoblacion(1);
        cout << endl;

        printHelper("Alajuela");
        root->traverseCantProvPoblacion(2);
        cout << endl;

        printHelper("Cartago");
        root->traverseCantProvPoblacion(3);
        cout << endl;

        printHelper("Heredia");
        root->traverseCantProvPoblacion(4);
        cout << endl;

        printHelper("Guanacaste");
        root->traverseCantProvPoblacion(5);

        printHelper("Puntarenas");
        root->traverseCantProvPoblacion(6);
        cout << endl;

        printHelper("Limon");
        root->traverseCantProvPoblacion(7);
        cout << endl;
    }      
}

void BTree::inOrderTraversalDesc(){

    root->inOrderTraversalDesc();
}

void BTree::printHelper(string provincia)
{
    cout << "\n----------------------------------" << endl;
    cout << "       " << provincia << endl;
    cout << "------------------------------------" << endl;
}


void BTree::ordenarCantPobxProvin(BTreeNode* nodoCanton, BTree* arbol, int idProvincia)
{

    if (nodoCanton == NULL)
        return;
}

BTreeNode *BTree::search(int key)
{
    if (root == nullptr)
        return nullptr;
    return root->search(key);
}

void BTree::insert(int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys.push_back(key);
        root->cantonPtrs.push_back(cantonPtr);
        root->provinciaCantonPtrs.push_back(provinciaCantonPtr);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* newRoot = new BTreeNode(t, false);
            newRoot->children.push_back(root);
            splitChild(newRoot, 0, root);
            insertNonFull(newRoot, key, cantonPtr, provinciaCantonPtr);
            root = newRoot;
        } else {
            insertNonFull(root, key, cantonPtr, provinciaCantonPtr);
        }
    }
}

void BTree::insertNonFull(BTreeNode* node, int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr) {
    int i = (int)node->keys.size() - 1;

    if (node->leaf) {
        node->keys.push_back(0);
        node->cantonPtrs.push_back(nullptr);
        node->provinciaCantonPtrs.push_back(nullptr);
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            node->cantonPtrs[i + 1] = node->cantonPtrs[i];
            node->provinciaCantonPtrs[i + 1] = node->provinciaCantonPtrs[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->cantonPtrs[i + 1] = cantonPtr;
        node->provinciaCantonPtrs[i + 1] = provinciaCantonPtr;
    } else {
        while (i >= 0 && node->keys[i] > key)
            i--;

        if (node->children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(node, i + 1, node->children[i + 1]);
            if (node->keys[i + 1] < key)
                i++;
        }
        insertNonFull(node->children[i + 1], key, cantonPtr, provinciaCantonPtr);
    }
}


void BTree::splitChild(BTreeNode* parentNode, int childIndex, BTreeNode* childNode) {
    BTreeNode* newNode = new BTreeNode(t, childNode->leaf);
    parentNode->keys.insert(parentNode->keys.begin() + childIndex, childNode->keys[t - 1]);
    parentNode->cantonPtrs.insert(parentNode->cantonPtrs.begin() + childIndex, childNode->cantonPtrs[t - 1]);
    parentNode->provinciaCantonPtrs.insert(parentNode->provinciaCantonPtrs.begin() + childIndex, childNode->provinciaCantonPtrs[t - 1]);
    parentNode->children.insert(parentNode->children.begin() + childIndex + 1, newNode);

    newNode->keys.assign(childNode->keys.begin() + t, childNode->keys.end());
    newNode->cantonPtrs.assign(childNode->cantonPtrs.begin() + t, childNode->cantonPtrs.end());
    newNode->provinciaCantonPtrs.assign(childNode->provinciaCantonPtrs.begin() + t, childNode->provinciaCantonPtrs.end());

    childNode->keys.resize(t - 1);
    childNode->cantonPtrs.resize(t - 1);
    childNode->provinciaCantonPtrs.resize(t - 1);
    childNode->children.resize(t);
}