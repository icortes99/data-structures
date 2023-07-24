#pragma once
#include "Canton.h"
#include <string>
using namespace std;

class NodeRB {
private:
	Canton* canton;
	std::string provinciaCanton;
	int codigoProvincia;
	bool color; //color is either black = false, or red = true
	NodeRB* parent;
	NodeRB* left;
	NodeRB* right;

public:
	NodeRB();
	NodeRB(std::string,int,Canton*);
	~NodeRB();
	std::string getProvinciaCanton();
	int getCodigoProvincia();
	NodeRB*& getLeft();
	NodeRB*& getRight();
	NodeRB*& getParent();
	Canton* getCanton();
	bool getColor(); // black = false, or red = true
	
	void setProvinciaCanton(std::string,int,Canton*);
	void setLeft(NodeRB *);
	void setRight(NodeRB *);
	void setColor(bool);
	void setParent(NodeRB*);
	void setRed(); //true
	void setBlack(); //false
	void printNode();
};