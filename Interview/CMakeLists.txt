set(SUBDIRS
  List
  Sort
  Stl
  String
)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
