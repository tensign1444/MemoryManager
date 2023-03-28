cmake_minimum_required(VERSION 3.24)
project(MemoryManager C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES_DATA_STRUCT DataStructures/LinkedList/LinkedList.c DataStructures/Util/Utility.c Src/Queue/Queue.c DataStructures/Src/Stack/Stack.c DataStructures/Test/TestRun.c DataStructures/Test/LinkedListTest.c DataStructures/Test/StackTest.c DataStructures/Test/StackTest.c)
set(SOURCE_FILES_MEM Src/MemoryManager.c)


add_library(DataStructures ${SOURCE_FILES_DATA_STRUCT})
add_library(MemoryManager ${SOURCE_FILES_MEM})


add_executable(MemoryManagerTest Src/main.c)

target_link_libraries(MemoryManager DataStructures)
target_link_libraries(MemoryManagerTest MemoryManager)
