cmake_minimum_required(VERSION 3.24)
project(MemoryManagerTest C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES_DATA_STRUCT DataStructures/Src/LinkedList/LinkedList.c DataStructures/Util/Utility.c DataStructures/Include/LinkedList.h DataStructures/Include/Utility.h)
set(SOURCE_FILES_MEM_MAN Src/MemoryManager.c Include/MemoryManager.h)

add_library(DataStructures ${SOURCE_FILES_DATA_STRUCT})

add_executable(MemoryManagerTest Test/MemoryManagerTest.c ${SOURCE_FILES_MEM_MAN})

target_link_libraries(MemoryManagerTest PRIVATE DataStructures)