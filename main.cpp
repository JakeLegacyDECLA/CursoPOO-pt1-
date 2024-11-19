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
using namespace std;

int main() {
    srand(time(0)); // Inicializa el generador de números aleatorios

    string ctop, cmid, cadc;

    cout << "Bienvenido al simulador de duelos de LoL" << endl;
    cout << "Ingresa tu campeon de Top: ";
    cin >> ctop;
    cout << "Ingresa tu campeon de Mid: ";
    cin >> cmid;
    cout << "Ingresa tu campeon de Adc: ";
    cin >> cadc;

    Top champT(ctop);
    Mid champM(cmid);
    Adc champA(cadc);

    champT.imprime_datos();
    champM.imprime_datos();
    champA.imprime_datos();

    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << "\n--- Ronda " << ronda << " ---" << endl;

        int accionT = rand() % 3;
        if (accionT == 0) champT.curar();
        else if (accionT == 1) champT.recargar_mana();
        else champT.atacar((rand() % 2 == 0) ? (Campeon&)champM : (Campeon&)champA);

        int accionM = rand() % 3;
        if (accionM == 0) champM.curar();
        else if (accionM == 1) champM.recargar_mana();
        else champM.atacar((rand() % 2 == 0) ? (Campeon&)champT : (Campeon&)champA);

        int accionA = rand() % 3;
        if (accionA == 0) champA.curar();
        else if (accionA == 1) champA.recargar_mana();
        else champA.atacar((rand() % 2 == 0) ? (Campeon&)champT : (Campeon&)champM);

        champT.imprime_datos();
        champM.imprime_datos();
        champA.imprime_datos();
    }

    return 0;
    
}