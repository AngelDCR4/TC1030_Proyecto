/*      
        Proyecto Biblioteca main
        Ángel David Candelario Rolon
        A01712387

        Dentro del main podemos agregar objetos de clase Libro o Audiolibro, solicitar su información e igual
        verificar su disponibilidad para luego pedir prestado
*/
#include <iostream>
#include <string>

#include "Material.h"
#include "Biblioteca.h"

using namespace std;

int main(){
/*
//PRUEBAS DENTRO DE LA CLASE MATERIAL PARA VER FUNCIONAMIENTO DE LIBROS Y AUDIOLIBROS
    Libros libro("El Quijote", "Miguel de Cervantes",123);
    Audiolibros audiolibro("1984", "George Orwell", 321);

    //----INTERFAS----
    cout << "BIENVENIDO A LA BIBLIOTECA VIRTUAL" << endl << "Tenemos disponibles estos materiales" << endl << endl;
    cout << "Libros:" << endl << libro.get_titulo() << endl << endl;
    cout << "Audiolibros:" << endl << audiolibro.get_titulo() << endl << endl;

//----SOLICITUDES-----
    
    //EJEMPLO LIBROS
    cout << "Solicitando libro: " << libro.get_titulo() << " verificando disponibilidad ---> " << libro.get_disponibilidad() << endl;
    libro.prestar();
    cout << "Ahora el libro:" << libro.get_titulo() << " tiene disponibilidad ---> " << libro.get_disponibilidad() << endl << endl;
    
    cout << "EN CASO DE QUE OTRO USUARIO SOLICITA LIBRO" << endl << endl;
    cout << "Solicitando libro: " << libro.get_titulo() << " verificando disponibilidad ---> " << libro.get_disponibilidad() << endl;
    libro.prestar();
    cout << "Ahora el libro:" << libro.get_titulo() << " tiene disponibilidad ---> " << libro.get_disponibilidad() << endl << endl;

    //EJEMPLO AUDIOLIBROS
    cout << "Solicitando audiolibro: " << audiolibro.get_titulo() << " verificando disponibilidad ---> " << audiolibro.get_disponibilidad() << endl;
    audiolibro.prestar();
    cout << "Ahora el audiolibro: " << audiolibro.get_titulo() << " tiene disponibilidad ---> " << audiolibro.get_disponibilidad() << endl << endl;

    cout << "EN CASO DE QUE OTRO USUARIO SOLICITA AUDIOLIBRO" << endl << endl;
    cout << "Solicitando audiolibro: " << audiolibro.get_titulo() << " verificando disponibilidad ---> " << audiolibro.get_disponibilidad() << endl;
    audiolibro.prestar();
    cout << "Ahora el audiolibro: " << audiolibro.get_titulo() << " tiene disponibilidad ---> " << audiolibro.get_disponibilidad() << endl << endl;
    return 0;
*/

    Biblioteca biblioteca;

    //----INTERFAS----
    
//VALORES INICIALES
    cout << "\n-- AGREGACION DE NUEVOS LIBROS --\n";
    biblioteca.agregar_libro("El Quijote", "Miguel de Cervantes", 123);
    biblioteca.agregar_audiolibro("1984", "George Orwell", 321, 120);
    biblioteca.agregar_usuario("Juan");

    cout << "\nBIENVENIDO A LA BIBLIOTECA VIRTUAL" << endl << "Tenemos disponibles estos materiales" << endl;
    
    biblioteca.checar_materiales();

    cout << "\n-- EJEMPLO DE PRESTAMOS --\n";
    biblioteca.entregar_libro(123, "Juan");
    biblioteca.entregar_audiolibro(321, "Juan");

    cout << "\n-- REVISION MATERIALES DESPUES DE SER PRESTADOS --\n";
    biblioteca.checar_materiales();
}
