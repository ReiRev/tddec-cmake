#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sprintf)
{
	RUN_TEST_CASE(Sprintf, NoFormatOperations);
	RUN_TEST_CASE(Sprintf, InsertString);
}