#include "LeerTxt.h"

/*LeerTxt::LeerTxt() {
	ifstream file_("Cantones.txt");
    string line_;

    if (file_.is_open()) {
        while(getline(file_, line_)){
            istringstream iss(line_);
            int id, idProvincia, cantHabitantes;
            string nombre, distritoCabecera, nombreAlcalde;

            if (iss >> id >> nombre >> distritoCabecera >> idProvincia >> nombreAlcalde >> cantHabitantes) {
                CantonTxt obj(id, nombre, distritoCabecera, idProvincia, nombreAlcalde, cantHabitantes);
                this->cantonList.push_back(obj);
            }
        }
        file_.close();
    } else {
        cout << "File is not open";
    }
}*/

LeerTxt::LeerTxt() {
    std::ifstream inputFile("Cantones.txt");

    std::string id_canton, nombre, distrito, provincia_id, alcalde, habitantes;

    std::string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {

            stringstream ss(line);

            getline(ss, id_canton, ',');
            getline(ss, nombre, ',');
            getline(ss, provincia_id, ',');
            getline(ss, distrito, ',');
            getline(ss, alcalde, ',');
            getline(ss, habitantes, ',');

            Canton* canton = new Canton(stoi(id_canton), nombre, stoi(provincia_id), distrito, alcalde, stoi(habitantes));

        }
        inputFile.close();
    }
}

CantonTxt* LeerTxt::obtener_canton_id(int id){
    for (auto& canton : cantonList) {
        if (canton.get_id_canton() == id) {
            return &canton;
        }
    }
	return nullptr;
}