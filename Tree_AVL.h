#pragma once
#include "NodeTAVL.h"

class Tree_AVL {
public:
	Tree_AVL();
	~Tree_AVL();

	/*Operations*/
	void add(Canton*);
	void display();
	int height(NodeTAVL*);
	NodeTAVL*& getRoot();
	void setRoot(NodeTAVL*);
	void displayCanton(std::string pnombre);
	void editDistrito(std::string ,std::string);
	void editAlcalde(std::string,std::string);
	void editHabitantes(std::string,int);


private:

	NodeTAVL* root;
	NodeTAVL* left;
	NodeTAVL* right;

	/*Basics*/
	NodeTAVL* insert(Canton*, NodeTAVL*);
	void makeEmpty(NodeTAVL*);
	int getBalance(NodeTAVL*);
	void inorder(NodeTAVL*);
	NodeTAVL* searchCanton(NodeTAVL*,std::string );
	
	/*Recursive Operations*/
	NodeTAVL* singleRightRotate(NodeTAVL*&);
	NodeTAVL* singleLeftRotate(NodeTAVL*&);
	NodeTAVL* doubleLeftRotate(NodeTAVL*&);
	NodeTAVL* doubleRightRotate(NodeTAVL*&);
	NodeTAVL* findMin(NodeTAVL*);
	NodeTAVL* findMax(NodeTAVL*);


};