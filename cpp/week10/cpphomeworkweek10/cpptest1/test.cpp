#define _CRT_SECURE_NO_WARNINGS  //VS��Ҫ
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i;
    char a[] = "student", b[] = "hello";
    for (i = 0; i < 100; i++) //20��Խ�磬Ŀ�ģ�
        cout << int(a[i]) << ' ';
    cout << endl;

    strncpy(a, b, 30);
    cout << a << endl;

    for (i = 0; i < 100; i++) //20��Խ�磬Ŀ�ģ�
        cout << int(a[i]) << ' ';
    cout << endl;
    return 0;
}
