/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<cmath>
int main()
{
	double number;
	int temp;
	printf("������[0-100��)֮�������: \n");
	scanf("%lf", &number);
	number += 0.009;
	//���˸ý���ֵ֮���ܱ���С�����ڶ�λ����ֵ�ı�,��Ϊ����������С����ڶ�λΪĩβ,
	//���Ե�����rounding��ʱ���ı�С�����ڶ�λ����ֵ,
	//���ϸ�У��ֵ��ɱ��������Ҳ���ı�С�����ڶ�λ��֮ǰ����ֵ
	printf("%-7s%-2s%d\n", "ʮ��λ", ":", (number / pow(10, 9)));//floor��Ϊ�˷�ֹ��λ
	printf("%-7s%-2s%d\n", "��λ", ":", ((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//һ�������ַ�ռ2�����
	printf("%-7s%-2s%d\n", "ǧ��λ", ":", ((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	printf("%-7s%-2s%d\n", "����λ", ":", ((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	printf("%-7s%-2s%d\n", "ʮ��λ", ":", ((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	printf("%-7s%-2s%d\n", "��λ", ":", ((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	printf("%-7s%-2s%d\n", "ǧλ", ":", ((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	printf("%-7s%-2s%d\n", "��λ", ":", ((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	printf("%-7s%-2s%d\n", "ʮλ", ":", ((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	printf("%-7s%-2s%d\n", "Բ", ":", ((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	printf("%-7s%-2s%d\n", "��", ":", ((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	printf("%-7s%-2s%d\n", "��", ":", ((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
	return 0;
}