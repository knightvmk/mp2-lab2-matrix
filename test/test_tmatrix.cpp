#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<double> m(6);
	TMatrix<double>m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<double> m(2);
	m[1][1] = 5;
	TMatrix<double> m1(m);
	m1[1][1] = 4;
	EXPECT_NE(m[1][1], m1[1][1]);

}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(2);
	int size = m.GetSize();
	//ASSERT_NO_THROW(m.GetSize()); // ??можно??
	EXPECT_EQ(size, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(2);
	m[0][1] = 1;
	int get = 1;
	EXPECT_EQ(get, m[0][1]);
	//ASSERT_NO_THROW(m[1][1]=2); //можно??
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<double>m(3);
	ASSERT_ANY_THROW(m[-1][0] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<double>m(5);
	ASSERT_ANY_THROW(m[7][0] = 12);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(3);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<double> m(4), m1(4);
	EXPECT_EQ(m, m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(3), m1(5);
	EXPECT_EQ(m1.GetSize(), (m = m1).GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<double> m(7), m1(5);
	EXPECT_EQ(m, m = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	bool eq= true;
	TMatrix<int> m(2), m1(2);
	EXPECT_EQ(eq, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	bool eq = true;
	TMatrix<int> m(7);
	EXPECT_EQ(eq, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	bool eq = true;
	TMatrix<double> m(5), m1(7);
	EXPECT_EQ(eq, m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2), m1(2),res(2);
	m[0][0] = m[0][1] = m[1][1] = 1;
	m1[0][0] = m1[0][1] = m1[1][1] = 4;
	res[0][0] = res[0][1] = res[1][1] = 5;
	EXPECT_EQ(res, m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<double> m(5), m1(7);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(2), m1(2), res(2);
	m[0][0] = m[0][1] = m[1][1] = 20;
	m1[0][0] = m1[0][1] = m1[1][1] = 7;
	res[0][0] = res[0][1] = res[1][1] = 13;
	EXPECT_EQ(res, m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<double> m(3), m1(5);
	ASSERT_ANY_THROW(m - m1);
}

