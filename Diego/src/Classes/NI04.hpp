#include "../Interfaces/IPrecipitationSensor.hpp"
#include <iostream>
#include "../Enums/PrecipitationTypes.hpp"
class NI04 : public IPrecipitationSensor
{
private:
    /* data */
public:
    NI04(/* args */)
{
    std::cout<< "hello from constructor NI04" <<std::endl;
}

bool isPrecipitationPresent() const override
{
    std::cout<<"Esta lloviendo from NIO4"<<std::endl;
    return true;
}
SensorType getSensorType() const override
{
    return SensorType::SENSOR_NI04;
}

bool getSensorError() const
{
    return false;
}
};


