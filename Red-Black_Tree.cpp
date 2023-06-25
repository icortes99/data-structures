#include <iostream>
#include "Red_Black_tree.h"

int main(){
    Red_Black_tree tree;
    int choice = 0;

    while (choice != 5) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar nodo" << std::endl;
        std::cout << "2. Eliminar nodo" << std::endl;
        std::cout << "3. Buscar nodo" << std::endl;
        std::cout << "4. Imprimir árbol" << std::endl;
        std::cout << "5. Salir" << std::endl;
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
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }
    }

    std::cout << "Good bye\n";
}