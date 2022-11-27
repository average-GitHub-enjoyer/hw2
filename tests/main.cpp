#include <gtest/gtest.h>
#include "bmstu/string.hpp"

TEST(bmstu_string_test, sum){
  bmstu::String str1("строка1");
  bmstu::String str2("строка2");
  bmstu::String str12(str1 + str2);
  ASSERT_EQ(str12, bmstu::String("строка1строка2"));
}

TEST(bmstu_string_test, copydefine){
  bmstu::String str1("строка1");
  bmstu::String str2 = str1;
  ASSERT_EQ(str2, str1);
}

TEST(bmstu_string_test, define){
  bmstu::String str1("строка1");
  bmstu::String str2("строка2");
  str1 = "строка2";
  ASSERT_EQ(str1, str2);
}

TEST(bmstu_string_test, sumstrings){
  bmstu::String str1("строка1");
  bmstu::String str2("строка2");
  bmstu::String str12 = str1 + str2;
  ASSERT_EQ(str12, "строка1строка2");
}

TEST(bmstu_string_test, sumstringarray){
  bmstu::String str1("строка1");
  bmstu::String str12 = str1 + "str2";
  ASSERT_EQ(str12, "строка1str2");
}

TEST(bmstu_string_test, sumeqstrings){
  bmstu::String str1("строка1");
  bmstu::String str2("строка2");
  str1 += str2;
  ASSERT_EQ(str1, "строка1строка2");
}

TEST(bmstu_string_test, sumeqstringarray){
  bmstu::String str1("строка1");
  str1 += "str2";
  ASSERT_EQ(str1, "строка1str2");
}

TEST(bmstu_string_test, sumeqstringsymbol){
  bmstu::String str1("строка1");
  str1 += 'V';
  ASSERT_EQ(str1, "строка1V");
}

TEST(bmstu_string_test, symbolindex){
  bmstu::String str1("string1");
  ASSERT_EQ(str1[1], 't');
  ASSERT_EQ(str1[3], 'i');
  ASSERT_EQ(str1[5], 'g');
}

TEST(bmstu_string_test, stringsize){
  bmstu::String str1("string1");
  ASSERT_EQ(str1.size(), 7);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
