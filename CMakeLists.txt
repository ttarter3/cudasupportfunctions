# cudasupportfunctions

cmake_minimum_required(VERSION 3.20)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

set(${ProjectId}_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(${ProjectId}_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}ConfigVersion.cmake")


# Set header files (C++ files)
file(GLOB_RECURSE _HDRS "include/*.hpp")

# Set source files (C++ files)
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")

# Set CUDA source files
file(GLOB_RECURSE CUDA_SOURCES "src/*.cu")

# Set include directories
include_directories(include)
include_directories(include/Common)

# Find CUDA package
find_package(CUDA REQUIRED)

# Specify GPU architecture, e.g., for NVIDIA GeForce GTX 1060
# set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode arch=compute_61,code=sm_61)

# Create shared library
cuda_add_library(${ProjectId} SHARED ${CPP_SOURCES} ${CUDA_SOURCES})

target_include_directories(${ProjectId} PUBLIC include)


# Install the library
install(TARGETS ${ProjectId} DESTINATION lib)
install(FILES ${_HDRS} DESTINATION include/${ProjectId})

# You can link against other libraries if needed
# target_link_libraries(${ProjectId} other_library)

# Optionally, if you want to build an executable using the library
# add_executable(${ProjectId} main.cpp)
# target_link_libraries(${ProjectId} ${ProjectId})