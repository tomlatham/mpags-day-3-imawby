# - Declare the build of a static MPAGS library 
add_library(MPAGSCipher STATIC
  TransformChar.hpp
  TransformChar.cpp
  ProcessCommandLine.cpp
  ProcessCommandLine.hpp
  CaesarCipher.hpp
  CaesarCipher.cpp
  CipherMode.hpp
)

target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(MPAGSCipher
  PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
)  
