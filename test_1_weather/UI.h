#pragma once
#include "Service.h"

class UI
{
private:
    Service &service;
    void printMenu();
    void printRepo(DynamicArray arr);
public:
    UI(Service &service);
    void run();
};