#pragma once

#include "const_table.h"
#include "lexeme.h"
#include <vector>

//Класс, для хранения переменных таблиц, в виде хеш-таблиц
//Реализация в виде хеш-таблицы с цепочками. Хеширование производится по первому символу индендификатора
const int hash_N = 26 * 2 + 10; //Максимальное значение хэша
class varTable {
public:
	//Конструктор, для выделения нужной памяти
	varTable() {
		table = new vector<lexeme>[hash_N];
	}
	//Деструктор
	~varTable() {
		for (int i = 0; i < hash_N; i++)
			table[i].clear();
		delete[] table;
	}

	bool addInd(string name); //Функция добавления индендификатора, true - если добавили, false - не добавили.
	bool setIndType(string iname, int type); //Функция добавления значения типа индендификатору.
	bool setIndFlagOfInit(string name, bool val); //Функция измения флага инициализации индендификатора.
	bool checkIndInTable(string name); //Проверка, входит ли индендификатор в таблицу, true - входит, false - нет.
	bool getAdress(string name, int& hash, int& numb); //Возврашает полный адрес идентификатора, либо false если его нет в таблице.
	bool getLexemeByInd(string name, lexeme& lexeme); //Получаем токен по идентификатору, если такого нет - false.
	bool getLexemeByAdress(int hash, int numb, lexeme& lexeme); //Получаем токен по его полному адресу, если такого нет - false.
	bool setTypeByAdress(int hash, int numb, int type); //Установка типа по полному адресу
	bool setFlagOfInitByAdress(int hash, int numb, bool val); //Установка значения по полному адресу



private:

	vector<lexeme>* table; //наша табличка


	int calcHash(string name);	//Функция вычисления хэша. Сначала - числа, потом строчные буквы, потом заглавные
	int findInVec(int hash, string name);
};

