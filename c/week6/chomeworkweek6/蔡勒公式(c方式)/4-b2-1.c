/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int zeller(int y, int m, int d)
{
	int c, w;
	y -= m == 1 || m == 2;
	c = y / 100;
	y %= 100;
	m += (m == 1 || m == 2) * 12;
	w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (m + 1) / 5.0) + d - 1;
	return ((w + 77) % 7);//��ֻ��7,������2000 4 13�ó�������-3
}

int invaliddaytest(int y, int m, int d)
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
	return(1 <= d && d <= max);
}

int main()
{
	int ret, y, m, d;
	printf("��������[1900 - 2100]���¡��գ�\n");
	while (1) {
		ret = scanf("%d%d%d", &y, &m, &d);

		if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12 && invaliddaytest(y, m, d) && ret == 3)
			break;
		while (getchar() != '\n')
			;
		printf("�����������������\n");
		printf("��������[1900-2100]���¡��գ�\n");
	}
	switch (zeller(y, m, d)) {
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
		default:
			printf("error\n");
			break;
	}
	return 0;
}