/* 2254298 ��11 ���� */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int side1, side2, angle;
	double pi = 3.14159;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> side1 >> side2 >> angle;
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << float(0.5 * side1 * side2 * sin(pi / 180 * angle))<<endl;

	return 0;
}