/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 0;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
   ***************************************************************************/
   //����n�㺺ŵ��,�Ƚ���ʼ���ϵ�n-1�������м���,Ȼ��������ʼ���ĵײ�����Ŀ����,�ٽ��м����ϵ�n-1������Ŀ������.
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		num++;
		printf("%5d:  1# %c-->%c\n", num, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	printf("%5d:%3d# %c-->%c\n", num, n, src, dst);
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/


int main()
{
	int n, ret;
	char src, tmp, dst;
	printf("�����뺺ŵ���Ĳ���(1-16)\n");
	while (1) {
		ret = scanf("%d", &n);
		while (getchar() != '\n')
			;
		if (n >= 0 && n <= 16 && ret == 1)
			break;
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
	}


	printf("��������ʼ��(A-C)\n");
	while (1) {
		ret = scanf("%c", &src);
		while (getchar() != '\n')
			;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && ret == 1) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			break;
		}
		printf("��������ʼ��(A-C)\n");
	}

	printf("������Ŀ����(A-C)\n");
	while (1) {
		ret = scanf("%c", &dst);
		while (getchar() != '\n')
			;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && ret == 1)
			break;
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, src);
		printf("������Ŀ����(A-C)\n");
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	printf("�ƶ�����Ϊ:\n");
	tmp = (int)(src != 'A') * (int)(dst != 'A') * 'A' + (int)(src != 'B') * (int)(dst != 'B') * 'B' + (int)(src != 'C') * (int)(dst != 'C') * 'C';
	hanoi(n, src, tmp, dst);
	return 0;
}