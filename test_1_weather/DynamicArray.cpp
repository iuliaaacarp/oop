#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->elements = new TElem[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& arr){
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elements = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = arr.elements[i];
}

DynamicArray::~DynamicArray(){
    delete[] this->elements;
}

TElem* DynamicArray::getALl() const{
    return this->elements;
}


int DynamicArray::getSize() const{
    return this->size;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr){
    if (this == &arr)
        return *this;
    this->capacity = arr.capacity;
    this->size = arr.size;

    delete [] this->elements;
    this->elements = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = arr.elements[i];

    return *this;
}

void DynamicArray::resize(int factor){
    this->capacity = factor * this->capacity;
    TElem* temp = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->elements[i];
    delete[] this->elements;
    this->elements = temp;
}

bool isEqual(Weather w1, Weather w2){
    if (w1.getPrecipitation() == w2.getPrecipitation() && w1.getTemperature() == w2.getTemperature()
        && w1.getDescription() == w2.getDescription() && w1.getStart() == w2.getStart() && w1.getEnd() == w2.getEnd())
        return true;
    return false;
}

int DynamicArray::findInArray(const DynamicArray &arr, TElem elem){
    for (int i = 0; i < this->size; i++)
        if (isEqual(arr.elements[i], elem))
            return i;
    return -1;
}

bool hourInInterval(int hour, int hour1, int hour2){
    if (hour1 <= hour && hour <= hour2)
        return true;
    return false;
}

bool DynamicArray::addToArray(TElem elem){
    if (findInArray(*this, elem) != -1)
        return false;
    if (this->size >= this->capacity)
        resize(2);
    this->elements[this->size++] = elem;
    return true;
}

DynamicArray DynamicArray::filterByPrecipitation(const DynamicArray& arr, int precipitation){
    DynamicArray *filter = new DynamicArray;
    for (int i = 0; i < arr.getSize(); i++)
        if (arr.elements[i].getPrecipitation() < precipitation)
            filter->addToArray(arr.elements[i]);
    return *filter;
}

DynamicArray DynamicArray::filterByDescription(const DynamicArray& arr, std::string description, int hour){
    DynamicArray *filter = new DynamicArray;
    for (int i = 0; i < arr.getSize(); i++)
        if (arr.elements[i].getDescription() == description && hourInInterval(hour, arr.elements[i].getStart(), arr.elements[i].getEnd()))
            filter->addToArray(arr.elements[i]);
    return *filter;
}

int DynamicArray::countHours(const DynamicArray& arr, std::string description, int hour){
    int count = 0;
    for (int i = 0; i < arr.getSize(); i++)
        if (arr.elements[i].getDescription() == description && hourInInterval(hour, arr.elements[i].getStart(), arr.elements[i].getEnd()))
            count += (arr.elements[i].getEnd() - hour);
    return count;
}
