#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
/**
 * @author Шиповский И.П
 * @date 05/29/21
 * @file 
 * @brief Хэдер для chipping.cpp
 * @details Описывает методы: void setMessage(wstring inputString); void setChiperedMessage(wstring inputChiperedString);
 * wstring getMessage(); wstring getChiperedMessage(); wstring chipping(std::wstring mess); wstring deChipping(std::wstring mess);
 * имеет 2 приватных переменных типа wstring, message, chiperedMessage;
 * запрещает конструктор поумолчанию и описывает конструктор Chiper(const int inputKey), получающий на вход целочисленное значение,
 * являющиеся Ключом(кол-вом столбцов).
 */

/// Класс Chiper
class Chiper{
/// Private часть класса Chiper
private:
/// Переменные для работы с сообщение и с зашифрованным сообщением
	wstring message, chiperedMessage;
/// Метод установки сообщения
	void setMessage(wstring inputString);
/// Метод установки зашифрованного сообщения
	void setChiperedMessage(wstring inputChiperedString);
/// Public часть класса Chiper
public:
/// Количество столбцов
	int kolichestvoStolbcov;
/// Метод получения сообщения
	wstring getMessage();
/// Метод получения зашифрованного сообщения
	wstring getChiperedMessage();
/// Метод шифрующий сообщение, на вход получает сообщение
	wstring chipping(std::wstring mess);
/// Метод расшифровывающий сообщение, на вход получает зашифрованное сообщение
	wstring deChipping(std::wstring mess);
/// Удаляем конструктор поумолчанию
	Chiper() = delete;
/// Создаем конструктор, получающий на вход Ключ(кол-во столбцов)
	Chiper(const int inputKey);
};
