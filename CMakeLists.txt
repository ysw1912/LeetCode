cmake_minimum_required(VERSION 3.14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_library(utils
  src/data_structure.cpp
  src/utils.cpp
)

set(SUBDIRS string_set_union backtrace binary_search dfs dp greedy two_pointers Interview)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
