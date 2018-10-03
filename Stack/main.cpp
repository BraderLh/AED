#include <iostream>
#include <fstream>

using namespace std;
#include "Pila.h"
#include "StackType.h"
#include "CalcuPosF.h"
#include "InPosFix.h"
#include <string>
using std::string;
using std::getline;

void testCopyConstructor(stackType<int> otherStack);

int main()
{
    string expresion;
    fixInPos infija;

    cout<<"Ingres una expresion infija: ";
    getline(cin,expresion);
    infija.setInfix(expresion);
    cout<<endl;
    cout<<infija.showInfix();
    infija.convertToPosfix();
    cout<<endl;
    cout<<infija.showPosfix();
    //cout<<infija.precedence('+')<<endl;

    /*
    bool expressionOk;
    char ch;
    stackType<double> stack(100);
    ifstream infile;
    ofstream outfile;

    infile.open("RpnData.txt");

    if (!infile)
    {
        cout << "Cannot open the input file. "
             << "Program terminates!" << endl;
        return 1;
    }

    outfile.open("RpnOutput.txt");

    outfile << fixed << showpoint;
    outfile << setprecision(2);

    infile >> ch;
    while (infile)
    {
        stack.initializeStack();
        expressionOk = true;
        outfile << ch;

        evaluateExpression(infile, outfile, stack, ch,expressionOk);
        printResult(outfile, stack, expressionOk);
        infile >> ch; //begin processing the next expression
    } //end while

    infile.close();
    outfile.close();

    return 0;

    /*
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(23);
    stack.push(45);
    stack.push(38);
    copyStack = stack; //copy stack into copyStack

    cout << "The elements of copyStack: ";

    while (!copyStack.isEmptyStack()) //print copyStack
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;
    copyStack = stack;
    testCopyConstructor(stack); //test the copy constructor
    if (!stack.isEmptyStack())
        cout << "The original stack is not empty." << endl<< "The top element of the original stack: "<< copyStack.top() << endl;

    dummyStack = stack; //copy stack into dummyStack

    cout << "The elements of dummyStack: ";

    while (!dummyStack.isEmptyStack()) //print dummyStack
    {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;


    Pila<double>pilaDouble(5);
    double valorDouble=1.1;
    cout<<"Metiendo elementos  a pilaDouble\n";
    while(pilaDouble.push(valorDouble))
    {
        cout<<valorDouble<<' ';
        valorDouble+=1.1;
    }
    cout<<"\nLa Pila esta llena. No se puede meter "<<valorDouble<<"\n\nSacando elementos de PilaDouble\n";
    while(pilaDouble.pop(valorDouble))
    cout<<valorDouble<<' ';
    cout<<"\nLa pila esta vacia. No se puede sacar\n";


    Pila<int>pilaInt;
    int valorInt=1;
    cout<<"\nMetiendo elementos a pilaInt\n";
    while(pilaInt.push(valorInt))
    {
        cout<<valorInt++<<' ';
    }
    cout<<"\nLa Pila esta llena. No se puede meter "<<valorInt<<"\n\nSacando elementos de pilaInt\n";
    while(pilaInt.pop(valorInt))
        cout<<valorInt<<' ';
    cout<<"\nLa pila esta vacia. No se puede sacar"<<endl;


    Pila<char>pilaChar;
    char valorChar;
    cout<<"\nMetiendo elementos a pilaChar\n";
    while(pilaChar.push(valorChar))
    {
        cin>>valorChar;
    }
    cout<<"\nLa Pila esta llena. No se puede meter "<<valorChar<<"\n\nSacando el elemento de pilaChar\n";
    while(pilaChar.pop(valorChar))
        cout<<valorChar<<' ';
    cout<<"\nLa pila esta vacia. No se puede sacar"<<endl;
    */
    //return 0;

}

void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack())
    {
        cout << "otherStack is not empty." << endl<< "The top element of otherStack: "
        << otherStack.top() << endl;
    }
}
