/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* 2254298 ��11 ���� */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double number;
	cout << "������[0 - 100��)֮�������:" << endl;
	cin >> number;
	number += 0.00000095367431640625;
	//���˸ý���ֵ֮���ܱ���С�����ڶ�λ����ֵ�ı�,��Ϊ����������С����ڶ�λΪĩβ,
	//���Ե�����rounding��ʱ���ı�С�����ڶ�λ����ֵ,
	//���ϸ�У��ֵ��ɱ��������Ҳ���ı�С�����ڶ�λ��֮ǰ����ֵ
	cout << floor(number / pow(10, 9)) << endl;//floor��Ϊ�˷�ֹ��λ
	cout << floor((number -=floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)) << endl;
	cout << floor((number -=floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)) << endl;
	cout << floor((number -=floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)) << endl;
	cout << floor((number -=floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)) << endl;
	cout << floor((number -=floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)) << endl;
	cout << floor((number -=floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)) << endl;
	cout << floor((number -=floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)) << endl;
	cout << floor((number -=floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)) << endl;
	cout << floor((number -=floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)) << endl;
	cout << floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)) << endl;
	cout << floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)) << endl;
	cout << setw(6) << setiosflags(ios::left) << "����" <<"��������" << endl;
	cout << "����" << "��������" << endl;
	return 0;
}