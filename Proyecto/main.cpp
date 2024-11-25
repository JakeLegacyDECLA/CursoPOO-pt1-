/*
Proyecto para Programación Orientada a Objetos
César Daniel Aguilar Kuri A01712823

Motor de League of Legends (Duelos)
*/

//Bibliotecas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Top.h"
#include "Mid.h"
#include "Adc.h"
#include "Campeon.h"
#include "Objeto.h"

using namespace std;

void Objeto::aplicar_bonificaciones(Campeon &campeon) {
    campeon.set_vida(campeon.get_vida() + bonificacion_vida);
    campeon.set_mana(campeon.get_mana() + bonificacion_mana);
    cout << campeon.get_nombre() << " usó " << nombre
         << ". Vida + " << bonificacion_vida << ", Maná + " << bonificacion_mana << endl;
}

int main() {
    srand(time(0));

    string ctop, cmid, cadc;

    cout << "Bienvenido al simulador de duelos de LoL" << endl;
    cout << "Ingresa tu campeón de Top: ";
    cin >> ctop;
    cout << "Ingresa tu campeón de Mid: ";
    cin >> cmid;
    cout << "Ingresa tu campeón de Adc: ";
    cin >> cadc;

    Top champT(ctop);
    Mid champM(cmid);
    Adc champA(cadc);

    // Crear objetos aleatorios
    Objeto objetos[] = {
        Objeto("Espada de vida", 100, 50),
        Objeto("Cetro mágico", 50, 100),
        Objeto("Armadura resistente", 150, 0)
    };

    champT.asignar_objeto(&objetos[rand() % 3]);
    champM.asignar_objeto(&objetos[rand() % 3]);
    champA.asignar_objeto(&objetos[rand() % 3]);

    champT.imprime_datos();
    champM.imprime_datos();
    champA.imprime_datos();

    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << "\n--- Ronda " << ronda << " ---" << endl;

        // Acción aleatoria para Top
        int accionT = rand() % 4;
        if (accionT == 0) champT.curar();
        else if (accionT == 1) champT.recargar_mana();
        else if (accionT == 2) champT.fortificar();
        else champT.usar_objeto();

        // Acción aleatoria para Mid
        int accionM = rand() % 4;
        if (accionM == 0) champM.curar();
        else if (accionM == 1) champM.recargar_mana();
        else if (accionM == 2) champM.lanza_hechizo((rand() % 2 == 0) ? (Campeon &)champT : (Campeon &)champA);
        else champM.usar_objeto();

        // Acción aleatoria para Adc
        int accionA = rand() % 4;
        if (accionA == 0) champA.curar();
        else if (accionA == 1) champA.recargar_mana();
        else if (accionA == 2) champA.golpe_critico((rand() % 2 == 0) ? (Campeon &)champT : (Campeon &)champM);
        else champA.usar_objeto();

        champT.imprime_datos();
        champM.imprime_datos();
        champA.imprime_datos();
    }

    return 0;
}