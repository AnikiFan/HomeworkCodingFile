/* 2254298 ��11 ���� */
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double radius, height,pi=3.14159;
	cout << "������뾶�͸߶�" << endl;
	cin >> radius >> height;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout <<"Բ�ܳ�     : "<<2.0*pi*radius <<endl;
	cout <<"Բ���     : "<< pi*radius*radius<<endl;
	cout <<"Բ������ : " <<4.0*pi * radius * radius<<endl;
	cout <<"Բ�����   : " <<4.0/3.0*pi * radius * radius * radius <<endl;
	cout <<"Բ�����   : " << pi * radius * radius*height<<endl;
	return 0;
}