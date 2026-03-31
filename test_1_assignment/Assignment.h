#pragma once
#include <string>

class Assignment{
private:
    int id;
    std::string studentName;
    std::string solution;

public:
    Assignment();
    Assignment(int id, const std::string& studentName, const std::string& solution);

    int getId() const;
    std::string getStudentName() const;
    std::string getSolution() const;

    void setId(int id);
    void setStudentName(const std::string& studentName);
    void setSolution(const std::string& studentName);
};
