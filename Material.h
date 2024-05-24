/*
 * Proyecto Biblioteca clase Material
 * Ángel David Candelario Rolon
 * A01712387
 * Esta clase define el objeto de tipo Material que contiene las clases heredadas
 * Libro y Audiolibro.
 */


#ifndef Material_H_
#define Material_H_

#include <iostream>
#include <string>

using namespace std;

//DECLARACIÓN CLASE MATERIAL ABSTRACTA

class Material{
    private:
        string titulo;
        string autor;
        int id;
        bool disponibilidad;
    public:
        Material():titulo(""),autor(""),id(0),disponibilidad(true){};   //CONSTRUCTOR DEFAULT
        Material(string tit, string aut, int id_num):titulo(tit),autor(aut),id(id_num), disponibilidad(true){};
        //GETTERS SETTERS
        string get_titulo(){
            return titulo;
        }
        string get_autor(){
            return autor;
        }
        int get_id(){
            return id;
        }
        bool get_disponibilidad(){
            return disponibilidad;
        }

        void set_titulo(string tit){
            titulo = tit;
        }
        void set_autor(string aut){
            autor = aut;
        }
        void set_id(int id_num){
            id = id_num;
        }
        void set_disponibilidad(bool dis){
            disponibilidad = dis;
        }

        virtual void prestar() = 0;     //METODO ABSTRACTO QUE SERA SOBREESCRITO
};



//DECLARACIÓN OBJETO LIBROS QUE HEREDA DE MATERIAL

class Libros: public Material {
    public:
        Libros():Material(){};
        Libros(string tit, string aut, int id_num):Material(tit,aut,id_num){};

        //La funcion prestar verificara la disponibilidad y cambiara la disponibilidad a false
        void prestar()override{
            if(get_disponibilidad()){  //SI DISPONIBILIDAD ES TRUE PROCEDE
                cout << "Prestar el libro:" << get_titulo() << endl;
                set_disponibilidad(false);
            } else {
                cout << "Lo sentimos el libro no esta disponible" << endl;
            }
        } 
        
};

//DECLARACIÓN OBJETO AUDIOLIBROS QUE HEREDA DE MATERIAL

class Audiolibro:public Material{
    public:
        Audiolibro():Material(){};
        Audiolibro(string tit, string aut, int id_num):Material(tit,aut,id_num){};

        void prestar()override{
            if(get_disponibilidad()){
                cout << "Prestar el audiolibro: " << get_titulo() << endl;
                set_disponibilidad(false);
            } else {
                cout << "Lo sentimos el audiolibro no esta dispobile" << endl;
            }
        }
};
#endif

