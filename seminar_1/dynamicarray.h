#pragma once

typedef int TElem;

typedef struct {
    int size, capacity;
    TElem *elems;
} DynamicArray;

DynamicArray *createDynamicArray(int cap);
void destroyDynamicArray(DynamicArray *array);
void addElem(DynamicArray *array, TElem elem);
void resize(DynamicArray *array);