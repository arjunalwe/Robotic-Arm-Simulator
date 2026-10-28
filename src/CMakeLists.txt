add_library(armsim armsim.cpp)

include(GenerateExportHeader)
target_link_libraries(armsim PUBLIC Eigen3::Eigen)
generate_export_header(armsim)

target_include_directories(armsim 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
)