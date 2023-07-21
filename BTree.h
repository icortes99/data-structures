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
    void traverse();
    BTreeNode *search(int key);
    BTreeNode* getRoot();
    void insert(int key, Canton *cantonPtr, NodeRB *provinciaCantonPtr);
    void inOrderDesc();
     void inOrderTraversalDesc();

private:
    void insertNonFull(BTreeNode* node, int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr);
    void splitChild(BTreeNode* parentNode, int childIndex, BTreeNode* childNode);
};
