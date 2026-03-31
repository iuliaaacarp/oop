#pragma once

#include "DynamicArray.h"

class Service{
private:
    DynamicArray repo;
public:
    Service(int capacity = 100);
    DynamicArray getRepo() const {return repo;};

    TElem *getAllAssignments();
    int getRepoSize() const;

    int addToRepo(TElem elem);
    std::string displayMatch();

    void populateRepo();
};