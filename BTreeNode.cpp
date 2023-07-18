#include "BTreeNode.h"
#include "NodeRB.h"
#include "Canton.h"
#include <iostream>

BTreeNode::BTreeNode(bool _leaf) : leaf(_leaf) {}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }

    if (!leaf)
        children[i]->traverse();
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
        i++;

    if (keys[i] == key)
        return this;

    if (leaf)
        return nullptr;

    return children[i]->search(key);
}

void BTreeNode::insert(int key, Canton* cantonPtr, NodeRB* provinciaCantonPtr) {
    int i = keys.size() - 1;
    if (leaf) {
        keys.push_back(0);
        cantonPtrs.push_back(nullptr);
        provinciaCantonPtrs.push_back(nullptr);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            cantonPtrs[i + 1] = cantonPtrs[i];
            provinciaCantonPtrs[i + 1] = provinciaCantonPtrs[i];
            i--;
        }
        keys[i + 1] = key;
        cantonPtrs[i + 1] = cantonPtr;
        provinciaCantonPtrs[i + 1] = provinciaCantonPtr;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insert(key, cantonPtr, provinciaCantonPtr);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
    cantonPtrs.insert(cantonPtrs.begin() + i, y->cantonPtrs[t - 1]);
    provinciaCantonPtrs.insert(provinciaCantonPtrs.begin() + i, y->provinciaCantonPtrs[t - 1]);
    y->keys.erase(y->keys.begin() + t - 1);
    y->cantonPtrs.erase(y->cantonPtrs.begin() + t - 1);
    y->provinciaCantonPtrs.erase(y->provinciaCantonPtrs.begin() + t - 1);
    children.insert(children.begin() + i + 1, z);
    z->keys.assign(y->keys.begin() + t, y->keys.end());
    z->cantonPtrs.assign(y->cantonPtrs.begin() + t, y->cantonPtrs.end());
    z->provinciaCantonPtrs.assign(y->provinciaCantonPtrs.begin() + t, y->provinciaCantonPtrs.end());
    y->keys.erase(y->keys.begin() + t, y->keys.end());
    y->cantonPtrs.erase(y->cantonPtrs.begin() + t, y->cantonPtrs.end());
    y->provinciaCantonPtrs.erase(y->provinciaCantonPtrs.begin() + t, y->provinciaCantonPtrs.end());

    if (!y->leaf) {
        z->children.assign(y->children.begin() + t, y->children.end());
        y->children.erase(y->children.begin() + t, y->children.end());
    }
}