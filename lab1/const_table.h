#pragma once

#include "lexeme.h"
#include <fstream>
#include <set>
#include <iostream>

//Класс, релазиующий хранение постоянных таблиц
//Поскольку у нас могут быть как целые строки, так и символы чтобы не тратить память - делаем шаблон
template <typename tableType> class ConstTable{
 public:

	 //Два конструктора. Скучный - по умлочанию, и для генерации из файла
	 ConstTable(){
	 }
	 ConstTable(string f_name){
		 generateTableFromFile(f_name);
	 }
	 //И деструктор, для приличия
	 ~ConstTable(){
		 table.clear();
	 }
	//Генерирует таблицу из файла, возаращает true если файл открыли, false если нет
	 bool generateTableFromFile(string fileName){
		 ifstream fileStream(fileName.c_str()); //поток чтения из файла

		 if(fileStream.is_open()){
			 tableType readElement; //считываемый элемент

			 while(!fileStream.eof()){
				 fileStream >> readElement;
				 table.insert(readElement);
			 };

			 fileStream.close();
			 return true;
		 }

		 else
			 return false;
	 }

	//Добавление одного элемента в табилцу. Малоли, вдруг пригодится.
	void addElement(tableType elem){
		table.insert(elem);
	}
	//Проверка - есть ли элемент в таблице, true если есть, false если нет.
	bool checkElementInTable(tableType elem){
		return table.count(elem) ? true : false;
	}
	//Поиск номера элемента. Если такого нет - false.
	bool findElementNumber(tableType elem, int& num){
		if(checkElementInTable(elem)){
			num = distance(table.begin(), table.find(elem));
			return true;
		}
		else
			return false;
	}
	//Поиск элемента по номеру. Если такого нет - false.
	bool findElement(int num, tableType& elem){
		if(num >= 0 && num < table.size()){
			typename::set<tableType>::iterator elIter = table.begin();
			for(int i = 0; i < num; i++)
				elIter++;
			elem = *elIter;
			return true;
		}
		else
			return false;
	}

 private:
	set<tableType> table; //собственно, наша табличка
};
