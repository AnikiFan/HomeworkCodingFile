#include <iostream>
using namespace std;
int main()
{
    int fun(int x, int y);
    int x = 10, y = 15;
    fun(x, y);
    return 0;
}
void f()
{
    fun(10, 15);
}
int fun(int x, int y)
{
    /* ע�⣺��������Ϊ�Լ�ѧ��-���� */
    cout << "2254298-����" << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    return 0;
}
