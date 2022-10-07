#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_
#include "../Enums/PrecipitationTypes.hpp"
class IPrecipitationSensor
{
public:

virtual ~IPrecipitationSensor() = default;

virtual SensorType getSensorType() const = 0; 

virtual bool isPrecipitationPresent() const = 0; 
};
#endif

