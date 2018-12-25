set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

file(GLOB MY_TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB MY_TEST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
set(MY_BINARY_NAME "UnitTestExecutor")

add_executable(${MY_BINARY_NAME}
  ${MY_TEST_SRCS}
  ${MY_SRCS_MINUS_MAIN}
  )

target_include_directories(${MY_BINARY_NAME} PUBLIC
  ${MY_INCLUDES}
  ${MY_TEST_INCLUDES}
  )

target_link_libraries(${MY_BINARY_NAME}
  GTest::GTest
  GTest::GMock
  )

add_dependencies(${MY_BINARY_NAME}
  GoogleTest
  )
