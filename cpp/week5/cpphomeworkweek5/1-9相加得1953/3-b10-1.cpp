/* 2254298 信11 范潇 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int i, j, k, no = 1;
	bool sum, unique;
	for (i = 100; i <= 999; i++) {
		for (j = i + 1; j <= 999; j++) {
			for (k = j + 1; k <= 999; k++) {
				sum = i + j + k == 1953;
				unique = (i / 100 - 9) && (j / 100 - 9) && (k / 100 - 9) && (i % 10 - 9) && (j % 10 - 9) && (k % 10 - 9) && (i % 100 / 10 - 9) && (j % 100 / 10 - 9) && (k % 100 / 10 - 9) ||
					(i / 100 - 8) && (j / 100 - 8) && (k / 100 - 8) && (i % 10 - 8) && (j % 10 - 8) && (k % 10 - 8) && (i % 100 / 10 - 8) && (j % 100 / 10 - 8) && (k % 100 / 10 - 8) ||
					(i / 100 - 7) && (j / 100 - 7) && (k / 100 - 7) && (i % 10 - 7) && (j % 10 - 7) && (k % 10 - 7) && (i % 100 / 10 - 7) && (j % 100 / 10 - 7) && (k % 100 / 10 - 7) ||
					(i / 100 - 6) && (j / 100 - 6) && (k / 100 - 6) && (i % 10 - 6) && (j % 10 - 6) && (k % 10 - 6) && (i % 100 / 10 - 6) && (j % 100 / 10 - 6) && (k % 100 / 10 - 6) ||
					(i / 100 - 5) && (j / 100 - 5) && (k / 100 - 5) && (i % 10 - 5) && (j % 10 - 5) && (k % 10 - 5) && (i % 100 / 10 - 5) && (j % 100 / 10 - 5) && (k % 100 / 10 - 5) ||
					(i / 100 - 4) && (j / 100 - 4) && (k / 100 - 4) && (i % 10 - 4) && (j % 10 - 4) && (k % 10 - 4) && (i % 100 / 10 - 4) && (j % 100 / 10 - 4) && (k % 100 / 10 - 4) ||
					(i / 100 - 3) && (j / 100 - 3) && (k / 100 - 3) && (i % 10 - 3) && (j % 10 - 3) && (k % 10 - 3) && (i % 100 / 10 - 3) && (j % 100 / 10 - 3) && (k % 100 / 10 - 3) ||
					(i / 100 - 2) && (j / 100 - 2) && (k / 100 - 2) && (i % 10 - 2) && (j % 10 - 2) && (k % 10 - 2) && (i % 100 / 10 - 2) && (j % 100 / 10 - 2) && (k % 100 / 10 - 2) ||
					(i / 100 - 1) && (j / 100 - 1) && (k / 100 - 1) && (i % 10 - 1) && (j % 10 - 1) && (k % 10 - 1) && (i % 100 / 10 - 1) && (j % 100 / 10 - 1) && (k % 100 / 10 - 1);
				if (sum && !unique) {
					cout << "No." << setw(3) << no << " : " << i << "+" << j << "+" << k << "=" << "1953" << endl;
					no++;
				}
			}
		}
	}
	no--;
	cout << "total=" << no << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}