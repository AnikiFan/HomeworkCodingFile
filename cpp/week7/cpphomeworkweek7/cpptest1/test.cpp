/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */


char splitter(int n)
{
	if (n == 1)
		return('=');
	if (n == 2) {
		cout << "=";
		return('=');
	}
	cout << "=";
	splitter(n - 1);
	return('=');
}

void ALPHAstring(int order, char endalpha)//��ʼ��ĸΪA,������orderΪ1
{
	if (order) {
		if (endalpha == 'A') {
			cout << 'A';
			return;
		}
		ALPHAstring(order, endalpha - 1);
		cout << endalpha;
		return;
	}
	else {
		if (endalpha == 'A') {
			cout << 'A';
			return;
		}
		cout << endalpha;
		ALPHAstring(order, endalpha - 1);
		return;
	}
}
void singlelevel(char maxchar, char levelchar)//levelchar���ò�������ĸ
{
	cout << setw(maxchar - levelchar);
	if (levelchar != 'A') {
		ALPHAstring(1, levelchar);
		ALPHAstring(0, levelchar - 1);
		cout << endl;
	}
	else
		cout << 'A' << endl;
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
			��ʾ����һ������order��ָ������/����
***************************************************************************/
void print_tower(int order, char maxchar)//order=1ʱΪ����
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	static char MAXCHAR = maxchar;
	if (order) {
		if (maxchar == 'A') {
			singlelevel(MAXCHAR, maxchar);
			return;
		}
		print_tower(order, maxchar - 1);
		singlelevel(MAXCHAR, maxchar);
		return;
	}
	else {
		if (maxchar == 'A') {
			singlelevel(MAXCHAR, maxchar);
			return;
		}
		singlelevel(MAXCHAR, maxchar);
		print_tower(order, maxchar - 1);
		return;
	}
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << splitter(2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << splitter(2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(1, end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << splitter(2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << splitter(2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(0, end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << splitter(2 * (end_ch - 'A') + 1) << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << splitter(2 * (end_ch - 'A') + 1) << endl;/* ����ĸ����������= */
	print_tower(1, end_ch);   //��ӡ A~�����ַ��������� 
	print_tower(0, end_ch);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}