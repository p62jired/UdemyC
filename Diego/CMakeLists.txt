# cmake_minimum_required(VERSION 3.0.0)
# project(hello_headers VERSION 0.1.0)

# include(CTest)
# enable_testing()

# add_executable(hello_headers main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)


# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (testing)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(testing ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(testing
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/Interfaces/IPrecipitaionSensors.hpp
        ${PROJECT_SOURCE_DIR}/src/Classes/NI04.hpp
        ${PROJECT_SOURCE_DIR}/src/Classes/NI05.hpp
        ${PROJECT_SOURCE_DIR}/src/Enums/PrecipitationTypes.hpp

)
