#include <iostream>
#include <string>
#include "candidateType.h"
#include <vector>
using namespace std;

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

    cout<<"Candidate"<<"\t"<<"Votes Received"<<"\t"<<"% of Total Votes"<<endl;
    for(int i=0;i<=candidatos.size();i++)
    {
        cout<<endl;
        candidatos[i].print(cout);
        cout<<endl;
    }
    return 0;

}
