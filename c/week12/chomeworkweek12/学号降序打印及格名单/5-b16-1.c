/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#define studentNum 10
#define studentCodeMaxLength 7
#define studnetNameMaxLength 4
#define studentNameEncodingLength 2
int tj_strcasecmp(char s1[], char s2[])//Ӧ��s1-s2
{
	int i = 0, se1, se2;
	while (1) {
		if ('A' <= s1[i] && s1[i] <= 'Z')
			se1 = s1[i] - ('A' - 'a');
		else
			se1 = s1[i];
		if ('A' <= s2[i] && s2[i] <= 'Z')
			se2 = s2[i] - ('A' - 'a');
		else
			se2 = s2[i];

		if (se1 - se2 != 0)
			return se1 - se2;
		else if (se1 == 0 && se2 == 0)
			return 0;
		i++;
	}
}
void input(char studentCode[studentNum][studentCodeMaxLength + 1], char studentName[studentNum][studnetNameMaxLength * 2], int studentScore[], int i)
{
	printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
	scanf("%s %s %d", studentCode[i], studentName[i], &studentScore[i]);
	return;
}
void selectSort(int studentScore[], char studentCode[studentNum][studentCodeMaxLength + 1], char studentName[studentNum][studnetNameMaxLength * studentNameEncodingLength])
{
	int i, j, k, t;
	char tempCode[studentCodeMaxLength + 1], tempName[studnetNameMaxLength * studentNameEncodingLength];
	for (i = 0; i < studentNum - 1; i++) {
		k = i;
		for (j = i + 1; j < studentNum; j++)
			if (tj_strcasecmp(studentCode[j], studentCode[k]) > 0)
				k = j;
		t = studentScore[k];
		studentScore[k] = studentScore[i];
		studentScore[i] = t;
		strcpy(tempCode, studentCode[k]);
		strcpy(studentCode[k], studentCode[i]);
		strcpy(studentCode[i], tempCode);
		strcpy(tempName, studentName[k]);
		strcpy(studentName[k], studentName[i]);
		strcpy(studentName[i], tempName);
	}
	return;
}
void output(int studentScore[], char studentCode[studentNum][studentCodeMaxLength + 1], char studentName[studentNum][studnetNameMaxLength * studentNameEncodingLength])
{
	int i;
	printf("\n");
	printf("��������(ѧ�Ž���) : \n");
	for (i = 0; i <studentNum; i++)
		if (studentScore[i] >= 60)
			printf("%s %s %d\n", studentName[i], studentCode[i], studentScore[i]);
	return;
}
int main()
{
	int i, studentScore[studentNum];
	char studentCode[studentNum][studentCodeMaxLength + 1], studentName[studentNum][studnetNameMaxLength * studentNameEncodingLength];
	for (i = 0; i < studentNum; i++)
		input(studentCode, studentName, studentScore, i);

	selectSort(studentScore, studentCode, studentName);
	//ð�ݷ���ʹ����ͬ�ɼ���ͬѧ˳��ı�
	output(studentScore, studentCode, studentName);
	return 0;
}