//
// Created by iulia on 3/19/2026.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->elements = new TElem[capacity];
}

DynamicArray::DynamicArray(const DynamicArray &arr) {
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elements = new TElem[arr.capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = arr.elements[i];
}

DynamicArray::~DynamicArray() {
    delete[] this->elements;
}

void DynamicArray::resize(int factor) {
    this->capacity *= factor;
    TElem* temp = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->elements[i];
    delete[] this->elements;
    this->elements = temp;
}

void DynamicArray::add(TElem elem) {
    if (this->size == this->capacity)
        this->resize();
    this->elements[this->size++] = elem;
}

int DynamicArray::getSize() {
    return this->size;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &arr) {
    this->capacity = arr.capacity;
    this->size = arr.size;

    delete[] this->elements;
    this->elements = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elements[i] = arr.elements[i];

    return *this;
}
