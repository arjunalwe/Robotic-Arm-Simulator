add_executable(unit_tests unit_tests.cpp)

target_link_libraries(unit_tests 
    PRIVATE
        gtest
        gtest_main
        armsim
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
