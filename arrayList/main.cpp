#include <iostream>
#include <string>

#include "arrayList.h"
#include "PolynomialType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);
    arrayListType<string> stringList;
    int number;

    polynomialType p(8);
    polynomialType q(4);
    polynomialType t;
    polynomialType r;

    cin >> p; //Line 9
    cout << endl << "Line 10: p(x): " << p << endl; //Line 10
    cout << "Line 11: p(5): " << p(5) << endl << endl; //Line 11
    cin >> q; //Line 12
    cout << endl << "Line 13: q(x): " << q << endl<< endl; //Line 13
    t = p + q; //Line 14
    cout << "Line 15: p(x) + q(x): " << t << endl; //Line 15
    cout << "Line 16: p(x) - q(x): " << p - q << endl; //Line 16
    r=p*q;
    cout<<" p(x) * q(x): "<<p*q<<endl;
    /*
    arrayListType<int> intList(100); //Line 7
    arrayListType<string> stringList; //Line 8
    arrayListType<int> intList1(100);

    int number; //Line 9
    int n;
    int n1;

    cout << "List 10: Enter 5 integers: "; //Line 10
    for (int counter = 0; counter < 5; counter++) //Line 11
    { //Line 12
        cin >> number; //Line 13
        intList.insertAt(counter, number); //Line 14
    } //Line 15
    cout << endl; //Line 16
    cout << "List 19: The list you entered is: "; //Line 17
    intList.print(); //Line 18
    cout << endl; //Line 19
    /*cout << "Line 20: Enter the item to be deleted: "; //Line 20
    cin >> number; //Line 21
    intList.remove(number); //Line 22
    cout << "Line 23: After removing " << number
    << ", the list is: "; //Line 23
    //intList.print(); //Line 24
    cout << endl; //Line 25
    cout<<"La lista fue eliminada: "<<endl;

    //intList.removeAll(n);
    intList.max(n1);
    cout<<"El numero mayor es el: "<<n1<<endl;
    //intList.print();

    */
    /*
    string str; //Line 26
    cout << "Line 27: Enter 5 strings: "; //Line 27
    for (int counter = 0; counter < 5; counter++) //Line 28
    { //Line 29
        cin >> str; //Line 30
        stringList.insertAt(counter, str); //Line 31
    } //Line 32
    cout << endl; //Line 33
    cout << "Line 34: The list you entered is: " << endl; //Line 34
    stringList.print(); //Line 35
    cout << endl; //Line 36
    cout << "Line 37: Enter the string to be deleted: "; //Line 37
    cin >> str; //Line 38
    stringList.remove(str); //Line 39
    cout << "Line 40: After removing " << str
    << ", the list is:" << endl; //Line 40
    stringList.print(); //Line 41
    cout << endl; //Line 42
    */



    return 0; //Line 43
}
