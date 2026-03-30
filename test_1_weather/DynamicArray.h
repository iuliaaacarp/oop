#pragma once
#include "Weather.h"

typedef Weather TElem;

class DynamicArray{
private:
    int capacity;
    int size;
    TElem *elements;

public:
    DynamicArray(int capacity = 100);

    DynamicArray(const DynamicArray &arr);
    DynamicArray &operator=(const DynamicArray &arr);

    int getSize() const;
    TElem *getALl() const;

    bool addToArray(TElem elem);
    int findInArray(const DynamicArray &arr, TElem elem);

    DynamicArray filterByPrecipitation(const DynamicArray &arr, int precipitation);
    DynamicArray filterByDescription(const DynamicArray &arr, std::string description, int hour);
    int countHours(const DynamicArray &arr, std::string description ,int hour);

    ~DynamicArray();

private:
    void resize(int factor = 2);
};