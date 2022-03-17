#pragma once

#include <string>

using namespace std;

//���������, ���������� ���������� �������������� ������.
struct lexeme {
	string name; //��� ���������������
	int type;
	//��� ���������������
	//0 - �� ���������
	//1 - int
	//2 - char
	//3 - float
	bool isInit; //�������������� �� �������������. true - ���������������, false - ���.

	//�����������, ��� ���������� ����
	lexeme() {
	}
	lexeme(string elemName) {
		name = elemName;
		type = 0;
		isInit = false;
	}

	//��� ����
	bool operator < (const lexeme& b) const {
		return name < b.name;
	}

	bool operator == (lexeme b) {
		return name == b.name;
	}
};

