#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator= (const arrayListType<elemType>&);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, elemType& retItem) const;
    void replaceAt(int location, const elemType& retItem);
    void clearList();
    int seqSearch(const elemType& item) const;
    void insert(const elemType& insertItem);
    void remove(const elemType& removeItem);
    arrayListType(int size=100);
    arrayListType(const arrayListType<elemType>& otherList);
    ~arrayListType();

    //ejercicios
    void removeAll(elemType& item1);
    void max(elemType& itemax);

protected:
    elemType *list;
    int length;
    int maxSize;
};

#endif // ARRAYLIST_H_INCLUDED
