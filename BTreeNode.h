#pragma once
#include "NodeRB.h"
#include "Canton.h"
#include <vector>
using namespace std;

class BTree;
class BTreeNode
{
    bool leaf;
    std::vector<int> keys;
    std::vector<Canton*> cantonPtrs;
    std::vector<NodeRB*> provinciaCantonPtrs;
    std::vector<BTreeNode*> children;
    int t; 

public:
    BTreeNode(int _t, bool _leaf);
    void traverse();
    void traverseCantProvPoblacion(int codigoProvincia);
    void traverseCantProvPoblacionRefe(int codigoProvincia, int poblacionReferencia);
    void inOrderTraversalDesc();
    void traversalDesc(BTreeNode*);
    BTreeNode* search(int key);
    friend class BTree;
    std::string split(const std::string&, char);
    

};