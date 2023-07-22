#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iostream>
#include <locale> 
#include <unordered_map>
#include "Red_Black_tree.h"
#include "Tree_AVL.h"
#include "BTree.h"
#include "Canton.h"
void menu();


using namespace std;
Tree_AVL* lcantones = new Tree_AVL();
Red_Black_tree* lprovincia_canton = new Red_Black_tree();
BTree lpoblacion(7);


string nombre_canton, nombre_distrito, nombre_alcalde;
int cantidad_habitantes, modificar_opcion, main_choice, provincia_opcion;
bool exit_program = false;

std::string getProvincia(int id_provincia) {
    std::unordered_map<int, std::string> mappings = {
        {1, "SANJOSE"},
        {2, "ALAJUELA"},
        {3, "CARTAGO"},
        {4, "HEREDIA"},
        {5, "GUANACASTE"},
        {6, "PUNTARENAS"},
        {7, "LIMON"}
    };

    auto it = mappings.find(id_provincia);
    if (it != mappings.end()) {
        return it->second;
    }

    return "Unknown";
}

void leerCantones() {
    std::ifstream inputFile("Cantones.txt");

    std::string nombre, distrito, provincia_id, alcalde, habitantes, nombre_provincia, provinciaCanton;

    std::string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {

            stringstream ss(line);

            getline(ss, nombre, ',');
            getline(ss, provincia_id, ',');
            getline(ss, distrito, ',');
            getline(ss, alcalde, ',');
            getline(ss, habitantes, ',');
            
            Canton* canton = new Canton(nombre, stoi(provincia_id), distrito, alcalde, stoi(habitantes));

            nombre_provincia = getProvincia(stoi(provincia_id));
            provinciaCanton = nombre_provincia + "-" + nombre;
            NodeRB* aux = new NodeRB(provinciaCanton, canton);

            lcantones->add(canton);
            lprovincia_canton->add(aux);
            lpoblacion.insert(stoi(habitantes), canton, aux);
            cout << provinciaCanton << endl;            
        }
        inputFile.close();
    }
}

int readIntegerInput(std::string Text) {
    int input;
    while (true) {
        cout << Text;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato incorrecto. Por favor ingrese datos numericos unicamente ." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}


std::string toUpperCase(const std::string& str) {
    std::string result;
    std::locale loc;

    for (char ch : str) {
        result += std::toupper(ch, loc);
    }

    return result;
}



std::string readStringInput(std::string prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;

        std::getline(cin, input);

        if (input.empty()) {
            std::cout << "Este campo es requerido, no debe estar vacio, por favor ingresar la informacion requerida." << std::endl;
        }
        else {
            return toUpperCase(input);
        }
    }
}

void modificarDistrito()
{
   nombre_canton = readStringInput("Ingrese el nombre del canton");
   nombre_distrito = readStringInput("Ingrese el nuevo distrito");
   lcantones->editDistrito(nombre_canton,nombre_distrito);
}

void modificarAlcalde()
{
    nombre_canton = readStringInput("Ingrese el nombre del canton");
    nombre_alcalde = readStringInput("Ingrese el nombre del nuevo alcalde(sa)");
    lcantones->editAlcalde(nombre_canton,nombre_alcalde);
}

void modificarHabitantes()
{
    nombre_canton = readStringInput("Ingrese el nombre del canton");
    cantidad_habitantes = readIntegerInput("Ingrese la cantidad de habitantes que desea agregar ");
    lcantones->editHabitantes(nombre_canton,cantidad_habitantes);
}

void modificarCantonMenu() {
    while (!0)
    {
        cout << "----------------------------------" << endl;
        cout << "  Opciones de modificacion" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Modificar distrito " << endl;
        cout << "(2) Modificar alcalde   " << endl;
        cout << "(3) Modificar habitantes   " << endl;
        cout << "(0) Regresar" << endl;
        modificar_opcion = readIntegerInput("Seleccione una opcion -> ");
        cout << "===================================" << endl;


        switch (modificar_opcion) {
        case 1: {
            modificarDistrito();
            break;
        }
        case 2: {
            modificarAlcalde();
            break;
        }
        case 3: {
            modificarHabitantes();
            break;
        }
        case 0: {
            cout << "Regresando...." << endl;
            system("cls");
            menu();
            break;
        }
        default: {
            cout << "Opcion no valida..." << endl;
            cout << "\n\n";
            system("cls");
            break;
        }

        }
    }

}

void consultarProvincia() {
    cout << "----------------------------------" << endl;
    cout << "  Codigo de Provincia" << endl;
    cout << "----------------------------------" << endl;
    cout << "(1) San Jose " << endl;
    cout << "(2) Alajuela " << endl;
    cout << "(3) Cartago" << endl;
    cout << "(4) Heredia " << endl;
    cout << "(5) Guanacaste " << endl;
    cout << "(6) Puntarenas " << endl;
    cout << "(7) Limon " << endl;
    cout << "----------------------------------" << endl;
    provincia_opcion = readIntegerInput("Digite el numero de la provincia a consultar:  ");


    switch (provincia_opcion) {
    case 1: {
        lcantones->display();
        break;
    }
    case 2: {
        lcantones->display();
        break;
    }
    case 0: {
        cout << "Regresando...." << endl;
        system("cls");
        modificarCantonMenu();
        break;
    }
    default: {
        cout << "Opcion no valida..." << endl;
        cout << "\n\n";
        system("cls");
        break;
    }

    }

}

void consultarCanton(){
    
    nombre_canton = readStringInput("Ingrese el nombre del canton que desea consultar: ");

    lcantones->displayCanton(nombre_canton);
}

void mostrarCantones(){
    cout << "\n----------------------------------" << endl;
    cout << "     Lista de Cantones" << endl;
    cout << "----------------------------------" << endl;
    lcantones->display();
}

void mostarCantonPoblacion(){
    lpoblacion.traverse();
}

void mostrarProvinciasCantonesPoblacion() {
    cout << "\n----------------------------------" << endl;
    cout << "     Mostrar provincia y cantones por poblacion" << endl;
    cout << "----------------------------------" << endl;
    lpoblacion.traverseCantProvPoblacion();
}

//este es el 9
void mostrarProvinciasCantonesPoblacionRef() {
    int pobReferencia = 0;
    cout << "\n----------------------------------" << endl;
    cout << "     Mostrar provincia y cantones por poblacion de referencia" << endl;
    cout << "----------------------------------" << endl;
    cout << "Digite poblacion de referencia\n> " << endl;
    cin >> pobReferencia;
    lpoblacion.traverseCantProvPoblacionRefe(pobReferencia);
}

void menu() {
    while (!exit_program)
    {
        cout << "----------------------------------" << endl;
        cout << " Bienvenido a Registro Provincial  " << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Modificar canton " << endl;
        cout << "(2) Consultar provincia   " << endl;
        cout << "(3) Cosultar canton   " << endl;
        cout << "(4) Mostrar cantones de provincia  " << endl;
        cout << "(5) Mostrar todos los cantones  " << endl;
        cout << "(6) Mostrar detalle de cantones por provincia  " << endl;
        cout << "(7) Mostrar cantones por poblacion  " << endl;
        cout << "(8) Mostrar provincia y cantones por poblacion   " << endl;
        cout << "(9) Mostrar provincia y cantones por referencia  " << endl;
        cout << "(0) Finalizar" << endl;

        main_choice = readIntegerInput("Seleccione una opcion ->  ");
        cout << "===================================" << endl;


        switch (main_choice) {
        case 1: {
            modificarCantonMenu();
            break;
        }
        case 2: {
            consultarProvincia();
            break;
        }
         case 3: {
            consultarCanton();
            break;
        }
         case 4: {
            
            break;
        }
         case 5: {
            mostrarCantones();
            break;
        }
         case 7: {
            mostarCantonPoblacion();
            break;
        }

        case 8: {
            mostrarProvinciasCantonesPoblacion();
            break;
        }
        case 9: {
            mostrarProvinciasCantonesPoblacionRef();
            break;
        }
        case 0: {
            cout << "Finalizando el programa... ";
            exit_program = true;
            break;
        }
        default: {
            cout << "Opcion no valida..." << endl;
            cout << "\n\n";
            system("pause");
            system("cls");

        }

        }
    }

}


int main() {
    leerCantones();
    menu();
    return 0;
}