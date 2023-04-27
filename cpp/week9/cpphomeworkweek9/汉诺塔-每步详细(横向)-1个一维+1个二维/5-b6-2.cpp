/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
#define arrow "-->"
using namespace std;
int top[3] = { 0 }, plate[3][10] = { 0 }, num = 0;
void horizontal()
{
	int i, tenflag = 0;
	cout << "A:";
	for (i = 0; i < top[0]; i++) {
		if (plate[0][i] == 10)
			tenflag = 1;
		cout << setw(2)<<plate[0][i] ;
	}
	cout << setw(2 * (10 - top[0])  + 3);
	tenflag = 0;

	cout << "B:";
	for (i = 0; i < top[1]; i++) {
		if (plate[1][i] == 10)
			tenflag = 1;
		cout << setw(2) << plate[1][i];
	}
	cout << setw(2 * (10 - top[1]) + 3);

	cout << "C:";
	for (i = 0; i < top[2]; i++) {
		cout << setw(2) << plate[2][i];
	}
	cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
	int temp;
	if (n == 1) {
		num++;
		plate[dst - 'A'][top[dst - 'A']] = plate[src - 'A'][top[src - 'A'] - 1];
		plate[src - 'A'][top[src - 'A'] - 1] = 0;
		top[dst - 'A']++;
		top[src - 'A']--;
		cout << "��" << setw(4) << num << " ��" << "(" << setw(2) << "1" << "): " << src << arrow << dst << " ";
		horizontal();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	plate[dst - 'A'][top[dst - 'A']] = plate[src - 'A'][top[src - 'A'] - 1];
	temp = plate[src - 'A'][top[src - 'A'] - 1];
	plate[src - 'A'][top[src - 'A'] - 1] = 0;
	top[dst - 'A']++;
	top[src - 'A']--;
	cout << "��" << setw(4) << num << " ��" << "(" << setw(2) << temp << "): " << src << arrow << dst << " ";
	horizontal();
	hanoi(n - 1, tmp, src, dst);
	return;
}


int main()
{
	int n, i;
	char src, tmp, dst;
	cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
	tmp = int(src != 'A') * int(dst != 'A') * 'A' + int(src != 'B') * int(dst != 'B') * 'B' + int(src != 'C') * int(dst != 'C') * 'C';
	switch (src) {
		case('A'):
			top[0] = n;
			for (i = 0; i < n; i++)
				plate[0][i] = n - i;
			break;
		case('B'):
			top[1] = n;
			for (i = 0; i < n; i++)
				plate[1][i] = n - i;
			break;
		case('C'):
			top[2] = n;
			for (i = 0; i < n; i++)
				plate[2][i] = n - i;
			break;
	}

	cout << "��ʼ:" << setw(16) << " ";
	horizontal();
	hanoi(n, src, tmp, dst);

	return 0;
}