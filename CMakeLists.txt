cmake_minimum_required(VERSION 3.14.0)
project(RoboticArmSimulator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# must place above add_subdirectory
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.18.0
  FIND_PACKAGE_ARGS NAMES GTest
)

FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG        5.0.0
  FIND_PACKAGE_ARGS NAMES Eigen3
)

FetchContent_MakeAvailable(googletest eigen)
  
add_subdirectory(src)
add_subdirectory(tests)