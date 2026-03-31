#include "Assignment.h"

#include <string>

Assignment::Assignment(){
    this->id = 0;
    this->studentName = "";
    this->solution = "";
}

Assignment::Assignment(int id, const std::string& studentName, const std::string& solution){
    this->id = id;
    this->studentName = studentName;
    this->solution = solution;
}

int Assignment::getId() const{
    return this->id;
}

std::string Assignment::getStudentName() const{
    return this->studentName;
}

std::string Assignment::getSolution() const{
    return this->solution;
}

void Assignment::setId(int id){
    this->id = id;
}

void Assignment::setStudentName(const std::string& studentName){
    this->studentName = studentName;
}

void Assignment::setSolution(const std::string& solution){
    this->solution = solution;
}