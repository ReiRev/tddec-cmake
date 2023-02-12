add_executable(suite_stdio_app
    suite_stdio.c
)

target_sources(suite_stdio_app PRIVATE
    TestSprintf_Runner.c
    TestSprintf.c
)

target_link_libraries(suite_stdio_app
    Unity
)

add_test(suite_stdio_test suite_stdio_app)