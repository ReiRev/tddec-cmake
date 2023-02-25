cmake_minimum_required(VERSION 3.8)
project("Test Driven Development for cpputest(2.3)")

set(TARGET_GROUP production CACHE STRING "Group to build")

include(FetchContent) # once in the project to include the module

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(src)
elseif(TARGET_GROUP STREQUAL test)
    FetchContent_Declare(CppUTest
                        GIT_REPOSITORY https://github.com/cpputest/cpputest.git
                        GIT_TAG        master)
    FetchContent_MakeAvailable(CppUTest)
    add_subdirectory(test)
    include(CTest)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()