cmake_minimum_required(VERSION 3.5)

# Add component directories nested under components/
set(EXTRA_COMPONENT_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/components
)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32-reptile-dashboard)
