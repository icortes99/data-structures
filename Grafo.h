#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

class Grafo {
private:
	map<string, int> sanjose; //map = dictionary
	map<string, int> alajuela;
	map<string, int> cartago;
	map<string, int> heredia;
	map<string, int> guanacaste;
	map<string, int> puntarenas;
	map<string, int> limon;

public:
	Grafo();
	void inicializarGrafos();
	void imprimirGrafo(string provincia);
	void rutaMasCorta(string provincia);
	void redFibraOptica(string provincia);
	void cantonesVecinos(string provincia, string canton);
};