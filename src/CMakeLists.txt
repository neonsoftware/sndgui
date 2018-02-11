cmake_minimum_required(VERSION 3.0)

#project(sndguiproj)

set(CMAKE_INSTALL_UCRT_LIBRARIES true)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)

# To use LibSndwch
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

# Find the QtWidgets library
find_package(LibSndwch)
find_package(Qt5Widgets)
find_package(Qt5Svg)

include_directories(${LIBSNDWCH_INCLUDE_DIR})


# Tell CMake to create the helloworld executable
add_executable(sndgui main_load.cpp loaddialog.cpp resources.qrc)
target_link_libraries(sndgui Qt5::Widgets Qt5::Svg sndwch xml2 yaml)

add_executable(svgeditor main_editor.cpp editdialog.cpp xmlsyntax.cpp)
target_link_libraries(svgeditor Qt5::Widgets Qt5::Svg)
