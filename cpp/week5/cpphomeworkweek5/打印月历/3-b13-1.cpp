/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
int main()
{
	int year, month, week;
	cout << "���������(2000-2030)���·�(1-12) : " << endl;
	cin >> year>>month;
	cout << "������"<<year<<"��"<<month<<"��1�յ�����(0 - 6��ʾ������ - ������) : " << endl;
	cin >> week;
	cout << year<<"��"<<month<<"�µ�����Ϊ: " << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	return 0;
}