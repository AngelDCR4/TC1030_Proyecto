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
#include "Material.h"
#include "Usuario.h"

using namespace std;

//Declaración de la clase biblioteca
class Biblioteca{
    private:
        string nombre;
        Material *material[100];
        int num_mate;
    public:
        Usuarios usuario[100];
        int num_usu;

    //IMPLEMENTAR METODOS
    public:
        Biblioteca():num_usu(0),num_mate(0){};

    /*
    agregar_libro añade un objeto libro solicitanto un titulo, autor y un ID
    se guardara dentro del arreglo libro[] e imprime un mensaje para la interfas
    */
        /*
        void agregar_libro(string tit, string aut, int id_num){
            if(num_lib < 100){
                libro[num_lib] = Libros(tit,aut,id_num);
                cout << "Se ha agregado \"" << libro[num_lib].get_titulo() << "\" a la biblioteca" << endl;
                num_lib++;
            } else {
                cout << "La libreria esta llena no se puede agregar libros" << endl;
            }
        }
        */
        //---------------

        void agregar_libro(string tit,string aut, int id_num){
            if(num_mate < 100){
                material[num_mate] = new Libros(tit,aut,id_num);
                cout << "Se ha agregado el libro \"" << material[num_mate]->get_titulo() << "\" a la biblioteca" << endl;
                num_mate++;
            }else{
                cout << "La libreria esta llena no se pueden agregar mas materiales" << endl;
            }
        }


    /*
    agregar_audiolibro añade un objeto audiolibro solicitanto un titulo, autor y un ID
    se guardara dentro del arreglo audiolibro[] e imprime un mensaje para la interfas
    */
    /*
        void agregar_audiolibro(string tit, string aut, int id_num, float dur){
            if(num_aud < 100){
                audiolibro[num_aud] = Audiolibros(tit,aut,id_num,dur);
                cout << "Se ha agregado \"" << audiolibro[num_aud].get_titulo() << "\" a la biblioteca" << endl;
                num_aud++;
            } else {
                cout << "La libreria esta llena no se puede agregar audiolibros" << endl;
            }
        }
    */
        //---------

        void agregar_audiolibro(string tit, string aut, int id_num, float dur){
            if (num_mate < 100){
                material[num_mate] = new Audiolibros(tit,aut,id_num,dur);
                cout << "Se ha agregado el audiolibro \"" << material[num_mate]->get_titulo() << "\" a la biblioteca" << endl;
                num_mate++;
            }else{
                cout << "La libreria esta llena no se pueden agregar mas materiales" << endl;
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
    /*
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
    */

   //-----------

        void entregar_libro(int id, string usu_nombre){
            bool encontrado = false;
            for(int i = 0; i < num_mate; i++){
                if(material[i]->get_id() == id and material[i]->get_tipo() == "Libro" and material[i]->get_disponibilidad()){
                    for(int j = 0; j < num_usu; j++){
                        if(usuario[j].get_nombre() == usu_nombre){
                            usuario[j].solicitar_material(*material[i]);
                            return;
                        }else{
                            cout << "El usuario " << usu_nombre << " no esta registrado\n";
                        }
                    } encontrado = true;
                      break;
                }else if(material[i]->get_tipo() == "Libro"){
                    cout << "Lo sentimos el material \""<< material[i]->get_titulo() <<"\" no se puede entregar.\n";
                }  
            }
            if(encontrado){
                    cout << "El libro con ID " << id << " no se ha encontrado" << endl;
                }
        }
    /*
    entregar_audiolibro se encarga de buscar el audiolibro con el ID respectivo
    dentro de todo el arreglo de audiolibro y tambien busca al usuario respectivo
    dentro del arreglo usuario y hace entrega del audiolibro al usuario correspondinte
    cambiando automaticamente su disponibilidad del audiolibro a False
    */
        void entregar_audiolibro(int id, string usu_nombre){
            bool encontrado = false;
            for (int i = 0; i < num_mate; i++){
                if(material[i]->get_id() == id and material[i]->get_tipo() == "Audiolibro" and material[i]->get_disponibilidad()){
                    for(int j = 0; j < num_usu; j++){
                        if(usuario[j].get_nombre() == usu_nombre){
                            usuario[j].solicitar_material(*material[i]);
                            return;
                        }else{
                            cout << "El usuario " << usu_nombre << " no esta registrado\n";
                        }
                    } encontrado = true;
                        break;
                }else if(material[i]->get_tipo() == "Audiolibro"){
                    cout << "Lo sentimos el material \"" << material[i]->get_titulo() << "\" no se puede entregar.\n";
                }
                
            }
            if(encontrado){
                    cout << "El audiolibro con ID " << id << " no se ha encontrado" << endl;
                }
        }
    /*
    checar_material hace todo un barrido de los libros y audiolibros agregados y los imprime
    dentro de un menu de LIBROS y AUDIOLIBROS y verifica la disponibilidad de cada material
    */
        void checar_materiales(){
            cout << "Tenemos los siguiente materiales: \n";
            for(int i = 0; i < num_mate; i++){
                        material[i]->informacion();
                    cout << "tiene disponibilidad: " << material[i]->get_disponibilidad() << endl;
            }
        }
};

#endif
