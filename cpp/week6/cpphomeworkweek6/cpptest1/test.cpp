#include <iostream>
using namespace std;

int fun(short x)
{
    cout << "x=" << x << endl;
    return 0;
}

int main()
{
    long k = 70000;
    fun(k);
    cout << "k=" << k << endl;
    /* ע�⣺��������Ϊ�Լ�ѧ��-���� */
    cout << "2254298-����" << endl;
    return 0;
}
