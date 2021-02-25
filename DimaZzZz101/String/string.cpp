// Copyright 2021 DimaZzZz101

#include "string.hpp"

/// Деструктор
String::~String() { delete[] Data; }

/// Конструктор по умолчанию
String::String() : Data(nullptr) {}

/// Конструктор копирования
String::String(const String& rhs) {
  size_t size = rhs.Size();

  Data = new char[size + 1];

  std::copy(rhs.Data, rhs.Data + size + 1, Data);
}

/// Пользовательский конструктор
String::String(const char* data) {
  size_t size = strlen(data);

  Data = new char[size + 1];

  std::copy(data, data + size + 1, Data);
}

/// Оператор копирующего присваивания
String& String::operator=(const String& rhs) {
  if (&rhs != this) {
    delete[] Data;

    size_t size = rhs.Size();

    Data = new char[size + 1];

    std::copy(rhs.Data, rhs.Data + size + 1, Data);
  }

  return *this;
}

/// Оператор +=
String& String::operator+=(const String& rhs) {
  size_t lhs_size = Size();
  size_t rhs_size = rhs.Size();

  char* tmp_str = new char[lhs_size + rhs_size + 1];

  for (size_t i = 0; i < lhs_size; ++i) tmp_str[i] = Data[i];
  for (size_t i = lhs_size; i < lhs_size + rhs_size + 1; ++i) tmp_str[i] = rhs[i - lhs_size];

  delete[] Data;
  Data = new char[lhs_size + rhs_size + 1];

  std::copy(tmp_str, tmp_str+ lhs_size + rhs_size + 1, Data);
  delete[] tmp_str;

  return *this;
}

/// Оператор *=
String& String::operator*=(unsigned int m) {
  size_t lhs_size = Size();

  char* tmp_str = new char[m * lhs_size + 1];

  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < lhs_size; ++j) {
      tmp_str[i * lhs_size + j] = Data[j];
    }
  }

  tmp_str[m * lhs_size] = '\0';

  delete[] Data;
  Data = new char[m * lhs_size + 1];

  std::copy(tmp_str, tmp_str + m * lhs_size + 1, Data);
  delete[] tmp_str;

  return *this;
}

/// Оператор ==
bool String::operator==(const String& rhs) const { return std::strcmp(Data,rhs.Data) == 0; }

/// Оператор &lt;
bool String::operator<(const String& rhs) const { return std::strcmp(Data, rhs.Data) < 0; }

/// Функция поиска подстроки
size_t String::Find(const String& substr) const {
  size_t substr_size = substr.Size();

  if (substr.Empty()) return -1;

  for (size_t i = 0; i < Size(); ++i) {
    if (Data[i] == substr[0]) {
      for (size_t j = 0; j < substr_size; ++j) {
        if (substr[j] != Data[i + j]) break;

        if (j == substr_size - 1) {
          return i;
        }
      }
    }
  }
  return -1;
}
/// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
void String::Replace(char oldSymbol, char newSymbol) {
  size_t str_size = Size();

  for (size_t i = 0; i < str_size; ++i) {
    if (Data[i] == oldSymbol) {
      Data[i] = newSymbol;
    }
  }
}

/// Функция возвращает длину строки
size_t String::Size() const { return std::strlen(Data); }

/// Функция для определения пуста ли строка
bool String::Empty() const { return Data == nullptr; }

/// Оператор [] константный
char String::operator[](size_t index) const { return Data[index]; }

/// Оператор []
char& String::operator[](size_t index) { return Data[index]; }

/// Смотри пример
/// <example>
/// <code>
/// String str = "___some string___";
/// str.RTrim('_'); // теперь переменная str равна "___some string"
/// </code>
/// </example>
/// <param name="symbol"> Значение символов, которе отрезаем </param>
void String::RTrim(char symbol) {
  size_t Data_size = Size() - 1;

  for (; Data_size > 0; --Data_size) {
    if (Data[Data_size] != symbol) {
      break;
    }
  }

  char* tmp_str = new char[Data_size + 2];

  std::copy(Data, Data + Data_size + 1, tmp_str);

  delete[] Data;

  tmp_str[Data_size + 1] = '\0';

  Data = tmp_str;
}

/// Смотри пример
/// <example>
/// <code>
/// String str = "___some string___";
/// str.LTrim('_'); // теперь переменная str равна "some string___"
/// </code>
/// </example>
/// <param name="symbol"> Значение символов, которе отрезаем </param>
void String::LTrim(char symbol) {
  size_t Data_size = 0;

  for (; Data_size < Size(); ++Data_size) {
    if (Data[Data_size] != symbol) {
      break;
    }
  }

  char* tmp_str = new char[Size() - Data_size + 1];

  std::copy(Data + Data_size, Data + Size() + 1, tmp_str);

  delete[] Data;

  Data = tmp_str;
}

/// Замена одной строки на другую
void String::swap(String& oth) { std::swap(Data,oth.Data); }

/// Оператор +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b) {
  String result_str = a;

  result_str += b;

  return result_str;
}



/// Оператор *
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c равна "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b) {
  String result_str = a;

  result_str *= b;

  return result_str;
}

/// Оператор !=
bool operator!=(const String& a, const String& b) { return !(a == b); }

/// Оператор &gt;
bool operator>(const String& a, const String& b) { return b < a; }

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>

std::ostream& operator<<(std::ostream& out, const String& str) {
  out << str.Data;
  return out;
}