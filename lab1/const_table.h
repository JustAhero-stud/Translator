#pragma once

#include "lexeme.h"
#include <fstream>
#include <set>
#include <iostream>

//�����, ����������� �������� ���������� ������
//��������� � ��� ����� ���� ��� ����� ������, ��� � ������� ����� �� ������� ������ - ������ ������
template <typename tableType> class ConstTable{
 public:

	 //��� ������������. ������� - �� ���������, � ��� ��������� �� �����
	 ConstTable(){
	 }
	 ConstTable(string f_name){
		 generateTableFromFile(f_name);
	 }
	 //� ����������, ��� ��������
	 ~ConstTable(){
		 table.clear();
	 }
	//���������� ������� �� �����, ���������� true ���� ���� �������, false ���� ���
	 bool generateTableFromFile(string fileName){
		 ifstream fileStream(fileName.c_str()); //����� ������ �� �����

		 if(fileStream.is_open()){
			 tableType readElement; //����������� �������

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

	//���������� ������ �������� � �������. ������, ����� ����������.
	void addElement(tableType elem){
		table.insert(elem);
	}
	//�������� - ���� �� ������� � �������, true ���� ����, false ���� ���.
	bool checkElementInTable(tableType elem){
		return table.count(elem) ? true : false;
	}
	//����� ������ ��������. ���� ������ ��� - false.
	bool findElementNumber(tableType elem, int& num){
		if(checkElementInTable(elem)){
			num = distance(table.begin(), table.find(elem));
			return true;
		}
		else
			return false;
	}
	//����� �������� �� ������. ���� ������ ��� - false.
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
	set<tableType> table; //����������, ���� ��������
};
