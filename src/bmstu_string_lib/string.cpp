#include "bmstu/string.hpp"

bmstu::String::String() {
    ptr_ = new char[1]; // Динамическое выделение памяти для 1 символа
    *ptr_ = '\0';       // Единственный символ в созданной строке завершающий строку символ \0
    size_ = 0;          // Значение размера строки при создании: 0
}

const char* bmstu::String::c_str() const {       // Pub-метод, возвращающий строку
    return ptr_;
}

/// Конструктор с параметрами
bmstu::String::String(const char *c_str) {     // Выполняется, если созданной строке присваювают зачение, например my_str = "Hello"
    clean_();
    size_ = strlen_(c_str);     // Вычисление размера полученной стоки
    if (size_ == 0) {       // Если пуская строка
        ptr_ = new char[1];
        *ptr_ = '\0';
        size_ = 0;
    } else {        // Если не пустая строка
        ptr_ = new char[size_ + 1];     // Выделенее памяти для всех символов строки и одного завершающего строку символа \0
        ptr_[size_] = '\0';             // Последний символ - \0

        for (int c = 0; c < size_; c++) {       // Посимвольное "копирование" строки в динамичную память
            ptr_[c] = c_str[c];
        }
    }
}

///  конструктор копирующего присваивания для строк класса bmstu::String с помощью скобок
bmstu::String::String(const bmstu::String &other) {
    if (this != &other) {
        clean_();
        size_ = other.size_;
        ptr_ = new char[size_ + 1];
        ptr_[size_] = 0;
        for (int i = 0; i < size_; i++) {
            *(ptr_ + i) = other.c_str()[i];
        }
    }
}

/// Конструктор через массив char
bmstu::String::String(std::initializer_list<char> il)  : ptr_(new char[il.size() + 1]) {
    ptr_[il.size()] = 0;
    size_ = il.size();
    for (int i = 0; i < il.size(); i++) {
        ptr_[i] = *(il.begin() + i);
    }
}

/// Перемещающий конструктор
bmstu::String::String(bmstu::String &&dying) {
    if (this != &dying) {
      clean_();
      ptr_ = dying.ptr_;
      size_ = dying.size_;
      dying.ptr_ = nullptr;
      dying.size_ = 0;
    }
}

/// Деконструктор - медор, удаляющий элемент класса после завершения работы с ним
bmstu::String::~String() {
  delete[] ptr_;
}

std::size_t bmstu::String::size() const {      // const метод - метод, который не изменяет значение
    return size_;
}

/// Оператор копирующего присваивания (=) - Работает со строками класс bmstu::String
bmstu::String &bmstu::String::operator=(const bmstu::String &other) {
    if (this != &other) {
        clean_();
        size_ = other.size_;
        ptr_ = new char[size_ + 1];
        ptr_[size_] = 0;
        for (int i = 0; i < size_; i++) {
            *(ptr_ + i) = other.c_str()[i];
        }
    }
    return *this;
}

/// Оператор перемещающего присваивания
bmstu::String &bmstu::String::operator=(bmstu::String &other) {
  clean_();
  ptr_ = other.ptr_;
  size_ = other.size_;
  other.size_ = 0;
  other.ptr_ = nullptr;
  return *this;
}

/// Оператор присваивания (=) - Работает со C - строками (char *str)
bmstu::String &bmstu::String::operator=(const char *c_str) {
    clean_();
    size_ = strlen_(c_str);
    ptr_ = new char[size_ + 1];
    ptr_[size_] = 0;
    for (int i = 0; i < size_; i++) {
        ptr_[i] = c_str[i];
    }
    return *this;
}

bmstu::String &bmstu::String::operator+=(const bmstu::String &other) {
    size_t new_size = size_ + other.size_;
    auto new_ptr = new char[new_size + 1];
    for (int i = 0; i < size_; i++) {
        new_ptr[i] = ptr_[i];
    }

    for (int i = 0; i < other.size_; i++) {
        new_ptr[i + size_] = other.ptr_[i];
    }

    new_ptr[new_size] = 0;
    clean_();
    ptr_ = new_ptr;
    size_ = new_size;
    return *this;
}

bmstu::String &bmstu::String::operator+=(const char *str) {
    size_t strlen = strlen_(str);
    size_t new_size = size_ + strlen;
    auto new_ptr = new char[new_size + 1];
    for (int i = 0; i < size_; i++) {
        new_ptr[i] = ptr_[i];
    }

    for (int i = 0; i < strlen; i++) {
        new_ptr[i + size_] = str[i];
    }

    new_ptr[new_size] = 0;
    clean_();
    ptr_ = new_ptr;
    size_ = new_size;
    return *this;
}

bmstu::String &bmstu::String::operator+=(const char symbol) {
    size_t new_size = size_ + 1;
    auto new_ptr = new char[new_size + 1];
    for (int i = 0; i < size_; i++) {
        new_ptr[i] = ptr_[i];
    }

    new_ptr[new_size-1] = symbol;
    new_ptr[new_size] = 0;
    clean_();
    ptr_ = new_ptr;
    size_ = new_size;
    return *this;
}

/// Метод получения символа строки по его индексу
char &bmstu::String::operator[](size_t index) {
    if (index < size_) {
        return *(ptr_ + index);
    }
    throw std::runtime_error("Wrong index " + std::to_string(index));
    // Если индекс привышает допустимое значени, выходится ошибка о неверном индексе
}

bmstu::String bmstu::operator+(const bmstu::String &left, const bmstu::String &right) {
    bmstu::String result = bmstu::String(left);
    result += right;
    return result;
}

bool bmstu::operator==(const bmstu::String &left, const bmstu::String &right){
  if (left.size_ != right.size_)
    return false;
  
  for(int i=0; i < left.size_; i++){
    if(*(left.ptr_ + i) != *(right.ptr_ + i))
      return false;
  }
  return true;
}

std::ostream& bmstu::operator<<(std::ostream &os, const bmstu::String &obj) {
    os << obj.c_str();
    return os;
}

std::istream& bmstu::operator>>(std::istream &is, bmstu::String &obj) {
    bmstu::String result;
    char buf;
    while (is.good()) {
        is.get(buf);
        if (buf == '\n') {
            break;
        }
        result += buf;
    }
    obj = std::move(result);
    return is;
}

std::size_t bmstu::String::strlen_(const char *str) {       // Pr-метод, вычисляющий длину строки
    size_t result = 0;
    while (*str) {
        result++;
        ++str;
    }
    return result;
}

void bmstu::String::clean_() {
    if (ptr_ != nullptr) {
        delete[] ptr_;
        ptr_ = nullptr;
    }
    size_ = 0;
}
