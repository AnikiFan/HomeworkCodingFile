#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	char  output[30];
	int  w, digitw;
	double num;
	printf("������double�����ݼ���ʾ�ܿ��,С�����λ��\n");
	scanf("%lf %d %d", &num, &w, &digitw); //�������������
	printf("01234567890123456789\n"); //���
	sprintf(output, "%%%d.%dlf*", w, digitw);
	printf(output, num);
	return 0;
}
