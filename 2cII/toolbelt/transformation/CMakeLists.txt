add_library(transformation STATIC interpolation.cpp)
target_compile_features(oscillators PUBLIC cxx_std_20)
target_include_directories(oscillators PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

