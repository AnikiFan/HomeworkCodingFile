/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double radius, height, pi = 3.14159;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &radius, &height);
	printf("Բ�ܳ�     : %.2f\n", 2.0 * pi * radius);
	printf("Բ���     : %.2f\n", pi * radius * radius);
	printf("Բ������ : %.2f\n", 4.0 * pi * radius * radius);
	printf("Բ�����   : %.2f\n", 4.0 / 3.0 * pi * radius * radius * radius);
	printf("Բ�����   : %.2f\n", pi * radius * radius * height);
	return 0;
} 