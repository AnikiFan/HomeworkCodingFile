/* 2254298 ��11 ���� */
#include<iostream>
#include<math.h>
using namespace std;
#define max 33
unsigned int convert(char *p)
{
	int num=0;
	char* backward = p,*forward;
	while (*backward != '\0')
		backward++;
	backward--;
	forward = backward;
	while (forward - p >= 0) {
		num += (*forward-'0') * (int)pow(2, backward - forward);
		forward--;
	}
	return num;
}
int main()
{
	char input[max];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> input;
	cout << convert(input) << endl;
	return 0;
}