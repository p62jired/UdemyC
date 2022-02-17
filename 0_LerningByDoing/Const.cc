#include <iostream>

constexpr int DEFAUT_VEHICLE_ID = -1;
constexpr int NUMB_VEHICLES = 3;

enum struct Lane : unsigned char
{
    RIGHT_LANE,
    CENTER,
    LEFT_LANE
};
struct Vehicle
{
    int id;
    float velocity;
    Lane lane;
};
// const&: Read-only
// *const <=> &
// const * const: Same as const&
void print_vehicle_data(const Vehicle &vehicle)
{
    std::cout << "Vehicle ID: " << vehicle.id << std::endl;
    std::cout << "Vehicle Velocity: " << vehicle.velocity << std::endl;
    switch (vehicle.lane)
    {
    case Lane::RIGHT_LANE:
        std::cout << "Vehicle Lane Association: Right lane" << std::endl;
        break;
    case Lane::CENTER:
        std::cout << "Vehicle Lane Association: Center lane" << std::endl;
        break;
    case Lane::LEFT_LANE:
        std::cout << "Vehicle Lane Association: Left lane" << std::endl;
        break;
    default:
        break;
    }
}


int main()
{
    Vehicle v1 = {1, 100.0f, Lane::CENTER};
    Vehicle v2 = {2, 90.0f, Lane::RIGHT_LANE};
    Vehicle v3 = {DEFAUT_VEHICLE_ID, 120.0f, Lane::LEFT_LANE};

    Vehicle vehicle_in_scene[NUMB_VEHICLES] = {v1, v2, v3};

    for (unsigned int i = 0; i < NUMB_VEHICLES; i++)
    {
        print_vehicle_data(vehicle_in_scene[i]);
    }

    return 0;
}
