/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	int i,j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			if (j <= i&&i*j<=9) {
				printf("%dx%d=%d   ", j, i, i * j);
			}
			else if (j <= i && i * j >= 10) {
				printf("%dx%d=%d  ", j, i, i * j);
			}
			if (j == 9) {
				printf("\n");
			}
		}
	}
	return 0;
}