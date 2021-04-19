set(SUBDIRS
  Queue
  Rand10
  SharedPtr
  String
  strStr
)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
