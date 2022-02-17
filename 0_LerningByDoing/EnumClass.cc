#include <iostream>
// Enum values are integers
// Enum values in UPPERCASE
// Enum values are constant

// 1.) Two Enums cannot share the same name
// 2.) No variable can have a name which already reverved by a enum
// 3.) Enums are not type safe
// Better use enum class

enum class PermissionLevel : unsigned char
{
    STUDENT,
    TUTOR,
    INSTRUCTOR,
    ADMIN,
    UNKNOWN
};
enum class ExamPerson : unsigned char
{
    STUDENT,
    INSPECTOR
};


int main()
{
    PermissionLevel permision_level_diego = PermissionLevel::INSTRUCTOR;
    PermissionLevel permision_level_peter = PermissionLevel::STUDENT;

    ExamPerson diego = ExamPerson::STUDENT;
    ExamPerson peter = ExamPerson::INSPECTOR;

    return 0;
}
