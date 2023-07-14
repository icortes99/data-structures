#include "NodeRB.h"
#include <iostream>

NodeRB::NodeRB(){
	this->provincia = NULL;
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

NodeRB::NodeRB(Provincia* newProvincia){
	this->provincia = newProvincia;
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

Provincia*NodeRB::getProvincia(){
	return this->provincia;
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

void NodeRB::setProvincia(Provincia* pProvincia){
	this->provincia = pProvincia;
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
	std::cout << this->provincia << endl;
}
