/*      
        Proyecto Biblioteca main
        Ángel David Candelario Rolon
        A01712387

        Dentro de este archivo de pruebas podemos hacer
        uso de los getter principalmente de las clases
        hijas Libro y Audiolibro, ademas de usar su metodo
        principal que es "prestar"

*/
#include <iostream>
#include <string>

#include "Material.h"
#include "Biblioteca.h"

using namespace std;

int main(){

//PRUEBAS DENTRO DE CLASE MATERIAL PARA FUNCIONAMIENTO DE LIBROS Y AUDIOLIBROS
    Libros libro("El Quijote", "Miguel de Cervantes",123);
    Audiolibros audiolibro("1984", "George Orwell", 321,120);

    //----INTERFAS----
    cout << "BIENVENIDO A LA BIBLIOTECA VIRTUAL" << endl 
    << "Tenemos disponibles estos materiales" << endl << endl;
    cout << "Libros:" << endl << libro.get_titulo() << endl << endl;
    cout << "Audiolibros:" << endl << audiolibro.get_titulo() << endl << endl;

//----SOLICITUDES-----
    
    //EJEMPLO LIBROS
    cout << "Solicitando libro: " << libro.get_titulo() 
    << " verificando disponibilidad ---> " << libro.get_disponibilidad() 
    << endl;
    libro.prestar();
    cout << "Ahora el libro:" << libro.get_titulo() 
    << " tiene disponibilidad ---> " << libro.get_disponibilidad() 
    << endl << endl;
    
    cout << "EN CASO DE QUE OTRO USUARIO SOLICITA LIBRO" << endl << endl;
    cout << "Solicitando libro: " << libro.get_titulo() 
    << " verificando disponibilidad ---> " << libro.get_disponibilidad() 
    << endl;
    libro.prestar();
    cout << "Ahora el libro:" << libro.get_titulo() 
    << " tiene disponibilidad ---> " << libro.get_disponibilidad() 
    << endl << endl;

    //EJEMPLO AUDIOLIBROS
    cout << "Solicitando audiolibro: " << audiolibro.get_titulo() 
    << " verificando disponibilidad ---> " 
    << audiolibro.get_disponibilidad() << endl;
    audiolibro.prestar();
    cout << "Ahora el audiolibro: " << audiolibro.get_titulo() 
    << " tiene disponibilidad ---> " << audiolibro.get_disponibilidad() 
    << endl << endl;

    cout << "EN CASO DE QUE OTRO USUARIO SOLICITA AUDIOLIBRO" 
    << endl << endl;
    cout << "Solicitando audiolibro: " << audiolibro.get_titulo() 
    << " verificando disponibilidad ---> " 
    << audiolibro.get_disponibilidad() << endl;
    audiolibro.prestar();
    cout << "Ahora el audiolibro: " << audiolibro.get_titulo() 
    << " tiene disponibilidad ---> " << audiolibro.get_disponibilidad() 
    << endl << endl;
    return 0;

}
