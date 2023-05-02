/* 2254298 ��11 ���� */
#define Bxcoordinate 20
#define Bycoordinate 20
#define Bposition (Bxcoordinate,Bycoordinate)//B�̱�ʶ����
#define xcoordinatediff 10//A,B,C��x����֮��Ĳ�
#define speed1 250
#define speed2 200
#define speed3 150
#define speed4 100
#define speed5 50
#define endposition (0,27)
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<Windows.h>
#include"5-b7.h"
#define arrow "-->"
using namespace std;
int Atop, Btop, Ctop, Astack[10], Bstack[10], Cstack[10], num = 0, speed, display;//Atop,Btop,Ctop��ջ��+1��λ��
void vertical(char src, char dst, int srctop, int dsttop, int moveelement)
{
	cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - srctop);
	cout << " ";
	cct_gotoxy(Bxcoordinate - ('B' - dst) * xcoordinatediff, Bycoordinate - 2 - dsttop);
	cout << moveelement;
	return;
}
void horizontal()
{
	int i, tenflag = 0;
	cout << "A:";
	for (i = 0; i < Atop; i++) {
		if (Astack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Astack[i];
	}
	cout << setw(2 * (10 - Atop) + 3);
	tenflag = 0;

	cout << "B:";
	for (i = 0; i < Btop; i++) {
		if (Bstack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Bstack[i];
	}
	cout << setw(2 * (10 - Btop) + 3);

	cout << "C:";
	for (i = 0; i < Ctop; i++) {
		if (Cstack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Cstack[i];
	}
	cout << setw(2 * (10 - Ctop) + 3) << " ";
	cout << endl;
}

void speedcontrol()
{
	switch (speed) {
		case 0:
			while (_getch() != 13)
				;
			break;
		case 1:
			Sleep(speed1);
			break;
		case 2:
			Sleep(speed2);
			break;
		case 3:
			Sleep(speed3);
			break;
		case 4:
			Sleep(speed4);
			break;
		case 5:
			Sleep(speed5);
			break;
	}
	return;
}

void hanoi(int n, char src, char tmp, char dst)
{
	int temp;

	if (n == 1) {
		num++;
		speedcontrol();
		switch (src) {
			case('A'):
				if (dst == 'C') {
					vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
					Cstack[Ctop++] = Astack[--Atop];

				}
				else {
					vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
					Bstack[Btop++] = Astack[--Atop];

				}
				break;
			case('B'):
				if (dst == 'C') {
					vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
					Cstack[Ctop++] = Bstack[--Btop];

				}
				else {
					vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
					Astack[Atop++] = Bstack[--Btop];

				}
				break;
			case('C'):
				if (dst == 'A') {
					vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
					Astack[Atop++] = Cstack[--Ctop];

				}
				else {
					vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
					Bstack[Btop++] = Cstack[--Ctop];

				}
				break;

		}

		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "��" << setw(4) << num << " ��" << "(1#: " << src << arrow << dst << ")  ";
		if (display == 1)
			horizontal();


		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	speedcontrol();
	switch (src) {
		case('A'):
			if (dst == 'C') {
				vertical(src, dst, Atop, Ctop, Astack[Atop - 1]);
				temp = (Cstack[Ctop++] = Astack[--Atop]);

			}
			else {
				vertical(src, dst, Atop, Btop, Astack[Atop - 1]);
				temp = (Bstack[Btop++] = Astack[--Atop]);

			}
			break;
		case('B'):
			if (dst == 'C') {
				vertical(src, dst, Btop, Ctop, Bstack[Btop - 1]);
				temp = (Cstack[Ctop++] = Bstack[--Btop]);

			}
			else {
				vertical(src, dst, Btop, Atop, Bstack[Btop - 1]);
				temp = (Astack[Atop++] = Bstack[--Btop]);

			}
			break;
		case('C'):
			if (dst == 'A') {
				vertical(src, dst, Ctop, Atop, Cstack[Ctop - 1]);
				temp = (Astack[Atop++] = Cstack[--Ctop]);

			}
			else {
				vertical(src, dst, Ctop, Btop, Cstack[Ctop - 1]);
				temp = (Bstack[Btop++] = Cstack[--Ctop]);

			}
			break;

	}

	cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
	cout << "��" << setw(4) << num << " ��" << "(" << temp << "#: " << src << arrow << dst << ")  ";
	if (display == 1)
		horizontal();

	hanoi(n - 1, tmp, src, dst);
	return;
}


int main()
{
	int n, i;
	char src, tmp, dst;
	cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
	}
	cout << "��������ʼ��(A-C)" << endl;
	while (1) {
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && !cin.rdstate()) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "��������ʼ��(A-C)" << endl;
	}
	cout << "������Ŀ����(A-C)" << endl;
	while (1) {
		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && !cin.rdstate()
			&& dst != src && dst != (src - 32) && dst != (src + 32)) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
		cout << "������Ŀ����(A-C)" << endl;
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	tmp = 'A' + 'B' + 'C' - src - dst;
	switch (src) {
		case('A'):
			Atop = n;
			for (i = 0; i < n; i++)
				Astack[i] = n - i;
			break;
		case('B'):
			Btop = n;
			for (i = 0; i < n; i++)
				Bstack[i] = n - i;
			break;
		case('C'):
			Ctop = n;
			for (i = 0; i < n; i++)
				Cstack[i] = n - i;
			break;
	}
	cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
	while (1) {
		cin >> speed;
		if (speed >= 0 && speed <= 5 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
	}
	cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
	while (1) {
		cin >> display;
		if (display >= 0 && display <= 1 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
	}
	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << ", " << (display ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;
	if (display == 1) {
		cct_gotoxy(Bxcoordinate, Bycoordinate + 6);
		cout << "��ʼ:" << setw(16) << " ";
		horizontal();
		if (speed == 0) {
			while (_getch() != 13)
				;
			cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
			cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
			cout << setfill(' ');
			cct_gotoxy Bposition;
			cout << "B";
			cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
			cout << "A";
			cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
			cout << "C";
			for (i = 1; i < n + 1; i++) {
				cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
				cout << n + 1 - i;
			}
			hanoi(n, src, tmp, dst);
		}
		else {
			cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
			cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
			cout << setfill(' ');
			cct_gotoxy Bposition;
			cout << "B";
			cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
			cout << "A";
			cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
			cout << "C";
			for (i = 1; i < n + 1; i++) {
				cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
				cout << n + 1 - i;
			}
			hanoi(n, src, tmp, dst);
		}
	}
	else {
		cct_gotoxy(Bxcoordinate - xcoordinatediff - 2, Bycoordinate - 1);
		cout << setfill('=') << setw(6 + 2 * xcoordinatediff) << " ";
		cout << setfill(' ');
		cct_gotoxy Bposition;
		cout << "B";
		cct_gotoxy(Bxcoordinate - xcoordinatediff, Bycoordinate);
		cout << "A";
		cct_gotoxy(Bxcoordinate + xcoordinatediff, Bycoordinate);
		cout << "C";
		for (i = 1; i < n + 1; i++) {
			cct_gotoxy(Bxcoordinate - ('B' - src) * xcoordinatediff, Bycoordinate - 1 - i);
			cout << n + 1 - i;

		}
		hanoi(n, src, tmp, dst);
	}


	cct_gotoxy endposition;
	system("pause");
	return 0;

}