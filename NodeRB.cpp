#include "NodeRB.h"
#include <iostream>

NodeRB::NodeRB(){
	this->key = 0;
	this->data = "";
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

NodeRB::NodeRB(int newKey, string newData){
	this->key = newKey;
	this->data = newData;
	this->color = false;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

string NodeRB::getData(){
	return this->data;
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

int NodeRB::getKey(){
	return this->key;
}

void NodeRB::setKey(int newKey){
	this->key = newKey;
}

void NodeRB::setData(string newData){
	this->data = newData;
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
	std::cout << "Key: ";
	std::cout << this->key;
	std::cout << ", data: ";
	std::cout << this->data;
	std::cout << "" << endl;
}
