/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	int year, month, week, day, i = 0,ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret=scanf("%d%d", &year,&month);
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12 && ret == 2)
			break;
		printf("����Ƿ�������������\n");
		if (ret != 2) {
			while (getchar() != '\n')
				;
		}
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ",year,month);
		ret = scanf("%d", &week);
		printf("\n");
		if (week >= 0 && week <= 6 && ret == 1)
			break;
		printf("����Ƿ�������������\n");
		if (ret != 1) {
			while (getchar() != '\n')
				;

		}
	}
	printf("%d��%d�µ�����Ϊ: \n",year,month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	switch (month) {
		case 1:
			day = 31;
			break;
		case 3:
			day = 31;
			break;
		case 5:
			day = 31;
			break;
		case 7:
			day = 31;
			break;
		case 8:
			day = 31;
			break;
		case 10:
			day = 31;
			break;
		case 12:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 6:
			day = 30;
			break;
		case 9:
			day = 30;
			break;
		case 11:
			day = 30;
			break;
		case 2:
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				day = 29;
			else
				day = 28;
			break;
	}
	while (i <= week - 1) {
		printf("        ");
		i++;
	}
	for (i = 1; i <= day; i++) {
		printf("%4d    ",i);
		if (!((week + i) % 7) || i == day) {
			printf("\n");
		}
	}
	return 0;
}