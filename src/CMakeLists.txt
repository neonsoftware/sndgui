cmake_minimum_required(VERSION 3.0)

project(sndguiproj)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

# Find the QtWidgets library
find_package(LibSndwch REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Svg)

# Tell CMake to create the helloworld executable
add_executable(sndgui main.cpp loaddialog.cpp editdialog.cpp xmlsyntax.cpp)

#target_include_directories(sndgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Use the Widgets module from Qt 5.
target_link_libraries(sndgui Qt5::Widgets Qt5::Svg sndwch xml2 yaml)
