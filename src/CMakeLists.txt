add_library(armsim armsim.cpp)

include(GenerateExportHeader)
add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE armsim PUBLIC Eigen3::Eigen)
generate_export_header(armsim)