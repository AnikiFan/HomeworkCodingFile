/* 2254298 ��11 ���� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	is_num = false;
	while (*p != '\0') {
		if (*p >= '0' && *p <= '9') {
			if (is_num == false) {
				if (pa - a == 9)
					break;
				if (*a != 0)
					pa++;
			}
				*pa *= 10;
				*pa += *p - '0';
			is_num = true;
		}
		else if (is_num == true)
			is_num = false;
		p++;
	}
	cout << "����" << (pa - a + 1)*(*pa!=0) << "������" << endl;
	pnum = a;
	if (*pa != 0) {
		while (pnum <= pa) {
			cout << *pnum << " ";
			pnum++;
		}
	}
	cout << endl;

	return 0;
}
