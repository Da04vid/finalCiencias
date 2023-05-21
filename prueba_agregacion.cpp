#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir(string bd);
string leer(string bd);

int main(){
    string bd = "candidatos";
    escribir(bd);
    cout << leer(bd);
    system("pause");
    return 0;
}


void escribir(string bd){
    ofstream archivo;
    bd.c_str();
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//").append(bd).append(".txt");
    archivo.open(s,ios::app);
    if(archivo.fail()){
        cout<<"Error al crear el archivo";
    }
    archivo<<"Hola como estas?, Bien";
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

