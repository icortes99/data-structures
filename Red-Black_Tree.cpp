#include <iostream>
#include <fstream>
#include <string>
#include "Red_Black_tree.h"
#include "LeerTxt.h"
using namespace std;

int main(){
    Red_Black_tree tree;
    LeerTxt archivoTxt;
    int choice = 0;

    while (choice != 5) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar nodo" << std::endl;
        std::cout << "2. Eliminar nodo" << std::endl;
        std::cout << "3. Buscar nodo" << std::endl;
        std::cout << "4. Imprimir árbol" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "6. Imprimir txt" << std::endl;
        std::cout << "7. Obtener canton por id" << std::endl;
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int inKey;
            string inData;
            std::cout << "Ingrese la clave del nodo a agregar: ";
            std::cin >> inKey;
            std::cout << "Ingrese la información del nodo a agregar: ";
            std::cin >> inData;
            NodeRB* newNode = new NodeRB(inKey, inData);
            tree.add(newNode);
            std::cout << "Nodo agregado correctamente." << std::endl;
            break;
        }
        case 2: {
            int key;
            std::cout << "Ingrese la clave del nodo a eliminar: ";
            std::cin >> key;
            tree.remove(key);
            std::cout << "Nodo eliminado correctamente." << std::endl;
            break;
        }
        case 3: {
            int key;
            std::cout << "Ingrese la clave del nodo a buscar: ";
            std::cin >> key;
            NodeRB* node = tree.find(key, tree.getRoot());
            if (node != nullptr) {
                node->printNode();
            }
            else {
                std::cout << "Nodo no encontrado." << std::endl;
            }
            break;
        }
        case 4: {
            tree.printTree();
            break;
        }
        case 5: {
            return 0;
        }
        case 6: {
            //string line_; funciona para el primer while
            ifstream file_("Cantones.txt");
            int id_canton;
            string canton;
            string distrito;
            int provincia_id;
            string alcalde;
            int habitantes;
            if (file_.is_open()) {
                /*while (getline(file_, line_)) {
                    cout << line_ << endl;
                }*/ //Funciona para leer linea por linea del documento txt
                while (file_ >> id_canton >> canton >> distrito >> provincia_id >> alcalde >> habitantes){
                    cout << "Canton: " << id_canton << " " << canton << " " << distrito << " " << provincia_id << " " << alcalde << " " << habitantes << endl;
                }
                file_.close();
            } else {
                cout << "File is not open";
            }
        }
        case 7: {
            int idCanton = 0;
            std::cout << "Id del canton: ";
            std::cin >> idCanton;
            archivoTxt.obtener_canton_id(idCanton)->imprimir();
        }
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }
    }

    std::cout << "Good bye\n";
}