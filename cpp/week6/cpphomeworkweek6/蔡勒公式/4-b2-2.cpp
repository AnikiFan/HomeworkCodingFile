/* 2254298 ��11 ���� */
#include<iostream>
#include<math.h>
using namespace std;

int zeller(int y, int m, int d)
{
	int c, w;
	y -= m == 1 || m == 2;
	c = y / 100;
	y %= 100;
	m += (m == 1 || m == 2) * 12;
	w = y + int(y / 4.0) + int(c / 4.0) - 2 * c + int(13 * (m + 1) / 5.0) + d - 1;
	return ((w + 77) % 7);//��ֻ��7,������2000 4 13�ó�������-3
}

int invaliddaytest(int y,int m,int d)
{
	int max;
	switch (m) {
		case 1:
			max = 31;
			break;
		case 3:
			max = 31;
			break;
		case 5:
			max = 31;
			break;
		case 7:
			max = 31;
			break;
		case 8:
			max = 31;
			break;
		case 10:
			max = 31;
			break;
		case 12:
			max = 31;
			break;
		case 4:
			max = 30;
			break;
		case 6:
			max = 30;
			break;
		case 9:
			max = 30;
			break;
		case 11:
			max = 30;
			break;
		case 2:
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
				max = 29;
			else
				max = 28;
			break;
	}
	return(1 <= d &&d<= max);
}

int main()
{
	int y, m, d;
	cout << "��������[1900-2100]���¡��գ�" << endl;
	while (1) {
		cin >> y >> m >> d;  
		if (y>=1900&&y<=2100  &&m>=1&&m<=12&&invaliddaytest(y,m,d)&& !cin.rdstate())
			break;
		else {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
		cout << "�����������������" << endl;
		cout << "��������[1900-2100]���¡��գ�" << endl;
	}
	switch (zeller(y,m,d)) {
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}
	return 0;
} 