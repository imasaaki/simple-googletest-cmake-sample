cmake_minimum_required(VERSION 3.0)

#
# project settings
#
project(SIMPLE_GOOGLETEST_CMAKE_SAMPLE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

#
# find pthread for googletest
#
find_package(Threads REQUIRED)

#
# import googletest as an external project
#
include(ExternalProject)

externalproject_add(
  GoogleTest
  URL https://github.com/google/googletest/archive/release-1.8.1.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lib
  INSTALL_COMMAND ""
  )

externalproject_get_property(GoogleTest source_dir)
include_directories(${source_dir}/googletest/include)
include_directories(${source_dir}/googlemock/include)

externalproject_get_property(GoogleTest binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY GTest::GTest)
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_LIBRARY} PROPERTIES
  IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}
  IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GTEST_LIBRARY} GoogleTest)

set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
set(GMOCK_LIBRARY GTest::GMock)
add_library(${GMOCK_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_LIBRARY} PROPERTIES
  IMPORTED_LOCATION ${GMOCK_LIBRARY_PATH}
  IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(${GMOCK_LIBRARY} GoogleTest)

#
# create common variable
#
file(GLOB MY_SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(MY_INCLUDES ${PROJECT_SOURCE_DIR}/src)

#
# sub directories
#
add_subdirectory(src)
add_subdirectory(test)
