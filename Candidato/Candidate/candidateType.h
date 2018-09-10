#ifndef CANDIDATETYPE_H_INCLUDED
#define CANDIDATETYPE_H_INCLUDED

#include <string>
using std::string;
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

class candidateType
{
public:
    void setCandidateInfo(string ctName, int ctVotes, float ctPVotes);
    void print(ostream& outp);
    int getVotes();
    string getCandidateName();
    float getPercent();

    bool operator== (const candidateType&) const;
    bool operator!= (const candidateType&) const;
    bool operator<= (const candidateType&) const;
    bool operator< (const candidateType&) const;
    bool operator>= (const candidateType&) const;
    bool operator> (const candidateType&) const;

    candidateType(string ctName = "", int ctVotes = 0,float ctPVotes = 0.0);
private:
    string canName;
    int canVotes;
    float canPVotes;
};
void candidateType::setCandidateInfo(string ctName, int ctVotes,float ctPVotes)
{
    canName = ctName;
    canVotes = ctVotes;
    canPVotes = ctPVotes;
}
void candidateType::print(ostream& outp)
{
    outp << left;
    outp << setw(8) << canName<<"\t";
    outp << setw(4) << canVotes <<"\t\t";
    outp.unsetf(ios::left);
    outp << setw(4) << canPVotes <<"   \t\t";
}
candidateType::candidateType(string ctName,int ctVotes,float ctPVotes)
{
    setCandidateInfo(ctName,ctVotes,ctPVotes);
}
int candidateType::getVotes()
{
    return canVotes;
}
string candidateType::getCandidateName()
{
    //canName=ctName;
    //cout<<ctName<<endl;
    return canName;
}
float candidateType::getPercent()
{
    return canPVotes;
}


#endif // CANDIDATETYPE_H_INCLUDED
