#ifndef ORDEREDLINKEDLIST_H_INCLUDED
#define ORDEREDLINKEDLIST_H_INCLUDED

#include <iostream>
#include <vector>
#include "unorderedLinkedList.h"
using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    void insert(const Type& newItem);
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
bool orderedLinkedList<Type>:: search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //start the search at the first node
    while (current != NULL && !found)
    {
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    }
    if (found)
        found = (current->info == searchItem); //test for equality
    return found;
}//end search

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode; //pointer to create a node

    bool found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem; //store newItem in the node
    newNode->link = NULL; //set the link field of the node

    if(this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found)
        {
            if (current->info >= newItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == this->first) //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
            {
                this->last = newNode;
            }
            this->count++;
        }
    }//end else
}//end insert

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (this->first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)
        {//search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == NULL) //Case 4
            cout << "The item to be deleted is not in the list."<< endl;
        else
        {

            if (current->info == deleteItem) //the item to be
            {
                if (this->first == current) //Case 2
                {
                    this->first = this->first->link;

                    if (this->first == NULL)
                    {
                        this->last = NULL;
                    }
                    delete current;
                }
                else //Case 3
                {
                    trailCurrent->link = current->link;
                    if (current == this->last)
                        this->last = trailCurrent;
                    delete current;
                }
                this->count--;
            }
            else
            {
                cout << "The item to be deleted is not in the "<< "list." << endl;
            }
        }
    }
}

#endif // ORDEREDLINKEDLIST_H_INCLUDED
