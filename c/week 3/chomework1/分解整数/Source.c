/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int number;
	printf( "������һ��[1..30000]�������:\n") ;
	scanf("%d", &number);
	printf( "��λ : %d\n", number / 10000 );
	printf( "ǧλ : %d\n", (number -= number / 10000 * 10000) / 1000 );//�˳�Ϊ����
	printf( "��λ : %d\n", (number -= number / 1000 * 1000) / 100 );
	printf( "ʮλ : %d\n", (number -= number / 100 * 100) / 10) ;
	printf( "��λ : %d\n", (number -= number / 10 * 10) / 1 );
	return 0;
}