#pragma once
#include <string>
using namespace std;

class NodeRB {
private:
	int key; //the key is like the ID, it's used for adding and deleting the whole node
	string data; //it's needed for saving information, the object could have more attributes
	bool color; //color is either black = false, or red = true
	NodeRB* parent;
	NodeRB* left;
	NodeRB* right;

public:
	NodeRB();
	NodeRB(int, string);
	string getData();
	NodeRB*& getLeft();
	NodeRB*& getRight();
	NodeRB*& getParent();
	bool getColor(); // black = false, or red = true
	int getKey();

	void setKey(int);
	void setData(string);
	void setLeft(NodeRB *);
	void setRight(NodeRB *);
	void setColor(bool);
	void setParent(NodeRB*);
	void setRed(); //true
	void setBlack(); //false
	void printNode();
};