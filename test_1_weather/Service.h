#pragma once

#include "DynamicArray.h"

class Service
{
private:
    DynamicArray repo;

public:
    Service(int capacity = 100);

    bool addWeatherToRepo(int start, int end, int temperature, int precipitation, const std::string description);
    DynamicArray& getRepo() {return repo;};
    TElem *getAllWeather();
    int getRepoSize() const;

    void populateRepo();
};