/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
#include"cmd_console_tools.h"
#include <conio.h>
#include<iomanip>
using namespace std;

int main()
{

	if (0) {
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();

		/* ��ӡ��ʼ���λ��[0,0] */
		//		cout << "[��ǰ���λ��] X:0  Y:0"; //��ӡ��ʼ���λ��

		while (loop) {
			/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				/* ת����7�н��д�ӡ */
				cct_gotoxy(0, 7);
				cout << "[��ǰ���λ��] X:" << setw(2) << X << " Y:" << setw(2) << Y << " ����:";

				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cout << "�ƶ�          " << endl;
						//showch(X, Y, '*');����ӡ�κ�����
						break;
					case MOUSE_LEFT_BUTTON_CLICK:			//�������
						cout << "�������      " << endl;
						cct_showch(X, Y, '1');			//�����ָ��λ����ʾ1
						break;
					case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//˫�����
						cout << "˫�����      " << endl;
						cct_showch(X, Y, '2');			//�����ָ��λ����ʾ2
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
						cout << "�����Ҽ�      " << endl;
						cct_showch(X, Y, '3');			//�����ָ��λ����ʾ3
						break;
					case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//˫���Ҽ�
						cout << "˫���Ҽ�      " << endl;
						cct_showch(X, Y, '4');			//�����ָ��λ����ʾ4
						loop = 0;
						break;
					case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//ͬʱ�������Ҽ�
						cout << "ͬʱ�������Ҽ�" << endl;
						cct_showch(X, Y, '5');			//�����ָ��λ����ʾ5
						break;
					case MOUSE_WHEEL_CLICK:
						cout << "���¹���      " << endl;
						break;
					case MOUSE_WHEEL_MOVED_UP:
						cout << "���������ƶ�  " << endl;
						break;
					case MOUSE_WHEEL_MOVED_DOWN:
						cout << "���������ƶ�  " << endl;
						break;
					case MOUSE_NO_ACTION:
					default:
						cout << "��������" << endl;
						cct_showch(X, Y, '0');			//�����ָ��λ����ʾ0
						break;
				} //end of switch(maction)
			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				/* ת����9�н��д�ӡ */
				cct_gotoxy(0, 9);
				cout << "[��ǰ����] : ";

				switch (keycode1) {
					case 27:	//ESC��
						loop = 0;
						cout << "ESC       ";
						break;
					case 32:	//SPACE��
						loop = 0;
						cout << "SPACE     ";
						break;
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								cout << "�ϼ�ͷ    ";
								break;
							case KB_ARROW_DOWN:
								cout << "�¼�ͷ    ";
								break;
							case KB_ARROW_LEFT:
								cout << "���ͷ    ";
								break;
							case KB_ARROW_RIGHT:
								cout << "�Ҽ�ͷ    ";
								break;
						}
						break;
					default:	//������ֱ�Ӵ�ӡASCIIֵ
						if (keycode2)
							cout << "Keycode=" << keycode1 << '/' << keycode2 << endl;
						else
							cout << "Keycode=" << keycode1 << endl;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT��
		} //end of while(1)

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
	}
	cct_setconsoleborder(20, 20, 20, 20);
	cct_gotoxy(0, 0);
	cout << "00000";
	cct_gotoxy(0, 2);
	cout << "222222";
	cct_gotoxy(0, 1);
	cout << "&&&";
	cct_gotoxy(50, 50);
	cout << "**************";
	cout << endl << "@@";

	return 0;
}