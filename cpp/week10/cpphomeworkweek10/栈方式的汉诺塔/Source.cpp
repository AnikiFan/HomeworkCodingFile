/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
#define arrow "-->"
using namespace std;
int Atop, Btop, Ctop, Astack[10], Bstack[10], Cstack[10], num = 0;//Atop,Btop,Ctop��ջ��+1��λ��
void horizontal()
{
	int i, tenflag = 0;
	cout << "A:";
	for (i = 0; i < Atop; i++) {
		if (Astack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Astack[i];
	}
	cout << setw(2 * (10 - Atop) + 3);
	tenflag = 0;

	cout << "B:";
	for (i = 0; i < Btop; i++) {
		if (Bstack[i] == 10)
			tenflag = 1;
		cout << setw(2) << Bstack[i];
	}
	cout << setw(2 * (10 - Btop) + 3);

	cout << "C:";
	for (i = 0; i < Ctop; i++) {
		cout << setw(2) << Cstack[i];
	}
	cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
	int temp;
	if (n == 1) {
		num++;
		switch (src) {
			case('A'):
				if (dst == 'C')
					Cstack[Ctop++] = Astack[--Atop];
				else
					Bstack[Btop++] = Astack[--Atop];
				break;
			case('B'):
				if (dst == 'C')
					Cstack[Ctop++] = Bstack[--Btop];
				else
					Astack[Atop++] = Bstack[--Btop];
				break;
			case('C'):
				if (dst == 'A')
					Astack[Atop++] = Cstack[--Ctop];
				else
					Bstack[Btop++] = Cstack[--Ctop];
				break;

		}
		cout << "��" << setw(4) << num << " ��" << "(" << setw(2) << "1" << "): " << src << arrow << dst << " ";
		horizontal();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	num++;
	switch (src) {
		case('A'):
			if (dst == 'C')
				temp = (Cstack[Ctop++] = Astack[--Atop]);
			else
				temp = (Bstack[Btop++] = Astack[--Atop]);
			break;
		case('B'):
			if (dst == 'C')
				temp = (Cstack[Ctop++] = Bstack[--Btop]);
			else
				temp = (Astack[Atop++] = Bstack[--Btop]);
			break;
		case('C'):
			if (dst == 'A')
				temp = (Astack[Atop++] = Cstack[--Ctop]);
			else
				temp = (Bstack[Btop++] = Cstack[--Ctop]);
			break;

	}
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
	tmp = 'A' + 'B' + 'C' - src - dst;
	switch (src) {
		case('A'):
			Atop = n;
			for (i = 0; i < n; i++)
				Astack[i] = n - i;
			break;
		case('B'):
			Btop = n;
			for (i = 0; i < n; i++)
				Bstack[i] = n - i;
			break;
		case('C'):
			Ctop = n;
			for (i = 0; i < n; i++)
				Cstack[i] = n - i;
			break;
	}

	cout << "��ʼ:" << setw(16) << " ";
	horizontal();
	hanoi(n, src, tmp, dst);

	return 0;
}