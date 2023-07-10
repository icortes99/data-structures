#pragma once
#include "Canton.h"

class NodeTAVL {
public:
    Canton* canton;
    NodeTAVL* left;
    NodeTAVL* right;
    int height;

    NodeTAVL();
    NodeTAVL(Canton*);
    ~NodeTAVL();
    NodeTAVL *&getLeft();
    NodeTAVL *&getRight();
    int getHeight();
    Canton* getCanton();
    void setCanton(Canton*);



  


};