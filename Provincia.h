#pragma once
#include <string>
#include <iostream>
#include "NodeTAVL.h"
using namespace std;

class Provincia{
    private:
    std::string nombre_provincia;
    int cantidad_cantones;
    int total_habitantes;
    NodeTAVL* cantones;

    public:
    Provincia();
    ~Provincia();
    void setNombreProvincia(std::string);
    void setCantidadCantones(int);
    void setTotalHabiatantes(int);
    void setCantones(NodeTAVL*);

    std::string getNombreProvincia();
    int getCantidadCantones();
    int getTotalHabiatantes();
    NodeTAVL* getCantones();

};