project("SimpleFunctions")


add_executable(ArrayFunctions main.cpp functions.cpp)
add_library(ArrayFunctionsLib functions.cpp)

add_subdirectory(Google_tests)

