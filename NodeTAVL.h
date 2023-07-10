#pragma once
#include "Canton.h"

class NodeTAVL {
public:
    Canton* canton;
    NodeTAVL* left;
    NodeTAVL* right;
    int height;

    std::string get_canton_name(std::string);
    std::string get_canton_distrito(std::string);
    std::string get_canton_alcalde(std::string);
    int get_canton_habitantes(std::string);

    void edit_canton_distrito(std::string,std::string);
    void edit_canton_alcalde(std::string,std::string);
    void edit_canton_habitantes(std::string,int);

};