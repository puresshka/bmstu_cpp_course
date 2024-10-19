#include <stdio.h>
#include <stdbool.h>
#include <limits.h> 

bool isSpace(char c) 
{
  return c == ' ';
}

bool isDigit(char c) 
{
  return c >= '0' && c <= '9'; // Исправлено условие
}

int str2int(const char *str) 
{
  int result = 0;
  int sign = 1;
  bool hasDigits = false; // Флаг, отмечающий, что хотя бы одна цифра была прочитана

  // Пропускаем пробелы
  while (isSpace(*str)) {
    str++;
  }

  // Обрабатываем знак (плюс или минус)
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++; // Пропускаем плюс, если он есть
  }

  // Читаем цифры
  while (isDigit(*str)) {
    int digit = *str - '0'; // Правильное преобразование символа в число
    
    // Проверка на переполнение 
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
      if (sign == 1) return INT_MAX;
      else return INT_MIN;
    }
    
    result = result * 10 + digit;
    str++;
    hasDigits = true; // Устанавливаем флаг, что цифры были прочитаны
  }


  if (!hasDigits) {
    return 0; // Возвращаем 0, если строка не содержит цифр
  }

  return result * sign;
}