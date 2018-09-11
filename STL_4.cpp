#include <iostream>
#include <vector>
using namespace std;
template<class T>
void reverseVector(vector<T>&lista)
{
    T aux;
    for(int i=0;i<lista.size()/2;i++)
    {
        aux=lista[i];
        lista[i]=lista[lista.size()-1-i];
        lista[lista.size()-1-i]=aux;
    }

}

int main()

{
    vector<int> lista1;
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(4);
    reverseVector(lista1);
    for(vector<int>::iterator it =lista1.begin();it!=lista1.end();++it)
    {
        cout<<*it<<" ";
    }
}