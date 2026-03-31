#include "DynamicArray.h"

#include <sstream>
#include <vector>

DynamicArray::DynamicArray(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->elems = new TElem[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& arr){
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elems = new TElem[capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = arr.elems[i];
}

void DynamicArray::resize(int factor){
    this->capacity *= factor;
    TElem *temp = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        temp[i] = this->elems[i];
    delete[] this->elems;
    this->elems = temp;
}

DynamicArray::~DynamicArray(){
    delete[] this->elems;
}

TElem* DynamicArray::getAll() const{
    return this->elems;
}

int DynamicArray::getSize() const{
    return this->size;
}

bool DynamicArray::isEqual(TElem elem1, TElem elem2){
    return elem1.getId() == elem2.getId();
}

int DynamicArray::findInArray(TElem elem){
    for (int i = 0; i < this->size; i++)
        if (isEqual(this->elems[i], elem))
            return i;
    return -1;
}

bool validateElem(TElem elem){
    std::string name = elem.getStudentName();
    std::string solution = elem.getSolution();
    if (name.length() < 3 || solution.empty())
        return false;
    return true;
}

int DynamicArray::addToArray(TElem elem){
    if (!validateElem(elem))
        return -1;
    if (findInArray(elem) != -1)
        return -2;
    if (this->size == this->capacity)
        resize(2);
    this->elems[this->size++] = elem;
    return 1;
}

int calculatePercent(std::string sol1, std::string sol2){
    std::stringstream ss1(sol1);
    std::stringstream ss2(sol2);
    std::vector<std::string> res;
    std::string temp;
    while (ss1 >> temp)
        res.push_back(temp);
    int count = 0, countTotal = 0;
    while (ss2 >> temp){
         for (const auto& w: res){
             if (w == temp) count++;
             countTotal++;
         }
    }
    int percent = (count / countTotal) * 100;
    return percent;
}

std::string DynamicArray::matchElements(){
    std::string solution = "";
    for (int i = 0; i < this->size - 1 ; i++)
        for (int j = i + 1; j < this->size; j++)
        {
            TElem elem1 = this->elems[i];
            TElem elem2 = this->elems[j];
            std::string percent = std::to_string(calculatePercent(elem1.getSolution(), elem2.getSolution()));
            solution = solution + elem1.getStudentName() + " " + elem2.getSolution() + "(" +
                percent + "% of " + elem2.getStudentName() + "'s solution)\n";
        }
    return solution;
}