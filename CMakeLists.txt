cmake_minimum_required(VERSION 3.16)

project(Kabaw_chat_client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick QuickWidgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall")

set(WARNING_EFFC "-Weffc++")
set(WARNING_CONVERSION "-Wconversion -Wsign-conversion")
set(WARNING_EXTRA "-Wall -Wextra -pedantic-errors")

set(FOCUS_WARNING ${WARNING_EFFC})
set(FOCUS_WARNING ${WARNING_CONVERSION})
set(FOCUS_WARNING ${WARNING_EXTRA})

include_directories(
    ${CMAKE_SOURCE_DIR}/Include
)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/main.cpp"
    "${CMAKE_SOURCE_DIR}/Include/*.h"
    "${CMAKE_SOURCE_DIR}/Include/**/*.h"
    "${CMAKE_SOURCE_DIR}/UI/*.cpp"
    "${CMAKE_SOURCE_DIR}/UI/**/*.cpp"
)

file(GLOB_RECURSE UI_FILES
    "${CMAKE_SOURCE_DIR}/UI/*.ui"
)

add_executable(Kabaw_chat_client
    ${APP_SOURCES}
    ${UI_FILES}
)

target_include_directories(Kabaw_chat_client PRIVATE
${CMAKE_SOURCE_DIR}/Include
)

set(CMAKE_AUTOUIC_OUTPUT_DIR "${CMAKE_BINARY_DIR}/Generated")

if(WIN32)
    set_target_properties(Kabaw_chat_client PROPERTIES OUTPUT_NAME "Kabaw_chat_client.exe")
else()
    set_target_properties(Kabaw_chat_client PROPERTIES OUTPUT_NAME "Kabaw_chat_client")
endif()

set_target_properties(Kabaw_chat_client PROPERTIES AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/UI/Dialogs")

target_link_libraries(Kabaw_chat_client
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickWidgets
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(Kabaw_chat_client PROPERTIES FOLDER "Apps")