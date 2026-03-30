#include "Weather.h"

Weather::Weather(){
    this->start = 0;
    this->end = 0;
    this->temperature = 0;
    this->precipitation = 0;
    this->description = "";
}

Weather::Weather(int start, int end, int temperature, int precipitation, const std::string &description){
    this->start = start;
    this->end = end;
    this->temperature = temperature;
    this->precipitation = precipitation;
    this->description = description;
}

int Weather::getStart() const{
    return this->start;
}

int Weather::getEnd() const{
    return this->end;
}

int Weather::getTemperature() const{
    return this->temperature;
}

int Weather::getPrecipitation() const{
    return this->precipitation;
}

std::string Weather::getDescription() const{
    return this->description;
}

void Weather::setStart(int start){
    this->start = start;
}

void Weather::setEnd(int end){
    this->end = end;
}

void Weather::setTemperature(int temperature){
    this->temperature = temperature;
}

void Weather::setPrecipitation(int precipitation){
    this->precipitation = precipitation;
}

void Weather::setDescription(const std::string &description){
    this->description = description;
}