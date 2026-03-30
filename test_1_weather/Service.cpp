#include "Service.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Service::Service(int capacity) : repo(capacity) {}

bool Service::addWeatherToRepo(int start, int end, int temperature, int precipitation, const std::string description){
    Weather weather{start, end, temperature, precipitation, description};
    this->repo.addToArray(weather);
    return true;
}

TElem* Service::getAllWeather(){
    return this->repo.getALl();
}

int Service::getRepoSize() const{
    return this->repo.getSize();
}

void Service::populateRepo() {
    std::ifstream fin("Input.txt");

    if (!fin.is_open()) {
        // Use std::endl to FORCE the text to the screen immediately
        std::cout << "DEBUG ERROR: Input.txt not found in " << std::endl;
        return;
    }

    std::string line;
    int count = 0;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string s1, s2, s3, s4, s5;

        if (std::getline(ss, s1, ';') &&
            std::getline(ss, s2, ';') &&
            std::getline(ss, s3, ';') &&
            std::getline(ss, s4, ';') &&
            std::getline(ss, s5))
        {
            if (!s5.empty() && s5.back() == '\r'){
                s5.pop_back();
            }
            while (!s5.empty() && isspace(s5.back()))
            {
                s5.pop_back();
            }
            try {
                int start = std::stoi(s1);
                int end = std::stoi(s2);
                int temp = std::stoi(s3);
                int precip = std::stoi(s4);

                Weather w{start, end, temp, precip, s5};
                this->repo.addToArray(w);
                count++;
            } catch (...) {
            }
        }
    }
    fin.close();
}
