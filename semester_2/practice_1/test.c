#include "unity/unity.h"
#include "funcs.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_generate_array()
{
	int arr[40][60];
	generate_array(40, 60, arr);
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 60; j++) {
			TEST_ASSERT_GREATER_OR_EQUAL(1, arr[i][j]);
			TEST_ASSERT_LESS_OR_EQUAL(10, arr[i][j]);
		}
}

static void test_is_even_array()
{
	int actual[4][5] = { { 1, 2, 3, 4, 5 },
			     { 6, 6, 6, 6, 6 },
			     { 7, 7, 7, 7, 7 },
			     { 8, 9, 10, 1, 2 } };

	int expected[4][5] = { { 1, 0, 1, 0, 1 },
			       { 0, 0, 0, 0, 0 },
			       { 1, 1, 1, 1, 1 },
			       { 0, 1, 0, 1, 0 } };

	is_even_array(4, 5, actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 20);
}

static void test_rows_bin_to_dec()
{
	int test_matrix[4][5] = { { 1, 0, 1, 0, 1 },
				  { 0, 0, 0, 0, 0 },
				  { 1, 1, 1, 1, 1 },
				  { 0, 1, 0, 1, 0 } };

	int expected[4] = { 21, 0, 31, 10 };
	int actual[4] = { 0 };
	rows_bin_to_dec(4, 5, test_matrix, actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 4);
}

static void test_cols_bin_to_dec()
{
	int test_matrix[4][5] = { { 1, 0, 1, 0, 1 },
				  { 0, 0, 0, 0, 0 },
				  { 1, 1, 1, 1, 1 },
				  { 0, 1, 0, 1, 0 } };

	int expected[5] = { 10, 3, 10, 3, 10 };
	int actual[5] = { 0 };
	cols_bin_to_dec(4, 5, test_matrix, actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 5);
}

static void test_max_element_position()
{
	int test_array[6] = { 1, 0, 5, 21, 2, 6 };
	int expected = 3;
	TEST_ASSERT_EQUAL(expected, max_element_position(test_array, 6));
}

int main(void)
{
	UnityBegin("test.c");

	RUN_TEST(test_generate_array);
	RUN_TEST(test_is_even_array);
	RUN_TEST(test_rows_bin_to_dec);
	RUN_TEST(test_cols_bin_to_dec);
	RUN_TEST(test_max_element_position);

	return UnityEnd();
}
