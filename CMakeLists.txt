cmake_minimum_required(VERSION 3.15)

# Project settings
project(FirstNHHSGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OS-specific SFML setup
if(WIN32)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/windows/SFML/lib/cmake/SFML")  # Windows-specific SFML path
    find_package(SFML REQUIRED COMPONENTS system window graphics)
elseif(APPLE)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/mac/SFML/lib/cmake/SFML")  # macOS-specific SFML path
    find_package(SFML REQUIRED COMPONENTS system window graphics)
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)  # Project-specific headers in 'include/'

# Source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Header files (to show headers in IDEs like Visual Studio)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# Post-build steps to copy DLLs for Windows
if (WIN32)
    file(GLOB SFML_DLLS "${CMAKE_SOURCE_DIR}/libs/windows/SFML/bin/*.dll")
    foreach(DLL ${SFML_DLLS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${DLL} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    endforeach()
endif()

# Optional message if SFML is not found
if(NOT SFML_FOUND)
    message(STATUS "SFML not found. Ensure it is installed and paths are correct.")
endif()
