add_library(sort_lib
  sort.cpp
)
target_include_directories(sort_lib
  PUBLIC
    .
)

set(SUBDIRS
  QuickSort
)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
