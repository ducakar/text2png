cmake_minimum_required(VERSION 3.10)
project(text2png)

set(CMAKE_INCLUDE_CURRENT_DIR)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion")

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

add_executable(text2png main.cc)
qt5_use_modules(text2png Widgets)
install(TARGETS text2png RUNTIME DESTINATION bin)
