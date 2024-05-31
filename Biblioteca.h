/*
 * Proyecto Biblioteca clase Biblioteca
 * Ángel David Candelario Rolon
 * A01712387
 * Esta clase define al objeto Biblioteca que realiza todas las operaciones.
 * para hacer la entrega de libros a los usuarios e igual a hacer un inventario
 * de los libros y audiolibros que se hayan agregado
 * 
 */

#ifndef Biblioteca_H_
#define Biblioteca_H_

#include <iostream>
#include <string>
#include <vector>
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
        solicitar_material se encarga de dependiendo si es libro o audiolibro
        manda a llamar a la funcion prestar de la clase material para hacer entrega de material
        e imprime un mensaje dependiendo de la disponibilidad del material
        */
        void solicitar_material(Material &material){
            if(material.get_disponibilidad()){
                material.prestar();
                cout << "El usuario " << nombre << " ha solicitado el material " << material.get_titulo() << endl;
            }else{
                cout << "Lo sentimos el " << material.get_titulo() << " no esta disponible" << endl;
            }
        }
};

//Declaración de la clase usuarios
class Biblioteca{
    private:
        string nombre;
    public:
        Usuarios usuario[100];
        Libros libro[100];
        Audiolibros audiolibro[100];
        int num_usu;
        int num_lib;
        int num_aud;

    //IMPLEMENTAR METODOS
    public:
        Biblioteca():num_usu(0),num_lib(0),num_aud(0){};

    /*
    agregar_libro añade un objeto libro solicitanto un titulo, autor y un ID
    se guardara dentro del arreglo libro[] e imprime un mensaje para la interfas
    */
        void agregar_libro(string tit, string aut, int id_num){
            if(num_lib < 100){
                libro[num_lib] = Libros(tit,aut,id_num);
                cout << "Se ha agregado \"" << libro[num_lib].get_titulo() << "\" a la biblioteca" << endl;
                num_lib++;
            } else {
                cout << "La libreria esta llena no se puede agregar libros" << endl;
            }
        }
    /*
    agregar_audiolibro añade un objeto audiolibro solicitanto un titulo, autor y un ID
    se guardara dentro del arreglo audiolibro[] e imprime un mensaje para la interfas
    */
        void agregar_audiolibro(string tit, string aut, int id_num){
            if(num_aud < 100){
                audiolibro[num_aud] = Audiolibros(tit,aut,id_num);
                cout << "Se ha agregado \"" << audiolibro[num_aud].get_titulo() << "\" a la biblioteca" << endl;
                num_aud++;
            } else {
                cout << "La libreria esta llena no se puede agregar audiolibros" << endl;
            }
        }
    /*
    agregar_usuario añade un objeto usuario solicitanto un nombre y
    se guardara dentro del arreglo usuario[] e imprime un mensaje para la interfas
    */
        void agregar_usuario(string nom){
            if(num_usu < 100){
                usuario[num_usu] = Usuarios(nom);
                cout << "Se ha unido " << usuario[num_usu].get_nombre() << " a la biblioteca" << endl;
                num_usu++;
            } else {
                cout << "No se pueden agregar mas usuarios" << endl;
            }
        }
    /*
    entregar_libro se encarga de buscar el libro con el ID respectivo
    dentro de todo el arreglo de libro y tambien busca al usuario respectivo
    dentro del arreglo usuario y hace entrega del libro al usuario correspondinte
    cambiando automaticamente su disponibilidad del libro a False
    */
        void entregar_libro(int id, string usu_nombre){
            for (int i = 0; i < num_lib; i++){
                if(libro[i].get_id() == id){
                    for ( int j = 0; j < num_usu; j++){
                        if(usuario[j].get_nombre() == usu_nombre){
                            usuario[j].solicitar_material(libro[i]);
                            return;
                        }
                    }
                    return;
                } else {
                cout << "El libro con ID " << id << " no se ha encontrado" << endl;
            }
            }
        }
    /*
    entregar_audiolibro se encarga de buscar el audiolibro con el ID respectivo
    dentro de todo el arreglo de audiolibro y tambien busca al usuario respectivo
    dentro del arreglo usuario y hace entrega del audiolibro al usuario correspondinte
    cambiando automaticamente su disponibilidad del audiolibro a False
    */
        void entregar_audiolibro(int id, string usu_nombre){
            for (int i = 0; i < num_usu; i++){
                if(audiolibro[i].get_id() == id){
                    for(int j = 0; j < num_usu; j++){
                        if(usuario[j].get_nombre() == usu_nombre){
                            usuario[j].solicitar_material(audiolibro[i]);
                            return;
                        }
                    }
                    return;
                } else {
                cout << "El audiolibro con ID " << id << " no se ha encontrado" << endl;
            }
            }
        }
    /*
    checar_material hace todo un barrido de los libros y audiolibros agregados y los imprime
    dentro de un menu de LIBROS y AUDIOLIBROS y verifica la disponibilidad de cada material
    */
        void checar_materiales(){
            cout << "LIBROS: \n";
            for(int i = 0; i < num_lib; i++){
                cout << "EL libro \"" << libro[i].get_titulo() << "\" tiene disponibilidad: " << libro[i].get_disponibilidad() << endl;
            }
            cout << "AUDIOLIBROS: \n";
            for(int i = 0; i < num_aud; i++){
                cout << "EL audiolibro \"" << audiolibro[i].get_titulo() << "\" tiene disponibilidad: " << audiolibro[i].get_disponibilidad() << endl;
            }
        }
};

#endif
