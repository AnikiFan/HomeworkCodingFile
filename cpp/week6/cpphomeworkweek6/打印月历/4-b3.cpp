/* 2254298 ��11 ���� */
#include<iostream>
#include<iomanip>
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

void calendar(int y, int m, int w)
{
	int max,i=0;
	cout << y << "��" << m <<"��"<< endl;
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;
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
	while (i <= w - 1) {
		cout << "        ";
		i++;
	}
	for (i = 1; i <= max; i++) {
		cout << setw(4) << i << "    ";
		if (!((w + i) % 7) || i == max) {
			cout << endl;
		}
	}
	return ;
}

int main()
{
	int y, m,d=1;
	cout << "��������[1900-2100]����" << endl;

	while (1) {
	cin >> y>>m;
		if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12  && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
		cout << "�����������������" << endl;
		cout << "��������[1900-2100]����" << endl;
	}
	calendar(y,m,zeller(y,m,1));
	return 0;
}