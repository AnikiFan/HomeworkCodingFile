/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
#define arrow "-->"
using namespace std;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
   ***************************************************************************/
   //����n�㺺ŵ��,�Ƚ���ʼ���ϵ�n-1�������м���,Ȼ��������ʼ���ĵײ�����Ŀ����,�ٽ��м����ϵ�n-1������Ŀ������.
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cout << " 1# " << src << arrow << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n << "# " << src << arrow << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/


int main()
{
	int n;
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
	hanoi(n, src, tmp, dst);
	return 0;
}