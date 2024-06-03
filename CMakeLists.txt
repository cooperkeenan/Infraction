cmake_minimum_required(VERSION 3.5)

project(sqlConnection VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    dashboard.h
    dashboard.cpp
    dashboard.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sqlConnection
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        db/InfractionDB.sqlite
        uk_map.png
        uk_map.png
        resources.qrc
        incidentwidget.h incidentwidget.cpp
        infractionwidget.h infractionwidget.cpp
    )
else()
    if(ANDROID)
        add_library(sqlConnection SHARED ${PROJECT_SOURCES})
    else()
        add_executable(sqlConnection ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(sqlConnection PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.sqlConnection)
endif()

set_target_properties(sqlConnection PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS sqlConnection
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sqlConnection)
endif()

# Custom command to copy the database file to the build directory
set(DB_SOURCE "${CMAKE_SOURCE_DIR}/db/InfractionDB.sqlite")
set(DB_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/sqlConnection.app/Contents/Resources/db/InfractionDB.sqlite")

message(STATUS "Copying database from ${DB_SOURCE} to ${DB_DESTINATION}")

add_custom_command(
    OUTPUT ${DB_DESTINATION}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/sqlConnection.app/Contents/Resources/db"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DB_SOURCE} ${DB_DESTINATION}
    COMMENT "Copying database file to bundle"
    VERBATIM
)

add_custom_target(CopyDatabase ALL DEPENDS ${DB_DESTINATION})
add_dependencies(sqlConnection CopyDatabase)


