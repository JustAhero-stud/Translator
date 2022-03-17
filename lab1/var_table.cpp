#include "var_table.h"

bool varTable::addInd(string name) {
	int hash = calcHash(name);
	bool check = checkIndInTable(name);
	if (!check) {
		table[hash].push_back(lexeme(name));
		return true;
	}
	else
		return false;
}

bool varTable::setIndType(std::string name, int type) {
	int hash = calcHash(name);
	if (checkIndInTable(name)) {
		int num = findInVec(hash, name); //ищим наш элемент
		table[hash][num].type = type;
		return true;
	}
	else
		return false;
}

bool varTable::setIndFlagOfInit(std::string name, bool val) {
	int hash = calcHash(name);
	if (checkIndInTable(name)) {
		int num = findInVec(hash, name); //ищим наш элемент
		table[hash][num].isInit = val;
		return true;
	}
	else
		return false;
}

bool varTable::setTypeByAdress(int hash, int numb, int type) {
	if (hash >= 0 && hash < hash_N && numb >= 0 && numb < table[hash].size()) {
		table[hash][numb].type = type;
		return true;
	}
	return false;
}

bool varTable::setFlagOfInitByAdress(int hash, int numb, bool val) {
	if (hash >= 0 && hash < hash_N && numb >= 0 && numb < table[hash].size()) {
		table[hash][numb].isInit = val;
		return true;
	}
	return false;
}

bool varTable::checkIndInTable(string name) {
	int hash = calcHash(name);

	int num = findInVec(hash, name); //номер элемента

	return num != -1 ? true : false;
}

int varTable::findInVec(int hash, string name) {
	lexeme findLexeme(name);
	for (int i = 0; i < table[hash].size(); i++)
		if (findLexeme == table[hash][i])
			return i;
	return -1;
}

bool varTable::getAdress(string name, int& hash, int& numb) {
	hash = calcHash(name);
	numb = findInVec(hash, name);
	return numb != -1 ? true : false;
}

bool varTable::getLexemeByInd(string name, lexeme& lexeme) {
	int hash, numb;
	bool check = getAdress(name, hash, numb);
	if (check) {
		lexeme = table[hash][numb];
		return true;
	}
	return false;
}

bool varTable::getLexemeByAdress(int hash, int numb, lexeme& lexeme) {
	if (hash >= 0 && hash < hash_N && numb >= 0 && numb < table[hash].size()) {
		lexeme = table[hash][numb];
		return true;
	}
	else
		return false;
}


int varTable::calcHash(string name) {
	if ('0' <= name[0] && name[0] <= '9')
		return name[0] - '0';
	if ('a' <= name[0] && name[0] <= 'z')
		return name[0] - 'a' + 10;
	if ('A' <= name[0] && name[0] <= 'Z')
		return name[0] - 'A' + 36;
	return 0;
}
