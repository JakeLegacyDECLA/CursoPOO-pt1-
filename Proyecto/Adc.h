#ifndef Adc_h
#define Adc_h

#include "Campeon.h" //Hereda todo de Campeon

class Adc : public Campeon {
public:
    Adc(string _nombre) : Campeon(_nombre) {}

        void golpe_critico(Campeon &oponente) {
        int crit_chance = rand() % 100;
        if (crit_chance < 30) { // 30% de probabilidad de golpe critico
            int dmg = 300;
            oponente.set_vida(oponente.get_vida() - dmg);
            cout << nombre << " realizó un golpe crítico contra " << oponente.get_nombre() << ", causando " << dmg << " de damage. Vida actual de " << oponente.get_nombre() << ": " << oponente.get_vida() << endl;
        } else {
            cout << nombre << " ataco, pero no fue un golpe crítico." << endl;
        }
    }


};

#endif
