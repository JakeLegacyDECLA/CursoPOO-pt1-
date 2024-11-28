#ifndef Objeto_h
#define Objeto_h

#include <iostream>
using namespace std;

//Se referencia a la clase campeon
class Campeon;

class Objeto {
private:
    string nombre;
    int bonificacion_vida;
    int bonificacion_mana;

public:
    Objeto(string _nombre, int _vida, int _mana)
        : nombre(_nombre), bonificacion_vida(_vida), bonificacion_mana(_mana) {}

    //Se le aplican las bonificaciones a los campeones derivados de campeon
    void aplicar_bonificaciones(Campeon &campeon);

    //GETTERS
    string get_nombre() {
        return nombre; 
        }
};

#endif
