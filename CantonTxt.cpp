#include "CantonTxt.h"

CantonTxt::CantonTxt(){
	this->id_canton = 0;
	this->canton = "";
	this->distrito = "";
	this->provincia_id = 0;
	this->alcalde = "";
	this->habitantes = 0;
}

CantonTxt::CantonTxt(int id, string nombre, string distr, int idProvincia, string alcald, int cantHabitantes){
	this->id_canton = id;
	this->canton = nombre;
	this->distrito = distr;
	this->provincia_id = idProvincia;
	this->alcalde = alcald;
	this->habitantes = cantHabitantes;
}

void CantonTxt::set_id_canton(int id){
	this->id_canton = id;
}

void CantonTxt::set_canton(string canton){
	this->canton = canton;
}

void CantonTxt::set_distrito(string distrito){
	this->distrito = distrito;
}

void CantonTxt::set_provincia_id(int idprovincia){
	this->provincia_id = idprovincia;
}

void CantonTxt::set_alcalde(string alcalde){
	this->alcalde = alcalde;
}

void CantonTxt::set_habitantes(int habitantes){
	this->habitantes = habitantes;
}

int CantonTxt::get_id_canton(){
	return this->id_canton;
}

string CantonTxt::get_canton(){
	return this->canton;
}

string CantonTxt::get_distrito(){
	return this->distrito;
}

int CantonTxt::get_provincia_id(){
	return this->provincia_id;
}

string CantonTxt::get_alcalde(){
	return this->alcalde;
}

int CantonTxt::get_habitantes(){
	return this->habitantes;
}

void CantonTxt::imprimir(){
	cout << "Canton: " << this->canton << ", distrito cabecera: " << this->distrito << ", provincia: " << obtenerProvincia(this->provincia_id) << ", alcalde: " << this->alcalde << ", cantidad de habitantes: " << this->habitantes << endl;
}

string CantonTxt::obtenerProvincia(int idProvincia){
	switch (idProvincia){
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
