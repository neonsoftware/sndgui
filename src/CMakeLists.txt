cmake_minimum_required(VERSION 3.0)

set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version")

project(sndguiproj)

set(CMAKE_INSTALL_UCRT_LIBRARIES true)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)

# To use LibSndwch
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/../cmake)

# Find the QtWidgets library
find_package(LibXml2)
find_package(LibYaml)
find_package(LibSndwch)
find_package(Qt5Widgets)
find_package(Qt5Svg)

include_directories(${LIBSNDWCH_INCLUDE_DIR})

set(CMAKE_MACOSX_BUNDLE true)

set(SOURCE_FILE_PROPERTIES ${CMAKE_SOURCE_DIR}/../icons/light.icns PROPERTIES MACOSX_PACKAGE_LOCATION)

set(MACOSX_BUNDLE_ICON_FILE light)

add_executable(sndgui main_load.cpp loaddialog.cpp resources.qrc ../icons/light.icns)

set_target_properties(sndgui PROPERTIES
  RESOURCE ../icons/light.icns
)

target_link_libraries(sndgui Qt5::Widgets Qt5::Svg ${LIBSNDWCH_LIBRARIES} ${LIBYAML_LIBRARIES} ${LIBXML2_LIBRARY} ${LIBXML2_LIBRARIES})

add_executable(svgeditor main_editor.cpp editdialog.cpp FileSelectorWidget.cpp SvgPreviewWidget.cpp SvgEditorWidget.cpp qdarkstyle/style.qrc xmlsyntax.cpp ../icons/light.icns)

set_target_properties(svgeditor PROPERTIES
  RESOURCE ../icons/light.icns
)

target_link_libraries(svgeditor Qt5::Widgets Qt5::Svg)
