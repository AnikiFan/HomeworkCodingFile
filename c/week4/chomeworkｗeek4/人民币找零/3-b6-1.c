/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{
	double num;

	int wsy = 0, esy = 0, sy = 0, wy = 0, yy = 0, wj = 0, yj = 0, wf = 0, ef = 0, yf = 0;//���������
	printf("����������ֵ��\n");//TODO:������ð�ţ�
	scanf("%lf", &num);
	num += 0.0001;

	if ((int)(num / 50)) {
		wsy = (int)(num / 50);
		num -= 50 * wsy;
	}
	if ((int)(num / 20)) {
		esy = (int)(num / 20);
		num -= 20 * esy;
	}
	if ((int)(num / 10)) {
		sy = (int)(num / 10);
		num -= 10 * sy;
	}
	if ((int)(num / 5)) {
		wy = (int)(num / 5);
		num -= 5 * wy;
	}
	if ((int)(num / 1)) {
		yy = (int)(num / 1);
		num -= 1 * yy;
	}
	if ((int)(num / 0.5)) {
		wj = (int)(num / 0.5);
		num -= 0.5 * wj;
	}
	if ((int)(num / 0.1)) {
		yj = (int)(num / 0.1);
		num -= 0.1 * yj;
	}
	if ((int)(num / 0.05)) {
		wf = (int)(num / 0.05);
		num -= 0.05 * wf;
	}
	if ((int)(num / 0.02)) {
		ef = (int)(num / 0.02);
		num -= 0.02 * ef;
	}
	if ((int)(num / 0.01)) {
		yf = (int)(num / 0.01);
		num -= 0.01 * yf;
	}
	//
	//���
	//
	printf("��%d�����㣬�������£�\n",wsy + esy + sy + wy + yy + wj + yj + wf + ef + yf);//TODO:�����Ķ��ż�ð�ţ�
	if (wsy) {
		printf("50Ԫ : %d��\n",wsy );//TODO:ÿ��ֽ�ҵı�ֵ��������Ӣ��ð�ţ�ǰ��Ӣ�Ŀո����¶��룬����Ϊ 0 �������
	}
	if (esy) {
		printf("20Ԫ : %d��\n",esy );
	}
	if (sy) {
		printf("10Ԫ : %d��\n",sy );
	}
	if (wy) {
		printf("5Ԫ  : %d��\n",wy );
	}
	if (yy) {
		printf("1Ԫ  : %d��\n",yy );
	}
	if (wj) {
		printf("5��  : %d��\n",wj );
	}
	if (yj) {
		printf("1��  : %d��\n",yj );
	}
	if (wf) {
		printf("5��  : %d��\n",wf );
	}
	if (ef) {
		printf("2��  : %d��\n",ef );
	}
	if (yf) {
		printf("1��  : %d��\n",yf );
	}
	return 0;
}