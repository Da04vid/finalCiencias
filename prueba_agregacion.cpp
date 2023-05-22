#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir(string bd);
string leer(string bd);

int main(){
    string bd = "ciudades";
    escribir(bd);
    cout << leer(bd);
    system("pause");
    return 0;
}


void escribir(string bd){
    ofstream archivo;
    string nombre;
    char respuesta;
    int poblacion;
    bd.c_str();
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//").append(bd).append(".txt");
    archivo.open(s,ios::app);
    if(archivo.fail()){
        cout<<"Error al crear el archivo";
    }
    do {
        cout << "Ingrese el nombre de la ciudad: ";
        cin >> nombre;

        cout << "Ingrese la poblacion de la ciudad: ";
        cin >> poblacion;

        archivo << nombre << "," << poblacion << endl;

        cout << "¿Desea agregar otra ciudad? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    archivo.close();
}

string leer(string bd){
    ifstream archivo;
    string texto;
    bd.c_str();
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//").append(bd).append(".txt");
    archivo.open(s,ios::in);
    if (archivo.fail()){
        cout<<"Error al abrir el archivo";
    }
    while(!archivo.eof()){
        getline(archivo,texto);
    }
    archivo.close();
    return texto;
}

