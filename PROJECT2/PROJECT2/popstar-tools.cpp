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
	//
	//cout << "*";
	//
	while (1) {
		cin.getline(input, 99, '\n');
		if ((input[0] == 'E' || input[0] == 'e') &&
			(input[1] == 'N' || input[1] == 'n') &&
			(input[2] == 'D' || input[2] == 'd'))
			break;
		input[0] = 0;
		input[1] = 0;
		input[2] = 0;
		cout << "�����������������";
		//
//cout << "*";
//
		cct_getxy(xcoo, ycoo);
		cct_showch(28, ycoo - 1, ' ', background, 20);
		cct_setcolor(defaultColor);
		cct_gotoxy(28, ycoo - 1);
	}
	cct_cls();
	return;
}
void searchPlus(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax, int option, int x, int y, int rowInterval, int colInterval, int pivot)
{
	switch (option) {
		case 0://���κβ���
			break;
		case 1://������ʾ
			cct_showch(x + srcCol + srcCol * colInterval, y + srcRow + srcRow * rowInterval, pivot + '0', highlight, 1);
			cct_setcolor(defaultColor);
			break;
		case 2://����������
			cct_showch(x + srcCol + srcCol * colInterval, y + srcRow + srcRow * rowInterval, '*', defaultColor, 1);
			break;
		case 3://�����ڶ�ӦԪ�����㲢������ʾ
			matrix[srcRow][srcCol] = 0;
			cct_showch(x + srcCol + srcCol * colInterval, y + srcRow + srcRow * rowInterval, '0', highlight, 1);
			cct_setcolor(defaultColor);
			break;
	}
	return;
}
int search(int srcRow, int srcCol, int matrix[][10], int rowMax, int colMax, int option, int x, int y, int rowInterval, int colInterval, int pivotMatrix[][10], int& sum)//xyΪ��һ��Ԫ�ص�����
{
	int pivot = matrix[srcRow][srcCol];
	pivotMatrix[srcRow][srcCol] = 1;
	searchPlus(srcRow, srcCol, matrix, rowMax, colMax, option, x, y, rowInterval, colInterval, pivot);//�Ե�ǰԪ�ؽ��ж������
	if (option != 5 || (option == 5 && pivot != 0))
		sum++;
	else
		sum = 1;
	if (srcRow != 0 && matrix[srcRow - 1][srcCol] == pivot && pivotMatrix[srcRow - 1][srcCol] == 0)
		search(srcRow - 1, srcCol, matrix, rowMax, colMax, option, x, y, rowInterval, colInterval, pivotMatrix, sum);
	if (srcCol != 0 && matrix[srcRow][srcCol - 1] == pivot && pivotMatrix[srcRow][srcCol - 1] == 0)
		search(srcRow, srcCol - 1, matrix, rowMax, colMax, option, x, y, rowInterval, colInterval, pivotMatrix, sum);
	if (srcRow != rowMax && matrix[srcRow + 1][srcCol] == pivot && pivotMatrix[srcRow + 1][srcCol] == 0)
		search(srcRow + 1, srcCol, matrix, rowMax, colMax, option, x, y, rowInterval, colInterval, pivotMatrix, sum);
	if (srcCol != colMax && matrix[srcRow][srcCol + 1] == pivot && pivotMatrix[srcRow][srcCol + 1] == 0)
		search(srcRow, srcCol + 1, matrix, rowMax, colMax, option, x, y, rowInterval, colInterval, pivotMatrix, sum);
	return sum;
}
void matrixGenerator(int matrix[][10], int rowInterval, int colInterval, int rowMax, int colMax, int srcxcoo, int srcycoo, bool zeroHighlight)//��ʼ����Ϊ(1,1)Ԫλ��,Ԫ������пո�
{
	int i, j, x, y;
	cct_gotoxy(srcxcoo, srcycoo);
	cout << setfill(' ');
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++)
			if (!zeroHighlight || (zeroHighlight && matrix[i][j] != 0))
				cout << setw(colInterval + 1) << setiosflags(ios::left) << matrix[i][j];
			else {
				cct_getxy(x, y);
				cct_showch(x, y, '0', highlight, 1);
				cct_setcolor(defaultColor);
				cout << setw(colInterval) << " ";
			}
		if (i != rowMax - 1)
			cct_gotoxy(srcxcoo, srcycoo + i * rowInterval + i + 1);
	}
	cout << endl;
	return;
}
void zeroMoving(int matrix[][10], int rowMax, int colMax)
{
	int i, j;
	bool horizontalMoveFinish, verticalMoveFinish;
	while (1) {
		verticalMoveFinish = true;
		for (j = 0; j < colMax; j++) {
			for (i = rowMax - 1; i > 0; i--) {
				if (matrix[i - 1][j] != 0 && matrix[i][j] == 0) {
					matrix[i][j] = matrix[i - 1][j];
					matrix[i - 1][j] = 0;
					verticalMoveFinish = false;
				}
			}
		}
		if (verticalMoveFinish)
			break;
	}
	while (1) {
		horizontalMoveFinish = true;
		for (j = 0; j < colMax - 1; j++)
			if (matrix[rowMax - 1][j] == 0 && matrix[rowMax - 1][j + 1] != 0) {
				horizontalMoveFinish = false;
				for (i = 0; i < rowMax; i++) {
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = 0;
				}
			}
		if (horizontalMoveFinish)
			break;
	}
	return;
}
int victory(int matrix[][10], int rowMax, int colMax)
{
	int i, j, u, v, pivotMatrix[10][10] = { 0 }, sum = 0;
	for (i = 0; i < rowMax; i++) {
		for (j = 0; j < colMax; j++) {
			search(i, j, matrix, rowMax, colMax, 5, 0, 0, 0, 0, pivotMatrix, sum);
			if (sum != 1)
				return 0;
			for (u = 0; u < 10; u++)
				for (v = 0; v < 10; v++)
					pivotMatrix[u][v] = 0;
		}
	}
	return 1;
}