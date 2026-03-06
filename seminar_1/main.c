#include <stdio.h>
#include <crtdbg.h>
#include "planet.h"

#include "dynamicarray.h"

int main() {
    testPlanet();
    DynamicArray *array = createDynamicArray(10);
    addElem(array, 1);
    addElem(array, 2);
    addElem(array, 3);
    destroyDynamicArray(array);
    return 0;
}