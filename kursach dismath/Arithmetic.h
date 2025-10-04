#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Arithmetic
{
	char alph[8] = { 'a','b','c','d','e','f','g','h' };
	char poryadok[8] = { 'a', 'b', 'e', 'h', 'c', 'd', 'g', 'f' };
	std::vector<char> plusone = { 'b', 'e', 'd', 'g', 'h', 'a', 'f', 'c' };
	string a;
	string b;
	//таблички
	char Sum[8][8];
	char SumSdvig[8][8];
	char Mult[8][8];
	char MultSdvig[8][8];
public:
	Arithmetic();
	void fillTableSum();  
	void fillTableSdvigSum();
	void fillTableMult();
	void fillTableSdvigMult();
	//inputs
	void sumInput();
	void subInput();
	void multInput();
	void divInput();
	void ChooseOperationsMenu(int op);
	//searchers
	char twoSum(char a, char b); 
	int searchIndex(char a);
	int searchAlph(char a);
	int searchPoryadok(char a);
	char searchSum(char a, char b);
	char searchSub(char a, char b);
	char searchMult(char a, char b);
	char searchMultSd(char a, char b);
	char searchSumSd(char a, char b);
	//сравнение
	int compare(string a, string b);
	bool Comparasion(char a, char b);
	//сумма
	string sum(string a, string b, bool flag);
	string plus(string a, string b);
	string minus(string a, string b);
	//умножение
	char twoMult(char a, char b);
	string mult(string a, string b);
	vector <string> div(string a, string b, vector <string> result);
};

