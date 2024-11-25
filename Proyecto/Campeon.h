#ifndef Campeon_h
#define Campeon_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Objeto.h"
using namespace std;

class Campeon {
protected:
    string nombre;
    int vida;
    int mana;
    Objeto* objeto;

public:
    Campeon(string _nombre) : nombre(_nombre), vida(500), mana(500) {}

    string get_nombre() { return nombre; }
    int get_vida() { return vida; }
    int get_mana() { return mana; }

    void set_nombre(string _nombre) { nombre = _nombre; }
    void set_vida(int _vida) { vida = max(0, _vida); }
    void set_mana(int _mana) { mana = max(0, _mana); }

    virtual void imprime_datos() {
        cout << "Campeon: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Mana: " << mana << endl;
    }

    void curar() {
        int cura = 100 + rand() % 51; // Curación entre 100 y 150
        vida += cura;
        cout << nombre << " se curó " << cura << " puntos de vida. Vida actual: " << vida << endl;
    }

    void recargar_mana() {
        int recarga = 50 + rand() % 51; // Recarga entre 50 y 100
        mana += recarga;
        cout << nombre << " recargó " << recarga << " puntos de maná. Maná actual: " << mana << endl;
    }

    void atacar(Campeon &oponente) {
        if (mana >= 50) {
            oponente.vida -= 150;
            mana -= 50;
            cout << nombre << " atacó a " << oponente.get_nombre() << ". " << oponente.get_nombre() << " perdió 150 puntos de vida. Vida actual: " << oponente.get_vida() << endl;
        } else {
            cout << nombre << " no tiene suficiente maná para atacar. Maná actual: " << mana << endl;
        }
    }

    void asignar_objeto(Objeto* _objeto) {
        objeto = _objeto;
    }

    void usar_objeto() {
        if (objeto) {
            objeto->aplicar_bonificaciones(*this);
            objeto = nullptr; // El objeto se consume después de usarse
        } else {
            cout << nombre << " no tiene ningún objeto para usar." << endl;
        }
    }
};

#endif
