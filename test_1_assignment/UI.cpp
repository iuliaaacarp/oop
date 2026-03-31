#include "Service.h"
#include <iostream>

void printRepo(DynamicArray &repo)
{
    for (int i = 0; i < repo.getSize(); i++)
    {
        Assignment assign = repo.getAll()[i];
        std::cout << "Id: " << assign.getId() << " Name: " << assign.getStudentName() << std::endl;
        std::cout << "Solution: " << assign.getSolution() << std::endl;
        std::cout << "------------------------------------\n";
    }
}

void printMenu(){
    std::cout << "Welcome to Assignment Menu!\n";
    std::cout << "------------------------------------\n";
    std::cout << "1. Show all assignments\n";
    std::cout << "2. Add new assignment\n";
    std::cout << "3. Check for dishonesty\n";
    std::cout << "0. Exit\n";
}

int main (){
    Service repoService;
    repoService.populateRepo();
    DynamicArray repo = repoService.getRepo();
    while (true){
        printMenu();
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        if (choice == 0)
            break;
        if (choice == 1){
            printRepo(repo);
        }
        else if (choice == 2){
            int id;
            std::string name, solution;
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter Name: ";
            std::getline(std::cin,name);
            std::cout << "Enter Solution: ";
            std::getline(std::cin,solution);
            Assignment assign{id, name, solution};
            if (repoService.addToRepo(assign))
                std::cout << "Successfully added assignment!\n";
            else
                std::cout << "Failed to add assignment!\n";
        }
        else if (choice == 3)
        {
            std::cout << repoService.displayMatch();
        }
    }
}