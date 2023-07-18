#pragma once
#include "Canton.h"
#include <string>
using namespace std;

class NodeRB {
private:
	Canton* canton;
	std::string provinciaCanton;
	bool color; //color is either black = false, or red = true
	NodeRB* parent;
	NodeRB* left;
	NodeRB* right;

public:
	NodeRB();
	NodeRB(std::string);
	~NodeRB();
	std::string getProvinciaCanton();
	NodeRB*& getLeft();
	NodeRB*& getRight();
	NodeRB*& getParent();
	bool getColor(); // black = false, or red = true
	
	void setProvinciaCanton(std::string);
	void setLeft(NodeRB *);
	void setRight(NodeRB *);
	void setColor(bool);
	void setParent(NodeRB*);
	void setRed(); //true
	void setBlack(); //false
	void printNode();
};