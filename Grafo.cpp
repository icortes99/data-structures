#include "Grafo.h"

Grafo::Grafo::Grafo(){
	inicializarGrafos();
}

void Grafo::inicializarGrafos(){

	std:ifstream inputFile("Grafo-lista-ady.txt");

	string canton1, canton2, line, pesoString;

	int peso;
	int contador = 0;

	if (inputFile.is_open()) {
		while (getline(inputFile, line)){
			contador++;

			stringstream ss(line);

			getline(ss, canton1, ',');
			getline(ss, canton2, ',');
			getline(ss, pesoString, ',');

			peso = std::stoi(pesoString);

			string llaveDiccionario = canton1 + "-" + canton2;

			for (auto& x : llaveDiccionario) {
				x = tolower(x);
			}

			if (contador <= 190) {
				this->sanjose.emplace(llaveDiccionario, peso);
			} else if (contador <= 295){
				this->alajuela.emplace(llaveDiccionario, peso);
			} else if (contador <= 323){
				this->cartago.emplace(llaveDiccionario, peso);
			} else if (contador <= 368) {
				this->heredia.emplace(llaveDiccionario, peso);
			} else if (contador <= 423) {
				this->guanacaste.emplace(llaveDiccionario, peso);
			} else if (contador <= 478) {
				this->puntarenas.emplace(llaveDiccionario, peso);
			} else {
				this->limon.emplace(llaveDiccionario, peso);
			}
		}
	}
}

void Grafo::imprimirGrafo(string provincia){
	map<string, int> print;

	for (auto& x : provincia) {
		x = tolower(x);
	}

	if (provincia == "sanjose" || provincia == "san jose") {
		print = this->sanjose;
	} else if (provincia == "alajuela") {
		print = this->alajuela;
	} else if (provincia == "cartago") {
		print = this->cartago;
	} else if (provincia == "heredia") {
		print = this->heredia;
	} else if (provincia == "guanacaste") {
		print = this->guanacaste;
	} else if (provincia == "puntarenas") {
		print = this->puntarenas;
	} else {
		print = this->limon;
	}

	for (const auto& par : print) {
		string llave = par.first;
		int peso = par.second;

		// Parsear la llave en 'canton1' y 'canton2'
		std::istringstream ss(llave);
		std::string canton1, canton2;
		std::getline(ss, canton1, '-');
		std::getline(ss, canton2, '-');

		// Imprimir 'canton1', 'canton2' y 'peso'
		std::cout << canton1 << ", " << canton2 << ", " << peso << std::endl;
	}
}

void Grafo::rutaMasCorta(string provincia){
	map<string, int> seleccionada;
	int peso = 99999;
	string llave = "";

	for (auto& x : provincia) {
		x = tolower(x);
	}

	if (provincia == "sanjose" || provincia == "san jose") {
		seleccionada = this->sanjose;
	} else if (provincia == "alajuela") {
		seleccionada = this->alajuela;
	} else if (provincia == "cartago") {
		seleccionada = this->cartago;
	} else if (provincia == "heredia") {
		seleccionada = this->heredia;
	} else if (provincia == "guanacaste") {
		seleccionada = this->guanacaste;
	} else if (provincia == "puntarenas") {
		seleccionada = this->puntarenas;
	} else {
		seleccionada = this->limon;
	}

	for (const auto& par : seleccionada) {
		int pesoA = par.second;

		if (peso > pesoA) {
			peso = pesoA;
			llave = par.first;
		}
	}

	//de la llave guardada imprimir del diccionario seleecionada
	std::istringstream ss(llave);
	string canton1, canton2;
	std::getline(ss, canton1, '-');
	std::getline(ss, canton2, '-');

	std::cout << "La ruta mas corta es del canton " << canton1 << " al canton " << canton2 << ", con una distancia de " << peso << std::endl;
}

void Grafo::redFibraOptica(string provincia){
}

void Grafo::cantonesVecinos(string provincia, string canton){
}
