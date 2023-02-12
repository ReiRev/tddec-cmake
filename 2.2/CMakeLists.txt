cmake_minimum_required(VERSION 3.12)
project("Test Driven Development for Embbed C(Unity ver)" C)

set(TARGET_GROUP production CACHE STRING "Group to build")

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(src)
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)

    add_library(Unity STATIC
        Unity/src/unity.c
        Unity/extras/fixture/src/unity_fixture.c
        Unity/extras/memory/src/unity_memory.c
    )

    target_include_directories(Unity PUBLIC
        Unity/src
        Unity/extras/fixture/src
        Unity/extras/memory/src
    )

    add_subdirectory(test)

else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()
