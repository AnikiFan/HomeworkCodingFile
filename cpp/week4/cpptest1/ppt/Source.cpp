/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
int main()
{
	int score;
	cout << "������ɼ�[0-100]" << endl;
	cin >> score;
	if (score >= 85 && score <= 100) {
		cout << "��" << endl;
	}
	else if (score >= 70 && score < 85) {
		cout << "��" << endl;
	}
	else if (score >= 60 && score < 70) {
		cout << "����" << endl;
	}
	else if (score >= 0 && score < 60) {
		cout << "������" << endl;
	}
	else {
		cout << "�������" << endl;
	}
	return 0;
}