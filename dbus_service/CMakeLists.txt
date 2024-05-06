cmake_minimum_required(VERSION 3.14)

project(dbus_service LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core DBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus)


add_executable(dbus_service
  main.cpp
  MyInterface.h
  MyInterface.cpp


)
target_link_libraries(dbus_service Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus)

set(DBUS_XML_FILES
    org.artem.Interface.xml)

qt6_add_dbus_interfaces(dbus_service ${DBUS_INTERFACE_FILES})



include(GNUInstallDirs)
install(TARGETS dbus_service
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
