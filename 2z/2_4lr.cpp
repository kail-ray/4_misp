//modAlphaCipher.h
/**
* @file 
* @author Karamishev I.A.
* @version 1.0.0
* @brief Заголовочный файл для модуля modAlphaCipher
* @date 20.12.2022
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;
/* @class modAlphaCipher
 * @author Karamishev I.A.
 * @date 20.12.2022
 * @file modAlphaCipher.h
 * @brief Шифрование методом Маршрутной перестановки
 * @detalies Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст на обработку передается до выбора опреации. Доступна отмена выполнения программы..
 * @warnings Реализация только для английского  языка!
 */
class modAlphaCipher
{
private:
    int key;
     /** @brief Метод класса, проверяющий текс на валидность
     ** @param [in] s Текст на русском языке
     ** @return result
     */
    string getValidText(const std::string & s);
     /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     ** @param [in] s Зашифрованный текст на английском языке
     ** @return result
     */
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& newkey) :key(newkey) {};   // конструктор
    /** @brief Зашифрование
     ** @param [in] text Открытый текст на английском языке
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Зашифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    string coder(const string& open_st);   // зашифрование
    /** @brief Расшифрование
     ** @param [in] text Зашифрованный текст на английском языке
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    string decoder(const string& cipher_st); // расшифрование
    
};
/** @class cipher_error
     ** @file modAlphaCipher.h
     ** @brief Класс вызова исключений 
     */
class cipher_error: public std::invalid_argument
{
public:
/** @brief Валидация текста
     ** @param [in] what_arg После проверки текста при помощи getValidText, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
         /** @brief Валидация текста
     ** @param [in] what_arg После проверки номера операции, если возвращенный параметр вызывает исключения, причина вызова исключений передается в качестве параметра функцию.
     ** @warnings Текс не должен быть пустоц строкой и не должен содержать пробелы. В тексте могут содержаться знаки перпинания и цифры.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста ввеена пустая строка
     */
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};