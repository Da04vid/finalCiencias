#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class BD{
    public:
        void insertarCiudad();
        void insertarCandidato();
        void insertarPartido();
    private:
        bool comprobarCiudad(string nombre);
        bool comprobarPartido(string nombre);
};

void BD::insertarCiudad(){
    ofstream archivo;
    string nombre,departamento;
    char respuesta;
    int concejo;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//ciudad.txt");
    archivo.open(s,ios::app);
    if(archivo.fail()){
        cout<<"ERROR AL CREAR EL ARCHIVO";
    }
    do {
        cout<<"POR FAVOR REGISTRE TODA LA INFORMACION EN MAYUSCULA\n";
        cout << "INGRESE EL NOMBRE DE LA CIUDAD: ";
        cin.ignore();
        getline(cin, nombre);
        if(!comprobarCiudad(nombre)){
            cout<<endl;
            cout << "INGRESE EL DEPARTAMENTO AL QUE PERTENECE LA CIUDAD: ";
            getline(cin, departamento);
            cout<<endl;
            cout << "INGRESE EL TAMANIO DEL CONCEJO DE LA CIUDAD: ";
            cin >> concejo;
            archivo << nombre << "," << departamento <<"," << concejo << endl;
            cout<<"PARTIDO REGISTRADO EXITOSAMENTE\n";
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

void BD::insertarPartido(){
    ofstream archivo;
    string nombre,representante;
    int estado;
    char respuesta;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//partido.txt");
    archivo.open(s,ios::app);
    if(archivo.fail()){
        cout<<"ERROR AL CREAR EL ARCHIVO";
    }
    do {
        cout<<"POR FAVOR REGISTRE TODA LA INFORMACION EN MAYUSCULA\n";
        cout << "INGRESE EL NOMBRE DEL PARTIDO\n";
        cin.ignore();
        getline(cin, nombre);
        if(!comprobarPartido(nombre)){
            cout << "INGRESE EL NOMBRE DEL REPRESENTANTE LEGAL\n";
            getline(cin, representante);
            cout << "¿EL PARTIDO ESTA ACTIVO?\n";
            cout<<"1. SI\n2. NO\n";
            cin>>estado;
            if(estado==2)estado=0;
            archivo << nombre << "," << representante <<"," << estado << endl;
            cout<<"PARTIDO REGISTRADO EXITOSAMENTE\n";
        }
        cout << "¿DESEA AGREGAR OTRO PARTIDO? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
    archivo.close();
}

bool BD::comprobarPartido(string nombre){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//partido.txt");
    archivo.open(s,ios::in);
    while(std::getline(archivo,linea)){
        std::istringstream iss(linea);
        string nombreAux;
        std::getline(iss,nombreAux,',');
        cout<<nombreAux;
        if(nombre == nombreAux){
            archivo.close();
            cout<<"\nEL PARTIDO: "<<nombre<<"  YA EXISTE\n";
            return true;
        } 
    }
    return false;
}
