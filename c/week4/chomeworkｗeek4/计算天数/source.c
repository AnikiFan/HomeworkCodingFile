/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	int year, month, day;
	printf("�������꣬�£���\n");//TODO:����Ϊ����ȫ��
	scanf("%d%d%d", &year, &month, &day);
	if (month > 0 && month <= 12) {//�ж��·��Ƿ�Ϸ�
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//���������
			if (month == 2 && !(1 <= day && day <= 29) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))

				printf("�������-�����µĹ�ϵ�Ƿ�\n");
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, month / 2 * 31 + (month - 1) / 2 * 30 - (month >= 3) * 1 + (month >= 9) * 1 - (month >= 10) * 1 + (month >= 11) * 1 - (month >= 12) * 1 + (month >= 13) * 1 + day);//TODO:�м��޿ո�,-ΪӢ�İ��
		}
		else {//��������
			if (month == 2 && !(1 <= day && day <= 28) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, month / 2 * 31 + (month - 1) / 2 * 30 - (month >= 3) * 2 + (month >= 9) * 1 - (month >= 10) * 1 + (month >= 11) * 1 - (month >= 12) * 1 + (month >= 13) * 1 + day);//TODO:�м��޿ո�,-ΪӢ�İ��
		}
	}
	else
		printf("�������-�·ݲ���ȷ\n");//TODO:�������ͬʱ�����ж��£�����˾�
	return 0;
}