#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip> 
using namespace std;

class Grafo {
private:
	map<string, int**> matrices;

	/* int matrizSanJose[20][20];
	int matrizAlajuela[16][16];
	int matrizCartago[8][8];
	int matrizHeredia[10][10];
	int matrizGuanacaste[11][11];
	int matrizPuntarenas[13][13];
	int matrizLimon[6][6];*/

	//int numNodos;
	//vector<vector<int>> matrizAdyacencia;
	//map<string, int> nodoIndice;

public:
	Grafo();

	//void agregarNodos(const std::vector<std::string>& nodos);

	//void agregarArista(const std::string&, const std::string&, int);

	//int minDistancia(const std::vector<int>&, const std::vector<bool>&);

	//void encontrarRutaCorta(const std::string& inicio, const std::string& destino);
	
	//void mostrarGrafo();

	void inicializarGrafos(vector<string>& cantones, string provincia);
	
	int** crearMatriz(int size);

	int* crearPesos(int size);

	void imprimirGrafo(string provincia, int cant);

	void redFibraOptica(string provincia, vector<string>& cantones);
	
	//void rutaMasCorta(string provincia);
	//void cantonesVecinos(string provincia, string canton);
};