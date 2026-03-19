#pragma once
#include "Song.h"

typedef Song TElem;

class DynamicArray {
private:
    int capacity;
    int size;
    TElem* elements;

public:
    DynamicArray(int capacity = 10);

    // these 3 must all be defined -----------------
    DynamicArray(const DynamicArray &arr);
    DynamicArray& operator=(const DynamicArray &arr);
    ~DynamicArray();
    // ---------------------------------------------

    void add(TElem elem);
    int getSize();

private:
    void resize(int factor = 2);
};

