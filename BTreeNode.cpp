#include "BTreeNode.h"
#include "BTree.h"
#include "NodeRB.h"
#include "Canton.h"
#include <iostream>

BTreeNode::BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

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

