#ifndef NODOTYPE_H_INCLUDED
#define NODOTYPE_H_INCLUDED

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif // NODOTYPE_H_INCLUDED
