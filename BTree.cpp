#include "BTree.h"
#include <iostream>
// Insertion operation
BTree::BTree(int _t) : root(nullptr), t(_t) {}

void BTree::traverse()
{
    if (root != nullptr)
        root->traverse();
}

BTreeNode *BTree::search(int key)
{
    if (root == nullptr)
        return nullptr;
    return root->search(key);
}

void BTree::insert(int key, Canton *cantonPtr, NodeRB *provinciaCantonPtr)
{
    if (root == nullptr)
    {
        root = new BTreeNode(true);
        root->keys.push_back(key);
        root->cantonPtrs.push_back(cantonPtr);
        root->provinciaCantonPtrs.push_back(provinciaCantonPtr);
    }
    else
    {
        if (root->keys.size() == 2 * t - 1)
        {
            BTreeNode *newRoot = new BTreeNode(false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);
            int i = 0;
            if (newRoot->keys[0] < key)
                i++;
            newRoot->children[i]->insert(key, cantonPtr, provinciaCantonPtr);
            root = newRoot;
        }
        else
        {
            root->insert(key, cantonPtr, provinciaCantonPtr);
        }
    }
}