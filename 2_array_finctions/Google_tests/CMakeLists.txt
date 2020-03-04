include_directories(../../google_tests_lib/${gtest_SOURCE_DIR}/include ../../google_tests_lib/${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(ArrayFunctions_tests FirstTest.cpp)

target_link_libraries(ArrayFunctions_tests ArrayFunctionsLib)

target_link_libraries(ArrayFunctions_tests gtest gtest_main)