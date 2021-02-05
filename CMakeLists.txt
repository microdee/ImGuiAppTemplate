cmake_minimum_required(VERSION 3.11)

project(MyApplication
    VERSION 0.0.1
    LANGUAGES CXX
)

# Setting up conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(
        DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake" 
        TLS_VERIFY ON
    )
endif()

include(Config.cmake)

# Add local libraries
add_subdirectory(libs/imgui)
add_subdirectory(libs/cml)

# Add Conan libraries
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(
    REQUIRES
        fmt/7.1.3
        entt/3.6.0
        boost/1.75.0
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

# Add targets
include(app.cmake)