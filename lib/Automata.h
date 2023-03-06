
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;

enum class Estado { INICIAL, ACEPTADO, RECHAZADO };

void gaAFD(){
    char gaObjetivo;
    cout << "Ingrese el tipo de objetivo de la bomba BOMB-II : ";
    cout<<"Nave = n"<<endl;
    cout<<"bombarderos = b"<<endl;
    cout<<"convoys = c"<<endl;
    cout<<"tanques = t"<<endl;
    cout<<"drones = d"<<endl;
    cin >> gaObjetivo;

    Estado gaEstadoactual = Estado::INICIAL;
    for (char c : gaObjetivo) {
        switch (gaEstadoactual) {
            case Estado::INICIAL:
                if (c == 'n') {
                    gaEstadoactual = Estado::ACEPTADO;
                } else if (c == 'b') {
                    gaEstadoactual = Estado::ACEPTADO;
                } else if (c == 'c') {
                    gaEstadoactual = Estado::ACEPTADO;
                } else if (c == 't') {
                    gaEstadoactual = Estado::ACEPTADO;
                } else {
                    gaEstadoactual = Estado::RECHAZADO;
                }
                break;
            case Estado::ACEPTADO:
                if (c != 'n' && c != 'b' && c != 'c' && c != 't') {
                    gaEstadoactual= Estado::RECHAZADO;
                }
                break;
            case Estado::RECHAZADO:
                break;
        }
    }

    if (gaEstadoactual == Estado::ACEPTADO) {
        cout << "La bomba ataca a " << gaObjetivo << endl;
    } else {
        cout << "La bomba BOMB-II no ataca a drones" << endl;
    }
}