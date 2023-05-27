#include <iostream>
#include <stdlib.h>
#include "BD.h"
using namespace std;


void registrar(BD bd);

int main(){
    cout<<"BIENVENIDO"<<endl;
    int respuesta;
    do{
        cout<<"SELECCIONE UNA DE LAS SIGUIENTES OPCIONES\n";
        cout<<"1. REGISTRAR CIUDAD, CANDIDATO O PARTIDO\n";
        cout<<"2. SALIR\n";
        cin>>respuesta;
        switch (respuesta){
        case 1:
            BD bd;
            registrar(bd);
            break;
        case 2:
            exit(1);
            break;
        default:
            break;
        }
    }while(respuesta!=2);

    system("pause");
    return 0;
}


void registrar(BD bd){
    int respuesta;
    do{ 
        cout<<"SELECCIONE QUE DESEA REGISTRAR\n";
        cout<<"1. CIUDAD\n";
        cout<<"2. CANDIDATO\n";
        cout<<"3. PARTIDO\n";
        cout<<"4. VOLVER\n";
        cout<<"5. SALIR\n";
        cin>>respuesta;
        switch (respuesta){
        case 1:
            bd.insertarCiudad();
            break;
        case 2:
            bd.insertarCandidato();
            break;
        case 3:
            bd.insertarPartido();
            break;
        case 4:
            break;
        case 5:
            exit(1);
            break;
        default:
            respuesta=0;
            break;
        }
        if ((respuesta != 4) && (respuesta!=5)){
            cout<<"DESEA REGISTRAR MAS INFORMACION\n";
            cout<<"1. SI\n2. NO\n";
            cin>>respuesta;
            if (respuesta==2){
                respuesta=4;
            }
        }
    }while(respuesta!=4);
}


