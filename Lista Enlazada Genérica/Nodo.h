#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>
using namespace std;

template <class nodoType>
class Nodo //definiendo la clase nodo
{

private:
    nodoType dato;//es el contenido que estara dentro de cada nodo el cual será de tipo entero
    Nodo *sig;//puntero al siguiente nodo

public:
    template<typename listType>
    friend class ListaEn;//se declara como amiga la clase ListaEn para que esta pueda acceder al los datos miembros de la clase Nodo
	Nodo();//Constructor predeterminado de la clase nodo
	Nodo(const nodoType&);//Constructor por parametros de la clase nodo
	Nodo<nodoType>(const Nodo<nodoType> &n) : dato(n.dato),sig(n.prox){};
	~Nodo();//Destructor de la clase nodo

    void getDato() const;//funcion devuele el valor que contiene el nodo
    void deleteDato();//funcion que elimina el valor que contiene el nodo
};

template<class nodoType>
Nodo<nodoType>::Nodo()/*Inicializamos el dato y el siguiente nodo como NULL de forma predeterminada*/
{
	dato=NULL;
	sig=NULL;
}

template<class nodoType>
Nodo<nodoType>::Nodo(const nodoType& dato)/*Inicializamos mediante un dato de tipo entero el dato y como NULL el siguente nodo*/
{
    this->dato=dato;
    this->sig=NULL;
}

template<class nodoType>
void Nodo<nodoType>::getDato() const /*Imprime el dato que contiene el nodo"*/
{
	cout<<dato<<" -> ";
}

template<class nodoType>
void Nodo<nodoType>::deleteDato()/*Borra el dato que contiene el nodo*/
{
	if(sig!=NULL)
	{
		sig->deleteDato();
	}
	delete this;
}

template<class nodoType>
Nodo<nodoType>::~Nodo() {}
#endif // NODO_H_INCLUDED
