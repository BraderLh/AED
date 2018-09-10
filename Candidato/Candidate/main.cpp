#include <iostream>
#include <string>
#include "candidateType.h"
#include <vector>
using std::string;
using namespace std;

void mostrarV(vector<candidateType>& candiClass)
{
    cout<<"Candidate"<<"\t"<<"Votes Received"<<"\t"<<"% of Total Votes"<<endl;
    for(int i=0;i<candiClass.size();i++)
    {
        cout<<endl;
        candiClass[i].print(cout);
        cout<<endl;
    }
    cout<<"\nTotal\t\t"<<19300<<endl;
}
void isWinner(vector<candidateType>& candiClass)
{
    int cm;
    string w;

    cm=candiClass[0].getVotes();

    for(int i=0 ;i < candiClass.size();i++)
    {
        if(cm<candiClass[i].getVotes())
        {
            cm=candiClass[i].getVotes();
            w=candiClass[i].getCandidateName();

        }
    }

    cout<<"\nEl ganador es: "<<w<<" con "<<cm<<"votos"<<endl;
}
int main()
{
    vector<candidateType>candidatos;

    candidateType a,b,c,d,e;
    a.setCandidateInfo("Johnson",5000,25.91);
    b.setCandidateInfo("Miller",4000,20.72);
    c.setCandidateInfo("Duffy",6000,31.09);
    d.setCandidateInfo("Robinson",2500,12.95);
    e.setCandidateInfo("Sam",1800,9.33);

    candidatos.push_back(a);
    candidatos.push_back(b);
    candidatos.push_back(c);
    candidatos.push_back(d);
    candidatos.push_back(e);

    mostrarV(candidatos);
    isWinner(candidatos);


    return 0;
}
