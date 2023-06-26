#pragma once
#include <string>
#include <iostream>
using namespace std;

class Canton {
private:
    int id_canton;
    std::string nombre;
    std::string distrito;
    int provincia_id;
    std::string alcalde;
    int habitantes;

public:
    Canton(int id_canton, std::string nombre, int provincia_id, std::string distrito, std::string alcalde, int habitantes);
    void set_id_canton(int id_canton);
    void set_nombre(std::string nombre);
    void set_distrito(std::string distrito);
    void set_provincia_id(int provincia_id);
    void set_alcalde(std::string);
    void set_habitantes(int habitantes);

    int get_id_canton();
    string get_nombre();
    string get_distrito();
    int get_provincia_id();
    string get_alcalde();
    int get_habitantes();

    void imprimir();
    string obtenerProvincia(int);
};