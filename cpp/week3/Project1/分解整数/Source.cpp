/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
int main()
{
	int number;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> number;
	cout << "��λ : "<< number/10000<< endl;
	cout<< "ǧλ : "<<(number-= number / 10000*10000)/1000 << endl;//�˳�Ϊ����
	cout<< "��λ : "<< (number -=  number / 1000 * 1000) / 100 << endl;
	cout<< "ʮλ : "<< (number -=  number / 100 * 100) / 10 << endl;
	cout << "��λ : " << (number -=  number / 10 * 10) / 1 << endl;
	return 0;
}