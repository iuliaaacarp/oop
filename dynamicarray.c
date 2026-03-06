#include  "dynamicarray.h"

#include <stdlib.h>

DynamicArray *createDynamicArray(int cap) {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    if (array == NULL) return NULL;
    array->size = 0;
    array->capacity = cap;
    array->elems = malloc(cap * sizeof(TElem));
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    if (array == NULL) return;
    free(array->elems);
    free(array);
}

void addElem(DynamicArray *array, TElem elem) {
    if (array == NULL)
        return;
    if (array->size >= array->capacity)
        resize(array);
    array->elems[array->size++] = elem;
}

void resize(DynamicArray *array) {
    if (array == NULL)
        return;
    array->capacity *= 2;
    TElem* aux = malloc(sizeof(TElem) * array->capacity);
    for (int i = 0; i < array->size; i++)
        aux[i] = array->elems[i];
    free(array->elems);
    array->elems = aux;
}
