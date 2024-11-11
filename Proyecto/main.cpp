/*
Proyecto para Programación Orientada a Objetos
César Daniel Aguilar Kuri A01712823

Motor de League of Legends (Duelos)
*/

//Bibliotecas
#include <iostream>
#include "top.h"
#include "mid.h"
using namespace std;

int main() {
    // Crear un campeón para cada rol
    Top topChampion("Garen", 1500, 200);
    Mid midChampion("Ahri", 1200, 300);

    // Mostrar información de cada campeón
    cout << "Información de los campeones:\n";
    topChampion.mostrarInfo();
    topChampion.atacar();

    cout << "\n";

    midChampion.mostrarInfo();
    midChampion.atacar();

    // Uso de getters y setters
    cout << "\nActualizando atributos de los campeones...\n";
    // Todavia por pensar como sería el consumir vida y demás - EN PROCESO -
    topChampion.setVida(1400);
    midChampion.setMana(280);

    cout << "Nueva vida de " << topChampion.getNombre() << ": " << topChampion.getVida() << endl;
    cout << "Nuevo mana de " << midChampion.getNombre() << ": " << midChampion.getMana() << endl;

    return 0;
}
