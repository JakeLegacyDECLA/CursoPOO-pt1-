#ifndef TOP_H
#define TOP_H

#include <string>
#include <iostream>
using namespace std;

class Top {
private:
    string nombre;
    int vida;
    int poder;

public:
    // Constructor
    Top(const string& nombre, int vida, int poder)
        : nombre(nombre), vida(vida), poder(poder) {}

    // Getters
    string getNombre() const { return nombre; }
    int getVida() const { return vida; }
    int getPoder() const { return poder; }

    // Setters
    void setNombre(const string& _Nombre) { nombre = _Nombre; }
    void setVida(int _Vida) { vida = _Vida; }
    void setPoder(int _Poder) { poder = _Poder; }

    // Método para mostrar la información del campeón
    void mostrarInfo() const {
        cout << "Campeón Top: " << nombre << "\n"
             << "Vida: " << vida << "\n"
             << "Poder: " << poder << endl;
    }

    // Método para atacar
    void atacar() const {
        cout << nombre << " ataca con " << poder << " de poder!" << endl;
    }
};

#endif // TOP_H
