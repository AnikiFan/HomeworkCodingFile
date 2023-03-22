#include <iostream>
#include <iomanip>    //��ʽ���
#include <cmath>      //fabs
#include <windows.h>  //ȡϵͳʱ��
using namespace std;

int main()
{
    int s = 1;
    float n = 1, t = 1, pi = 0;

    LARGE_INTEGER tick, begin, end;
    QueryPerformanceFrequency(&tick);	//ȡ������Ƶ��
    QueryPerformanceCounter(&begin);	//ȡ��ʼӲ����ʱ������

    while (fabs(t) > 1e-8) {
        pi = pi + t;
        n = n + 2 ;
        s = -s;
        t = s / n;
        if (fabs(t) < 3.0e-8) {
            cout <<setprecision(10)<< t <<"    "<<n  << endl;
        }

    }

    QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������

    pi = pi * 4;
    cout << "n=" << setprecision(10) << n << endl;
    cout << "pi=" << setiosflags(ios::fixed) << setprecision(9) << pi << endl;

    cout << "������Ƶ�ʣ�" << tick.QuadPart << "Hz" << endl;
    cout << "ʱ�Ӽ���  ��" << end.QuadPart - begin.QuadPart << endl;
    cout << setprecision(6) << (end.QuadPart - begin.QuadPart) / double(tick.QuadPart) << "��" << endl;

    return 0;
}
