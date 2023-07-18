#include "Canton.h"

Canton::Canton(std::string pnombre, int pprovincia_id, std::string pdistrito, std::string palcalde, int phabitantes) {
	this->nombre = pnombre;
	this->distrito = pdistrito;
	this->provincia_id = pprovincia_id;
	this->alcalde = palcalde;
	this->habitantes = phabitantes;
}

void Canton::set_nombre(std::string pnombre) {
	this->nombre = pnombre;
}

void Canton::set_distrito(std::string pdistrito) {
	this->distrito = pdistrito;
}

void Canton::set_provincia_id(int idprovincia) {
	this->provincia_id = idprovincia;
}

void Canton::set_alcalde(std::string palcalde) {
	this->alcalde = palcalde;
}

void Canton::set_habitantes(int phabitantes) {
	this->habitantes = phabitantes;
}

string Canton::get_nombre() {
	return this->nombre;
}

string Canton::get_distrito() {
	return this->distrito;
}

int Canton::get_provincia_id() {
	return this->provincia_id;
}

string Canton::get_alcalde() {
	return this->alcalde;
}

int Canton::get_habitantes() {
	return this->habitantes;
}

void Canton::imprimir() {
	cout << "Canton: " << this->nombre << ", distrito cabecera: " << this->distrito << ", provincia: " << ", alcalde: " << this->alcalde << ", cantidad de habitantes: " << this->habitantes << endl;
}
