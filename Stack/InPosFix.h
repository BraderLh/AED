#ifndef INPOSFIX_H_INCLUDED
#define INPOSFIX_H_INCLUDED

#include <iostream>
#include "StackType.h"
#include <string>
#include <stack>
#include <ctype.h>
using std::string;
using namespace std;

//template <class Type>
class fixInPos
{
private:
    string infix;
    string posfix;
public:
    //friend class stackADT;
    fixInPos();
    //~fixInPos();
    //template <class Type>
    void setInfix(string);
    string showInfix();
    string showPosfix();
    //void showPosfix();
    void convertToPosfix();
    int precedence(char);
    bool comparePre(char,char);
};
fixInPos::fixInPos()
{
    infix = "";
    posfix = "";
}
void fixInPos::setInfix(string in)
{
    infix=in;
}
string fixInPos::showInfix()
{
    return this->infix;
}

void fixInPos::convertToPosfix()
{
    posfix = "";
    int len = infix.length();
    //char temp;
    //stack<char> stack;
    stackType<string> stack1;
    string sym = "";

    for(int i = 0; i < len; i++)
    {
        sym=infix[i];

        //SI ES UN LETRA DEL ALFABETO
        if(isdigit(infix[i]) || infix[i] == '#')
        {
            if(infix[i]=='#')
                posfix.append("#");
            else{
                posfix.append(sym);
            }

        }
        else if(infix[i] == '(' || infix[i] == ')')
        {
            if(infix[i]=='(')
            {
                stack1.push(sym);
            }
            if(infix[i] == ')')
            {
                bool done=false;
                while(done==false)
                {
                    sym=stack1.top();
                    if(sym=="(")
                    {
                        stack1.pop();
                        done=true;
                    }
                    else
                    {
                        posfix.append(sym);
                        stack1.pop();
                    }
                }
            }
        }

        else if(sym==";")
        {

        }

        //SI ES UN OPERADOR
        else if(!isalpha(infix[i]))
        {
            posfix.append(" ");
            //cout<<" ";
            while(!stack1.isEmptyStack())
            {
                //posfix.append(" ");
                if(comparePre(stack1.top()[0], sym[0]))
                {
                    posfix.append(stack1.top());
                    stack1.pop();
                    posfix.append(" ");
                }
                else
                {
                    break;
                }
            }

            //posfix.append(" ");
            stack1.push(sym);
        }
        /*while(!stack1.isEmptyStack())
        {

            posfix.append(sym);
        }*/
    }
    while(!stack1.isEmptyStack())
    {
        sym=stack1.top();
        posfix.append(" ");
        posfix.append(sym);
        stack1.pop();
    }
}

//string fixInPos::showPosfix()
string fixInPos::showPosfix()
{
    return this->posfix;
    //cout<<posfix<<endl;
}

int fixInPos::precedence(char op)
{
    int pre = -1;
    switch (op) {
        case '+':
        case '-':
            pre = 1;
            break;
        case '*':
        case '/':
            pre= 2;
            break;
        case '^':
            pre = 3;
            break;
    }
    return pre;

}
bool fixInPos::comparePre(char op1,char op2)
{
    int prec1,prec2;
    if(op1 == '*' || op2=='/')
        prec1=2;
    else
        if(op1=='+' || op2=='-')
            prec1=1;
        else
            if(op1='(')
               prec1=0;
    if(op2=='*' || op2=='/')
        prec2=2;
    else
        if(op2=='+' || op2=='-')
            prec2=1;
    return (prec1>=prec2);
}

#endif // INPOSFIX_H_INCLUDED
