#pragma once
#include "Provincia.h"
#include <string>
using namespace std;

class NodeRB {
private:
	Provincia* provincia;
	bool color; //color is either black = false, or red = true
	NodeRB* parent;
	NodeRB* left;
	NodeRB* right;

public:
	NodeRB();
	NodeRB(Provincia*);
	Provincia* getProvincia();
	NodeRB*& getLeft();
	NodeRB*& getRight();
	NodeRB*& getParent();
	bool getColor(); // black = false, or red = true

	void setProvincia(Provincia*);
	void setLeft(NodeRB *);
	void setRight(NodeRB *);
	void setColor(bool);
	void setParent(NodeRB*);
	void setRed(); //true
	void setBlack(); //false
	void printNode();
};