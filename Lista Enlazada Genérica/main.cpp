#include <iostream>
#include <fstream>
using namespace std;
#include "ListaEnlazada.h"

int main()
{
	ListaEn<int> lista1;
	ListaEn<int> otralist;
	ListaEn<string> lista2;

	int e,l,m,n,t;
	int dim;

    int opc;
	for(;;)
    {
        cout<<"\n*********OPERACIONES CON LISTAS ENLAZADAS**********\n"<<endl;
        cout<<"\n<1>LLENAR\n<2>MOSTRAR\n<3>ANADIR\n<4>ELIMINAR\n<5>BUSCAR\n<6>INVERTIR\n<7>ORDENAR\n<8>COPIAR\n<9>TAMANO\n<0>SALIR "<<endl;
        cout<<"Valor: ";
        cin>>opc;
        switch(opc)
        {
                case 1:
                    cout<<"\n--------------LLENAR LISTA------------\n"<<endl;
                    cout<<endl;
                    cout<<"Ingrese la dimesion de la lista: ";
                    cin>>dim;
                    lista1.llenar(dim);
                    break;
                case 2:
                    cout<<"\n---------------MOSTRAR LISTA-----------\n"<<endl;
                    cout<<"La lista es: "<<endl;
                    lista1.Mostrar();
                    break;
                case 3:
                    char c;
                    cout<<"\n------------------INSERTAR LISTA--------\n"<<endl;
                    cout<<"\n-----INICIO(i)------\n"<<endl;
                    cout<<"\n-----FINAL(f)-------\n"<<endl;
                    cout<<"Escoja (i) o (f): ";cin>>c;
                    switch(c)
                    {
                        case 'i':
                            cout<<"Ingrese un elemento al inicio a la lista: ";
                            cin>>e;cout<<endl;
                            lista1.InsertIni(e);
                            lista1.Mostrar();
                            break;

                        case 'f':
                            cout<<"Ingrese un elemento al final de la lista: ";
                            cin>>l;cout<<endl;
                            lista1.InsertFin(l);
                            lista1.Mostrar();
                            break;
                        default:
                            cout<<"VOLVER"<< endl;

                    }
                    break;

                    case 4:

                        cout<<"\n------------------ELIMINAR--------\n"<<endl;

                        cout<<"Eliminado el primer elemento: ";
                        lista1.EliminarIni();
                        lista1.Mostrar();

                        cout<<"Eliminando el ultimo elemento: ";
                        lista1.EliminarFin();
                        lista1.Mostrar();

                        cout<<"Eliminar un elemento mediante una posiciom: ";
                        cout<<"\nIngrese una posicion: ";cin>>n;
                        lista1.eliminarPos(n);
                        lista1.Mostrar();

                        cout<<"Eliminar un elemento que este en la lista: ";
                        cout<<"\nIngrese el elemento que desee eliminar: ";cin>>t;
                        lista1.EliminarEle(t);
                        lista1.Mostrar();
                        break;

                    case 5:

                        cout<<"\n------------------BUSCAR LISTA--------\n"<<endl;
                        cout<<"\nBuscar un elemento: ";
                        cin>>m;
                        if(lista1.buscarEle(m)==true)
                        {
                            cout<<"El elemento esta en la lista.";
                        }
                        else
                            cout<<"No esta en la lista";
                        break;
                    case 6:
                        cout<<"\n------------------INVERTIR LISTA--------\n"<<endl;
                        cout<<"La lista invertida es: "<<endl;
                        lista1.Invertir();
                        lista1.Mostrar();
                        break;
                    case 7:
                        cout<<"\n------------------ORDENAR LISTA--------\n"<<endl;
                        cout<<"La lista ordenada es: "<<endl;
                        lista1.inSort();
                        lista1.Mostrar();
                        break;
                    case 8:
                        cout<<"\n------------------COPIAR ELEMS. A OTRA LISTA--------\n"<<endl;
                        //lista2.Mostrar();
                        cout<<"Lista: "<<endl;
                        lista1.Mostrar();
                        cout<<"Copiando..."<<endl;
                        lista1.copiar(otralist);
                        cout<<"Otra Lista: "<<endl;
                        otralist.Mostrar();
                        break;
                    case 9:
                        cout<<"\n------------------TAMAÑO DE LA LISTA--------\n"<<endl;
                        cout<<"Es: "<<lista1.getTama();
                        break;

                    case 0:
                        cout<<"\n---------------PROGRAMA TERMINADO--------\n"<<endl;
                        return 0;

                    default:
                        cout<<"\n\nINCORRECTO!!!\nINGRESE UNA OPCION CORRECTA "<<endl;
                }
    }
    return 0;
	//Tarea: Hacer más funciones para lista enlazada, no usar var=tamaño pero si tener una
	//funcion q devuelva el tamaño*/

}
