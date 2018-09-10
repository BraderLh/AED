#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <stdlib.h>


using namespace std;




int main()
{
	int numest;
	cout<<"Digite el numero de estudiantes que desea ingresar: ";
	cin>>numest;
	vector <string> estudiantes(numest);
	vector <float> puntajes(numest);
	vector <int> puntajesbajos;
	float totalp=0;
	float promedio=0;;
	float mayor;
	
	

	for (int i = 0; i < numest; ++i)
	{
		cout<<"Escriba el nombre del estudiante: ";
		cin>>estudiantes[i];
		cout<<"Digite el puntaje del estudiante: ";
		cin>>puntajes[i];
		totalp+=puntajes[i];
		
	}
	promedio=totalp/numest;
	for (int i = 0; i < numest; ++i)
	{

		if(puntajes[i]<promedio){
			puntajesbajos.push_back(i);
		}

		
	}
	cout<<"Estudiantes\tPuntaje\t\t"<<"\t\tObservacion"<<endl;
	for (int i = 0; i < puntajesbajos.size(); ++i)
	{
		//cout<<puntajesbajos[i]<<puntajesbajos[i]<<endl;
		cout<<estudiantes[puntajesbajos[i]]<<"\t\t"<<puntajes[puntajesbajos[i]]<<"\t\t(No obtuvo una nota mayor al promedio) " <<endl;
		
	}
	cout<<"Promedio de estudiantes: "<<promedio<<endl;;
	//cout<<"El ganador es: \t"<<apellidos[mayor]<<endl;
	
	return 0;
}