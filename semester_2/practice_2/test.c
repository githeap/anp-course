#include <stdlib.h>
#include "unity/unity.h"
#include "funcs.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_array_create()
{
	int *actual = array_create(40);
	TEST_ASSERT_NOT_NULL(actual);

	for (int i = 0; i < 40; i++)
		actual[i] = 0;

	free(actual);
}

static void test_array_pushback()
{
	int *actual = calloc(10, sizeof(int));
	TEST_ASSERT_NOT_NULL(actual);

	TEST_ASSERT_TRUE(array_pushback(&actual, 10, 42));
	TEST_ASSERT_EQUAL(42, actual[10]);

	free(actual);
}

static void test_array_popback()
{
	int *actual = calloc(10, sizeof(int));
	actual[9] = 42;
	TEST_ASSERT_TRUE(array_popback(&actual, 10));

	TEST_ASSERT_EACH_EQUAL_INT(0, actual, 9);

	free(actual);
}

static void test_array_insert()
{
	int *actual = calloc(8, sizeof(int));

	int expected[] = { 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0 };
	int insert[] = { 1, 2, 3, 4 };
	TEST_ASSERT_TRUE(array_insert(&actual, 8, insert, 4, 4));
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 5);

	free(actual);
}

static void test_array_remove()
{
	int *actual = calloc(8, sizeof(int));
	actual[0] = 0;
	actual[1] = 1;
	actual[2] = 2;
	actual[3] = 3;
	actual[4] = 4;
	actual[5] = 5;
	actual[6] = 6;
	actual[7] = 7;

	TEST_ASSERT_TRUE(array_remove(&actual, 8, 2, 4));
	int expected[4] = { 0, 1, 6, 7 };
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 4);

	free(actual);
}

int main(void)
{
	UnityBegin("test.c");

	RUN_TEST(test_array_create);
	RUN_TEST(test_array_pushback);
	RUN_TEST(test_array_popback);
	RUN_TEST(test_array_insert);
	RUN_TEST(test_array_remove);

	return UnityEnd();
}
