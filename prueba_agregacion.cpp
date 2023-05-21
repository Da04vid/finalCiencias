#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir(string bd);
string leer(string bd);

int main(){
    string bd = "candidatos";
    escribir(bd);
    system("pause");
    return 0;
}


void escribir(string bd){
    ofstream ciudades;
    bd.c_str();
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//").append(bd).append(".txt");
    ciudades.open(s,ios::out);
    if(ciudades.fail()){
        cout<<"Error al crear el archivo";
    }
    ciudades<<"Hola como estas?, Bien";
    ciudades.close();
}

