/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<math.h>
int main()
{
	int side1, side2, angle;
	double pi = 3.14159;
	printf( "�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &side1, &side2, &angle);
	printf("���������Ϊ : %.3f", (float)(0.5 * side1 * side2 * sin(pi / 180.0 * angle)));

	return 0;
}