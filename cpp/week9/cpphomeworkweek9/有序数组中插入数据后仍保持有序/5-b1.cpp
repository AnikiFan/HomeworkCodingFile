/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
int main()
{

	int array[21] = { 0 }, i, j, temp, t, s;
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i < 21; i++) {
		cin >> temp;
		if (temp > 0) {
			array[i] = temp;
		}
		else
			break;
		if (array[20] != 0) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
	}
	if (array[0] == 0)
		cout << "����Ч����" << endl;
	else {
		cout << "ԭ����Ϊ��" << endl;
		for (i = 0; i < 20; i++)
			if (array[i] != 0)
				cout << array[i] << " ";
		cout << endl;
		cout << "������Ҫ�����������" << endl;//����û�ж������벻Ϊ������������д���,�����������������Ļ�����᲻��ȷ
		cin >> temp;
		for (i = 0; i < 20; i++)
			if (array[i] <= temp && temp < array[i + 1])
				break;
		if (i == 20)
			array[20] = temp;
		else {
			t = array[i + 1];
			array[i + 1] = temp;
			for (j = i + 1; j < 20; j++) {
				s = array[j + 1];
				array[j + 1] = t;
				t = s;

			}
		}
		cout << "����������Ϊ��" << endl;
		for (i = 0; i < 21; i++)
			if (array[i] != 0)
				cout << array[i] << " ";
		cout << endl;
	}

	return 0;
}