#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
int main()
{
	char str[13], output[30];
	int  w;
	printf("������[3..12]����ַ�������ʾ���[len+1..20]\n");
	scanf("%s %d", str, &w); //�������������
	printf("01234567890123456789\n"); //���
	if (w <= (int)strlen(str))
		w = strlen(str) + 1;
	sprintf(output, "%%-%ds*", w);
	printf(output, str);
	return 0;
}
