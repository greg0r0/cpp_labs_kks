#include <gtest/gtest.h>
#include "../includes/substring.hpp"
#include <iostream>

std::string s0 = "i'm, simple little text";
std::string p0 = "simple";
std::vector<int> expect_res0 = {5};

std::string s1 = "aaaaaaaaaaaaaaaaaa";
std::string p1 = "aaa";
std::vector<int> expect_res1 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

std::string s2 = "addaabbaabbaadba";
std::string p2 = "abba";
std::vector<int> expect_res2 = {4,8};

std::string s3 = "Never gonna give you up \nNever gonna let you down";
std::string p3 = "you";
std::vector<int> expect_res3 = {17,41};

std::string s4 = "abcbacdabdbabdbabcabddba";
std::string p4 = "abdbab";
std::vector<int> expect_res4 = {7,11};

std::string s5 = "asdasdaasddasdassd";
std::string p5 = "asd";
std::vector<int> expect_res5 = {0,3,7,11};

std::string s6 = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
std::string p6 = "ab";
std::vector<int> expect_res6 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256, 258, 260, 262, 264, 266, 268, 270, 272, 274, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298};

/*
    Boyer-Moor
*/
TEST (_alg_boyer_mur_Test, __test_1)
{
    auto res = lab6::alg_boyer_mur(s0,p0);
    ASSERT_EQ(res, expect_res0);
}

TEST (_alg_boyer_mur_Test, __test_2)
{
    auto res = lab6::alg_boyer_mur(s1,p1);
    ASSERT_EQ(res, expect_res1);
}

TEST (_alg_boyer_mur_Test, __test_3)
{
    auto res = lab6::alg_boyer_mur(s2,p2);
    ASSERT_EQ(res, expect_res2);
}

TEST (_alg_boyer_mur_Test, __test_4)
{
    auto res = lab6::alg_boyer_mur(s3,p3);

    ASSERT_EQ(res, expect_res3);
}

TEST (_alg_boyer_mur_Test, __test_5)
{
    auto res = lab6::alg_boyer_mur(s4,p4);
    ASSERT_EQ(res, expect_res4);
}

TEST (_alg_boyer_mur_Test, __test_6)
{
    auto res = lab6::alg_boyer_mur(s5,p5);
    ASSERT_EQ(res, expect_res5);
}


TEST (_alg_boyer_mur_Test, __test_7)
{
    auto res = lab6::alg_boyer_mur(s6,p6);
    ASSERT_EQ(res, expect_res6);
}

/*
    Rabin-Karp
*/

TEST (_alg_rabin_karp_Test, __test_1)
{
    auto res = lab6::alg_rabin_karp(s0,p0);
    ASSERT_EQ(res, expect_res0);
}

TEST (_alg_rabin_karp_Test, __test_2)
{
    auto res = lab6::alg_rabin_karp(s1,p1);
    ASSERT_EQ(res, expect_res1);
}

TEST (_alg_rabin_karp_Test, __test_3)
{
    auto res = lab6::alg_rabin_karp(s2,p2);
    ASSERT_EQ(res, expect_res2);
}

TEST (_alg_rabin_karp_Test, __test_4)
{
    auto res = lab6::alg_rabin_karp(s3,p3);
    ASSERT_EQ(res, expect_res3);
}

TEST (_alg_rabin_karp_Test, __test_5)
{
    auto res = lab6::alg_rabin_karp(s4,p4);
    ASSERT_EQ(res, expect_res4);
}

TEST (_alg_rabin_karp_Test, __test_6)
{
    auto res = lab6::alg_rabin_karp(s5,p5);
    ASSERT_EQ(res, expect_res5);
}

TEST (_alg_rabin_karp_Test, __test_7)
{
    auto res = lab6::alg_rabin_karp(s6,p6);
    ASSERT_EQ(res, expect_res6);
}

/*
    KMP
*/

TEST (_alg_KMP_Test, __test_1)
{
    auto res = lab6::alg_KMP(s0,p0);
    ASSERT_EQ(res, expect_res0);
}

TEST (_alg_KMP_Test, __test_2)
{
    auto res = lab6::alg_KMP(s1,p1);
    ASSERT_EQ(res, expect_res1);
}

TEST (_alg_KMP_Test, __test_3)
{
    auto res = lab6::alg_KMP(s2,p2);
    ASSERT_EQ(res, expect_res2);
}

TEST (_alg_KMP_Test, __test_4)
{
    auto res = lab6::alg_KMP(s3,p3);
    ASSERT_EQ(res, expect_res3);
}

TEST (_alg_KMP_Test, __test_5)
{
    auto res = lab6::alg_KMP(s4,p4);
    ASSERT_EQ(res, expect_res4);
}

TEST (_alg_KMP_Test, __test_6)
{
    auto res = lab6::alg_KMP(s5,p5);
    ASSERT_EQ(res, expect_res5);
}

TEST (_alg_KMP_Test, __test_7)
{
    auto res = lab6::alg_KMP(s6,p6);
    ASSERT_EQ(res, expect_res6);
}

/*
    FSM generator
*/

TEST (_alg_FSM_Test, __test_1)
{
    auto res = lab6::alg_KMP(s0,p0);
    ASSERT_EQ(res, expect_res0);
}

TEST (_alg_FSM_Test, __test_2)
{
    auto res = lab6::alg_KMP(s1,p1);
    ASSERT_EQ(res, expect_res1);
}

TEST (_alg_FSM_Test, __test_3)
{
    auto res = lab6::alg_KMP(s2,p2);
    ASSERT_EQ(res, expect_res2);
}

TEST (_alg_FSM_Test, __test_4)
{
    auto res = lab6::alg_KMP(s3,p3);
    ASSERT_EQ(res, expect_res3);
}

TEST (_alg_FSM_Test, __test_5)
{
    auto res = lab6::alg_KMP(s4,p4);
    ASSERT_EQ(res, expect_res4);
}

TEST (_alg_FSM_Test, __test_6)
{
    auto res = lab6::alg_KMP(s5,p5);
    ASSERT_EQ(res, expect_res5);
}

TEST (_alg_FSM_Test, __test_7)
{
    auto res = lab6::alg_KMP(s6,p6);
    ASSERT_EQ(res, expect_res6);
}