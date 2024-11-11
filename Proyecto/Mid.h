#ifndef MID_H
#define MID_H

#include <string>
#include <iostream>
using namespace std;

class Mid {
private:
    string nombre;
    int vida;
    int mana;

public:
    // Constructor
    Mid(const string& nombre, int vida, int mana)
        : nombre(nombre), vida(vida), mana(mana) {}

    // Getters
    string getNombre() const { return nombre; }
    int getVida() const { return vida; }
    int getMana() const { return mana; }

    // Setters
    void setNombre(const string& _Nombre) { nombre = _Nombre; }
    void setVida(int _Vida) { vida = _Vida; }
    void setMana(int _Mana) { mana = _Mana; }

    // Mostrar la información del campeón (Método)
    void mostrarInfo() const {
        cout << "Campeón Mid: " << nombre << "\n"
             << "Vida: " << vida << "\n"
             << "Mana: " << mana << endl;
    }

    // Ataque (Método)
    void atacar() const {
        cout << nombre << " lanza un hechizo usando " << mana << " de mana!" << endl;
    }
};

#endif // MID_H
