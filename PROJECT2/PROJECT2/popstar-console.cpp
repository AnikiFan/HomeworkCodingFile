/* 2254298 ��11 ���� */
#include"popstar.h"
void blockGenrator(int x, int y, int colorCode)
{//xy�����ǵ�����
	int color[10][2] = colorBoard, i, j;
	cct_gotoxy(x - 2, y - 1);
	cct_setcolor(color[colorCode][0], color[colorCode][1]);
	for (i = 0; i < blockheight; i++) {
		for (j = 0; j < blockwidth; j++) {
			cout << " ";
			delay;
		}
		cct_gotoxy(x - 2, y + i);
	}

	cct_gotoxy(x - 2, y - 1);
	cct_setcolor(color[colorCode][0], 0);
	cct_getxy(x, y);
	delay;
	cout << "�X�T�[" << endl;
	cct_gotoxy(x, y + 1);
	delay;
	cout << "�U  �U" << endl;
	cct_gotoxy(x, y + 2);
	delay;
	cout << "�^�T�a" << endl;
	cct_gotoxy(x + 2, y + 1);
	cct_setcolor(color[colorCode][0], 0);
	delay;
	cout << "��";
}
void inverseBlock(int x, int y, int colorCode)
{
	int color[10][2] = colorBoard;
	cct_setcolor(color[colorCode][0], 15);
	cct_gotoxy(x - 2, y - 1);
	cct_getxy(x, y);
	cout << "�X�T�[" << endl;
	cct_gotoxy(x, y + 1);
	cout << "�U  �U" << endl;
	cct_gotoxy(x, y + 2);
	cout << "�^�T�a" << endl;
	cct_gotoxy(x + 2, y + 1);
	cout << "��";
	cct_setcolor(defaultColor);
	return;
}
void reverseBlock(int x, int y, int colorCode)
{
	int color[10][2] = colorBoard;
	cct_setcolor(color[colorCode][0], 0);
	cct_gotoxy(x - 2, y - 1);
	cct_getxy(x, y);
	cout << "�X�T�[" << endl;
	cct_gotoxy(x, y + 1);
	cout << "�U  �U" << endl;
	cct_gotoxy(x, y + 2);
	cout << "�^�T�a" << endl;
	cct_gotoxy(x + 2, y + 1);
	cout << "��";
	cct_setcolor(defaultColor);
	return;
}
void matrixInitialize(int maxRow, int maxCol, bool frame, int matrix[][10])
{
	int i, j;
	cct_setconsoleborder(55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8), 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8), 55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8), 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8));
	cout << "��Ļ��ǰ����Ϊ: " << 32 + (maxRow - 8) * 3 + frame * 7 + frame * (maxRow - 8) << "��" << 55 + (maxCol - 8) * 6 + frame * 14 + frame * 2 * (maxCol - 8) << "��" << endl;
	for (i = 0; i < maxCol; i++) {
		delay;
		cct_showint(6 + i * (6 + 2 * frame), 1, i, defaultColor, 1);
	}
	for (i = 0; i < maxRow; i++) {
		delay;
		cct_showch(0, 4 + i * (3 + frame), 'A' + i, defaultColor, 1);
	}
	for (i = 0; i < maxCol; i++)
		for (j = 0; j < maxRow; j++)
			blockGenrator(6 + i * (6 + 2 * frame), 4 + j * (3 + frame), matrix[i][j]);
	cct_setcolor(inverseColor);
	cct_gotoxy(2, 2);
	delay;
	cout << "�X";
	cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 2);
	delay;
	cout << "�[";
	cct_gotoxy(2, 4 + (maxRow - 1) * (3 + frame) + 2);
	delay;
	cout << "�^";
	cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 4 + (maxRow - 1) * (3 + frame) + 2);
	delay;
	cout << "�a";
	cct_setcolor(inverseColor);
	i = 4;
	while (i < 6 + (maxCol - 1) * (6 + 2 * frame) + 4) {
		cct_gotoxy(i, 2);
		delay;
		cout << "�T";
		cct_gotoxy(i, 4 + (maxRow - 1) * (3 + frame) + 2);
		delay;
		cout << "�T";
		i++;
		i++;
	}
	i = 3;
	while (i < 4 + (maxRow - 1) * (3 + frame) + 2) {
		cct_gotoxy(2, i);
		delay;
		cout << "�U";
		cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, i);
		delay;
		cout << "�U";
		i++;
	}
	cct_setcolor(inverseColor);
	if (frame) {
		for (i = 0; i < maxCol - 1; i++) {
			cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 2);
			delay;
			cout << "�j";
			cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 4 + (maxRow - 1) * (3 + frame) + 2);
			delay;
			cout << "�m";
		}
		for (i = 0; i < maxRow - 1; i++) {
			cct_gotoxy(2, 4 + i * (3 + frame) + 2);
			delay;
			cout << "�d";
			cct_gotoxy(6 + (maxCol - 1) * (6 + 2 * frame) + 4, 4 + i * (3 + frame) + 2);
			delay;
			cout << "�g";
		}
		for (i = 0; i < maxCol - 1; i++) {
			j = 3;
			while (j < 4 + (maxRow - 1) * (3 + frame) + 2) {
				cct_gotoxy(6 + i * (6 + 2 * frame) + 4, j);
				delay;
				cout << "�U";
				j++;
			}
			j = 4;
			while (j < 6 + (maxCol - 1) * (6 + 2 * frame) + 4) {
				cct_gotoxy(j, 4 + i * (3 + frame) + 2);
				delay;
				cout << "�T";
				j++;
				j++;
			}
		}
		for (i = 0; i < maxCol - 1; i++)
			for (j = 0; j < maxRow - 1; j++) {
				cct_gotoxy(6 + i * (6 + 2 * frame) + 4, 4 + j * (3 + frame) + 2);
				delay;
				cout << "�p";
			}
	}
	cct_setcolor(defaultColor);
	return;
}
void module4(int rowMax, int colMax, int matrix[][10])
{
	bool frame = false,first=true;
	int x=-1 , y=-1 ;
	cct_cls();
	matrixInitialize(rowMax, colMax, frame, matrix);
	if (1) {
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
				if (Y > 2 && Y < 4 + (rowMax - 1) * (3 + frame) + 2 && X>2 && X < 6 + (colMax - 1) * (6 + 2 * frame) + 4) {

					inverseBlock(6 + ((X - 4) / blockwidth) * (6 + 2 * frame), 4 + ((Y - 3) / blockheight) * (3 + frame), matrix[(X - 4) / blockwidth][((Y - 3) / blockheight)]);
					if ((x != 6 + ((X - 4) / blockwidth) * (6 + 2 * frame) || y != 4 + ((Y - 3) / blockheight) * (3 + frame))&&!first)
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
					if (first) 
						first = false;
					x = 6 + ((X - 4) / blockwidth) * (6 + 2 * frame);
					y = 4 + ((Y - 3) / blockheight) * (3 + frame);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] " << (char)('A' + (Y - 3) / blockheight) << "��" << (X - 4) / blockwidth << "��";
				}
				else {
					
					if (!first) {
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
						first = true;
					}
cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] λ�÷Ƿ�";
				}

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
	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	return;
}
void module5(int rowMax, int colMax, int matrix[][10])
{
	bool frame = true;
	cct_cls();
	matrixInitialize(rowMax, colMax, frame, matrix);

	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	return;
}
void module6(int rowMax, int colMax, int matrix[][10])
{
	return;
}
void module7(int rowMax, int colMax, int matrix[][10])
{
	return;
}

