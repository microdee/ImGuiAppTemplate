add_executable( ${IMAPP_TARGET_NAME} ${IMAPP_TARGET_SRC_FILES} )

target_link_libraries( ${APP_TARGET_NAME}
    imgui
    CONAN_PKG::fmt
)
