#include "NodeTAVL.h"


NodeTAVL::~NodeTAVL(){

}

NodeTAVL::NodeTAVL(){
    this->canton = NULL;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;
}

NodeTAVL::NodeTAVL(Canton* pcanton){
    this->canton = pcanton;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;
}

int NodeTAVL::getHeight(){
    return this->height;

}

NodeTAVL*& NodeTAVL::getLeft(){
    return this->left;

}
NodeTAVL*& NodeTAVL::getRight(){
    return this->right;

}

Canton* NodeTAVL::getCanton(){
    return this->canton;

}




