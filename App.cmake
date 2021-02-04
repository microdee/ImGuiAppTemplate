get_filename_component(
    APP_TARGET_NAME
    ${CMAKE_CURRENT_LIST_FILE}
    NAME_WE
)

message(STATUS "Parsing target: ${APP_TARGET_NAME}")

file(
    GLOB_RECURSE APP_TARGET_SRC_FILES
    FOLLOW_SYMLINKS
    LIST_DIRECTORIES false
    CONFIGURE_DEPENDS
    ${APP_TARGET_NAME}/*.cpp ${APP_TARGET_NAME}/*.h
)

add_executable( ${APP_TARGET_NAME} ${APP_TARGET_SRC_FILES} )

target_link_libraries( ${APP_TARGET_NAME}
    imgui
    cml
    CONAN_PKG::fmt
    CONAN_PKG::boost
)