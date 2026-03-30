#pragma once
#include <string>

class Weather {
private:
    int start, end, temperature, precipitation;
    std::string description;

public:
    Weather();
    Weather(int start, int end, int temperature, int precipitation, const std::string &description);

    int getStart() const;
    int getEnd() const;
    int getTemperature() const;
    int getPrecipitation() const;
    std::string getDescription() const;

    void setStart(int value);
    void setEnd(int value);
    void setTemperature(int value);
    void setPrecipitation(int value);
    void setDescription(const std::string &value);
};