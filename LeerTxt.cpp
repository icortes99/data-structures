#include "LeerTxt.h"

LeerTxt::LeerTxt(){
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
}

CantonTxt* LeerTxt::obtener_canton_id(int id){
    for (auto& canton : cantonList) {
        if (canton.get_id_canton() == id) {
            return &canton;
        }
    }
	return nullptr;
}