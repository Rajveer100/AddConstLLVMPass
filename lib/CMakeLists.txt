add_library(AddConst MODULE
        AddConstAnalysis.cpp
        AddConstPlugin.cpp
        AddConstPass.cpp)

target_include_directories(AddConst PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../include")

llvm_map_components_to_libnames(llvm_libs support core irreader analysis)

target_link_libraries(AddConst PRIVATE ${llvm_libs})
