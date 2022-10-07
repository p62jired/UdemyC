#include "../Interfaces/IPrecipitationSensor.hpp"
#include <iostream>
#include "../Enums/PrecipitationTypes.hpp"
class NI05 : public IPrecipitationSensor
{
private:
    /* data */
public:
    NI05(/* args */)
{
    std::cout<< "hello from constructor NI05" <<std::endl;
}

bool isPrecipitationPresent() const override
{
    std::cout<<"Esta lloviendo from NIO5"<<std::endl;
    return true;
}

SensorType getSensorType() const override
{
    return SensorType::SENSOR_NI05;
}
};


