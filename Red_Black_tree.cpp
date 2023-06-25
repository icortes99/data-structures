#include "Red_Black_tree.h"
#include <iostream>
using namespace std;

Red_Black_tree::Red_Black_tree(){
	this->root = NULL;
}

NodeRB*& Red_Black_tree::getRoot(){
	return this->root;
}

void Red_Black_tree::setRoot(NodeRB* newRoot){
	this->root = newRoot;
}

bool Red_Black_tree::isEmpty(){
	if (getRoot() == NULL){
		return true;
	}
	return false;
}

void Red_Black_tree::add(NodeRB* newNode){
	addNode(newNode, this->root);
	organize();
}

void Red_Black_tree::remove(int removeKey){
	deleteNode(removeKey, this->root);
	organize();
}

void Red_Black_tree::addNode(NodeRB* newNode, NodeRB* tree_root){
	if (tree_root == nullptr) {
		setRoot(newNode);
	}
	else {
		if (newNode->getKey() == tree_root->getKey()) {
			cout << "Key already exists" << endl;
		}
		else if (newNode->getKey() < tree_root->getKey()) {
			if (tree_root->getLeft() == nullptr) {
				tree_root->setLeft(newNode);
				newNode->setParent(tree_root);
			}
			else {
				addNode(newNode, tree_root->getLeft());
			}
		}
		else {
			if (tree_root->getRight() == nullptr) {
				tree_root->setRight(newNode);
				newNode->setParent(tree_root);
			}
			else {
				addNode(newNode, tree_root->getRight());
			}
		}
	}
}

void Red_Black_tree::deleteNode(int key_to_delete, NodeRB* tree_root){
	if (tree_root == nullptr) {
		cout << "Key not found" << endl;
		return;
	}

	NodeRB* node = find(key_to_delete, tree_root);

	if (node == nullptr) {
		cout << "Key not found" << endl;
		return;
	}

	NodeRB* child = nullptr;
	NodeRB* parent = nullptr;
	bool is_left_child = false;

	if (node->getLeft() != nullptr && node->getRight() != nullptr) {
		NodeRB* predecessor = findSuccessor(node);
		node->setKey(predecessor->getKey());
		node = predecessor;
	}

	if (node->getLeft() != nullptr) {
		child = node->getLeft();
	}
	else {
		child = node->getRight();
	}

	parent = node->getParent();

	if (parent == nullptr) {
		setRoot(child);
	}
	else {
		if (node == parent->getLeft()) {
			parent->setLeft(child);
			is_left_child = true;
		}
		else {
			parent->setRight(child);
			is_left_child = false;
		}
	}

	if (child != nullptr) {
		child->setParent(parent);
	}

	if (!node->getColor()) {
		if (child != nullptr && child->getColor()) {
			child->setBlack();
		}
		else {
			deleteAdjustment(child, parent, is_left_child);
		}
	}

	delete node;
}

void Red_Black_tree::organize(){
	if (getRoot() == nullptr) {
		return;
	}

	NodeRB* node = getRoot();
	NodeRB* parent = nullptr;
	NodeRB* grandParent = nullptr;

	//if father and grandfater are red, then we have to re-organize the colors's tree
	//no pueden existir 2 nodos rojos (true) consecutivos, validamos si existen para reorganizar los colores
	while (node != nullptr && node->getColor() && node->getParent()->getColor()) {
		parent = node->getParent();
		grandParent = parent->getParent();

		//si el padre es el hijo izquiero del abuelo (solo puede ser izquierdo o derecho)
		if (parent == grandParent->getLeft()) {
			NodeRB* uncle = grandParent->getRight();

			//caso 1: el tio es rojo
			if (uncle != nullptr && uncle->getColor()) {
				parent->setBlack();
				uncle->setBlack();
				grandParent->setRed();
				node = grandParent;
			}
			else {
				//caso 2: el tio es negro y el nodo es el hijo derecho
				if (node == parent->getRight()) {
					rotateLeft(parent);
					node = parent;
					parent = node->getParent();
				}

				rotateRight(grandParent);
				//Intercambiar colores
				bool tempColor = parent->getColor();
				parent->setColor(grandParent->getColor());
				grandParent->setColor(tempColor);
				node = parent;
			}
		}
		else {
			NodeRB* uncle = grandParent->getLeft();

			if (uncle != nullptr && uncle->getColor()) {
				parent->setBlack();
				uncle->setBlack();
				grandParent->setRed();
				node = grandParent;
			}
			else {
				if (node == parent->getLeft()) {
					rotateRight(parent);
					node = parent;
					parent = node->getParent();
				}

				rotateLeft(grandParent);
				bool tempColor = parent->getColor();
				parent->setColor(grandParent->getColor());
				grandParent->setColor(tempColor);
				node = parent;
			}
		}
	}

	getRoot()->setBlack();
}

void Red_Black_tree::rotateLeft(NodeRB* rotateNode){
	NodeRB* rightChild = rotateNode->getRight();
	rotateNode->setRight(rightChild->getLeft());

	if (rightChild->getLeft() != nullptr) {
		rightChild->getLeft()->setParent(rotateNode);
	}

	rightChild->setParent(rotateNode->getParent());

	if (rotateNode->getParent() != nullptr) {
		if (rotateNode == rotateNode->getParent()->getLeft()) {
			rotateNode->getParent()->setLeft(rightChild);
		} else {
			rotateNode->getParent()->setRight(rightChild);
		}
	} else {
		setRoot(rightChild);
	}

	rightChild->setLeft(rotateNode);
	rotateNode->setParent(rightChild);
}

void Red_Black_tree::rotateRight(NodeRB* rotateNode){
	NodeRB* leftChild = rotateNode->getLeft();
	rotateNode->setLeft(leftChild->getRight());

	if (leftChild->getRight() != nullptr) {
		leftChild->getRight()->setParent(rotateNode);
	}

	leftChild->setParent(rotateNode->getParent());

	if (rotateNode->getParent() == nullptr) {
		if (rotateNode == rotateNode->getParent()->getRight()) {
			rotateNode->getParent()->setRight(leftChild);
		} else {
			rotateNode->getParent()->setLeft(leftChild);
		}
	} else {
		setRoot(leftChild);
	}

	leftChild->setRight(rotateNode);
	rotateNode->setParent(leftChild);
}

void Red_Black_tree::replaceNode(NodeRB* node_to_replace, NodeRB* replacement_node){
	NodeRB* parent = node_to_replace->getParent();

	if (parent == nullptr) {
		setRoot(replacement_node);
	} else if (node_to_replace == parent->getLeft()) {
		parent->setLeft(replacement_node);
	} else {
		parent->setRight(replacement_node);
	}

	if (replacement_node != nullptr) {
		replacement_node->setParent(parent);
	}
}

void Red_Black_tree::deleteAdjustment(NodeRB* node, NodeRB* parent, bool is_left_child){
	NodeRB* sibling;

	while (node != getRoot() && (node == nullptr || !node->getColor())) {
		if (is_left_child) {
			sibling = parent->getRight();

			if (sibling != nullptr && sibling->getColor()) {
				sibling->setBlack();
				parent->setRed();
				rotateLeft(parent);
				sibling = parent->getRight();
			}

			if ((sibling == nullptr || sibling->getLeft() == nullptr || !sibling->getLeft()->getColor()) && (sibling == nullptr || sibling->getRight() == nullptr || !sibling->getRight()->getColor())) {
				if (sibling != nullptr)
					sibling->setRed();
				node = parent;
				parent = node->getParent();
				if (parent != nullptr)
					is_left_child = (node == parent->getLeft());
				else
					is_left_child = false;
			}
			else {
				if (sibling == nullptr || sibling->getRight() == nullptr || !sibling->getRight()->getColor()) {
					if (sibling != nullptr && sibling->getLeft() != nullptr)
						sibling->getLeft()->setBlack();
					if (sibling != nullptr)
						sibling->setRed();
					rotateRight(sibling);
					sibling = parent->getRight();
				}

				if (sibling != nullptr) {
					sibling->setColor(parent->getColor());
					if (parent != nullptr)
						parent->setBlack();
					if (sibling->getRight() != nullptr)
						sibling->getRight()->setBlack();
					rotateLeft(parent);
				}
				node = getRoot();
				break;
			}
		}
		else {
			sibling = parent->getLeft();

			if (sibling != nullptr && sibling->getColor()) {
				sibling->setBlack();
				parent->setRed();
				rotateRight(parent);
				sibling = parent->getLeft();
			}

			if ((sibling == nullptr || sibling->getRight() == nullptr || !sibling->getRight()->getColor()) && (sibling == nullptr || sibling->getLeft() == nullptr || !sibling->getLeft()->getColor())) {
				if (sibling != nullptr)
					sibling->setRed();
				node = parent;
				parent = node->getParent();
				if (parent != nullptr)
					is_left_child = (node == parent->getLeft());
				else
					is_left_child = false;
			}
			else {
				if (sibling == nullptr || sibling->getLeft() == nullptr || !sibling->getLeft()->getColor()) {
					if (sibling != nullptr && sibling->getRight() != nullptr)
						sibling->getRight()->setBlack();
					if (sibling != nullptr)
						sibling->setRed();
					rotateLeft(sibling);
					sibling = parent->getLeft();
				}

				if (sibling != nullptr) {
					sibling->setColor(parent->getColor());
					if (parent != nullptr)
						parent->setBlack();
					if (sibling->getLeft() != nullptr)
						sibling->getLeft()->setBlack();
					rotateRight(parent);
				}
				node = getRoot();
				break;
			}
		}
	}

	if (node != nullptr) {
		node->setBlack();
	}
}

NodeRB* Red_Black_tree::findSuccessor(NodeRB* node){
	if (node->getRight() != nullptr) {
		NodeRB* successor = node->getRight();
		while (successor->getLeft() != nullptr) {
			successor = successor->getLeft();
		}
		return successor;
	}
	else {
		NodeRB* current = node;
		NodeRB* parent = current->getParent();

		while (parent != nullptr && current == parent->getRight()) {
			current = parent;
			parent = parent->getParent();
		}

		return parent;
	}
}

void Red_Black_tree::printInOrder(NodeRB* node){
	if (node == nullptr) {
		return;
	}

	printInOrder(node->getLeft());
	cout << node->getKey() << " ";
	printInOrder(node->getRight());
}

void Red_Black_tree::printTree(){
	if (isEmpty()) {
		cout << "Tree is empty." << endl;
		return;
	}

	cout << "Tree elements in ascending order: ";
	printInOrder(root);
	cout << endl;
}

NodeRB* Red_Black_tree::find(int keyNode, NodeRB* tree_root){
	if (tree_root == nullptr) {
		return nullptr;
	}

	if (keyNode == tree_root->getKey()) {
		return tree_root;
	}
	else if (keyNode < tree_root->getKey()) {
		return find(keyNode, tree_root->getLeft());
	}
	else {
		return find(keyNode, tree_root->getRight());
	}
}