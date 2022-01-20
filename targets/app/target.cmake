message(STATUS "Target: ${IMAPP_TARGET_NAME}")

add_executable( ${IMAPP_TARGET_NAME} ${IMAPP_TARGET_SRC_FILES} )

target_link_libraries( ${IMAPP_TARGET_NAME}
    imgui
    CONAN_PKG::fmt
)
