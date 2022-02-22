#include <iostream>
namespace ad
{
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


} // namespace ad


int main()
{
    ad::Vehicle v1 = {1, 100.0f, ad::Lane::CENTER};
    ad::Vehicle v2 = {2, 90.0f, ad::Lane::RIGHT_LANE};
    ad::Vehicle v3 = {ad::DEFAUT_VEHICLE_ID, 120.0f, ad::Lane::LEFT_LANE};

    ad::Vehicle vehicle_in_scene[ad::NUMB_VEHICLES] = {v1, v2, v3};

    for (unsigned int i = 0; i < ad::NUMB_VEHICLES; i++)
    {
        ad::print_vehicle_data(vehicle_in_scene[i]);
    }
    return 0;
}
