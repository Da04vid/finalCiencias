#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;

struct ciudad{
    string nombre,departamento;
    int concejo,censo;
};


class MP{
    public:
        void cargar_datos();
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
    string nombre,departamento,concejoAux;
    int concejo,censo;
    std::random_device rd;
    std::mt19937 gen(rd());
    int min=100;
    int max=5000;
    std::uniform_int_distribution<> dis(min,max);
    while(std::getline(archivo,linea)){
        std::istringstream iss(linea);
        
        std::getline(iss,nombre,',');
        std::getline(iss,departamento,',');
        std::getline(iss,concejoAux,',');
        concejo = std::stoi(concejoAux);
        censo = dis(gen);
        cout<<nombre<<","<<departamento<<","<<concejo<<","<<censo<<endl;
    }
}

// void MP::cargar_candidato(){

// }

// void MP::cargar_partido(){

// }