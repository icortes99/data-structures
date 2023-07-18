#pragma once
#include "NodeRB.h"
#include "Canton.h"
using namespace std;

class BTreeNode
{
    bool leaf;
    std::vector<int> keys;
    std::vector<Canton*> cantonPtrs;
    std::vector<NodeRB*> provinciaCantonPtrs;
    std::vector<BTreeNode*> children;

public:
    BTreeNode(bool _leaf);
    void traverse();
    BTreeNode* search(int key);
    void insert(int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr);

private:
    void splitChild(int i, BTreeNode* y);
    friend class BTree;

};