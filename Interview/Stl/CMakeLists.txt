set(SUBDIRS
  LRU
  Queue
  Rand10
  SharedPtr
  String
  StringSplit
  strStr
)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
