#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//238
class Polinomio{
private:
    int grado;
    vector<int> pol;
public:
    Polinomio(int grad=0){
        grado=grad;
        pol.assign(grad,0);
    }
    Polinomio(int lis[],int n){
        grado=n;
        //copy(lis,lis+grado,pol.begin());
        for(int i=0;i<n;i++){
            pol.push_back(lis[i]);
        }
    }
    void a_coeficiente(int grado,int valor){
        if(this->grado<grado)pol.resize(grado);
        pol[grado]=valor;
    }
    void s_coeficiente(int grado,int valor){
        if(this->grado<grado)pol.resize(grado);
        pol[grado]+=valor;
    }
    void mostrar(){
        bool inicio=false;
        for(int i=grado-1;i>=0;i--){
            if(pol[i]==0)continue;
            if(pol[i]>0){
                if(inicio)cout<<"+";
            }
            inicio=true;
            if(i==0)cout<<pol[i];
            else if(i==1)cout<<pol[i]<<"x";
            else cout<<pol[i]<<"x^"<<i;

        }
        cout<<endl;
    }
    int get_g(){
        return grado;
    }
    int get_i(int i){
        return pol[i];
    }
    Polinomio operator + (Polinomio&p){
        int ma=max(grado,p.get_g());
        Polinomio aux(ma);
        for(int i=0;i<ma;i++){
            aux.a_coeficiente(i,pol[i]+p.get_i(i));
        }
        return aux;
    }
    Polinomio operator - (Polinomio&p){
        int ma=max(grado,p.get_g());
        Polinomio aux(ma);
        for(int i=0;i<ma;i++){
            aux.a_coeficiente(i,pol[i]-p.get_i(i));
        }
        return aux;
    }
    Polinomio operator *(Polinomio&p){
        Polinomio aux(grado+p.get_g());
        for(int i=0;i<grado;i++){
            for(int j=0;j<p.get_g();j++){
                aux.s_coeficiente(i+j,pol[i]*p.get_i(j));
            }
        }
        return aux;

    }
    Polinomio operator ~ (){
        for(int i=0;i<grado;i++){;
            pol[i]=pol[i+1]*(i+1);
        }
        grado--;
        pol.resize(grado);
    }
};


int main(){
    /*
    int lista[] ={2,1,3,0,1};
    int lista2[] ={1,0,3,4,5};
    Polinomio p1(lista,5);
    Polinomio p2(lista2,5);
    p1.mostrar();
    p2.mostrar();
    Polinomio p3 =p1+p2;
    //Polinomio p3 =p1-p2;
    p3.mostrar();
    */
    int lista3[] ={0,-2,3};
    int lista4[] ={-3,2};
    Polinomio p4(lista3,3);
    Polinomio p5(lista4,2);
    p4.mostrar();
    p5.mostrar();
    Polinomio p6 =p4*p5;
    //Polinomio p3 =p1-p2;
    p6.mostrar();
    ~p6;
    p6.mostrar();

}