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
        bool comprobarRepresentante(string nombre);
        bool comprobarCandidato(string nombre, string apellido);
        bool comprobarIdentificacion(int identificacion);
        string calculofechaNacimiento(int anio,int mes,int dia);
        string calculoEstadoCivil(int opc);
};

void BD::insertarCiudad(){
    ofstream archivo;
    string nombre,departamento;
    char respuesta;
    int concejo;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//ciudad.txt");
    do {
        
        archivo.open(s,ios::app);
        if(archivo.fail()){
            cout<<"ERROR AL CREAR EL ARCHIVO";
        }
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
        archivo.close();
        cout << "¿DESEA AGREGAR OTRA CIUDAD? (s/n): ";
        cin >> respuesta;
        
    } while (respuesta == 's' || respuesta == 'S');
    
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
    do {
        archivo.open(s,ios::app);
        if(archivo.fail()){
            cout<<"ERROR AL CREAR EL ARCHIVO";
        }
    
        cout<<"POR FAVOR REGISTRE TODA LA INFORMACION EN MAYUSCULA\n";
        cout << "INGRESE EL NOMBRE DEL PARTIDO\n";
        cin.ignore();
        getline(cin, nombre);
        if(!comprobarPartido(nombre)){
            cout << "INGRESE EL NOMBRE DEL REPRESENTANTE LEGAL\n";
            getline(cin, representante);
            if(!comprobarRepresentante(representante)){
                cout << "¿EL PARTIDO ESTA ACTIVO?\n";
                cout<<"1. SI\n2. NO\n";
                cin>>estado;
                if(estado==2)estado=0;
                archivo << nombre << "," << representante <<"," << estado << "\n";
                cout<<"PARTIDO REGISTRADO EXITOSAMENTE\n";
            }
        }else{
            cout<<"\nEL PARTIDO: "<<nombre<<"  YA EXISTE\n";
        }
        archivo.close();
        cout << "¿DESEA AGREGAR OTRO PARTIDO? (s/n): ";
        cin >> respuesta;
        
    } while (respuesta == 's' || respuesta == 'S');
    
}

bool BD::comprobarPartido(string nombre){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//partido.txt");
    archivo.open(s,ios::in);
    string nombreAux;
    while(std::getline(archivo,linea)){
        std::istringstream iss(linea);
        std::getline(iss,nombreAux,',');
        if(nombre == nombreAux){
            archivo.close();
            return true;
        } 
    }
    return false;
}

bool BD::comprobarRepresentante(string nombre){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//partido.txt");
    archivo.open(s,ios::in);
    string partido, representante;
    while(std::getline(archivo,linea)){
        stringstream ss(linea);
        getline(ss, partido, ',');
        getline(ss, representante, ',');
        cout<<representante<<endl;
        if(nombre == representante){
            archivo.close();
            cout<<"\nEL REPRESENTANTE: "<<nombre<<"  YA EXISTE\n";
            return true;
        }
    }
    return false;
}

void BD::insertarCandidato(){
    ofstream archivo;
    std::string nombre,apellido,estadoCivil,fechaNacimiento,ciudadNacimiento,CiudadRepresenta,Partido,Postulacion;
    int anio,mes,dia,identificacion,estado;
    char respuesta,sexo;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//candidato.txt");
    do {
        archivo.open(s,ios::app);
        if(archivo.fail()){
            cout<<"ERROR AL CREAR EL ARCHIVO";
        }
    
        cout<<"POR FAVOR REGISTRE TODA LA INFORMACION EN MAYUSCULA\n";
        cout << "INGRESE EL NOMBRE DEL CANDIDATO\n";
        cin.ignore();
        getline(cin, nombre);
        cout << "INGRESE EL APELLIDO DEL CANDIDATO\n";
        getline(cin, apellido);
        if(!comprobarCandidato(nombre,apellido)){
            do{
                cout << "DIGITE EL ANIO DE NACIMIENTO DEL CANDIDATO\n";
                cin>>anio;
                if (anio<1953 || anio>2005){
                    cout<<"POR FAVOR INGRESE UN ANIO VALIDO\n";
                }
            }while(anio<1953 || anio>2005);
            do{
                cout << "SELECCIONE EL MES DE NACIMIENTO\n";
                cout<< "1. ENERO\n2. FEBRERO\n3. MARZO\n4. ABRIL\n5. MAYO\n6. JUNIO\n7. JULIO\n8. AGOSTO\n9. SEPTIEMBRE\n10. OCTUBRE\n11. NOVIEMBRE\n12. DICIEMBRE\n";
                cin>>mes;
                if (mes<1 || mes>12){
                    cout<<"POR FAVOR INGRESE UN MES VALIDO\n";
                }
            }while(mes<1 || mes>12);
            do{
                cout << "DIGITE EL DIA DE NACIMIENTO DEL CANDIDATO\n";
                cin>>dia;
                if (dia<1 || dia>31){
                    cout<<"POR FAVOR INGRESE UN DIA VALIDO\n";
                }
            }while(dia<1 || dia>31);
            fechaNacimiento = calculofechaNacimiento(anio,mes,dia);
            do{
                cout<<"INGRESE EL NUMERO DE IDENTIFICACION DEL CANDIDATO\n";
                cin>>identificacion;
                if(comprobarIdentificacion(identificacion)){
                    cout<<"YA EXISTE UN CANDIDATO CON ESA IDENTIFICACION\n";
                }
            }while(comprobarIdentificacion(identificacion));
            do{
                cout<<"INGRESE EL SEXO DEL CANDIDATO\n";
                cout<<"F. FEMENINO\n";
                cout<<"M. Masculino\n";
                cin>>sexo;
                if (sexo!='M' || sexo!='F'){
                    cout<<"POR FAVOR INGRESE UN SEXO VALIDO\n";
                }
            }while(sexo!='M' && sexo!='F');

            cout<<"INGRESE EL ESTADO CIVIL DEL CANDIDATO\n";
            do{
                cout<<"1. CASADO\n2. SOLTERO\n3. UNION LIBRE\n4. DIVORCIADO\n";
                cin>>estado;
                if (estado<1 || estado>4){
                    cout<<"POR FAVOR INGRESE UN ESTADO VALIDO\n";
                }
            }while(estado<1 || estado>4);
            estadoCivil = calculoEstadoCivil(estado);
            cout<<"INGRESE LA CIUDAD DE NACIMIENTO DEL CANDIDATO\n";
            cin >> ciudadNacimiento;
            cout<<"INGRESE LA CIUDAD DE RESIDENCIA DEL CANDIDATO\n";
            cin >> CiudadRepresenta;
            if(!comprobarCiudad(CiudadRepresenta)){
                cout<<"EL CANDIDATO NO PUEDE POSTULARSE POR QUE NO HABITA EN UNA CIUDAD REGISTRADA\n";
            }
            do{
                cout<<"INGRESE EL PARTIDO DEL CANDIDATO\n";
                getline(cin,Partido);
                if(!comprobarPartido(Partido)){
                    cout<<"INGRESE UN PARTIDO VALIDO\n";
                }
            }while(!comprobarPartido(Partido));
            // if(!comprobarRepresentante(representante)){
            //     cout << "¿EL PARTIDO ESTA ACTIVO?\n";
            //     cout<<"1. SI\n2. NO\n";
            //     cin>>estado;
            //     if(estado==2)estado=0;
            archivo << nombre << "," << apellido <<"," << identificacion <<","<<sexo<<","<<estadoCivil<<","<<fechaNacimiento<<","<<ciudadNacimiento<<","<<CiudadRepresenta<<","<<Partido<< "\n";
            cout<<"CANDIDATO REGISTRADO EXITOSAMENTE\n";
            // }
        }else{
            cout<<"CANDIDATO YA REGISTRADO\n";
        }
        archivo.close();
        cout << "¿DESEA AGREGAR OTRO CANDIDATO? (s/n): ";
        cin >> respuesta;
        
    } while (respuesta == 's' || respuesta == 'S');
    
}
string BD::calculoEstadoCivil(int opc){
    string estadoCivil;
    switch (opc) {
        case 1:
            estadoCivil = "CASADO";
            break;
        case 2:
            estadoCivil = "SOLTERO";
            break;
        case 3:
            estadoCivil = "UNION LIBRE";
            break;
        case 4:
            estadoCivil = "DIVORCIADO";
            break;
        
        default:
            estadoCivil = "ESTADO NO VALIDO";
            break;
    }
    return estadoCivil;
}

bool BD::comprobarCandidato(string nombre,string apellido){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//candidato.txt");
    archivo.open(s,ios::in);
    string nombreAux,apellidoAux;
    while(std::getline(archivo,linea)){
        istringstream ss(linea);
        getline(ss,nombreAux,',');
        getline(ss, apellidoAux, ',');
        if (nombre == nombreAux && apellido==apellidoAux) {
            return true;
        }
    }
    return false;
}

bool BD::comprobarIdentificacion(int identificacion){
    ifstream archivo;
    string linea;
    std::string s;
    s.append("C://Users//David//Desktop//Ciencias I//final//BD//candidato.txt");
    archivo.open(s,ios::in);
    std::string nombre,apellido,identificacionStr;
    int identificacionAux;
    while(std::getline(archivo,linea)){
        istringstream ss(linea);
        getline(ss,nombre,',');
        getline(ss, apellido, ',');
        getline(ss,identificacionStr,',');
        identificacionAux = std::stoi(identificacionStr);
        if (identificacion == identificacionAux) {
            return true;
        }
    }
    return false;
}

string BD::calculofechaNacimiento(int anio,int mes,int dia){
    string fechaNacimiento;
    switch (mes) {
        case 1:
            fechaNacimiento = std::to_string(anio) + "-ENERO-" + std::to_string(dia);
            break;
        case 2:
            fechaNacimiento = std::to_string(anio) + "-FEBRERO-" +std::to_string(dia);
            break;
        case 3:
            fechaNacimiento = std::to_string(anio) + "-MARZO-" +std::to_string(dia);
            break;
        case 4:
            fechaNacimiento = std::to_string(anio) + "-ABRIL-" +std::to_string(dia);
            break;
        case 5:
            fechaNacimiento = std::to_string(anio) + "-MAYO-" +std::to_string(dia);
            break;
        case 6:
            fechaNacimiento = std::to_string(anio) + "-JUNIO-" +std::to_string(dia);
            break;
        case 7:
            fechaNacimiento = std::to_string(anio) + "-JULIO-" +std::to_string(dia);
            break;
        case 8:
            fechaNacimiento = std::to_string(anio) + "-AGOSTO-" +std::to_string(dia);
            break;
        case 9:
            fechaNacimiento = std::to_string(anio) + "-SEPTIEMBRE-" +std::to_string(dia);
            break;
        case 10:
            fechaNacimiento = std::to_string(anio) + "-OCTUBRE-" +std::to_string(dia);
            break;
        case 11:
            fechaNacimiento = std::to_string(anio) + "-NOVIEMBRE-" +std::to_string(dia);
            break;
        case 12:
            fechaNacimiento = std::to_string(anio) + "-DICIEMBRE-" +std::to_string(dia);
            break;
        default:
            fechaNacimiento = "MES NO VALIDO";
            break;
    }
    return fechaNacimiento;
}