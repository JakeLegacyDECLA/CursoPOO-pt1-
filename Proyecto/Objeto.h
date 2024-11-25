#ifndef Objeto_h
#define Objeto_h

#include <iostream>
using namespace std;

class Campeon;

class Objeto {
private:
    string nombre;
    int bonificacion_vida;
    int bonificacion_mana;

public:
    Objeto(string _nombre, int _vida, int _mana)
        : nombre(_nombre), bonificacion_vida(_vida), bonificacion_mana(_mana) {}


    void aplicar_bonificaciones(Campeon &campeon);

    string get_nombre() { return nombre; }
};

#endif
