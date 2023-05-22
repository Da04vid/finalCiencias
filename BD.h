#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class BD{
    public:
        void insertarCiudad();
    private:
        bool comprobarCiudad(string nombre);
};

void BD::insertarCiudad(){
    ofstream archivo;
    string nombre,departamento;
    char respuesta;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//ciudad.txt");
    archivo.open(s,ios::app);
    if(archivo.fail()){
        cout<<"ERROR AL CREAR EL ARCHIVO";
    }
    do {
        cout<<"POR FAVOR REGISTRE TODA LA INFORMACION EN MAYUSCULA\n";
        cout << "INGRESE EL NOMBRE DE LA CIUDAD: ";
        cin >> nombre;
        if(!comprobarCiudad(nombre)){
            cout<<endl;
            cout << "INGRESE EL DEPARTAMENTO DE LA CIUDAD: ";
            cin >> departamento;
            archivo << nombre << "," << departamento << endl;
        }else{
            cout<<"LA CIUDAD YA EXISTE\n";
        }
        
        cout << "¿DESEA AGREGAR OTRA CIUDAD? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    archivo.close();
}

bool BD::comprobarCiudad(string nombre){
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
