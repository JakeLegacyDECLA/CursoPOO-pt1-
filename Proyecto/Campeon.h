#ifndef Campeon_h
#define Campeon_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Objeto.h"
using namespace std;

// Clase padre Campeon, de la cual se derivan Top, Mid y Adc
class Campeon {
// Se ajustan los parámetros que heredarán las posiciones Top, Mid y Adc
protected:
    string nombre;
    int vida;
    int mana;
    vector<Objeto*> objetos; // Vector para almacenar múltiples objetos

public:
    // Constructor
    Campeon(string _nombre) : nombre(_nombre), vida(500), mana(500) {}

    // GETTERS
    string get_nombre() { return nombre; }
    int get_vida() { return vida; }
    int get_mana() { return mana; }

    // SETTERS
    void set_nombre(string _nombre) { nombre = _nombre; }
    void set_vida(int _vida) { vida = max(0, _vida); }
    void set_mana(int _mana) { mana = max(0, _mana); }

    // Método virtual para imprimir datos
    virtual void imprime_datos() {
        cout << "Campeón: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Maná: " << mana << endl;
    }

    // Acciones básicas
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

    // Método para atacar campeones oponentes
    void atacar(Campeon &oponente) {
        if (mana >= 50) {
            oponente.vida -= 150; // Le resta 150 a la vida del oponente
            mana -= 50; // Le resta 50 maná al atacante
            cout << nombre << " atacó a " << oponente.get_nombre() << ". " 
                 << oponente.get_nombre() << " perdió 150 puntos de vida. Vida actual: " 
                 << oponente.get_vida() << endl;
        } else {
            cout << nombre << " no tiene suficiente maná para atacar. Maná actual: " << mana << endl;
        }
    }

    // Métodos relacionados con objetos
    void asignar_objeto(Objeto* _objeto) {
        objetos.push_back(_objeto); // Agrega el objeto al vector
    }

    void usar_objeto() {
        if (!objetos.empty()) {
            int index = rand() % objetos.size(); // Seleccionar un objeto aleatoriamente
            Objeto* objeto_a_usar = objetos[index];
            objeto_a_usar->aplicar_bonificaciones(*this);
            objetos.erase(objetos.begin() + index); // Elimina el objeto después de usarlo
        } else {
            cout << nombre << " no tiene ningún objeto para usar." << endl;
        }
    }
};

#endif
