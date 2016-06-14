#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("OUTPUT.txt");
void countweekdays(int year0) {
	int year, month, c, y, wd;
	string mass_month[12] = { "JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER" };
	for (int i = 1; i<13; i++) {
		if (i<3)
		{
			month = i + 12;
			year = year0 - 1;
		}
		else
		{
			month = i;
			year = year0;
		}
		c = year / 100;//������������ ��������� ��� ������� ���������� ������������������ ���� � ������
		y = year % 100;//������������ ��������� ��� ������� ���������� ������������������ ���� � ������
		wd = ((month + 1) * 26 / 10 + 13 + y + y / 4 + c / 4 - 2 * c) % 7;//���� ������ ���������� �� 13 ����� ������(0=��,1=��,...,6=��)
		if (wd == 6) //���� ���� ������ =6, �� ��� �������
		{
			fout << year0;
			fout << " "
				fout << mass_month[i - 1];
				fout << endl;
		}
	}

	int main()
	{
		ifstream fin("INPUT.txt");
		if (!fin)
		{
			cout << "Error!" << endl; system("pause"); return 0;
		}
		int year1, year2;
		fin >> year1 >> year2;
		for (int i = year1; i <= year2; i++)countweekdays(i);
		getchar();
		system("pause");
		return 0;
	}

