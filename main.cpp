/*      
        Proyecto Biblioteca main
        Ángel David Candelario Rolon
        A01712387

        Dentro del main podemos agregar objetos de clase Libro o Audiolibro,
        solicitar su información e igual verificar su disponibilidad para
        luego pedir prestado
*/

#include <iostream>
#include <string>

#include "Material.h"
#include "Biblioteca.h"

using namespace std;

void menu(){
    cout << "\n----> BIBLIOTECA TEC <----\n";
    cout << "\n--- MENU DE BIBLIOTECA ---\n";
    cout << "1 - Agregar usuario\n";
    cout << "2 - Agregar libro\n";
    cout << "3 - Agregar audiolibro\n";
    cout << "4 - Consultar materiales\n";
    cout << "5 - Prestar audiolibro\n";
    cout << "6 - Prestar libro\n";
    cout << "7 - Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Biblioteca biblioteca;
    string nombre_biblioteca;

    string ini_usuario;
            cout << "Ingrese el nombre de un usuario --> ";
            getline(cin, ini_usuario);
            biblioteca.agregar_usuario(ini_usuario);

    cout << "\n-- MATERIALES POR DEFAULT --\n";
    biblioteca.agregar_libro("El Quijote", "Miguel de Cervantes", 123);
    biblioteca.agregar_audiolibro("1984", "George Orwell", 321, 120);
    biblioteca.agregar_usuario("Angel");
    biblioteca.agregar_libro("Nexo","A. Rolon",777);

    while(true){
        menu();
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            string nombre_usuario;
            cout << "Ingrese el nombre del usuario: ";
            cin.ignore();
            getline(cin, nombre_usuario);
            biblioteca.agregar_usuario(nombre_usuario);
        }
        else if (opcion == 2) {
            string titulo, autor;
            int id;
            cout << "Ingrese el titulo del libro: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);
            cout << "Ingrese el ID del libro unico: ";
            cin >> id;
            biblioteca.agregar_libro(titulo, autor, id);
        }
        else if (opcion == 3) {
            string titulo, autor;
            int id;
            float duracion;
            cout << "Ingrese el titulo del audiolibro: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese el autor del audiolibro: ";
            getline(cin, autor);
            cout << "Ingrese el ID del audiolibro unico: ";
            cin >> id;
            cout << "Ingrese la duracion del audiolibro (en minutos): ";
            cin >> duracion;
            biblioteca.agregar_audiolibro(titulo, autor, id, duracion);
        }
        else if (opcion == 4) {
            biblioteca.checar_materiales();
        }else if (opcion == 5) {
            int id;
            string nombre_usuario;
            cout << "Ingrese el ID del audiolibro a prestar (numeros): ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del usuario: ";
            getline(cin, nombre_usuario);
            biblioteca.entregar_audiolibro(id, nombre_usuario);
        }else if (opcion == 6) {
            int id;
            string nombre_usuario;
            cout << "Ingrese el ID del libro a prestar (numeros): ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del usuario: ";
            getline(cin, nombre_usuario);
            biblioteca.entregar_libro(id, nombre_usuario);
        }
        else if (opcion == 7) {
            cout << "Saliendo de la biblioteca...\n";
            break;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }

    return 0;
}
