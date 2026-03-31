#include "Service.h"

Service::Service(int capacity) : repo(capacity){}

int Service::getRepoSize() const{
    return this->repo.getSize();
}

TElem* Service::getAllAssignments(){
    return this->repo.getAll();
}

int Service::addToRepo(TElem elem){
    return this->repo.addToArray(elem);
}

void Service::populateRepo()
{
    this->repo.addToArray({1, "Andrea", "lala mimi mamu"});
    this->repo.addToArray({2, "Iulia", "inimini lala"});
}

std::string Service::displayMatch()
{
    return this->repo.matchElements();
}