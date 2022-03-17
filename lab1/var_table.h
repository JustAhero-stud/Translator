#pragma once

#include "const_table.h"
#include "lexeme.h"
#include <vector>

//�����, ��� �������� ���������� ������, � ���� ���-������
//���������� � ���� ���-������� � ���������. ����������� ������������ �� ������� ������� ���������������
const int hash_N = 26 * 2 + 10; //������������ �������� ����
class varTable {
public:
	//�����������, ��� ��������� ������ ������
	varTable() {
		table = new vector<lexeme>[hash_N];
	}
	//����������
	~varTable() {
		for (int i = 0; i < hash_N; i++)
			table[i].clear();
		delete[] table;
	}

	bool addInd(string name); //������� ���������� ���������������, true - ���� ��������, false - �� ��������.
	bool setIndType(string iname, int type); //������� ���������� �������� ���� ���������������.
	bool setIndFlagOfInit(string name, bool val); //������� ������� ����� ������������� ���������������.
	bool checkIndInTable(string name); //��������, ������ �� �������������� � �������, true - ������, false - ���.
	bool getAdress(string name, int& hash, int& numb); //���������� ������ ����� ��������������, ���� false ���� ��� ��� � �������.
	bool getLexemeByInd(string name, lexeme& lexeme); //�������� ����� �� ��������������, ���� ������ ��� - false.
	bool getLexemeByAdress(int hash, int numb, lexeme& lexeme); //�������� ����� �� ��� ������� ������, ���� ������ ��� - false.
	bool setTypeByAdress(int hash, int numb, int type); //��������� ���� �� ������� ������
	bool setFlagOfInitByAdress(int hash, int numb, bool val); //��������� �������� �� ������� ������



private:

	vector<lexeme>* table; //���� ��������


	int calcHash(string name);	//������� ���������� ����. ������� - �����, ����� �������� �����, ����� ���������
	int findInVec(int hash, string name);
};

