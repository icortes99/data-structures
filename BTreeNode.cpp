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

    //if (codigoProvincia == cantonPtrs[i - 1]->get_provincia_id()) {
        if (!leaf)
            children[i]->traverseCantProvPoblacion(codigoProvincia);
    //}
}


void BTreeNode::inOrderTraversalDesc() {
    int i;
    for (i = (int)keys.size()-1; i >= 0; i--) {
        if (!leaf)
            children[i]->inOrderTraversalDesc();
        std::cout << "Canton: " << cantonPtrs[i]->get_nombre() << endl;
        std::cout << "Poblacion: " << keys[i]<< endl;
        std::cout<< endl;
    }

    if (!leaf)
        children[i]->inOrderTraversalDesc();
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

