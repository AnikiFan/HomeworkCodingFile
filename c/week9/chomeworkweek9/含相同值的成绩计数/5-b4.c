/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 1000
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	int array[max], inverse[max], i, j, temp, t;
	for (i = 0; i < max; i++)
		array[i] = -1;
	printf("������ɼ������1000������������������\n");
	for (i = 0; i < max; i++) {
		scanf("%d", &temp);
		if (temp >= 0)
			array[i] = temp;
		else
			break;
	}
	if (array[0] == -1)
		printf("����Ч����\n");
	else {
		printf("���������Ϊ:\n");
		for (i = 0; i < max; i++) {
			if (array[i] >= 0)
				printf("%d ", array[i]);
			if (array[i] >= 0 && !((i + 1) % 10))
				printf("\n");
			else if (array[i] >= 0 && array[i + 1] == -1) {//i�������999
				printf("\n");
				break;
			}
		}
		printf("�����������Ķ�Ӧ��ϵΪ:\n");
		for (i = 0; i < max - 1; i++)//ð�ݷ�����
			for (j = 0; j < max - (i + 1); j++)
				if (array[j] > array[j + 1]) {
					t = array[j];
					array[j] = array[j + 1];
					array[j + 1] = t;
				}
		for (i = 0; i < max; i++)
			inverse[i] = array[max - 1 - i];
	}
	j = -1;
	for (i = 0; i < max - 1; i++) {
		if (inverse[i + 1] < inverse[i]) {
			printf("%d %d\n", inverse[i], i - j);
			j = i;

		}
		if (inverse[max - 1] != -1)
			printf("%d %d\n", inverse[max - 1], max - 1 - j);
	}
	return 0;
}