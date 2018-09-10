#include <iostream>
#include <string>

using namespace std;
class largeInteger{
private:
    string numero;
    int tam;
    friend ostream& operator <<(ostream&o,const largeInteger&a);
public:
    largeInteger(string num="0",int tam=0):numero(num),tam(num.size()){}
    int get_t(){
        return tam;
    }
    string get_s(){
        return numero;
    }

    largeInteger operator + (largeInteger a){
        int tam1=tam,tam2=a.get_t();
        int su,aux=0,ma=max(tam1,tam2)-1;
        string re="";
        for(;ma>=0;){
            tam1--;tam2--;
            if(tam2<0)su=int(numero[tam1]-'0')+aux;
            else if(tam1<0)su=int(a.get_s()[tam2]-'0')+aux;
            else su=int(a.get_s()[tam2]-'0')+int(numero[tam1]-'0')+aux;
            if(su>9){aux=1;su=su-10;}
            else aux=0;
            re=char(su+'0')+re;
            ma--;
        }
        if(aux==1)re='1'+re;
        largeInteger b(re);
        return b;
    }
    largeInteger operator - (largeInteger a){
        int tam1=tam,tam2=a.get_t();
        int resta,aux=0,ma=tam1;
        int temp1,temp2;
        string re="";
        bool com=false;
        if(tam2>tam1){
            com=true;
            ma=tam2;
        }
        for(;ma-1>=0;){
            tam1--;tam2--;
            temp1=numero[tam1]-'0';
            temp2=a.get_s()[tam2]-'0';
            if(com)swap(temp1,temp2);
            if(tam2<0){
                resta=temp1+aux;
                aux=0;
                if(resta==0)break;
            }
            else if(tam1<0){
                resta=temp1+aux;
                aux=0;
                if(resta==0)break;
            }
            else if(temp1>=temp2){
                temp1+=aux;
                resta=temp1-temp2;
                aux=0;
            }
            else{
                temp1+=aux;
                resta=(10+temp1)-temp2;
                aux=-1;
            }
            re=char(resta+'0')+re;
            ma--;
        }
        if(com)re='-'+re;
        largeInteger b(re);
        return b;
    }
    largeInteger operator * (largeInteger a){
        int mu,aux,aux2;
        int temp1,temp2,com=false;
        string re="";
        for(int i=tam-1;i>=0;i--){
            aux=0;
            for(int j=a.get_t()-1;j>=0;j--){
                temp1=numero[i]-'0';
                temp2=a.get_s()[j]-'0';
                mu=temp1*temp2+aux;
                if(i==tam-1)re=char(mu%10+'0')+re;
                else{
                    aux2=mu%10+int(re[j]-'0');
                    if(aux2>9){
                        aux2-=10;
                        com=true;
                    }
                    else com=false;
                    re[j]=char(aux2+'0');

                }
                if(mu>10){aux=(mu-mu%10)/10;}
                else aux=0;
                if(com)aux++;
                //cout<<i<<""<<j<<""<<aux<<endl;
                //cout<<temp1<<""<<temp2<<""<<mu<<"*"<<aux<<endl;

            }
            if(i>0)re=char(aux+'0')+re;
            //cout<<re<<endl;
        }

        largeInteger b(re);
        return b;

    }
};

ostream& operator <<(ostream&o,const largeInteger&a){
        o<<a.numero;
        return o;
    }
int main(){
    largeInteger n1("99999999999999999999999999999999999"),n2("1");
    largeInteger n3("99999999999999999999999999999999999"),n4("99999999999999999999999999999999999999999");
    largeInteger n5("999999999999999"),n6("999999999999999");
    cout<<n1<<"+"<<n2<<"="<<n1+n2<<endl;
    cout<<n3<<"-"<<n4<<"="<<n3-n4<<endl;
    cout<<n5<<"*"<<n6<<"="<<n5*n6<<endl;
}