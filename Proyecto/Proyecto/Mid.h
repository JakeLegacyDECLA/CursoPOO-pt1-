#ifndef Mid_h
#define Mid_h

#include "Campeon.h" //Hereda todo de Campeon

class Mid : public Campeon {
public:
    Mid(string _nombre) : Campeon(_nombre) {}

        void lanza_hechizo(Campeon &oponente) {
        if (mana >= 100) {
            int daño = 200;
            oponente.set_vida(oponente.get_vida() - daño);
            mana -= 100;
            cout << nombre << " lanzó un hechizo a " << oponente.get_nombre() << ", causando " << daño << " de daño. Vida actual de " << oponente.get_nombre() << ": " << oponente.get_vida() << endl;
        } else {
            cout << nombre << " no tiene suficiente maná para lanzar un hechizo." << endl;
        }
    }


};

#endif
