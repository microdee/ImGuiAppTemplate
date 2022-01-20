cmake_minimum_required(VERSION 3.11)

project(MyApplication
    VERSION 0.0.1
    LANGUAGES CXX
)

# Setting up conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(
        DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/release/0.17/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake" 
        TLS_VERIFY ON
    )
endif()

# Setting up conan
include(Config.cmake)

# Add local libraries
add_subdirectory(libs/imgui)

# Add Conan libraries
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(
    REQUIRES
        fmt/8.1.1
        bitserializer/0.44
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

# Search for targets
file(
    GLOB_RECURSE IMAPP_TARGETS
    LIST_DIRECTORIES false
    CONFIGURE_DEPENDS
    targets/*target.cmake
)

foreach(IMAPP_TARGET_FILE ${IMAPP_TARGETS})
    cmake_path(GET ${IMAPP_TARGET_FILE} PARENT_PATH IMAPP_TARGET_DIR)
    cmake_path(GET ${IMAPP_TARGET_DIR} FILENAME IMAPP_TARGET_NAME)

    message(STATUS "Adding target: ${IMAPP_TARGET_NAME}")
    
    file(
        GLOB_RECURSE IMAPP_TARGET_SRC_FILES
        FOLLOW_SYMLINKS
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS
        ${IMAPP_TARGET_DIR}/*.cpp ${IMAPP_TARGET_DIR}/*.h
    )

    include(${IMAPP_TARGET_FILE})
endforeach()