#include <iostream>
#include <stdlib.h>
using namespace std;


template <class myType>
class safeArray{
private:
    int tamano;
    int limite;
    myType lista[100];
    int  indi;
public:
    safeArray(int indice,int tama){
        limite=tama;
        indi=indice;
        if(indi>0){
            tamano=tama-indi;
        }
        else{
            tamano=tama+abs(indice);}
        for(int i=0;i<tamano;i++){
            lista[i]=0;}
    }

    void llenar(){
        for(int i=0;i<tamano;i++){
            cin>>lista[i];


        }

    }

    void mostrar(){
        for(int i=0;i<tamano;i++){
            cout<<lista[i]<<" ";
        }
        cout<<endl;
    }

    void consul(int consu){
        if((consu<0 && indi>0) || (consu>=limite)|| (consu<indi)){
            cout<<"Fuera de limite"<<endl;
        }
        else if(consu<0&&indi<0){
            cout<<"Valor en la posicion: "<<lista[abs(indi)-abs(consu)];
        }
        else if(consu>0 && indi<0){
            cout<<"Valor en la posicion: "<<lista[abs(indi)+abs(consu)];

        }

        else if(consu<limite && consu>0){
             cout<<"Valor en la posicion: "<<lista[consu-indi];

        }
        else if(consu==indi){
            cout<<"Valor en la posicion: "<<lista[0];
        }
    }



};





int main()
{
    safeArray <char> arra(-5,9);
    arra.llenar();
    arra.mostrar();
    arra.consul(-4);
    return 0;
}