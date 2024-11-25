#ifndef Top_h
#define Top_h

#include "Campeon.h" //Hereda todo de Campeon

class Top : public Campeon {
public:
    Top(string _nombre) : Campeon(_nombre) {}

        void fortificar() {
        int bonus_vida = 200;
        vida += bonus_vida;
        cout << nombre << " usó fortificar, ganando " << bonus_vida << " puntos de vida. Vida actual: " << vida << endl;
    }

};

#endif
