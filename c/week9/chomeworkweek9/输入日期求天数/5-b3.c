/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxday {31,28,31,30,31,30,31,31,30,31,30,31}//���»�Ҫ�����ж�
#define accumulate {0,31,59,90,120,151,181,212,243,273,304,334}//���»�Ҫ�����ж�
int invaliddaytest(int y, int m, int d)
{
	int max[12] = maxday;
	max[1] += y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return(1 <= d && d <= max[m-1]);
}
int currentday(int y, int m, int d)
{
	int i,accumulateday[12]=accumulate;
	for (i = 1; i < 12; i++)
		accumulateday[i]+= y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return(accumulateday[m - 1] + d);
}
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	int year, month, day;
	int max[12] = maxday;
	printf("�������꣬�£���\n");//TODO:����Ϊ����ȫ��
	scanf("%d%d%d", &year, &month, &day);
	max[1] =year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month > 0 && month <= 12) {//�ж��·��Ƿ�Ϸ�
			if (day<1||day>max[month-1])
				printf("�������-�����µĹ�ϵ�Ƿ�\n");
			else
				printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, currentday(year,month,day));//TODO:�м��޿ո�,-ΪӢ�İ��
	}
	else
		printf("�������-�·ݲ���ȷ\n");//TODO:�������ͬʱ�����ж��£�����˾�
	return 0;
}