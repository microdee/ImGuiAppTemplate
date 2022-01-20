cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0079 NEW)

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

message(STATUS "\nAdd local libraries\n")
add_subdirectory(libs/imgui)

message(STATUS "\nAdd libraries from Conan\n")
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(
    REQUIRES
        fmt/8.1.1
        bitserializer/0.44
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

message(STATUS "\nSearching for targets\n")
file(
    GLOB_RECURSE IMAPP_TARGETS
    LIST_DIRECTORIES false
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/targets/*target.cmake
)

foreach(IMAPP_TARGET_FILE ${IMAPP_TARGETS})
    cmake_path(GET IMAPP_TARGET_FILE PARENT_PATH IMAPP_TARGET_DIR)
    cmake_path(GET IMAPP_TARGET_DIR FILENAME IMAPP_TARGET_NAME)

    if(IMAPP_TARGET_DIR)
        message(STATUS "Found target: ${IMAPP_TARGET_NAME} (${IMAPP_TARGET_DIR})")
        file(
            GLOB_RECURSE IMAPP_TARGET_SRC_FILES
            FOLLOW_SYMLINKS
            LIST_DIRECTORIES false
            CONFIGURE_DEPENDS
            ${IMAPP_TARGET_DIR}/*.cpp ${IMAPP_TARGET_DIR}/*.h
        )

        include(${IMAPP_TARGET_FILE})
    endif()
endforeach()
message(STATUS "\nTargets added\n")