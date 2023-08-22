#include "Grafo.h"

Grafo::Grafo() {
	this->matrices["SAN JOSE"] = crearMatriz(20);
	this->matrices["ALAJUELA"] = crearMatriz(16);
	this->matrices["CARTAGO"] = crearMatriz(8);
	this->matrices["HEREDIA"] = crearMatriz(10);
	this->matrices["GUANACASTE"] = crearMatriz(11);
	this->matrices["PUNTARENAS"] = crearMatriz(13);
	this->matrices["LIMON"] = crearMatriz(6);
}

void Grafo::inicializarGrafos(vector<string>& cantones, string provincia) {

	std:ifstream inputFile("Conexiones.txt");

	string canton1, canton2, line, pesoString;

	int peso;

	if (inputFile.is_open()) {
		while (getline(inputFile, line)){
			int c1 = 99;
			int c2 = 99;

			stringstream ss(line);

			getline(ss, canton1, ',');
			getline(ss, canton2, ',');
			getline(ss, pesoString, ',');

			peso = std::stoi(pesoString);

			for (int i = 0; i < size(cantones); i++) {
				
				if (canton1 == cantones[i]) {
					c1 = i;

					for (int j = 0; j < size(cantones); j++) {
						if (canton2 == cantones[j]){
							c2 = j;
						}
					}
				}
			}

			if (c1 != 99 && c2 != 99) {
				this->matrices[provincia][c1][c2] = peso;
				this->matrices[provincia][c2][c1] = peso;
			}
		}
	}
}

int** Grafo::crearMatriz(int size) {
	int** matriz = new int* [size];
	for (int i = 0; i < size; ++i) {
		matriz[i] = new int[size];
		for (int j = 0; j < size; ++j) {
			matriz[i][j] = 0;  // Valores por defecto
		}
	}
	return matriz;
}

int* Grafo::crearPesos(int size){
	int* matriz = new int [size];
	for (int i = 0; i < size; ++i) {
		matriz[i] = 0;
	}
	return matriz;
}

void Grafo::imprimirGrafo(string provincia, int cant){
	int** arr = this->matrices[provincia];

	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < cant; j++) {

			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Grafo::redFibraOptica(string provincia, vector<string>& cantones) {
	int** arr = this->matrices[provincia];
	vector<int> agregados = {};
	vector<int> noAgregados = {};
	string concatPesos = "";
	vector<string> pesos = {};
	int menor = 999;
	int startX;
	int startY;

	for (int i = 0; i < size(cantones); i++) {
		//aun ningun vertice ha sido agregado al resultado
		noAgregados.push_back(i); //equivalente a canton id

		for (int j = 0; j < size(cantones); j++) {
			if (arr[i][j] < menor && arr[i][j] > 0) {
				menor = arr[i][j];
				startX = i;
				startY = j;
			}
		}
	}

	//definimos un punto de comienzo (el camino mas corto de todo el grafo)
	agregados.push_back(startX);
	agregados.push_back(startY);
	concatPesos = cantones[startX] + " - " + cantones[startY] + ", " + std::to_string(menor);
	pesos.push_back(concatPesos);

	//eliminamos los 2 primeros vertices ya agregados
	noAgregados.erase(std::remove(noAgregados.begin(), noAgregados.end(), startX), noAgregados.end());
	noAgregados.erase(std::remove(noAgregados.begin(), noAgregados.end(), startY), noAgregados.end());

	//con informacion inicializada, repetimos el proceso de comparacion hasta acabar los vertices
	while (size(noAgregados) > 0){
	
		menor = 999;
		startX = 99;
		startY = 99;

		//analizamos las posibilidades de cada nodo ya agregado
		for (int i = 0; i < size(agregados); i++) {

			//los comparamos contra los que aun no estan agregados, ya que no tiene sentido reevaluar los ya agregados
			for (int j = 0; j < size(noAgregados); j++) {
				if (arr[agregados[i]][noAgregados[j]] < menor && arr[agregados[i]][noAgregados[j]] > 0) {
					menor = arr[agregados[i]][noAgregados[j]];
				}
			}		
		}

		//buscamos el (x, y) del peso escogido para guardarlo
		for (int i = 0; i < size(cantones); i++) {
			for (int j = 0; j < size(cantones); j++) {
				if (arr[i][j] == menor) {
					//guardamos las coordenadas
					startX = i;
					startY = j;
				}
			}
		}

		cout << "x: " << startX << cantones[startX] << endl;
		cout << "y: " << startY << cantones[startY] << endl;

		//debemos validar cual de las 2 coordenadas no esta guardada (una de esas ya debe estar guardada)
		bool xAgregado = false;
		for (const int& w : agregados) {
			if (startX == w) {
				xAgregado = true;
			}
		}

		if (xAgregado == true) {
			agregados.push_back(startY);
			noAgregados.erase(std::remove(noAgregados.begin(), noAgregados.end(), startY), noAgregados.end());
		} else {
			agregados.push_back(startX);
			noAgregados.erase(std::remove(noAgregados.begin(), noAgregados.end(), startX), noAgregados.end());
		}
		
		concatPesos = cantones[startX] + " - " + cantones[startY] + ", " + std::to_string(menor);
		pesos.push_back(concatPesos);
	}

	//print de las conexiones dijkstra
	for (const std::string& str : pesos) {
		std::cout << str << endl;
	}
}