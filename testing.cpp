//
// Created by santas_molderras on 22.09.22.
//
#include <gtest/gtest.h>
#include "../cassini.h"


TEST(PointConstructor, ConstructorWithArguments)
{
Lab2::Point p(1, 4);
    ASSERT_EQ(1, p.x);
    ASSERT_EQ(4, p.y);

}

TEST(CassiniConstructor, InitConstructors)
{
Lab2::Point F1(1, 2);
Lab2::Point F2(7, 3);
Lab2::Cassini cassini(F1, F2, 14);
    ASSERT_EQ(1, cassini.getF1().x);
    ASSERT_EQ(2, cassini.getF1().y);
    ASSERT_EQ(7, cassini.getF2().x);
    ASSERT_EQ(3, cassini.getF2().y);

Lab2::Cassini cassini2(1, 2, 1, 2, 8);
    ASSERT_EQ(1, cassini2.getF1().x);
    ASSERT_EQ(2, cassini2.getF1().y);
    ASSERT_EQ(1, cassini2.getF2().x);
    ASSERT_EQ(2, cassini2.getF2().y);
    ASSERT_EQ(8, cassini2.getA());
}

TEST(CassiniConstructor, TestException)
{
Lab2::Point F1(5, 12);
Lab2::Point F2(-4, 2);
    ASSERT_ANY_THROW(Lab2::Cassini(F1, F2, 100));
    ASSERT_ANY_THROW(Lab2::Cassini(12.7, -34, -0.32, 9, 9.33));
}

TEST(CassiniMethods, Setters)
{
Lab2::Cassini a (12);
Lab2::Point p1(3, 2);
Lab2::Point p2(31, 2.5);
a.setF1(p1);
a.setF2(p2);
    ASSERT_EQ(3, a.getF1().x);
    ASSERT_EQ(2, a.getF1().y);
    ASSERT_EQ(31, a.getF1().x);
    ASSERT_EQ(2.5, a.getF1().y);
a.setA(12);
    ASSERT_EQ(12, a.getA());
    ASSERT_ANY_THROW(a.setA(-1));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
