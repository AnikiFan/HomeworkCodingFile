/* 2254298 ��11 ���� */
#include<iostream>
#include<conio.h>
using namespace std;
#define line 3
#define max 128
int main()
{
	int i,j;
	char str[ line ][max],input;
	for (j = 0; j < line; j++) {
		cout << "�������"<<j+1<<"��" << endl;
		cin.getline(str[j], max);
	}
	for (j = 0; j < 3; j++)
		cout << str[j][0];
	return 0;
}