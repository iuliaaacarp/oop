#pragma once
#include "Assignment.h"

typedef Assignment TElem;

class DynamicArray{
private:
    int size;
    int capacity;
    TElem *elems;

public:
    DynamicArray(int capacity = 100);
    DynamicArray(const DynamicArray& arr);
    ~DynamicArray();

    int addToArray(TElem elem);
    int deleteFromArray(TElem elem);
    int updateArray(TElem elem);

    std::string matchElements();

    int findInArray(TElem elem);
    bool isEqual(TElem elem1, TElem elem2);

    int getSize() const;
    TElem *getAll() const;

private:
    void resize(int factor = 2);
};