#include "arrayList.h"
#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

//CONSTRUCTOR
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "<< "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}
//CONSTRUCTOR COPIA
template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL); //terminate if unable to allocate
//memory space
    for (int j = 0; j < length; j++) //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor*/

template <class elemType>
bool arrayListType<elemType> :: isEmpty() const
{
    return (length==0);
}

template <class elemType>
bool arrayListType<elemType> :: isFull() const
{
    return (length==maxSize);
}

template <class elemType>
int arrayListType<elemType> :: listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType> :: maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType> :: print() const
{
    for(int i=0;i<length;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
    {
        cerr << "The position of the item to be inserted "<< "is out of range" << endl;
    }
    else
    {
        if (length >= maxSize) //list is full
        cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1]; //move the elements down
            list[location] = insertItem; //insert the item at the
            //specified position
            length++; //increment the length
        }
    }
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize) //the list is full
    cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem; //insert the item at the end
        length++; //increment the length
    }
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
    cerr << "The location of the item to be removed "<< "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        length--;
    }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "<< "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "<< "out of range." << endl;
    else
        list[location] = repItem;
} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator= (const arrayListType<elemType>& otherList)
{
    if (this != &otherList) //avoid self-assignment
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize]; //create the array
        assert(list != NULL); //if unable to allocate memory
//space, terminate the program
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}


template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    if (length == 0) //list is empty
        list[length++] = insertItem; //insert the item and
    //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1) //the item to be inserted
        //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
            << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."<< endl;
    }
} //end remove

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length; loc++)
    {
        if (list[loc] == item)
        {
            found = true;
            break;
        }
    }
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

//FUNCIONES HECHAS POR MI
template<class elemType>
void arrayListType<elemType>::max(elemType& itemax)
{
    itemax=list[0];

    for(int i=0;i<length;i++)
    {
        if(itemax<list[i])
        {
            itemax=list[i];
        }
    }
}

template<class elemType>
void arrayListType<elemType>::removeAll(elemType& item1)
{
    int loc;
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        elemType *aux;
        aux = new elemType;
        aux=list;
        for(int i=0;i<length;i++)
        {
            item1=list[i];
            list=aux;
            aux++;
            list++;
        }
        delete aux;
    }
}


//DESTRUCTOR
template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}
