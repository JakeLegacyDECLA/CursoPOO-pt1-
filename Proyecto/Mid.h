#ifndef Mid_h
#define Mid_h

#include "Campeon.h" //Hereda todo de Campeon

class Mid : public Campeon {
public:
    Mid(string _nombre) : Campeon(_nombre) {}

        void lanza_hechizo(Campeon &oponente) {
        if (mana >= 100) {
            int dmg = 200;
            oponente.set_vida(oponente.get_vida() - dmg);
            mana -= 100;
            cout << nombre << " lanzo un hechizo a " << oponente.get_nombre() << ", causando " << dmg << " de damage. Vida actual de " << oponente.get_nombre() << ": " << oponente.get_vida() << endl;
        } else {
            cout << nombre << " no tiene suficiente mana para lanzar un hechizo." << endl;
        }
    }


};

#endif
