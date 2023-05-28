#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include "lista.h"
using namespace std;

struct ciudad{
    std::string nombre,departamento;
    int id,concejo,censo;
};


class MP{
    public:
        void cargar_datos();
        lista<ciudad> lista_ciudad;
    private:
        void cargar_ciudad();
        // void cargar_candidato();
        // void cargar_partido();
};

void MP::cargar_datos(){
    cargar_ciudad();
}

void MP::cargar_ciudad(){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//ciudad.txt");
    archivo.open(s,ios::in);
    std::string nombre,departamento,concejoAux,idAux;
    int id,concejo,censo;
    std::random_device rd;
    std::mt19937 gen(rd());
    int min=100;
    int max=5000;
    ciudad ciudadAux;
    std::uniform_int_distribution<> dis(min,max);
    while(std::getline(archivo,linea)){
        std::istringstream iss(linea);
        std::getline(iss,idAux,',');
        id = std::stoi(idAux);
        std::getline(iss,nombre,',');
        std::getline(iss,departamento,',');
        std::getline(iss,concejoAux,',');
        concejo = std::stoi(concejoAux);
        censo = dis(gen);
        cout<<id<<","<<nombre<<","<<departamento<<","<<concejo<<","<<censo<<endl;
        ciudadAux.id = id;
        ciudadAux.nombre=nombre;
        ciudadAux.departamento=departamento;
        ciudadAux.concejo=concejo;
        ciudadAux.censo=censo;
        lista_ciudad.insertar(ciudadAux);
    }
    lista_ciudad.mostrar_lista("ciudad");
}

// void MP::cargar_candidato(){

// }

// void MP::cargar_partido(){

// }