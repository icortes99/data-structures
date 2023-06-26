#pragma once
#include <string>
#include <iostream>
using namespace std;

class CantonTxt {
private:
    int id_canton;
    string canton;
    string distrito;
    int provincia_id;
    string alcalde;
    int habitantes;

public:
    CantonTxt();
    CantonTxt(int, string, string, int, string, int);
    void set_id_canton(int);
    void set_canton(string);
    void set_distrito(string);
    void set_provincia_id(int);
    void set_alcalde(string);
    void set_habitantes(int);

    int get_id_canton();
    string get_canton();
    string get_distrito();
    int get_provincia_id();
    string get_alcalde();
    int get_habitantes();

    void imprimir();
    string obtenerProvincia(int);
};