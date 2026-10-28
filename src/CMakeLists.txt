add_library(armsim armsim.cpp)

include(GenerateExportHeader)
target_link_libraries(armsim PUBLIC Eigen3::Eigen)
generate_export_header(armsim)