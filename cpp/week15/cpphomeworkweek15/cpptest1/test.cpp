/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
/* warning, this file is reserved for testing file only*/
#include<iostream>
using namespace std;
#define srcage 10
struct test
{
	double a;
	double b;
}test1;
struct demo
{
	char a;
	test test1;
}demo1;
int fun(int num)
{
	if (num == 1) {
		cout <<"��һ��ѧ��˵:��" << srcage << "����" << endl;
		return srcage+2;
	}
	int temp = fun(num - 1) + 2;
	cout <<"��"<<num<<"��ѧ��˵:"<< "��" << temp << "����" << endl;
	return temp+2;
}
int main()
{
	int a = { 1,2 };
	cout << *a++ << endl;
	return 0;
}