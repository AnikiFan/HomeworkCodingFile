/* 2254298 ��11 ���� */
#include"popstar.h"
/***************************************************************************
  �������ƣ�reload
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �������س�������,��������Ϊһ������
***************************************************************************/
void reload(void)
{
	char input[100];
	int xcoo, ycoo;
	cout << "��С�������������End����...";
	while (1) {
		cin.get(input, 99);
		if ((input[0] == 'E' || input[0] == 'e') &&
			(input[1] == 'N' || input[1] == 'n') &&
			(input[2] == 'D' || input[2] == 'd'))
			break;
		input[0] = 0;
		input[1] = 0;
		input[2] = 0;
		cout << "�����������������";
		cct_getxy(xcoo, ycoo);
		cct_showch(29, ycoo - 1, ' ', background, 20);
		cct_setcolor(defaultColor);
		cct_gotoxy(29, ycoo - 1);
	}
	cct_cls();
	return;
}
void searchPlus(void)
{
	return;
}
void search(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax)
{
	int pivot = matrix[srcRow][srcCol];
	if (srcRow != 0 && matrix[srcRow - 1][srcCol] == pivot) {
		searchPlus();//�Ե�ǰԪ�ؽ��ж������
		search(srcRow - 1, srcCol, matrix, rowMax, colMax);
	}
	if (srcCol != 0 && matrix[srcRow][srcCol - 1] == pivot) {
		searchPlus();//�Ե�ǰԪ�ؽ��ж������
		search(srcRow, srcCol - 1, matrix, rowMax, colMax);
	}
	if (srcRow != rowMax && matrix[srcRow + 1][srcCol] == pivot) {
		searchPlus();//�Ե�ǰԪ�ؽ��ж������
		search(srcRow + 1, srcCol, matrix, rowMax, colMax);
	}
	if (srcCol != colMax && matrix[srcRow][srcCol + 1] == pivot) {
		searchPlus();//�Ե�ǰԪ�ؽ��ж������
		search(srcRow, srcCol + 1, matrix, rowMax, colMax);
	}
	return;
}
void matrixGenerator(int matrix[][10], int rowInterval, int colInterval, int rowMax, int colMax, int srcxcoo, int srcycoo)//��ʼ����Ϊ(1,1)Ԫλ��,Ԫ������пո�
{
	int i, j, k;
	cct_gotoxy(srcxcoo, srcycoo);
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++)
			cout << setw(colInterval + 1) << setiosflags(ios::left) << matrix[i][j];
		for (k = 0; k < rowInterval; k++)
			cout << endl;
	}
	return;
}