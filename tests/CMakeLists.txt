add_executable(unit_tests test1.cpp)

target_link_libraries(unit_tests 
    PRIVATE
        gtest
        gtest_main
        armsim
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
