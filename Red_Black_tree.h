#pragma once
#include "NodeRB.h"

class Red_Black_tree {
private:
	NodeRB* root;
	
	//Recursive operations, strictly internal
	void addNode(NodeRB*, NodeRB*);
	void organize();
	void rotateLeft(NodeRB*);
	void rotateRight(NodeRB*);
	void replaceNode(NodeRB*, NodeRB*);
	void deleteAdjustment(NodeRB*, NodeRB*, bool);
	NodeRB* findSuccessor(NodeRB*);
	void printInOrder(NodeRB*);
	void printInOrderProvinciaId(NodeRB*);
	void printProvinciaCantones(NodeRB*,std::string);
	int totalCantones(NodeRB*,std::string);
	int totalHabitantes(NodeRB*,std::string);
	std::string split(const std::string&, char);
	void printProvinciaCantonInfo(NodeRB*,int);

public:
	Red_Black_tree();
	NodeRB*& getRoot();
	void setRoot(NodeRB*);

	bool isEmpty();
	void add(NodeRB*);
	void printProvincia(std::string);
	void printInfoProvincia(std::string);
	void printProvinciaDescend();
	void printProvinciaAsced();
	NodeRB* find(std::string,NodeRB*);
};