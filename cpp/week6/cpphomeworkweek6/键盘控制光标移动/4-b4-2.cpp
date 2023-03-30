/* 2254298 ��11 ���� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��,����λ��Ϊ35
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�,����λ��Ϊ9

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	   //������������ͬʱ,��һ����ĸ�Ḳ�ǵ�ǰһ��,�Ӷ�����20��
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

int menu(void)
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.�ü�ͷ��������������(�߽�ֹͣ����ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)" << endl;
	cout << "6.�ü�ͷ��������������(�߽���ƣ���ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";
	return _getch();
}

void initialize() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��


	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);
	gotoxy(hout, 35, 9);
	return;
}

void quitmodule()//���س����Ż��˳�
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س����˳�.";
	while (_getch() != 13)
		;
	return;
}

void move(bool alphamove, bool loop)
{
	int input, input2 = 0, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		if (!alphamove && input == 224)
			input2 = _getch();//�����̼����ͷ��ʱ,�������������
		if (input == 113 || input == 81)//�˳�
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//����
		if ((input == 105 || input == 73) && alphamove || !alphamove && input == 224 && input2 == 72)
			y--;
		if ((input == 107 || input == 75) && alphamove || !alphamove && input == 224 && input2 == 80)
			y++;
		if ((input == 106 || input == 74) && alphamove || !alphamove && input == 224 && input2 == 75)
			x--;
		if ((input == 108 || input == 76) && alphamove || !alphamove && input == 224 && input2 == 77)
			x++;
		if (x == 0)
			gotoxy(hout, x = 1 + loop * 68, y);
		else if (x == 70)
			gotoxy(hout, x = 69 - loop * 68, y);
		else if (y == 0)
			gotoxy(hout, x, y = 1 + 16 * loop);
		else if (y == 18)
			gotoxy(hout, x, y = 17 - 16 * loop);
		else gotoxy(hout, x, y);

	}
	quitmodule();
	return;
}

void module1() {
	initialize();
	move(true, false);
	return;
}

void module2() {
	initialize();
	move(true, true);
	return;
}

void module3() {
	initialize();
	move(false, false);
	return;
}

void module4() {
	initialize();
	move(false, true);
	return;
}

void module5() {
	initialize();
	int input, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		if (input == 113 || input == 81)//�˳�
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//����
		if (input == 224)
			_getch();//����������ĵڶ�������
		if (input == 105 || input == 73)
			y--;
		if (input == 107 || input == 75)
			y++;
		if (input == 106 || input == 74)
			x--;
		if (input == 108 || input == 76)
			x++;
		if (x == 0)
			gotoxy(hout, x = 1, y);
		else if (x == 70)
			gotoxy(hout, x = 69, y);
		else if (y == 0)
			gotoxy(hout, x, y = 1);
		else if (y == 18)
			gotoxy(hout, x, y = 17);
		else gotoxy(hout, x, y);
	}
	quitmodule();
	return;
}

void module6() {
	initialize();
	int input, x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		if (input == 113 || input == 81)//�˳�
			break;
		if (input == 32)
			showch(hout, x, y, ' ');//����
		if (input == 224)
			_getch();//����������ĵڶ�������
		if (input == 105 || input == 73)
			y--;
		if (input == 107 || input == 75)
			y++;
		if (input == 106 || input == 74)
			x--;
		if (input == 108 || input == 76)
			x++;
		if (x == 0)
			gotoxy(hout, x = 69, y);
		else if (x == 70)
			gotoxy(hout, x = 1, y);
		else if (y == 0)
			gotoxy(hout, x, y = 17);
		else if (y == 18)
			gotoxy(hout, x, y = 1);
		else gotoxy(hout, x, y);
	}
	quitmodule();
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	int temp;
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	bool game = true, alphamove = true, loop = false;//Ĭ��Ϊ����ĸ�����ƶ����޻���




	while (game) {
		cls(hout);
		temp = menu();
		game = temp != 48;
		switch (temp - 48) {
			case 1:
				module1();
				break;
			case 2:
				module2();
				break;
			case 3:
				module3();
				break;
			case 4:
				module4();
				break;
			case 5:
				module5();
				break;
			case 6:
				module6();
				break;
		}
	}
	return 0;
}
/*
1.�����¼����ϵķ����ʱ,���ڻ������ڼ�����������,�������ͷ������,������������ascill������Ϊ224,75,
��K��ascill��ҲΪ75,����224,��75������q��Q��ascill��,������Ϸ���������˳�,�������ڶ�ȡ�������е�224��������ȡ75,
�Ӷ������ƶ�.
2.������������ͬʱ,��һ����ĸ�Ḳ�ǵ�ǰһ��,�Ӷ�����20��
*/
