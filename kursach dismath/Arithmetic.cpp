#include "Arithmetic.h"
#include "func.h"

Arithmetic::Arithmetic() {
	fillTableSum();
	fillTableSdvigSum();
	fillTableMult();
	fillTableSdvigMult();
}

void Arithmetic::fillTableSum() {
	for (int i = 0; i < 8; i++) {
		Sum[i][0] = alph[i];
		Sum[0][i] = alph[i];
		Sum[i][1] = plusone[i];
		Sum[1][i] = plusone[i];
	}

	for (int i = 2; i < 8; i++) {
		for (int j = i; j < 8; j++) {
			char buf = twoSum(alph[i], alph[j]);
			Sum[i][j] = buf;
			Sum[j][i] = buf;

		}
	}
}

char Arithmetic::twoSum(char a, char b) {
	int k = 0;
	char result = a;
	char buf = b;
	char check = b;
	while (check != 'b') {
		buf = alph[searchIndex(buf)];
		check = plusone[searchAlph(buf)];
		k++;
	}
	while (k > 0) {
		result = plusone[searchAlph(result)];
		k--;
	}
	return result;
}

void Arithmetic::fillTableSdvigSum() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int tmp = searchPoryadok(alph[i]) + searchPoryadok(alph[j]);
			tmp = tmp / 8;
			SumSdvig[i][j] = poryadok[tmp];
		}
	}
}

void Arithmetic::fillTableMult() {
	for (int i = 0; i < 8; i++) {
		Mult[i][0] = 'a';
		Mult[0][i] = 'a';
		Mult[i][1] = alph[i];
		Mult[1][i] = alph[i];
	}
	for (int i = 2; i < 8; i++) {
		for (int j = i; j < 8; j++) {
			char sd = twoMult(alph[i], alph[j]);
			Mult[i][j] = sd;
			Mult[j][i] = sd;

		}
	}
}

char Arithmetic::twoMult(char a, char b) {
	char result = a;
	char buf = a;
	int k = searchPoryadok(b) - 1;
	while (k > 0) {
		result = searchSum(result, buf);
		k--;
	}
	return result;
}

void Arithmetic::fillTableSdvigMult() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int tmp =  searchPoryadok(alph[i]) * searchPoryadok(alph[j]);
			tmp = tmp / 8;
			MultSdvig[i][j] = poryadok[tmp];
		}
	}
}

void Arithmetic::ChooseOperationsMenu(int op)
{
	switch (op) {
	case 0:
		break;
	case 1:
		sumInput();
		break;
	case 2:
		subInput();
		break;
	case 3:
		multInput();
		break;
	case 4:
		divInput();
		break;
	}
}

char Arithmetic::searchSum(char a, char b) {
	return Sum[searchAlph(a)][searchAlph(b)];
};

char Arithmetic::searchSumSd(char a, char b) {
	return SumSdvig[searchAlph(a)][searchAlph(b)];
};

char Arithmetic::searchMult(char a, char b) {
	return Mult[searchAlph(a)][searchAlph(b)];
};

char Arithmetic::searchMultSd(char a, char b) {
	return MultSdvig[searchAlph(a)][searchAlph(b)];
};

int Arithmetic::searchIndex(char a) {
	for (int i = 0; i < 8; i++)
		if (plusone[i] == a) return i;
};

int Arithmetic::searchAlph(char a) {
	for (int i = 0; i < 8; i++) {
		if (a == alph[i]) return i;
	}
}

int Arithmetic::searchPoryadok(char a) {
	for (int i = 0; i < 8; i++)
		if (a == poryadok[i]) return i;
};

char Arithmetic::searchSub(char a, char b) {
	for (int i = 0; i < 8; i++)
		if (Sum[i][searchAlph(b)] == a) return alph[i];

};

void Arithmetic::sumInput() {
	a = Input1();
	b = Input2();
	string answer = sum(a, b, 1);
	cout << "�����: " << a << " + " << b << " = " << answer << "\n";
}


void Arithmetic::subInput() {
	a = Input1();
	b = Input2();
	string answer = sum(a, b, 0);
	cout << "�����: " << a << " - " << b << " = " << answer << "\n\n";
}

string Arithmetic::sum(string a, string b, bool fl) {
	string answer = "";
	int minuses_a = 0;
	int minuses_b = 0;
	int flag;
	if (a[0] == '-') {
		minuses_a++;
		a.erase(0, 1);
	}
	if (b[0] == '-') {
		minuses_b++;
		b.erase(0, 1);
	}
	while (a.size() != b.size()) {
		a.size() < b.size() ? a = 'a' + a : b = 'a' + b;
	}

	flag = compare(a, b);
	if ((minuses_a + minuses_b) == 1 && fl == 1
		|| (minuses_a + minuses_b) != 1 && fl == 0) {
		answer = minus(a, b);
		if (answer.size() > 8)
			answer = "overflow";
		if (answer != "overflow" &&
			((minuses_b == 1 && flag == -1 && fl == 1) ||
				(minuses_a == 1 && flag == 1 && fl == 1) ||
				((minuses_a + minuses_b) == 0 && flag == -1 && fl == 0) ||
				((minuses_a + minuses_b) == 2 && flag == 1 && fl == 0))) {
			answer = '-' + answer;
		}
	}
	else {
		answer = plus(a, b);
		if (answer.size() > 8)
			answer = "overflow";
		if (answer != "overflow" &&
			((minuses_a == 1 && flag == 1 && fl == 0) ||
				(minuses_a == 1 && flag == -1 && fl == 0) ||
				((minuses_a + minuses_b) == 2 && flag == -1 && fl == 1) ||
				((minuses_a + minuses_b) == 2 && flag == 1 && fl == 1)))
			answer = '-' + answer;
	}
	return answer;
}

string Arithmetic::plus(string a, string b) {
	char shift1 = 'a', shift2 = 'a', shift3 = 'a', solution;
	string answer = "";

	while (a.size() != b.size()) a.size() < b.size() ? a = 'a' + a : b = 'a' + b;

	for (int i = a.size() - 1; i >= 0; i--) {
		solution = searchSum(a[i], b[i]);
		shift2 = searchSumSd(a[i], b[i]);
		shift3 = searchSumSd(solution, shift1);
		solution = searchSum(solution, shift1);
		shift1 = searchSum(shift2, shift3);
		answer = solution + answer;
		shift2 = shift3 = 'a';
		if (i == 0 && shift1 != 'a') answer = shift1 + answer;
	}
	while (answer.size() > 1 && answer[0] == 'a') answer.erase(0, 1);
	return answer;
}

string Arithmetic::minus(string a, string b) {
	int flag;
	char solution;
	string answer = "";

	// ��������� �����
	flag = compare(a, b);
	if (flag == 0) {
		// ���� ����� �����, ��������� - 'a' (0)
		return "a";
	}
	else {
		// ���� b > a, ������ �� �������
		bool isNegative = false;
		if (flag == -1) {
			a.swap(b);
			isNegative = true; // ��������, ��� ��������� ����� �������������
		}

		// ������������ ����� �����
		while (b.size() < a.size()) {
			b = 'a' + b; // ��������� ������� 'a' � b
		}

		// ��������� � ��������������
		for (int i = a.size() - 1; i >= 0; i--) {
			if (Comparasion(a[i], b[i])) {
				// ��������� �������������
				int j = i - 1;
				while (j >= 0) {
					if (a[j] != 'a') {
						a[j] = searchSub(a[j], 'b'); // ��������� ������� ������
						break;
					}
					else {
						a[j] = 'z'; // ���������� �� �����������
					}
					j--;
				}
				// ������������ �������� �������� �������
				solution = searchSub('f', b[i]);
				solution = searchSum('b', solution);
				solution = searchSum(a[i], solution);
			}
			else {
				// ����������� ��������� ��� �������������
				solution = searchSub(a[i], b[i]);
			}
			// ��������� �����
			answer = solution + answer;
		}
	}

	// ������� ������� ���� ('a'), ���� ��� ����
	while (answer.size() > 1 && answer[0] == 'a') {
		answer.erase(0, 1);
	}

	return answer;
}


void Arithmetic::multInput() {
	a = Input1();
	b = Input2();
	string answer = mult(a, b);
	cout << "�����: " << a << " * " << b << " = " << answer << "\n\n";
}

void Arithmetic::divInput() {
	vector<string> answer;
	a = Input1();
	b = Input2();
	answer = div(a, b, answer);
	if (answer[1] == "-1")
	{
		cout << "\n�����: " << a << " / " << b << " = " << answer[0] << "\n";
	}
	else
	{
		cout << "\n�����: " << a << " / " << b << " = " << answer[0] << "\n";
		cout << "       ������� = " << answer[1] << "\n\n";
	}
}



int Arithmetic::compare(string a, string b) {
	if (a[0] == '-') a.erase(0, 1);
	if (b[0] == '-') b.erase(0, 1);

	while (a.size() != b.size()) a.size() < b.size() ? a = 'a' + a : b = 'a' + b;

	for (int i = 0; i < a.size(); i++) {
		if (Comparasion(a[i], b[i])) return -1; //b<a
		else if (Comparasion(b[i], a[i])) return 1; //a>b
		if (i == a.size() - 1) return 0;
	}

}

bool Arithmetic::Comparasion(char a, char b) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (poryadok[i] == a && poryadok[j] == b)
				if (i < j)
					return true;
				else
					return false;
		}
	}
}


string Arithmetic::mult(string a, string b) {
	string answer = "a";
	string answer_buf = "";
	char shift1 = 'a';
	char shift2 = 'a';
	char shift3 = 'a';
	char solution;
	int minuses_a = 0;
	int minuses_b = 0;
	if (a[0] == '-') {
		minuses_a++;
		a.erase(0, 1);
	}
	if (b[0] == '-') {
		minuses_b++;
		b.erase(0, 1);
	}
	while (a.size() != b.size()) {
		a.size() < b.size() ? a = 'a' + a : b = 'a' + b;
	}
	int flag;
	int k = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		for (int j = a.size() - 1; j >= 0; j--) {
			solution = searchMult(a[j], b[i]);
			shift2 = searchMultSd(a[j], b[i]);
			shift3 = searchSumSd(solution, shift1);
			solution = searchSum(solution, shift1);
			shift1 = searchSum(shift2, shift3);
			answer_buf = solution + answer_buf;
			shift3 = 'a';
			shift2 = 'a';
			if (j == 0 && shift1 != 'a') answer_buf = shift1 + answer_buf;
		}
		shift1 = 'a';
		int s = k;
		while (s > 0) {
			answer_buf += 'a';
			s--;
		}
		k++;
		answer = plus(answer, answer_buf);
		answer_buf = "";
	}
	while (answer.size() > 1 && answer[0] == 'a')
		answer.erase(0, 1);

	if (answer.size() > 8)
		answer = "overflow";

	if (answer[0] != 'a' && answer != "overflow" && (minuses_a + minuses_b) == 1)
		answer = '-' + answer;
	return answer;
}

vector<string> Arithmetic::div(string a, string b, vector<string> result) {

	string answer = "a"; // �������
	string remainder = "a"; // �������
	int minuses_a = 0;
	int minuses_b = 0;

	// ��������� ����� �����
	if (a[0] == '-') {
		minuses_a++;
		a.erase(0, 1);
	}
	if (b[0] == '-') {
		minuses_b++;
		b.erase(0, 1);
	}

	// ������� ���������� 'a'
	while (a.size() > 1 && a[0] == 'a') a.erase(0, 1);
	// ������� ���������� 'a'
	while (b.size() > 1 && b[0] == 'a') b.erase(0, 1);

	// ��������� ������� �� ����
	if (compare(b, "a") == 0) {
		// ��������� � �� �
		if (a == "a") {
			result.push_back("[-ffffffff;ffffffff]");
			result.push_back("-1");
			result.push_back("1");
			return result;
		}
		result.push_back("������ ���������");
		result.push_back("-1");
		result.push_back("1");
		return result;
	}


	// ���������� ����� �����
	while (a.size() != b.size()) a.size() < b.size() ? a = 'a' + a : b = 'a' + b;

	// ���� ��� ����������� ��������
	int flag = 0;
	while (true) {
		flag = 0;
		string temp_answer = answer;

		// ��������� ����������� �������
		for (char i = 'b'; i <= 'f'; i++) { //�� b �� f
			string trial = mult(b, plus(temp_answer, string(1, i))); //���� ���� ����� b
			if (trial[0] == '-') trial.erase(0, 1); // ������� ����, ���� ����
			if (compare(trial, a) != 1) { // ���� trial <= a
				answer = plus(temp_answer, string(1, i));
				flag = 1;
				break;
			}
		}

		if (flag == 0) break; // ���� ������ ������ ������, ������� �� �����
	}

	// ������� ���������� 'a'
	while (answer.size() > 1 && answer[0] == 'a') answer.erase(0, 1);

	// ��������� �������
	remainder = minus(a, mult(b, answer));

	// ������� ���������� 'a' � �������
	while (remainder.size() > 1 && remainder[0] == 'a') remainder.erase(0, 1);

	// ��������� ������
	if (minuses_a == 1 && minuses_b == 0) {
		if (remainder != "a") {
			answer = plus(answer, "b"); // ����������� ������� �� "b"
			string old_remainder = remainder; // ��������� ������� �� ���������
			remainder = minus(b, old_remainder); // ������ ����� ����� ������ �������
		}
		answer = '-' + answer; // ������� ���������� �������������
	}

	if (minuses_a == 0 && minuses_b == 1) {
		answer = '-' + answer; // ������� ���������� �������������
	}

	// ���������� ���������
	result.push_back(answer);
	result.push_back(remainder);
	result.push_back("0");
	return result;
}


