/*
@autor: Gabriel Del Valle
@Fecha: 06/03/2023
Examen 2 */

#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;


string gaNombre = "Gabriel Sebastian Del Valle Lascano";
string gaCedula = "1850432723";

struct gaCoordenadas{
    int gaCapacidadBe,*CB;
    string gaGeolocalizacion, *Ge;
    string gaArsenal,*Ar;
};

int gaArchivo(){
    ofstream archivo("Coordenadas.txt");
    archivo<<"Cap,  Geo,        Tipo arsenal, "<< endl;
    archivo<<"3,    GPS3,        bcd,     "<< endl;
    archivo<<"2,    GPS2,        ac,      "<< endl;
    archivo<<"7,    GPS7,        aaabbct, "<< endl;
    archivo<<"2,    GPS2,        ac,      "<< endl;
    archivo<<"3,    GPS3,        bcd,     "<< endl;
    archivo<<"4,    GPS4,        acd,     "<< endl;
    archivo<<"0,    GPS0,        ab,      "<< endl;
    archivo<<"5,    GPS5,        bct,     "<< endl;
    archivo<<"8,    GPS8,        abbccdt, "<< endl;
    archivo<<"1,    GPS1,        ab,      "<< endl;
    archivo.close();
    return 0;
}

void gaLeerarchivo(string Coordenadas){
    ifstream archivo(Coordenadas);
    string gaLinea;
    int numlineas = 0;
        cout << " Leyendo coordenadas... " <<endl;
        while (getline(archivo, gaLinea)){
        numlineas++;
        }
        archivo.clear();
        archivo.seekg(0);
        int gaProgreso = 0;
        while (getline(archivo, gaLinea)){
        gaProgreso = archivo.tellg()*10/30;
            if(gaProgreso == 14){
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                cout<<"ERROR: "<<gaLinea<<endl<<flush;
            }else{
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
            cout<< "%"<< gaProgreso << "\t"  << gaLinea<<endl<<flush;
            this_thread::sleep_for(chrono::milliseconds(220));
            }
        }
        cout<<" % 100      Carga completa.."<<endl;
        archivo.close();
}

void gaPresentar(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    cout<<"INFORMACION ARBOL BINARIO CAPACIDAD BELICA UCARNIA:"<<endl;
    cout<<"Developer-Nombre :"<<gaNombre<<endl;
    cout<<"Developer-Cedula :"<<gaCedula<<endl;
    cout<<"Capacidad Belica :"<< "30"<<endl;
    cout<<"Coordenadas totales:"<< "8"<<endl;
    cout<<"Coordenada-SecCarga :"<<" 1 2 3 4 5 7 8"<<endl;
}



int main(){
    gaLeerarchivo("Coordenadas.txt");
    gaPresentar();
return 0;
}