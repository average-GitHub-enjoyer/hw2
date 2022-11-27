#include <iostream>
#include "bmstu/string.hpp"

int main(){
  bmstu::String str1 = bmstu::String();
  bmstu::String str2 = bmstu::String("строка2");
  bmstu::String str3 = bmstu::String("строка3");
  bmstu::String str4 = bmstu::String("строка2");
  bmstu::String str23 = bmstu::String(str2 + str3);
  bmstu::String str32 = str3 + str2;

  std::cout << str23 << std::endl;
  std::cout << str32 << std::endl;
  std::cout << str1 << std::endl;
  std::cout << "Hello world!" << std::endl;
  std::cout << (str2 == str3) << std::endl;
  std::cout << (str2 == str4) << std::endl;
  
  return 0;
}
