#ifndef CALCUPOSF_H_INCLUDED
#define CALCUPOSF_H_INCLUDED

#include <iomanip>
#include <stdlib.h>
#include <iostream>
using namespace std;

void evaluateExpression(ifstream& inpF, ofstream& outF,stackType<double>& stack,char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stackType<double>& stack,char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stackType<double>& stack,bool isExpOk);

void evaluateExpression(ifstream& inpF, ofstream& outF,stackType<double>& stack,char& ch, bool& isExpOk)
{
    double num;
    outF << ch;

    while (ch != '=')
    {
        switch (ch)
        {
            case '#':
                inpF >> num;
                outF << num << " ";
                if (!stack.isFullStack())
                    stack.push(num);
                else
                {
                    cout << "Stack overflow. "<< "Program terminates!" << endl;
                    exit(0);  //terminate the program
                }
                break;
            case '(':
                inpF >> num;
                outF << "(" << num;
                if(!stack.isFullStack())
                    stack.push(num);
                else
                {
                    cout<<"Stack Overflow. "<<" Programa terminado! "<< endl;
                    exit(0);
                }
            default:
                evaluateOpr(outF, stack, ch, isExpOk);
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch;
            outF << ch;

            if (ch != '#')
                outF << " ";
            //if(ch != '#')
        }
        else
            discardExp(inpF, outF, ch);
    } //end while (!= '=')
} //end evaluateExpression

void evaluateOpr(ofstream& out, stackType<double>& stack,char& ch, bool& isExpOk)
{
    double op1, op2;

    if (stack.isEmptyStack())
    {
        out << " (Not enough operands)";
        isExpOk = false;
    }
    else
    {
        op2 = stack.top();
        stack.pop();

        if (stack.isEmptyStack())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = stack.top();
            stack.pop();

            switch (ch)
            {
            case '+':
                stack.push(op1 + op2);
                break;

            case '-':
                stack.push(op1 - op2);
                break;

            case '*':
                stack.push(op1 * op2);
                break;

            case '/':
                if (op2 != 0)
                    stack.push(op1 / op2);
                else
                {
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;

            case '%':
                if(op1>op2)
                {
                    int op3, op4;
                    op3 =  static_cast<int>(op1);
                    op4 = static_cast<int>(op2);
                    stack.push(op3 % op4);
                }
                else
                {
                    out<< "El primer elemento es mayor, no se hace el modulo. \n Retorna el primer elemento: ";
                    out<<op1;
                    isExpOk = false;
                }
                break;
            default:
                out << " (Illegal operator)";
                isExpOk = false;
            }//end switch
        } //end else
    } //end else
} //end evaluateOpr

void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
} //end discardExp

void printResult(ofstream& outF, stackType<double>& stack,bool isExpOk)
{
    double result;

    if (isExpOk) //if no error, print the result
    {
        if (!stack.isEmptyStack())
        {
            result = stack.top();
            stack.pop();

            if (stack.isEmptyStack())
                outF << result << endl;
            else
                outF << " (Error: Too many operands)" << endl;
        } //end if
        else
            outF << " (Error in the expression)" << endl;
    }
    else
        outF << " (Error in the expression)" << endl;

    outF << "_________________________________"
         << endl << endl;
}

#endif // CALCUPOSF_H_INCLUDED
