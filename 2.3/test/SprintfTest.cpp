#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"

#include <stdio.h>
#include <string.h>

static char output[100];
static const char* expected;

TEST_GROUP(Sprintf)
{

    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }

    void teardown() {}

    static void expect(const char* s)
    {
        expected = s;
    }

    static void given(int charsWritten)
    {
        LONGS_EQUAL(strlen(expected), charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};

TEST(Sprintf, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(Sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}