#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "StackADT.h"
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Pila
{
private:
    int tamano;
    int cima;
    T *pilaPtr;
public:
    Pila(int=10);
    ~Pila()
    {
        delete []pilaPtr;
    }
    bool push(const T &);
    bool pop(T &);

    bool estaVacia()
    {
        return cima==-1;
    }
    bool estaLlena()
    {
        return cima==tamano-1;
    }
};

template<typename T>
Pila<T>::Pila(int s)
    :tamano(s>0 ? s:10),
    cima(-1),
    pilaPtr(new T[tamano])
    {

    }
template<typename T>
bool Pila<T>::push(const T &valorMeter)
{
    if(!estaLlena())
    {
        pilaPtr[++cima]=valorMeter;
        return true;
    }
}
template<typename T>
bool Pila<T>::pop(T &valorSacar)
{
    if(!estaVacia())
    {
        valorSacar = pilaPtr[cima--];
        return true;
    }
    return false;
}


#endif // PILA_H_INCLUDED
