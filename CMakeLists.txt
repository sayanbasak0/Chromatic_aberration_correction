cmake_minimum_required( VERSION 3.13 )

project( CACtest VERSION 0.1.0 )

include( CTest )
enable_testing()

set( SOURCE_DIR src )
set( BUILD_DIR build )


find_package( OpenCV REQUIRED )

add_executable( ${PROJECT_NAME} main.cpp )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_subdirectory( ${SOURCE_DIR} )

target_include_directories( ${PROJECT_NAME} PUBLIC ${SOURCE_DIR} )

# target_link_directories( ${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src )

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} CAC )
# target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)