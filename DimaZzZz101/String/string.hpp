// Copyright 2021 DimaZzZz101

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <iostream>
#include <cstring>

class String {
 public:
  /// Деструктор
  ~String();

  /// Конструктор по умолчанию
  String();

  /// Конструктор копирования
  /// <param name="rhs">Объект, который копируем </param>
  String(const String& rhs);

  /// Пользовательский конструктор
  /// <param name="data">Данные, которые требуется поместить в создаваемый
  /// объект </param>
  explicit String(const char* data);

  /// Оператор присваивания
  /// <param name="data">Объект, который копируем </param>
  /// <returns>Возвращаем ссылку на себя</returns>
  String& operator=(const String& rhs);

  /// Оператор +=
  /// <param name="rhs">Объект, который стоит после знака '+=' </param>
  /// <returns>Возвращаем ссылку на себя</returns>
  String& operator+=(const String& rhs);

  /// Оператор *=
  /// <returns>Возвращаем ссылку на себя</returns>
  String& operator*=(unsigned int m);

  /// Оператор ==
  /// <param name="rhs">Объект, который стоит после знака '==' </param>
  /// <returns>Возвращаем значения равенства двух строк</returns>
  bool operator==(const String& rhs) const;

  /// Оператор &lt;
  /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
  /// <returns>Возвращаем значения сравнения двух строк</returns>
  bool operator<(const String& rhs) const;

  /// Функция поиска подстроки
  /// <param name="substr">Подстрока, которую необходимо найти </param>
  /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то
  /// возвратить -1</returns>
  size_t Find(const String& substr) const;

  /// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
  /// <param name="oldSymbol">Символ, который требуется заменить </param>
  /// <param name="newSymbol">Символ, на который требуется заменить </param>
  void Replace(char oldSymbol, char newSymbol);

  /// Функция возвращает длину строки
  /// <returns>Возвращаем длину строки</returns>
  size_t Size() const;

  /// Функция для определения пуста ли строка
  bool Empty() const;

  /// Оператор []
  /// <example>
  /// <code>
  /// String str = "some string";
  /// char symbol = str[2]; // symbol == 'm'
  /// </code>
  /// </example>
  /// <param name="index"> Индекс символа </param>
  /// <returns> Значение символа в строке с индексом index</returns>
  char operator[](size_t index) const;

  /// Оператор []
  /// <example>
  /// <code>
  /// String str = "some string";
  /// str[0] = 'S'; // теперь переменная str равна "Some string"
  /// </code>
  /// </example>
  /// <param name="index"> Индекс символа </param>
  /// <returns> Ссылка на символ в строке с индексом index</returns>
  char& operator[](size_t index);

  /// Смотри пример
  /// <example>
  /// <code>
  /// String str = "___some string___";
  /// str.RTrim('_'); // теперь переменная str равна "___some string"
  /// </code>
  /// </example>
  /// <param name="symbol"> Значение символов, которе отрезаем </param>
  void RTrim(char symbol);

  /// Смотри пример
  /// <example>
  /// <code>
  /// String str = "___some string___";
  /// str.LTrim('_'); // теперь переменная str равна "some string___"
  /// </code>
  /// </example>
  /// <param name="symbol"> Значение символов, которе отрезаем </param>
  void LTrim(char symbol);

  void swap(String& oth);

  friend std::ostream& operator<<(std::ostream&, const String&);

 private:
  char* Data;
};

/// Оператор +
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b);

/// Оператор +
/// <example>
/// <code>
/// String a = "A";
/// String c = a * 5; // c равна "AAAAA"
/// </code>
/// </example>
String operator*(const String& a, unsigned int b);

/// Оператор !=
bool operator!=(const String& a, const String& b);

/// Оператор &gt;
bool operator>(const String& a, const String& b);

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream& operator<<(std::ostream& out, const String& str);

#endif  // INCLUDE_STRING_HPP_
