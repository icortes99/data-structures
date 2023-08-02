#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Grafo {
private:
	map<string, int> listaAdyacencia; //diccionario, se puede utilizar otra estructura en cambio

public:
	void agregarArista();
	void agregarVertice();
	int obtenerDistancia(string, string);
	vector<string> obtenerConexiones(); //retorna una lista de todas las conexiones
};