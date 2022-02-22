#include <iostream>
// Enum values are integers
// Enum values in UPPERCASE
// Enum values are constant

enum PermissionLevel
{
    STUDENT,
    TUTOR,
    INSTRUCTOR,
    ADMIN,
    UNKNOWN
};
void greet_permission_level(PermissionLevel level)
{
    switch (level)
    {
    case PermissionLevel::STUDENT:
        std::cout << "Hello Student" << std::endl;
        break;
    case PermissionLevel::TUTOR:
        std::cout << "Hello Tuto" << std::endl;
        break;
    case PermissionLevel::INSTRUCTOR:
        std::cout << "Hello Instructor" << std::endl;
        break;
    case PermissionLevel::ADMIN:
        std::cout << "Hello Admin" << std::endl;
        break;

    default:
        std::cout << "UNKNOWN error!!" << std::endl;
        break;
    }
}

int main()
{
    PermissionLevel permision_level_diego = PermissionLevel::INSTRUCTOR;
    greet_permission_level(permision_level_diego);
    PermissionLevel permision_level_peter = PermissionLevel::STUDENT;
    greet_permission_level(permision_level_peter);


    return 0;
}
