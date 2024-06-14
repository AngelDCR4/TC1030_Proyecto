/*
 * Proyecto Biblioteca clase Usuario.h
 * Ángel David Candelario Rolon
 * A01712387
 * Esta clase define el objetos de tipo Usuario para registrarlos
 * y solicitar materiales.
 */

#ifndef Usuario_H_
#define Usuario_H_

#include <iostream>
#include <string>
#include "Material.h"

using namespace std;


//Declaración de la clase Usuarios
class Usuarios{
    private:
        string nombre;
    public:
        Usuarios(): nombre(""){};
        Usuarios(string nom):nombre(nom){};

        string get_nombre(){
            return nombre;
        }

        void set_nombre(string nom){
            nombre = nom;
        }
        /*
        *   solicitar_material()
        *
        *   solicitar_material se encarga de mandar a llamar a la funcion
        *   prestar de la clase material para hacer entrega del material e 
        *   imprime un mensaje dependiendo de la disponibilidad del material
        * 
        *   @objeto material de la clase Material
        *   @return funcion prestar
        *     
        */

        void solicitar_material(Material &material){
            if(material.get_disponibilidad()){
                cout << "El usuario " << nombre 
                << " ha solicitado el material " 
                << material.get_titulo() << endl;
                material.prestar();
            }else{
                cout << "Lo sentimos el " << material.get_titulo() 
                << " no esta disponible" << endl;
            }
        }
};

#endif
