#ifndef FIRST_BMSTU_STRING_H
#define FIRST_BMSTU_STRING_H

#include <cstddef>
#include <ostream>
#include <iostream>


namespace bmstu {
  class String {
    public:
      String();
      String(const char *c_str);
      String(const String &other);
      String(std::initializer_list<char> il);
      String(String &&dying);
      ~String();
  
      std::size_t size() const;
      const char* c_str() const;
  
      String &operator=(const String &other);
      String &operator=(String &other);
      String &operator=(const char *c_str);
      String &operator+=(const String &other);
      String &operator+=(const char *str);
      String &operator+=(const char symbol);

      char &operator[](std::size_t index);
 
    private:
      friend String operator+(const String &left, const String &right);
      friend bool operator==(const String &left, const String &right);
      friend std::ostream &operator<<(std::ostream &os, const String &obj);
      friend std::istream &operator>>(std::istream &is, String &obj);
      std::size_t strlen_(const char *str);
      void clean_();
      char *ptr_ = nullptr;   
      std::size_t size_;
  };
}

#endif //FIRST_BMSTU_STRING_H
