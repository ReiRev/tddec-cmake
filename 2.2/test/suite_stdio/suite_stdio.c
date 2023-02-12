#include "unity_fixture.c"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(Sprintf);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}