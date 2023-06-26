#include "Canton.h"

Canton::Canton(int pid_canton, std::string pnombre, int pprovincia_id, std::string pdistrito, std::string palcalde, int phabitantes) {
	this->id_canton = pid_canton;
	this->nombre = pnombre;
	this->distrito = pdistrito;
	this->provincia_id = pprovincia_id;
	this->alcalde = palcalde;
	this->habitantes = phabitantes;
}

void Canton::set_id_canton(int pid_canton) {
	this->id_canton = pid_canton;
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

int Canton::get_id_canton() {
	return this->id_canton;
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
	cout << "Canton: " << this->nombre << ", distrito cabecera: " << this->distrito << ", provincia: " << obtenerProvincia(this->provincia_id) << ", alcalde: " << this->alcalde << ", cantidad de habitantes: " << this->habitantes << endl;
}

string Canton::obtenerProvincia(int idProvincia) {
	switch (idProvincia) {
	case 1:
		return "SanJose";
		break;
	case 2:
		return "Alajuela";
		break;
	case 3:
		return "Cartago";
		break;
	case 4:
		return "Heredia";
		break;
	case 5:
		return "Guanacaste";
		break;
	case 6:
		return "Puntarenas";
		break;
	case 7:
		return "Limon";
		break;
	default:
		return "Null";
		break;
	}
}