/* 2254298 ��11 ���� */
#include<iostream>
#include<math.h>
#define delta b * b - 4 * a * c
using namespace std;
void invalid()
{
	cout << "����һԪ���η���" << endl;
	return;
}
void same_real_root(double a, double b, double c)
{
	cout << "���������ʵ����" << endl;
	if (-b / (2 * a) == -0)
		cout << "x1=x2=0" << endl;
	else
		cout << "x1=x2=" << -b / (2 * a) << endl;
	return;
}
void dif_real_roots(double a, double b, double c)
{
	double neg, pos;
	neg = (-b - sqrt(delta)) / (2 * a);
	pos = (-b + sqrt(delta)) / (2 * a);
	cout << "����������ʵ����" << endl;
	if (a > 0) {
		cout << "x1=" << pos << endl;
		cout << "x2=" << neg << endl;
	}
	else {
		cout << "x1=" << neg << endl;
		cout << "x2=" << pos << endl;
	}
	return;
}
void im_roots(double a, double b, double c)
{
	double re, im;
	re = (-b) / (2 * a);
	im = fabs(sqrt(-(delta)) / (2 * a));
	cout << "�����������" << endl;
	if (fabs(re) < 1e-6 && fabs(im - 1) >= 1e-6) {
		cout << "x1=" << im << "i" << endl;
		cout << "x2=" << "-" << im << "i" << endl;
	}
	else if (fabs(re) < 1e-6) {
		cout << "x1=i" << endl;
		cout << "x2=-i" << endl;
	}
	else {
		cout << "x1=" << re << "+" << im << "i" << endl;
		cout << "x2=" << re << "-" << im << "i" << endl;
	}
	return;
}