#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

#include "StackADT.h"
template <class Type>
class stackType: public stackADT<Type>
{
public:

    const stackType<Type>& operator=(const stackType<Type>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
    stackType(int stackSize = 100);
    stackType(const stackType<Type>& otherStack);
    ~stackType();
private:
    int maxStackSize; //tamano de la pila
    int stackTop; //variable que guarda el top de la pila
    Type *list; //puntero al array que contiene los elementos de la pila
    void copyStack(const stackType<Type>& otherStack);
};
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem; //add newItem at the top
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}
template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0); //if stack is empty, terminate the
    //program
    return list[stackTop - 1]; //return the element of the stack
    //indicated by stackTop - 1
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--; //decrement stackTop
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "<< "be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize; //set the stack size to
    //the value specified by
    //the parameter stackSize
    stackTop = 0; //set stackTop to 0
    list = new Type[maxStackSize]; //create the array to
    //hold the stack elements
}//end constructor

//CONSTRUCTOR COPIA
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;
    copyStack(otherStack);
}

//SOBRECARGA DEL OPERADOR DE ASIGNACION( = )
template <class Type>
const stackType<Type>& stackType<Type>::operator= (const stackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);
    return *this;
} //end operator=

//DESTRUCTOR
template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied
    //by the array
}
#endif // STACKTYPE_H_INCLUDED
