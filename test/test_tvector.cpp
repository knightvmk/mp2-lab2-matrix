#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5, 0);
	v[1] = 5;
	TVector<int> v1(v);
	EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(6, 0);
	v[2] = 7;
	TVector<int> v1(v);
	v1[2] = 8;
	EXPECT_NE(v1, v);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW(v[-6]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW(v[11]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5, 0);
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(3, 0), v1(3, 0);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5, 0);
	TVector<int>v1(6, 0);
	v = v1;
	EXPECT_EQ(v.GetSize(), 6);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5, 0), v1(7, 0);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int>v(4, 0), v1(4, 0);
	v[1] = v1[1] = 5;
	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5, 0);
	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5, 0), v1(6, 0);
	EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(2, 0), v1(2, 0);
	v[0] = v[1] = 0;
	v = v + 5;
	v1[0] = 5;
	v1[1] = 5;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(2, 0), v1(2, 0);
	v[0] = v[1] = 0;
	v = v - 7;
	v1[0] = -7;
	v1[1] = -7;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(2, 0),v1(2,0);
	v[0]=v[1] = 1;
	v1[0] = v1[1] = 7;
	EXPECT_EQ(v1, v*7);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<double> v(2, 0), v1(2, 0),res(2,0);
	res[0] = res[1] = 3;
	v[0] = v[1] = 1;
	v1[0] = v1[1] = 2;
	v= v + v1;
	EXPECT_EQ(v,res);
}


TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<double> v(5, 0), v1(6, 0);
	ASSERT_ANY_THROW(v = v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<double> v(2, 0), v1(2, 0);
	v[0] = v[1] = 5;
	v1[0] = v1[1] = 2;
	v = v - v1;
	EXPECT_EQ(v[0], 3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(2, 0), v1(3, 0);
	ASSERT_ANY_THROW(v = v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<unsigned int> v(2, 0), v1(2, 0);
	v[0] = v[1] = 2;
	v1[0] = v1[1] = 10;
	int res = 40;
	EXPECT_EQ(40, v*v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<double> v(4, 0), v1(6, 0);
	ASSERT_ANY_THROW(v = v*v1);
}
