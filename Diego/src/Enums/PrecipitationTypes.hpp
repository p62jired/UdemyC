#include <iostream>
#ifndef SENSOR_TYPE
#define SENSOR_TYPE
enum class SensorType : uint8_t
{
    NO_SENSOR 		= 0,
    SENSOR_NI04,
    SENSOR_NI05
};
#endif /* SENSOR_TYPE */
