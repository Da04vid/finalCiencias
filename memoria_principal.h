#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class MP{
    public:
        void cargar_datos();
    private:
        void cargar_ciudad();
        void cargar_candidato();
        void cargar_partido();
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
    while(std::getline(archivo,linea)){
        std::istringstream iss(linea);
        string nombreAux;
        std::getline(iss,nombreAux,',');
        cout<<nombreAux;
        if(nombre == nombreAux){
            archivo.close();
            cout<<"\nLA CIUDAD: "<<nombre<<"  YA EXISTE\n";
            return true;
        } 
    }
    return false;
}

void MP::cargar_candidato(){

}

void MP::cargar_partido(){

}