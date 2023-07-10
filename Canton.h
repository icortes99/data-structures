#pragma once
#include <string>
#include <iostream>
using namespace std;

class Canton {
private:
    std::string nombre;
    std::string distrito;
    int provincia_id;
    std::string alcalde;
    int habitantes;

public:
    Canton( std::string nombre, int provincia_id, std::string distrito, std::string alcalde, int habitantes);
    void set_nombre(std::string nombre);
    void set_distrito(std::string distrito);
    void set_provincia_id(int provincia_id);
    void set_alcalde(std::string);
    void set_habitantes(int habitantes);

    std::string get_nombre();
    std::string get_distrito();
    int get_provincia_id();
    std::string get_alcalde();
    int get_habitantes();

    void imprimir();
    std::string obtenerProvincia(int);
};