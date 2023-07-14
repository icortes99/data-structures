#include "Provincia.h"

Provincia::Provincia(){

}
Provincia::~Provincia(){

}

void Provincia::setNombreProvincia(std::string pNombeProvincia){
    this->nombre_provincia = pNombeProvincia;

}

void Provincia::setCantidadCantones(int pCantidadCantones){
    this->cantidad_cantones = pCantidadCantones;

}

void Provincia::setTotalHabiatantes(int pTotalHabitantes){
    this->total_habitantes = pTotalHabitantes;
}
void Provincia::setCantones(NodeTAVL* pcantones){
    this->cantones = pcantones;

}

std::string Provincia::getNombreProvincia(){
    return this->nombre_provincia;

}

int Provincia::getCantidadCantones(){
    return this->cantidad_cantones;

}

int Provincia::getTotalHabiatantes(){
    return this->total_habitantes;

}
NodeTAVL* Provincia::getCantones(){
    return this->cantones;

}

