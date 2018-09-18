#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include "Nodo.h"
using namespace std;
#include <stdlib.h>
#include <time.h>

template <class leType>
class ListaEn
{
    Nodo<leType> *inicio;//Puntero al primero nodo o inicio
    Nodo<leType> *fin;//Puntero al ultimo nodo
public:
	ListaEn();
	~ListaEn();
	ListaEn<leType>(const ListaEn<leType> &);
    //void setNodo(class Nodo,int,*);
	void InsertIni(const leType&);
	void InsertFin(const leType&);
	void llenar(int);
	void llenar_r(int);
	void EliminarIni();
	void EliminarFin();
	int getTama() const;
	void eliminarPos(int);
	void EliminarEle(const leType&);
	bool buscarEle(const leType&);
	void inSort();
	void Invertir();
	void Mostrar() const;
	const ListaEn<leType>& copiar(ListaEn<leType>&);
};
//CONSTRUCTOR
template<class leType>
ListaEn<leType>::ListaEn()/*se incicializa ambos apuntando al null*/
{
    this->inicio=NULL;
    this->fin=NULL;
}
//CONSTRUCTOR COPIA
/*template<class leType>
ListaEn<leType>::ListaEn(const ListaEn<leType>& otraList)
{
    Nodo<leType> *aux,*temp;
    if(otraList.getTama()>0)
    {
        aux=otraList.I;
        I = new Nodo<leType>(temp->sig(),NULL);
        temp=I;
        aux=aux->sig();
        while(aux!=NULL)
        {
            temp->
        }

    }

}*/

template<class leType>
void ListaEn<leType>::InsertIni(const leType& dato)
{
	Nodo<leType> *nuevo_nodo=new Nodo<leType> (dato);
	Nodo<leType> *temp=inicio;
	if(inicio==NULL)
	{
		inicio=nuevo_nodo;
	}
	else
	{
	    nuevo_nodo->sig=inicio;
	    inicio=nuevo_nodo;
	    while(temp!=NULL)
        {
            temp=temp->sig;
        }
	}
}
template<class leType>
void ListaEn<leType>::InsertFin(const leType& dato)
{
	Nodo<leType> *nuevo_nodo=new Nodo<leType> (dato);
	Nodo<leType> *temp=inicio;
	if (inicio==NULL)
	{
		inicio=nuevo_nodo;
	}
	else
	{
		while(temp->sig!=NULL)
		{
			temp=temp->sig;
		}
		temp->sig=nuevo_nodo;
		//nuevo_nodo=fin;
	}
}
template<class leType>
void ListaEn<leType>::llenar_r(int dim)
{
    int num;
    srand(time(NULL));
    for(int i=0;i<dim;i++)
    {
        InsertFin(rand()%100);
    }
}
template<class leType>
void ListaEn<leType>::llenar(int dim)
{
    int num;
    cout<<"Ingrese los valores de la lista: ";
    //srand(time(NULL));
    for(int i=0;i<dim;i++)
    {
        cout<<"\nValor: ";
        cin>>num;
        InsertFin(num);
    }
}
template<class leType>
void ListaEn<leType>::EliminarIni()
{
	leType de;
	Nodo<leType> *aux1=inicio;//aux=primer nodo (direccion de memoria del primer puntero)
	de=aux1->dato;//guarda el dato del primer nodo en una variable de tipo entera
    inicio=inicio->sig;//el inicio ahora será el siguiente de el mismo
	delete aux1;//Desasigna la memoria del nodo aux
}
template<class leType>
void ListaEn<leType>::EliminarFin()
{
    leType ult,pen;
    Nodo<leType> *aux1=inicio;
    Nodo<leType> *aux2=inicio->sig;
    if(inicio==NULL)
    {
        cout<<"La lista está vacia"<<endl;
    }
    else
    {
        if(aux2==NULL)
        {
            inicio=fin=NULL;
            return;
        }
        while(aux2->sig!=NULL)
        {
            aux1=aux2;
            aux2=aux2->sig;
        }
        fin=aux1;
        aux1->sig=NULL;
        //delete aux2;
    }
}
template<class leType>
void ListaEn<leType>::eliminarPos(int pos)
{
    Nodo<leType> *temp=inicio;
    Nodo<leType> *temp1=temp->sig;

    if(pos<1 || pos>getTama())
    {
        cout<<"Esta posicion no se encuentra en la lista "<<endl;
    }
    else if(pos==1)
    {
        inicio=temp->sig;
    }
    else
    {
        for(int i=2;i<=pos;i++)
        {
            if(i==pos)
            {
                Nodo<leType> *aux=temp1;
                temp->sig=temp1->sig;
                delete aux;
            }
            temp=temp->sig;
            temp1=temp1->sig;
        }
    }
}
template<class leType>
bool ListaEn<leType>::buscarEle(const leType& x)
{
    Nodo<leType> *temp=inicio;
    Nodo<leType> *temp1;

    if(inicio==NULL)
    {
        cout<<"Lista Vacia"<<endl;
    }
    else
    {
        if(inicio->dato==x)
        {
            return true;
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->dato==x)
                {
                    return true;
                }
                else
                {
                    temp=temp->sig;
                }
            }
        }

    }
}
template<class leType>
void ListaEn<leType>::EliminarEle(const leType& data)
{
    Nodo<leType> *aux=inicio;
    Nodo<leType> *ant;

    if(inicio==NULL)
    {
        cout<<"\nLista Vacia"<<endl;
    }
    if(inicio->dato==data)
    {
        inicio=inicio->sig;
        delete aux;
        return;
    }
    else
    {
        if(aux->sig==NULL)
        {
            if(aux->dato==data)
            {
                delete aux;
                inicio=0;
            }
        }
        else
        {
            while(aux->sig!=NULL)
            {
                ant=aux;
                aux=aux->sig;
                if(aux->dato==data)
                {
                    ant->sig=aux->sig;
                    delete aux;
                    return;
                }
            }
            cout<<"El elemento a eliminar no se encontró";
        }

    }
}
template <class leType>
void ListaEn<leType>::inSort()
{
    Nodo<leType> *iz=inicio;
    Nodo<leType> *actual=iz;

    while(iz!=NULL)
    {
        actual=iz;

        while(actual->sig!=NULL)
        {
            actual=actual->sig;
            if(iz->dato > actual->dato)
            {
                swap(iz->dato,actual->dato);
                /*int temp=iz->dato;
                iz->dato=actual->dato;
                actual->dato=temp;*/
            }
        }
        iz=iz->sig;
    }

}
template <class leType>
void ListaEn<leType>::Invertir()
{
    Nodo<leType> *prev=fin;
    Nodo<leType> *sig=NULL;
    Nodo<leType> *aux=inicio;

    while(aux!=NULL)
    {
        sig=aux->sig;
        aux->sig=prev;
        prev=aux;
        aux=sig;
    }
    inicio=prev;
}
template <class leType>
void ListaEn<leType>::Mostrar() const
{
	Nodo<leType> *aux=inicio;
	if(inicio==NULL)
    {
        cout<<" La lista esta vacia "<<endl;
    }
    else
    {
        while(aux!=NULL)
        {
            aux->getDato();
            aux=aux->sig;
        }
        cout<<"NULL";
    }
    cout<<endl<<endl;
}
template <class leType>
int ListaEn<leType>::getTama() const
{
    Nodo<leType> *aux1=inicio;
    int s=0;
    while(aux1!=NULL)
    {
        if(aux1==NULL)
        {
            break;
        }
        s++;
        aux1=aux1->sig;
    }
    return s;
    //cout<<s<<endl;
}
template <class leType>
const ListaEn<leType>& ListaEn<leType>::copiar(ListaEn<leType>& lista2)
{
    Nodo<leType> *temp= this->inicio;
    lista2.inicio = new Nodo<leType>(temp->dato);
    Nodo<leType>* copiador = lista2.inicio;
    while(temp->sig){
        copiador->sig = new Nodo<leType>(temp->sig->dato);
        copiador = copiador->sig;
        temp = temp->sig;
    }
    lista2.fin = copiador;

    return lista2;
}
template <class leType>
ListaEn<leType>::~ListaEn() {}
#endif // LISTAENLAZADA_H_INCLUDED
