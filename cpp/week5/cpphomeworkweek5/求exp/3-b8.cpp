/* 2254298 ��11 ���� */
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	int x,n=1,i;
	double exp=1,pi=1;
	while (1) {
		cout << "������ x ��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (x >= -10 && x <= 65)
			break;
		cout << "����Ƿ�������������" << endl;
	}
	while (1) {
		pi = 1;
		for (i = 1; i <= n;  i++) {
			pi *= i;//�۳�
		}
		if (pow(x, n)  < 1e-6*pi|| isinf(1e-6 * pi)) {
			break;
		}
		exp += pow(x, n) / pi;

		n++;
	}


	cout <<setprecision(10)<<"e^"<<x<<"=" <<exp<< endl;
	return 0;
}