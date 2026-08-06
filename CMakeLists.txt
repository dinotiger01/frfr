cmake_minimum_required(VERSION 3.22)
project(Qt6QmlApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic compilation handling for Qt assets
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find the essential Qt6 modules
find_package(Qt6 COMPONENTS Core Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)
find_package(CURL REQUIRED)
find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
    find_package(nlohmann_json CONFIG REQUIRED)
endif()

# Use modern Qt application layout rules
qt_standard_project_setup()

qt_policy(SET QTP0001 NEW)
# Define your C++ executable targets
qt_add_executable(Qt6QmlApp
#        main.cpp

)


target_link_libraries(Qt6QmlApp
        PRIVATE
        CURL::libcurl
        nlohmann_json::nlohmann_json
)

# Embed your QML files directly into the application binar
qt_add_qml_module(Qt6QmlApp
        URI MainApplication
        VERSION 1.0
        QML_FILES
            main.qml
        SOURCES
            main.cpp
            controlls.cpp
            controlls.h
        RESOURCES
            test.webp
            cat.jpg
            kitty.jpg
)

# Link your executable against the Qt Quick rendering module
target_link_libraries(Qt6QmlApp PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::Widgets
)
