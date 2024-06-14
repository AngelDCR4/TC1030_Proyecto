/*
 * Proyecto Biblioteca clase Material
 * Ángel David Candelario Rolon
 * A01712387
 * Esta clase define el objeto de tipo Material que contiene las clases 
 * heredadas
 * Libro y Audiolibros.
 */


#ifndef Material_H_
#define Material_H_

#include <iostream>
#include <string>

using namespace std;

//DECLARACIÓN CLASE MATERIAL ABSTRACTA

class Material{
    protected:
        string titulo;
        string autor;
        int id;
        bool disponibilidad;
    public:
        Material():titulo(""),autor(""),id(0),disponibilidad(true){};
        //CONSTRUCTOR DEFAULT
        Material(string tit, string aut, int id_num):titulo(tit),autor(aut),
        id(id_num), disponibilidad(true){};
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

        virtual string get_tipo() = 0;  //Uso polimorfismo método virtual puro
        virtual void prestar() = 0;     //Uso polimorfismo método virtual puro
        virtual void informacion() = 0; //Uso polimorfismo método virtual puro
};



//DECLARACIÓN OBJETO LIBROS QUE HEREDA DE MATERIAL

class Libros: public Material {
    public:
        Libros():Material(){};
        Libros(string tit, string aut, int id_num):Material(tit,aut,id_num){};

        string get_tipo(){
            return "Libro";
        }

        /*
        *   prestar()
        *
        *   La funcion prestar verificara la disponibilidad, cambiara la 
        *   disponibilidad a false y mostrara un mensaje sobre el resultado
        *
        *   @param
        *   @return establece dispobilidad a false y muestra 
        *    mensaje en pantalla
        */ 
        void prestar(){     //Sobreescritura del método prestar de Material
            if(get_disponibilidad()){  //SI DISPONIBILIDAD ES TRUE PROCEDE
                cout << "Se ha prestado el libro:" << get_titulo() << endl;
                set_disponibilidad(false);
            } else {
                cout << "Lo sentimos el libro no esta disponible" << endl;
            }
        } 

        /*
        *   informacion()
        *
        *   Muestra informacion principal sobre el libro como su titulo y autor
        * 
        *   @param
        *   @return informacion sobre el libro
        */

        void informacion(){
            cout << "El Libro \"" << get_titulo() << "\" es del autor " 
            << get_autor() << " ID asignado --> " << get_id() << endl;;
        }
};

//DECLARACIÓN OBJETO AUDIOLIBROS QUE HEREDA DE MATERIAL

class Audiolibros:public Material{
    private:
    float duracion;
    public:
        Audiolibros():Material(){};
        Audiolibros(string tit, string aut, int id_num, float dur):
        Material(tit,aut,id_num), duracion(dur){};

        float get_duracion(){
            return duracion;
        }

        string get_tipo(){
            return "Audiolibro";
        }

        /*
        *   informacion()
        *
        *   Muestra informacion principal sobre el audiolibro como 
        *   su titulo, autor y su duracion
        * 
        *   @param
        *   @return informacion sobre el audiolibro
        */

        void informacion(){
            cout << "El Audiolibro \"" << get_titulo() << "\" de " 
            << get_autor() << " tiene una duracion de ";
            cout << get_duracion() << " minutos" << " ID asignado --> " 
            << get_id() << endl;
        }

        /*
        *   prestar()
        *
        *   La funcion prestar verificara la disponibilidad, cambiara la 
        *   disponibilidad a false y mostrara un mensaje sobre el resultado
        *
        *   @param
        *   @return establece dispobilidad a false y muestra 
        *    mensaje en pantalla
        */ 

        void prestar(){
            if(get_disponibilidad()){
                cout << "Se ha prestado el audiolibros: " 
                << get_titulo() << endl;  
                set_disponibilidad(false);
            } else {
                cout << "Lo sentimos el audiolibros no esta dispobile" 
                << endl;
            }
        }
};
#endif
