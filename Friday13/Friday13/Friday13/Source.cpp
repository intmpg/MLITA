#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("OUTPUT.txt");

void countWeekDays(int year0) {
	int year, monthNum, c, y, dayNum;
	string monthNumbers[12] = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
	
	for (int i = 1; i < 13; i++) {
		
		if (i < 3)
		{
			monthNum = i + 12;
			year = year0 - 1;
		}
		else
		{
			monthNum = i;
			year = year0;
		}
		
		c = year / 100;//������������ ��������� ��� ������� ���������� ������������������ ���� � ������
		y = year % 100;//������������ ��������� ��� ������� ���������� ������������������ ���� � ������
		
		dayNum = ((monthNum + 1) * 26 / 10 + 13 + y + y / 4 + c / 4 - 2 * c) % 7;//���� ������ ���������� �� 13 ����� ������(0=��,1=��,...,6=��)

		if (dayNum == 6) {
			fout << year0 << " " << monthNumbers[i - 1].c_str() << endl; //���� ���� ������ =6, �� ��� �������
		}
	}
}

int main()
{
	ifstream fin("INPUT.txt");

	if (!fin)
	{
		cout << "Error!" << endl; 
		return 0;
	}

	int year1, year2;
	fin >> year1 >> year2;
	
	for (int i = year1; i <= year2; i++) {
		countWeekDays(i);
	}

	cout << "Succesful" << endl;
	getchar();
	return 0;
}

