# Immediate App template

This template provides a good start for small to mid-sized C++ projects using ImGui and built via CMake.

Targets are automatically added from recursive sub-directories of `targets` folder containing a `*target.cmake` file. It is included into `CMakeLists.txt` so targets can access shared directories and the same scope as `CMakeLists.txt`. Predefined variables for targets are:

* `IMAPP_TARGET_NAME`: plain name of target (same as subfolder name) (example: **app**)
* `IMAPP_TARGET_DIR`: full path of the target (example: **/myproject/app**)
* `IMAPP_TARGET_FILE`: full path of the target file  (example: **/myproject/app/target.cmake**)
* `IMAPP_TARGET_SRC_FILES`: the list of source files (.h | .cpp) found in target's folder
* `IMAPP_TARGETS`: the list of all targets in the project