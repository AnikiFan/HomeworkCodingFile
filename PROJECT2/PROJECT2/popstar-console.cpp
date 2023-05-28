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
	bool frame = false, first = true, prompt = true;
	int x = 6, y = 4;
	cct_cls();
	cct_setcursor(CURSOR_INVISIBLE);
	matrixInitialize(rowMax, colMax, frame, matrix);
	if (prompt) {
		cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
		cout << "��ͷ��/����ƶ�, �س���/�������ѡ�񲢽���";
	}
	inverseBlock(6, 4, matrix[0][0]);
	first = false;
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
				if (prompt) {
					prompt = false;
					cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 50);
					cct_setcolor(defaultColor);
				}
				if (Y > 2 && Y < 4 + (rowMax - 1) * (3 + frame) + 2 && X>2 && X < 6 + (colMax - 1) * (6 + 2 * frame) + 4) {

					inverseBlock(6 + ((X - 4) / blockwidth) * (6 + 2 * frame), 4 + ((Y - 3) / blockheight) * (3 + frame), matrix[(X - 4) / blockwidth][((Y - 3) / blockheight)]);
					if ((x != 6 + ((X - 4) / blockwidth) * (6 + 2 * frame) || y != 4 + ((Y - 3) / blockheight) * (3 + frame)) && !first)
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
					if (first)
						first = false;
					x = 6 + ((X - 4) / blockwidth) * (6 + 2 * frame);
					y = 4 + ((Y - 3) / blockheight) * (3 + frame);
					cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
					cct_setcolor(defaultColor);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] " << (char)('A' + (Y - 3) / blockheight) << "��" << (X - 4) / blockwidth << "��";
					switch (maction) {
						case MOUSE_LEFT_BUTTON_CLICK:			//�������
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��" ;
							loop = 0;
							break;
						case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//˫�����
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
							loop = 0;
							break;
						case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
							loop = 0;
							break;
						case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//˫���Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
							loop = 0;
							break;
						case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//ͬʱ�������Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
							loop = 0;
							break;
						default:
							break;
					} //end of switch(maction)
				}
				else {

					if (!first) {
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
						first = true;
					}
					cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
					cct_setcolor(defaultColor);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] λ�÷Ƿ�";
				}

				
			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				if (prompt) {
					prompt = false;
					cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 50);
					cct_setcolor(defaultColor);
				}
				cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
				cct_setcolor(defaultColor);
				cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
				cout << "[��ǰ����] ";

				switch (keycode1) {
					case 224:
						reverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
						switch (keycode2) {
							case KB_ARROW_UP:

								if (y == 4)
									y = 4 + (rowMax - 1) * (3 + frame);
								else
									y -= blockheight;

								break;
							case KB_ARROW_DOWN:
								if (y == 4 + (rowMax - 1) * (3 + frame))
									y = 4;
								else
									y += blockheight;
								break;
							case KB_ARROW_LEFT:
								if (x == 6)
									x = 6 + (colMax - 1) * (6 + 2 * frame) ;
								else
									x -= blockwidth;

								break;
							case KB_ARROW_RIGHT:
								if (x == 6 + (colMax - 1) * (6 + 2 * frame) )
									x = 6;
								else
									x += blockwidth;

								break;
						}
						inverseBlock(x, y, matrix[(x - 4) / blockwidth][((y - 3) / blockheight)]);
						cct_gotoxy(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
						cout << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
						break;
					case 13:	//ENTER��
						cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
						cct_setcolor(defaultColor);
						cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
						cout << "ѡ����" << (char)('A' + (y - 3) / blockheight) << "��" << (x - 4) / blockwidth << "��";
						loop = 0;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT��
		} //end of while(1)

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
	}
	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	cin.ignore(10000, '\n');
	return;
}
void module5(int rowMax, int colMax, int matrix[][10])
{
	bool frame = true, first = true, prompt = true, valid;
	int x = 6, y = 4,i;
	cct_cls();
	matrixInitialize(rowMax, colMax, frame, matrix);

	if (prompt) {
		cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
		cout << "��ͷ��/����ƶ�, �س���/�������ѡ�񲢽���";
	}
	inverseBlock(6, 4, matrix[0][0]);
	first = false;
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
				if (prompt) {
					prompt = false;
					cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 50);
					cct_setcolor(defaultColor);
				}
				valid = true;
				if (Y > 2 && Y < 4 + (rowMax - 1) * (3 + frame) + 2 && X>2 && X < 6 + (colMax - 1) * (6 + 2 * frame) + 4) {
					for (i = 0; i < colMax -1; i++) 
						if (X == 6 + i * (6 + 2 * frame) + 4|| X == 6 + i * (6 + 2 * frame) + 5)
							valid = false;
					for (i = 0; i < rowMax - 1; i++) 
						if (Y == 4 + i * (3 + frame) + 2)
							valid = false;
				}
				else
					valid = false;
				if (valid) {
					inverseBlock(6 + ((X - 4) / (blockwidth+2*frame)) * (6 + 2 * frame), 4 + ((Y - 3) / (blockheight+frame)) * (3 + frame), matrix[(X - 4) / (blockwidth+2*frame)][((Y - 3) / (blockheight+frame))]);
					if ((x != 6 + ((X - 4) / (blockwidth+2*frame)) * (6 + 2 * frame) || y != 4 + ((Y - 3) / (blockheight+frame)) * (3 + frame)) && !first)

						reverseBlock(x, y, matrix[(x - 4) / (blockwidth+2*frame)][((y - 3) / (blockheight+frame))]);
					if (first)
						first = false;
					x = 6 + ((X - 4) / (blockwidth+2*frame)) * (6 + 2 * frame);
					y = 4 + ((Y - 3) / (blockheight+frame)) * (3 + frame);
					cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
					cct_setcolor(defaultColor);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] " << (char)('A' + (Y - 3) /( blockheight+frame)) << "��" << (X - 4) / (blockwidth+2*frame) << "��";
					switch (maction) {
						case MOUSE_LEFT_BUTTON_CLICK:			//�������
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight+frame)) << "��" << (x - 4) / (blockwidth+2*frame) << "��";
							loop = 0;
							break;
						case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//˫�����
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight + frame)) << "��" << (x - 4) / (blockwidth + 2 * frame) << "��";
							loop = 0;
							break;
						case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight + frame)) << "��" << (x - 4) / (blockwidth + 2 * frame) << "��";
							loop = 0;
							break;
						case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//˫���Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight + frame)) << "��" << (x - 4) / (blockwidth + 2 * frame) << "��";
							loop = 0;
							break;
						case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//ͬʱ�������Ҽ�
							cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
							cct_setcolor(defaultColor);
							cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
							cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight + frame)) << "��" << (x - 4) / (blockwidth + 2 * frame) << "��";
							loop = 0;
							break;
						default:
							break;
					} //end of switch(maction)
				}
				else {
					if (!first) {
						reverseBlock(x, y, matrix[(x - 4) / (blockwidth+2*frame)][((y - 3) / (blockheight+frame))]);
						first = true;
					}
					cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
					cct_setcolor(defaultColor);
					cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
					cout << "[��ǰ���] λ�÷Ƿ�";
				}


			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				if (prompt) {
					prompt = false;
					cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 50);
					cct_setcolor(defaultColor);
				}
				cct_showch(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
				cct_setcolor(defaultColor);
				cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
				cout << "[��ǰ����] ";

				switch (keycode1) {
					case 224:
						reverseBlock(x, y, matrix[(x - 4) / (blockwidth + 2 * frame)][((y - 3) / (blockheight + frame))]);
						switch (keycode2) {
							case KB_ARROW_UP:

								if (y == 4)
									y = 4 + (rowMax - 1) * (3 + frame);
								else
									y -= (blockheight+1);

								break;
							case KB_ARROW_DOWN:
								if (y == 4 + (rowMax - 1) * (3 + frame))
									y = 4;
								else
									y += (blockheight+1);
								break;
							case KB_ARROW_LEFT:
								if (x == 6)
									x = 6 + (colMax - 1) * (6 + 2 * frame);
								else
									x -= (blockwidth+2);

								break;
							case KB_ARROW_RIGHT:
								if (x == 6 + (colMax - 1) * (6 + 2 * frame))
									x = 6;
								else
									x += (blockwidth+2);

								break;
						}
						inverseBlock(x, y, matrix[(x - 4) / (blockwidth + 2 * frame)][((y - 3) / (blockheight + frame))]);
						cct_gotoxy(11, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
						cout << (char)('A' + (y - 3) / (blockheight+frame)) << "��" << (x - 4) / (blockwidth+2*frame) << "��";
						break;
					case 13:	//ENTER��
						cct_showch(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4, ' ', background, 20);
						cct_setcolor(defaultColor);
						cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 4);
						cout << "ѡ����" << (char)('A' + (y - 3) / (blockheight+frame)) << "��" << (x - 4) / (blockwidth+2*frame) << "��";
						loop = 0;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT��
		} //end of while(1)

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
	}

	cct_gotoxy(0, 32 + (rowMax - 8) * 3 + frame * 7 + frame * (rowMax - 8) - 3);
	cin.ignore(10000, '\n');
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

