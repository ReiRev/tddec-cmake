add_executable(AllTests
    AllTests.cpp
    SprintfTest.cpp
)

target_include_directories(AllTests
    PRIVATE
        .
)

target_link_libraries(AllTests
    PRIVATE
        CppUTest
)

enable_testing()
add_test(AllTests AllTests)