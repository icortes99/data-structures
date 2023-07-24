#include "NodeRB.h"
#include <iostream>

NodeRB::NodeRB(){
	this->provinciaCanton = "";
	this->codigoProvincia = 0;
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

NodeRB::NodeRB(std::string newProvinciaCanton, int codigo, Canton* cantonPtr){
	this->provinciaCanton = newProvinciaCanton;
	this->canton = cantonPtr;
	this->codigoProvincia = codigo;
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

NodeRB::~NodeRB(){
	
}

Canton* NodeRB::getCanton(){
	return this->canton;
}

std::string NodeRB::getProvinciaCanton(){
	return this->provinciaCanton;
}

int NodeRB::getCodigoProvincia(){
	return this->codigoProvincia;
}

NodeRB*& NodeRB::getLeft(){
	return this->left;
}

NodeRB*& NodeRB::getRight(){
	return this->right;
}

NodeRB*& NodeRB::getParent(){
	return this->parent;
}

bool NodeRB::getColor(){
	return this->color;
}

void NodeRB::setProvinciaCanton(std::string newProvinciaCanton,int codigo, Canton* cantonPtr){
	this->provinciaCanton = newProvinciaCanton;
	this->codigoProvincia = codigo;
	this->canton = cantonPtr;
}

void NodeRB::setLeft(NodeRB* newLeft){
	this->left = newLeft;
}

void NodeRB::setRight(NodeRB* newRight){
	this->right = newRight;
}

void NodeRB::setColor(bool newColor){
	this->color = newColor;
}

void NodeRB::setParent(NodeRB* newParent){
	this->parent = newParent;
}

void NodeRB::setRed(){
	this->color = true;
}

void NodeRB::setBlack(){
	this->color = false;
}

void NodeRB::printNode(){
	std::cout << "data: ";
	std::cout << this->provinciaCanton << endl;
}
