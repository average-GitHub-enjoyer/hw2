#include <gtest/gtest.h>
#include "string.hpp"

TEST(bmstu_string_test, MoveConstructor) {
    bmstu::String str1 = "string1";
    bmstu::String<char> str2;
    str2 += str1;
    bmstu::String str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}

TEST(bmstu_string_test, RuMoveConstructor) {
    bmstu::String<wchar_t> str1 = L"строка1";
    bmstu::String<wchar_t> str2;
    str2 += str1;
    bmstu::String str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}

TEST(Operator, CopyAssignment) {
    bmstu::String str1 = "string1";
    bmstu::String<char> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str2.c_str(), "string1");
    ASSERT_STREQ(str1.c_str(), "string1");
}

TEST(Operator, RuCopyAssignment) {
    bmstu::String str1 = L"строка1";
    bmstu::String<wchar_t> str2;
    str2 = str1;
    str1 = str1;
    ASSERT_STREQ(str1.c_str(), L"строка1");
    ASSERT_STREQ(str2.c_str(), L"строка1");
}

TEST(Operator, MoveAssignment) {
    bmstu::String str1 = "string1";
    bmstu::String str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), "string1");
}

TEST(Operator, RuMoveAssignment) {
    bmstu::String<wchar_t> str1 = L"строка1";
    bmstu::String str3 = std::move(str1);
    ASSERT_STREQ(str3.c_str(), L"строка1");
}

TEST(Operator, MoveSelfAssignment) {
    bmstu::String str1 = "string1";
    str1 = std::move(str1);
    ASSERT_STREQ(str1.c_str(), "string1");
}

TEST(Operator, RuMoveSelfAssignment) {
    bmstu::String<wchar_t> str1 = L"строка1";
    str1 = std::move(str1);
    ASSERT_EQ(str1.size(), 7);
    ASSERT_STREQ(str1.c_str(), L"строка1");
}

TEST(Operator, StringAssignment) {
    bmstu::String<char> str;
    str = "string1";
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), "string1");
}

TEST(Operator, RuStringAssignment) {
    bmstu::String<wchar_t> str;
    str = L"строка1";
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), L"строка1");
}

TEST(Operator, Concatination) {
    bmstu::String str1("string ");
    bmstu::String str2("one");
    bmstu::String str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 10);
    ASSERT_STREQ(str3.c_str(), "string one");
}

TEST(Operator, RuConcatination) {
    bmstu::String str1 = L"строка ";
    bmstu::String str2 = L"один";
    bmstu::String str3 = str1 + str2;
    ASSERT_EQ(str3.size(), 11);
    ASSERT_STREQ(str3.c_str(), L"строка один");
}

TEST(Operator, ConcatenationAssignment) {
    bmstu::String str1 = "string ";
    bmstu::String str2 = "one";
    str1 += str2;
    ASSERT_EQ(str1.size(), 10);
    ASSERT_STREQ(str1.c_str(), "string one");
}

TEST(Operator, RuConcatenationAssignment) {
    bmstu::String str1 = L"строка ";
    bmstu::String str2 = L"один";
    str1 += str2;
    ASSERT_EQ(str1.size(), 11);
    ASSERT_STREQ(str1.c_str(), L"строка один");
}

TEST(Operator, CharAddition) {
    bmstu::String str = "string on";
    str += 'e';
    ASSERT_EQ(str.size(), 10);
    ASSERT_STREQ(str.c_str(), "string one");
}

TEST(Operator, RuCharAddition) {
    bmstu::String<wchar_t> str = L"строка оди";
    str += L'н';
    ASSERT_EQ(str.size(), 11);
    ASSERT_STREQ(str.c_str(), L"строка один");
}

TEST(Operator, SimbolIndex) {
    bmstu::String str = "string1";
    ASSERT_EQ(str[3], 'i');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, RuSimbolIndex) {
    bmstu::String<wchar_t> str = L"строка1";
    ASSERT_EQ(str[3], L'о');
    ASSERT_THROW(str[100], std::runtime_error);
}

TEST(Operator, Cout) {
    bmstu::String str = "string1";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, RuCout) {
    bmstu::String str = "строка1";
    testing::internal::CaptureStdout();
    std::cout << str;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(str.c_str(), output);
}

TEST(Operator, Cin) {
    std::stringstream str;
    str.str("string111");
    bmstu::String str2("string2");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "string111");
}

TEST(Operator, RuCin) {
    std::stringstream str;
    str.str("строка111");
    bmstu::String str2("строка2");
    str >> str2;
    ASSERT_STREQ(str2.c_str(), "строка111");
}

TEST(Getters, CString) {
    bmstu::String str("string1");
    ASSERT_STREQ(str.c_str(), "string1");
}

TEST(Getters, RuCString) {
    bmstu::String<wchar_t> str(L"строка1");
    ASSERT_STREQ(str.c_str(), L"строка1");
}

TEST(Getters, SizeOfString) {
    bmstu::String str = "string1";
    ASSERT_EQ(str.size(), 7);
}

TEST(Getters, RuSizeOfString) {
    bmstu::String<wchar_t> str = L"строка2";
    ASSERT_EQ(str.size(), 7);
}

TEST(Constructor, DefaultConstructor) {
    bmstu::String<char> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(Constructor, WideStringDefaultConstructor) {
    bmstu::String<wchar_t> str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"");
}

TEST(Constructor, CStr) {
    bmstu::String str("string1");
    const char *c_str = "string1";
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST(Constructor, RuCStr) {
    bmstu::String<wchar_t> str(L"строка1");
    const wchar_t *c_str = L"строка1";
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), c_str);
}

TEST (Constructor, WithCStringParametrsNullptr) {
    bmstu::String str = "";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "\0");
}

TEST (Constructor, WideWithCStringParametrsNullptr) {
    bmstu::String<wchar_t> str = L"";
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), L"\0");
}

TEST (Constructor, WithCstringParametrs) {
    bmstu::String str("string1");
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), "string1");
}

TEST (Constructor, RuWithCstringParametrs) {
    bmstu::String<wchar_t> str(L"строка1");
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), L"строка1");
}

TEST(Constructor, CopyConstructor) {
    bmstu::String str1("string1");
    bmstu::String str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, RuCopyConstructor) {
    bmstu::String<wchar_t> str1(L"строка1");
    bmstu::String str2(str1);
    ASSERT_STREQ(str1.c_str(), str2.c_str());
}

TEST(Constructor, MoveConstructor) {
    bmstu::String str1 = "string1";
    bmstu::String<char> str2;
    str2 += str1;
    bmstu::String str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}
TEST(Constructor, RuMoveConstructor) {
    bmstu::String<wchar_t> str1 = L"строка1";
    bmstu::String<wchar_t> str2;
    str2 += str1;
    bmstu::String str3 = std::move(str1);
    ASSERT_EQ(str1.size(), 0);
    ASSERT_STREQ(str3.c_str(), str2.c_str());
}

TEST(StringTest, DefaultConstructor) {
    bmstu::string str;
    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, RuDefaultConstructor) {
    bmstu::wstring str;
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, InitializerListConstructor) {
    bmstu::wstring str{};
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, RuInitializerListConstructor) {
    bmstu::wstring str{};
    ASSERT_STREQ(str.c_str(), L"");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, InitializerListConstructorNotEmpty) {
    bmstu::wstring str{L'С', L'Т', L'Р', L'О', L'К', L'А'};
    ASSERT_STREQ(str.c_str(), L"СТРОКА");
    ASSERT_EQ(str.size(), 6);
}


TEST(StringTest, ConstructorSize) {
    bmstu::string str(10);
    ASSERT_STREQ(str.c_str(), "          ");
    ASSERT_EQ(str.size(), 10);
}


TEST(StringTest, ConstructorSizeW) {
    bmstu::wstring str(10);
    ASSERT_STREQ(str.c_str(), L"          ");
    ASSERT_EQ(str.size(), 10);
}

TEST(StringTest, ConstructorSizeOne) {
    bmstu::wstring str(1);
    ASSERT_STREQ(str.c_str(), L" ");
    ASSERT_EQ(str.size(), 1);
}

TEST(StringTest, FromCStr) {
    bmstu::string str("str\n");
    ASSERT_STREQ(str.c_str(), "str\n");
    ASSERT_EQ(str.size(), 4);
}

TEST(StringTest, WFromCStr) {
    bmstu::wstring str(L"строка1");
    ASSERT_STREQ(str.c_str(), L"строка1");
    ASSERT_EQ(str.size(), 7);
}

TEST(StringTest, FromWCStrSymbol) {
    bmstu::wstring str(L"строка1");
    ASSERT_STREQ(str.c_str(), L"строка1");
    wchar_t c = L'с';
    ASSERT_EQ(str[0], c);
}

TEST(StringTest, USymbolsW) {
    bmstu::wstring str(L"с");
    ASSERT_STREQ(str.c_str(), L"с");
    wchar_t c = L'с';
    ASSERT_EQ(str.size(), 1);
}


TEST(StringTest, Empty) {
    bmstu::string empty;
    ASSERT_EQ(empty.size(), 0);
    ASSERT_STREQ(empty.c_str(), "");
}

TEST(StringTest, EmptyW) {
    bmstu::wstring empty;
    ASSERT_EQ(empty.size(), 0);
    ASSERT_STREQ(empty.c_str(), L"");
}

TEST(StringTest, CopyAssignW) {
    bmstu::wstring empty(L"строка1");
    bmstu::wstring nonempty = empty;
    ASSERT_STREQ(nonempty.c_str(), L"строка1");
    ASSERT_EQ(nonempty.size(), 7);
}

TEST(StringTest, CopyConstructor) {
    bmstu::string empty("строка1");
    bmstu::string nonempty = empty;
    ASSERT_STREQ(nonempty.c_str(), "строка1");
    ASSERT_EQ(nonempty.size(), sizeof("строка1") - 1);
}

TEST(StringTest, CopyAssignConstructor) {
    bmstu::string *str = new bmstu::string("string1");
    bmstu::string *nonempty = new bmstu::string;
    *nonempty = *str;
    ASSERT_STREQ(nonempty->c_str(), "string1");
    ASSERT_EQ(nonempty->size(), sizeof("string1") - 1);
    delete str;
    delete nonempty;
}

TEST(StringTest, MoveAssignConstructor) {
    bmstu::string str = "string1";
    bmstu::string str2 = "string2";
    str2 = std::move(str);
    ASSERT_STREQ(str2.c_str(), "string1");
    ASSERT_EQ(str2.size(), sizeof("string1") - 1);

    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, MoveAssignConstructor2) {
    bmstu::string str = "string1";
    bmstu::string str2 = "string2";
    str2 = std::move(str);
    ASSERT_STREQ(str2.c_str(), "string1");
    ASSERT_EQ(str2.size(), sizeof("string1") - 1);

    ASSERT_STREQ(str.c_str(), "");
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTest, MoveAssignConstructorW) {
    bmstu::wstring str2(std::move(bmstu::wstring(L"string2")));
    ASSERT_STREQ(str2.c_str(), L"string2");
    ASSERT_EQ(str2.size(), (sizeof(L"string2") / sizeof(wchar_t)) - 1);
}

TEST(StringTest, CStrCopyAssign) {
    const char *str = "string1";
    bmstu::string b_str;
    b_str = str;
    ASSERT_STREQ(b_str.c_str(), str);
}

TEST(StringTest, CStrCopyAssignW) {
    const wchar_t *str = L"строка1";
    bmstu::wstring b_str;
    b_str = str;
    ASSERT_STREQ(b_str.c_str(), str);
}

TEST(StringTest, AssignCStr) {
    bmstu::wstring str = L"строка1";
    ASSERT_STREQ(str.c_str(), L"строка1");
}

TEST(StringTest, ConcatOpW) {
    bmstu::wstring a_str(L"строка ");
    bmstu::wstring b_str(L"один");
    auto c_str = a_str + b_str;
    ASSERT_STREQ(c_str.c_str(), L"строка один");
}

TEST(StringTest, ConcatOp) {
    bmstu::string a_str("string ");
    bmstu::string b_str("one");
    auto c_str = a_str + b_str;
    ASSERT_STREQ(c_str.c_str(), "string one");
}

TEST(StringTest, OStream) {
    bmstu::string a_str("string1");
    std::stringstream ss;
    ss << a_str;
    ASSERT_STREQ(ss.str().c_str(), "string1");
}

TEST(StringTest, OStreamW) {
    bmstu::wstring a_str(L"строка1");
    std::wstringstream ss;
    ss << a_str;
    ASSERT_STREQ(ss.str().c_str(), L"строка1");
}

TEST(StringTest, IStream) {
    std::stringstream ss;
    ss.str("string1");
    bmstu::string a_str;
    std::string a;
    ss >> a_str;
    ASSERT_STREQ(a_str.c_str(), "string1");
}

TEST(StringTest, IStreamW) {
    std::wstringstream ss;
    ss.str(L"строка1");
    bmstu::wstring a_str;
    ss >> a_str;
    ASSERT_STREQ(a_str.c_str(), L"строка1");
}

TEST(StringTest, IStreamWNewLine) {
    std::wstringstream ss;
    ss.str(L"Value of\nstring");
    bmstu::wstring a_str;
    ss >> a_str;
    ASSERT_STREQ(ss.str().c_str(), L"Value of\nstring");
}

TEST(StringTest, ConcatSymbol) {
    bmstu::wstring a_str;
    a_str += L'S';
    ASSERT_STREQ(a_str.c_str(), L"S");
    a_str += L't';
    ASSERT_STREQ(a_str.c_str(), L"St");
    a_str += L'r';
    ASSERT_STREQ(a_str.c_str(), L"Str");
    ASSERT_EQ(a_str.size(), 3);
}

TEST(StringTest, Item) {
    bmstu::wstring a_str(L"строкаодин");
    ASSERT_EQ(a_str[0], L'с');
    ASSERT_EQ(a_str[1], L'т');
    ASSERT_EQ(a_str[a_str.size() - 1], L'н');
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
