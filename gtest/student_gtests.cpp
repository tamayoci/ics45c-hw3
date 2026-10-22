#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10] = "aso";

    EXPECT_EQ(String::strncpy(result, "as", 5), result);
    EXPECT_STREQ(result, "as");
    EXPECT_EQ(result[2], '\0');
    EXPECT_EQ(result[3], '\0');
    EXPECT_EQ(result[4], '\0');
}

TEST(StringFunction, strcat) {
    char result[10] = "foo";

    EXPECT_EQ(String::strcat(result, "bar"), result);
    EXPECT_STREQ(result, "foobar");

    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(result, "foobar");
}

TEST(StringFunction, strncat) {
    char result[10] = "foo";

    String::strncat(result, "bar", 2);
    EXPECT_STREQ(result, "fooba");

    String::strncat(result, "baz", 3);
    EXPECT_STREQ(result, "foobabaz");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abcd"), 0);
    EXPECT_GT(String::strcmp("abcd", "abc"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abc", 3), 0);
    EXPECT_EQ(String::strncmp("abc", "abd", 2), 0);
    EXPECT_LT(String::strncmp("abc", "abd", 3), 0);
    EXPECT_GT(String::strncmp("abd", "abc", 3), 0);
    EXPECT_LT(String::strncmp("abc", "abcd", 4), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[10];

    String::reverse_cpy(result, "abc");
    EXPECT_STREQ(result, "cba");

    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";

    EXPECT_EQ(String::strchr(s, 'e'), s + 1);
    EXPECT_EQ(String::strchr(s, 'h'), s);
    EXPECT_EQ(String::strchr(s, 'z'), nullptr);
    EXPECT_EQ(String::strchr(s, '\0'), s + 5);
}

TEST(StringFunction, strstr) {
    const char *s = "hello";

    EXPECT_EQ(String::strstr(s, "ell"), s + 1);
    EXPECT_EQ(String::strstr(s, "lo"), s + 3);
    EXPECT_EQ(String::strstr(s, "h"), s);
    EXPECT_EQ(String::strstr(s, "z"), nullptr);
    EXPECT_EQ(String::strstr(s, ""), s);
}
