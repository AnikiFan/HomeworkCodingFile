/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
int is_power(int num, int base)
{
	if (num == 1)
		return 1;
	if (num % base != 0)
		return 0;
	else
		return(is_power(num / base, base));
}
int main()
{
	int base, n, i, input[10000], sum = 0;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (i = 0; i < n; i++)
		cin >> input[i];
	cout << "���������[2..9]" << endl;
	cin >> base;
	for (i = 0; i < n; i++)
		if (is_power(input[i], base))
			sum++;
	cout << n << "�����л���" << base << "���ݵĸ��� : " << sum << endl;
	return 0;
}