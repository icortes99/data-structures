#include "BTreeNode.h"
#include "BTree.h"
#include "NodeRB.h"
#include "Canton.h"
#include <iostream>

BTreeNode::BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

std::string BTreeNode::split(const std::string& input, char delimiter){
    size_t pos = input.find(delimiter);
    if (pos != std::string::npos) {
        return input.substr(0, pos);
    }
    return input;

}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        std::cout << "Poblacion: " << keys[i]<< endl;
        std::cout << "Canton: " << cantonPtrs[i]->get_nombre() << endl;
        std::cout << "Provincia: " << split(provinciaCantonPtrs[i]->getProvinciaCanton(), '-')<< endl; 
        std::cout << "ID Prov: " << cantonPtrs[i]->get_provincia_id() << endl;
        std::cout << endl;
    }

    if (!leaf)
        children[i]->traverse();
}

void BTreeNode::traverseCantProvPoblacion(int codigoProvincia) {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverseCantProvPoblacion(codigoProvincia);
        if (codigoProvincia == cantonPtrs[i]->get_provincia_id()) {
            std::cout << "Poblacion: " << keys[i] << endl;
            std::cout << "Canton: " << cantonPtrs[i]->get_nombre() << endl;
            std::cout << "Provincia: " << split(provinciaCantonPtrs[i]->getProvinciaCanton(), '-') << endl;
            std::cout << "ID Prov: " << cantonPtrs[i]->get_provincia_id() << endl;
            std::cout << endl;
        }

        }

        if (!leaf)
            children[i]->traverseCantProvPoblacion(codigoProvincia);
}

void BTreeNode::traverseCantProvPoblacionRefe(int codigoProvincia, int poblacionReferencia) {
    int i;
    for (i = keys.size() - 1; i >= 0; i--) {
        if (!leaf)
            children[i + 1]->traverseCantProvPoblacionRefe(codigoProvincia, poblacionReferencia);
        if (codigoProvincia == cantonPtrs[i]->get_provincia_id() && cantonPtrs[i]->get_habitantes() >= poblacionReferencia) {
            std::cout << "Poblacion: " << keys[i] << std::endl;
            std::cout << "Canton: " << cantonPtrs[i]->get_nombre() << std::endl;
            std::cout << "Provincia: " << split(provinciaCantonPtrs[i]->getProvinciaCanton(), '-') << std::endl;
            std::cout << "ID Prov: " << cantonPtrs[i]->get_provincia_id() << std::endl;
            std::cout << std::endl;
        }
    }

    if (!leaf)
        children[i + 1]->traverseCantProvPoblacionRefe(codigoProvincia, poblacionReferencia);
}



void BTreeNode::inOrderTraversalDesc() {
    int i;
    for (i = (int)keys.size() - 1; i >= 0; i--) {
        if (!leaf)
            children[i + 1]->inOrderTraversalDesc(); // Visit the right child first
        std::cout << "Canton: " << cantonPtrs[i]->get_nombre() << std::endl;
        std::cout << "Poblacion: " << keys[i] << std::endl;
        std::cout << std::endl;
    }

    // Visit the last right child if it exists
    if (!leaf)
        children[i + 1]->inOrderTraversalDesc();
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
