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
    void insert(int key, Canton *cantonPtr, NodeRB *provinciaCantonPtr);

private:
    //
};
