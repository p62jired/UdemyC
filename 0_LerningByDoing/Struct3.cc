#include <iostream>
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
void print_vehicle_data(Vehicle &vehicle)
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
void print_vehicle_data_pointer(Vehicle *vehicle)
{
    std::cout << "Vehicle ID: " << vehicle->id << std::endl;
    std::cout << "Vehicle Velocity in Kmh: " << vehicle->velocity << std::endl;
    switch (vehicle->lane)
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
    Vehicle v1 = {.id = 1, .velocity = 100.0f, .lane = Lane::CENTER};
    print_vehicle_data(v1);
    print_vehicle_data_pointer(&v1);
    return 0;
}
