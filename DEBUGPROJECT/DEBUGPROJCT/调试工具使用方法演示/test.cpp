/*2254298 ��11 ����*/
#include<iostream>
using namespace std;
void fun(void) 
{
	cout << "����fun����" << endl;
	cout << sqrt(0) << endl;
	cout << "fun�������ý���" << endl;
	return;
}
int main()
{
	cout << "����ʼ" << endl;
	cout << "test" << endl;
	fun();
	fun();
	cout << "�������" << endl;
	return 0;
}