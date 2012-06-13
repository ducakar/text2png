cmake_minimum_required( VERSION 2.8 )
project( text2png )

find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )

add_definitions( ${QT_DEFINITIONS} )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra" )

add_executable( text2png main.cc )
target_link_libraries( text2png ${QT_LIBRARIES} )
install( TARGETS text2png RUNTIME DESTINATION bin )
