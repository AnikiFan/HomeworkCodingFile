/* 2254298 ��11 ���� */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double number;
	cout << setiosflags(ios::left) << "������[0-100��)֮�������: " << endl;
	cin >> number;
	number += 0.009;
	//���˸ý���ֵ֮���ܱ���С�����ڶ�λ����ֵ�ı�,��Ϊ����������С����ڶ�λΪĩβ,
	//���Ե�����rounding��ʱ���ı�С�����ڶ�λ����ֵ,
	//���ϸ�У��ֵ��ɱ��������Ҳ���ı�С�����ڶ�λ��֮ǰ����ֵ
	cout <<setw(6)<<"ʮ��λ"<<" : "<<floor(number / pow(10, 9)) << endl;//floor��Ϊ�˷�ֹ��λ
	cout <<setw(6)<<"��λ"<<" : "<<floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)) << endl;//һ�������ַ�ռ2�����
	cout <<setw(6)<<"ǧ��λ"<<" : "<<floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)) << endl;
	cout <<setw(6)<<"����λ"<<" : "<<floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)) << endl;
	cout <<setw(6)<<"ʮ��λ"<<" : "<<floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)) << endl;
	cout <<setw(6)<<"��λ"<<" : "<<floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)) << endl;
	cout <<setw(6)<<"ǧλ"<<" : "<<floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)) << endl;
	cout <<setw(6)<<"��λ"<<" : "<<floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)) << endl;
	cout <<setw(6)<<"ʮλ"<<" : "<<floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)) << endl;
	cout <<setw(6)<<"Բ"<<" : "<<floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)) << endl;
	cout <<setw(6)<<"��"<<" : "<<floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)) << endl;
	cout <<setw(6)<<"��"<<" : "<<floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)) << endl;
 
	return 0;
}