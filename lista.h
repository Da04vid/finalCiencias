#include <iostream>

#ifndef LISTA_H
#define LISTA_H

using namespace std;

template <class T>
struct nodo {
	T Dato;
	nodo<T> *sig;
};
template <class T>
class lista{
    nodo<T> *cab;
    nodo<T> *fin;
    int tam;

	public:
		lista() {
            cab = new nodo<T>;
            fin = NULL;
			tam=0;
		}
		void mostrar_lista(string tabla);
		int getTam() {
			return tam;
		}
		bool lista_vacia();
		void insertar(T Dato);
		bool borrar(int id);
		T buscar (int id);
		bool modificar(int  id,string tabla,string campo);
    private:
        void modificar_ciudad(string campo, T Dato);
        void modificar_candidato(string campo, T Dato);
        void modificar_partido(string campo, T Dato);
};
template <class T>
void lista<T>::mostrar_lista(string tabla){
	if(lista_vacia()) {
		cout << "La lista esta vacia." << endl;
		return;
	}
	nodo<T> *p = cab->sig;
	while(p != NULL) {

        if (tabla=="ciudad"){
            cout<<"ID DE LA CIUDAD: "<<p->Dato.id<<endl;
            cout<<"NOMBRE DE LA CIUDAD: "<<p->Dato.nombre<<endl;
            // cout<<"DEPARTAMENTO DE LA CIUDAD: "<<p->Dato.departamento<<endl;
            // cout<<"TAMANIO DEL CONCEJO DE LA CIUDAD: "<<p->Dato.concejo<<endl;
            // cout<<"CENSO DE LA CIUDAD: "<<p->Dato.censo<<endl;
        }
		p = p->sig;
	}
}

template <class T>
bool lista<T>::lista_vacia(){
	if(tam==0) {
		return true;
	}
	return false;
}

template <class T>
void lista<T>::insertar(T Dato){
    nodo<T> *p = cab->sig;
	nodo<T> *ant = cab;
	nodo<T> *nuevo = new nodo<T>;
	nuevo->Dato = Dato;
	while(p != NULL && p->Dato.id < Dato.id) {
		ant = p;
		p = p->sig;
	}
	ant->sig = nuevo;
	nuevo->sig = p;
	tam++;
}

template <class T>
bool lista<T>::borrar(int id){
    nodo<T> *p = cab->sig;
	nodo<T> *ant = cab;
	while(p != NULL && p->Dato.id != id) {
		ant = p;
		p = p->sig;
	}
	if(p == NULL) {
		return false;
	}
	ant->sig = p->sig;
	delete p;
	tam--;
	return true;
}

template<class T>
T lista<T>::buscar(int id){
    nodo<T> *p = cab->sig;
	while(p != NULL && p->Dato.id != id) {
		p = p->sig;
	}
	if(p == NULL) {
		T vacio = {"NULO", -1};
		return vacio;
	}
	return p->Dato;
}

template <class T>
bool lista<T>::modificar(int id,string tabla,string campo){
    nodo<T> *p = cab->sig;
	while(p != NULL && p->Dato.id != id) {
		p = p->sig;
	}
	if(p == NULL) {
		return false;
	}
    if (tabla == "Ciuddad"){
        modificar_ciudad(campo,p);
    }
    // else if(tabla == "Candidato"){
    //     modificar_candidato(campo,p);
    // }else if(tabla == "Partido"){
    //     modificar_partido(campo,p);
    // }
	return true;
}

template<class T>
void lista<T>::modificar_ciudad(string campo, T Dato){
    if (campo=="nombre"){
        cout<< "INGRESE EL NUEVO NOMBRE: \n";
        cin>> Dato.nombre;
    }else if(campo=="departamento"){
        cout<< "INGRESE EL NUEVO DEPARTAMENTO: \n";
        cin>> Dato.departamento;
    }else if(campo=="concejo"){
        cout<< "INGRESE EL NUEVO TAMANIO DEL CONCEJO: \n";
        cin>> Dato.concejo;
    }else if(campo=="censo"){
        cout<< "INGRESE EL NUEVO CENSO ELECTORAL: \n";
        cin>> Dato.censo;
    }

}

#endif