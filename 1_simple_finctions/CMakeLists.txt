project("SimpleFunctions")


add_executable(SimpleFunctions main.cpp functions.cpp)
add_library(SimpleFunctionsLib functions.cpp)

add_subdirectory(Google_tests)

