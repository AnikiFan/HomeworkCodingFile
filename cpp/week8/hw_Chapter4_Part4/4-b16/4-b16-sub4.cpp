/* 2254298 ��11 ���� */
#include<iostream>
#include<math.h>
#define delta b * b - 4 * a * c
using namespace std;
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