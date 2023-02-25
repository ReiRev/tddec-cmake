add_executable(AllTests
    AllTests.cpp
    SprintfTest.cpp
)

target_include_directories(AllTests
    PRIVATE
        .
)

target_compile_options(AllTests
    PRIVATE $<$<BOOL:${MSVC}>:/wd4723>
)

target_link_libraries(AllTests
    PRIVATE
        CppUTest
)

if(CPPUTEST_TEST_DISCOVERY OR NOT DEFINED CPPUTEST_TEST_DISCOVERY)
    include(CppUTest)
    cpputest_discover_tests(AllTests)
endif()

add_test(hoge AllTests)
