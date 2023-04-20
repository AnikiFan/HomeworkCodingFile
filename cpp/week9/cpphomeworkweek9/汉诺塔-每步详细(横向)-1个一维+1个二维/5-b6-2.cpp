/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
#define arrow "-->"
using namespace std;
int top[3]={0}, int plate[3][10]={0}, count;


void hanoi(int n, char src, char tmp, char dst)
{
	cout << setw(21) << "��ʼ:";
	if (n == 1) {
		cout << " 1# " << src << arrow << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n << "# " << src << arrow << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}


int main()
{
	int n,i;
	char src, tmp, dst;
	cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
	}
	cout << "��������ʼ��(A-C)" << endl;
	while (1) {
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && !cin.rdstate()) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "��������ʼ��(A-C)" << endl;
	}
	cout << "������Ŀ����(A-C)" << endl;
	while (1) {
		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && !cin.rdstate()
			&& dst != src && dst != (src - 32) && dst != (src + 32)) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
		cout << "������Ŀ����(A-C)" << endl;
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	cout << "�ƶ�����Ϊ:" << endl;
	tmp = int(src != 'A') * int(dst != 'A') * 'A' + int(src != 'B') * int(dst != 'B') * 'B' + int(src != 'C') * int(dst != 'C') * 'C';
	switch (src) {
		case('A'):
			top[0] = n;
			for (i = 0; i < n - 1; i++)
				plate[0][i] = n - i;
			break;
		case('B'):
			top[1] = n;
			for (i = 0; i < n - 1; i++)
				plate[1][i] = n - i;
			break;
		case('C'):
			top[1] = n;
			for (i = 0; i < n - 1; i++)
				plate[2][i] = n - i;
			break;
	}
	hanoi(n, src, tmp, dst);
	return 0;
}