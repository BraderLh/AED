   #include <iostream>
   #include <vector>
   #include <math.h>
   using namespace std;

    int main()

 {
    int n;
    cout<<"Ingrese el numero de elementos"<<endl;
    cin>>n;
    vector<int> lista2(n);
    cout<<"Ingrese los numeros"<<endl;
    for(int i=0;i<n;i++)
    {

        cin>>lista2[i];
    }
    float s=0,media;
    for(int k=0;k<n;k++)
    {
        s=s+lista2[k];
    }
    media=s/n;

    cout<<"La media es "<<media<<endl;
    float d_standar,s2=0;
    for(int h=0;h<n;h++)
    {
        s2=s2+pow((lista2[h]-media),2);
    }
    d_standar=sqrt(s2/n);
    cout<<"La desviacion estandar es "<<d_standar<<endl;
 }