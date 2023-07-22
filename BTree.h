#pragma once
#include "BTreeNode.h"
#include "NodeRB.h"
#include "Canton.h"
#include <cstddef>
using namespace std;
// Un BTree
class BTree
{
    BTreeNode *root;
    int t;

public:
    BTree(int _t);
    BTree();
    void traverse();
    void traverseCantProvPoblacion();
    BTreeNode *search(int key);
    BTreeNode* getRoot();
    void insert(int key, Canton *cantonPtr, NodeRB *provinciaCantonPtr);
    void inOrderDesc();
     void inOrderTraversalDesc();

     void printHelper(string provincia);

     //Nuevos para Cantones
     void displayProvinciasCantonesPoblacion();
     void displayProvCantxPoblaRef(int pobReferencia);

     void ordenarCantPobxProvin(BTreeNode* nodoCanton, BTree* arbol, int idProvincia);
     void ordenarCantProvxPobRef(BTreeNode* nodoCanton, BTree* arbol, int idProvincia, int pobReferencia);

private:
    void insertNonFull(BTreeNode* node, int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr);
    void splitChild(BTreeNode* parentNode, int childIndex, BTreeNode* childNode);

    //Nuevos para cantones 
    void addOrdenPoblacion(Canton*);
    BTreeNode* insertOrdenPoblacion(Canton*, BTreeNode*);
};
