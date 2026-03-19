#pragma once
#include "DynamicArray.h"

class Repository {
private:
    DynamicArray songs;
public:
    void add(const Song& song);
    int getSize();
};

