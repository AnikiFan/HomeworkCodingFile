/* 2254298 ��11 ���� */
#define  _CRT_SECURE_NO_WARNINGS
#include<math.h>//��λΪ��,(Ǫ��ʰ)��,(Ǫ��ʰ)Բ,��,��/��
#include<stdio.h>
#include<string.h>
const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */
char temp[10];
int main()
{
	strncat(temp, &chnstr[0], 2);
	strncat(temp, &chnstr[2], 2);

	printf("%s", temp);
	return 0;
}