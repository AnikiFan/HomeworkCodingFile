/* 2254298 ��11 ���� */
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int year, month, week, day,i=0;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.sync();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
		cout << "����Ƿ�������������" << endl;
	}
	while (1) {
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> week;
		cout << endl;
		if (week >= 0 && week <= 6 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.sync();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
		cout << "����Ƿ�������������" << endl;
	}
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	switch (month) {
		case 1:
			day = 31;
			break;
		case 3:
			day = 31;
			break;
		case 5:
			day = 31;
			break;
		case 7:
			day = 31;
			break;
		case 8:
			day = 31;
			break;
		case 10:
			day = 31;
			break;
		case 12:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 6:
			day = 30;
			break;
		case 9:
			day = 30;
			break;
		case 11:
			day = 30;
			break;
		case 2:
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				day = 29;
			else
				day = 28;
			break;
	}
	while (i <= week - 1) {
		cout << "        ";
		i++;
	}
	for (i = 1; i <= day; i++) {
		cout << setw(4) << i << "    ";
		if (!((week +  i) % 7)||i==day) {
			cout << endl;
		}
	}
	return 0;
}