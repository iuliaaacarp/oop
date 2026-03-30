#include "UI.h"
#include <iostream>

UI::UI(Service& service) : service(service){}

void UI::printMenu(){
    std::cout << "Welcome to the Weather Menu!\n";
    std::cout << "1. Show me all weather data\n";
    std::cout << "2. Add weather report\n";
    std::cout << "3. Filter weather by precipitation probability\n";
    std::cout << "4. Display intervals based on criteria\n";
    std::cout << "0. Exit\n";
}

void UI::printRepo(DynamicArray arr){
    for (int i = 0; i < arr.getSize() - 1; i++)
        for (int j = i + 1; j < arr.getSize(); j++)
        {
            Weather w1 = arr.getALl()[i];
            Weather w2 = arr.getALl()[j];
            if (w1.getStart() > w2.getStart())
            {
                Weather w = w1;
                arr.getALl()[i] = w2;
                arr.getALl()[j] = w;
            }
        }
    for (int i = 0; i < arr.getSize(); i++)
    {
        Weather w = arr.getALl()[i];
        std::cout << "Start: " << w.getStart() << " - End: " << w.getEnd() << "\n";
        std::cout << "Precipitation: " << w.getPrecipitation() << " , Temperature: " << w.getTemperature() << "\n";
        std::cout << "Description >> " << w.getDescription() << "\n";
        std::cout << "----------------------------------------\n";
    }
}

void UI::run(){
    service.populateRepo();
    while (true){
        printMenu();
        int input;
        std::cout << ">> Enter your choice: ";
        std::cin >> input;
        if (input == 0) break;
        if (input == 1)
        {
            printRepo(service.getRepo());
        }
        else if (input == 2)
        {
            int start, end, precipitation, temperature;
            std::string description;
            std::cout <<"Enter start time: ";
            std::cin >> start;
            std::cout <<"Enter end time: ";
            std::cin >> end;
            std::cout <<"Enter precipitation value: ";
            std::cin >> precipitation;
            std::cout <<"Enter temperature value: ";
            std::cin >> temperature;
            std::cin.ignore();
            std::cout <<"Enter description: ";
            std::getline(std::cin, description);
            service.addWeatherToRepo(start, end, temperature, precipitation, description);
            std::cout << "Weather repo updated\n";
        }
        else if (input == 3)
        {
            int precipitation;
            std::cout <<"Enter precipitation value: ";
            std::cin >> precipitation;
            printRepo(service.getRepo().filterByPrecipitation(service.getRepo(), precipitation));
        }
        else if (input == 4)
        {
            int hours;
            std::string description;
            std::cout <<"Enter hours value: ";
            std::cin >> hours;
            std::cin.ignore();
            std::cout <<"Enter description: ";
            std::getline(std::cin, description);
            printRepo(service.getRepo().filterByDescription(service.getRepo(),description, hours));
        }
        else
            std::cout << "Invalid choice!\n";
    }
}