#pragma once
#include "Canton.h"

class NodeTAVL {
public:
    Canton* canton;
    NodeTAVL* left;
    NodeTAVL* right;
    int height;
};