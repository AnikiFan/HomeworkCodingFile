/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
#define studentNum 10
void input(string studentCode[], string studentName[], int studentScore[], int i)
{
	cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
	cin >> studentCode[i] >> studentName[i] >> studentScore[i];
	return;
}
void selectSort(int studentScore[], string studentCode[], string studentName[])
{
	int i, j, k, t;
	string temp;
	for (i = 0; i < studentNum - 1; i++) {
		k = i;
		for (j = i + 1; j < studentNum; j++)
			if (studentCode[j] < studentCode[k])
				k = j;
		t = studentScore[k];
		studentScore[k] = studentScore[i];
		studentScore[i] = t;
		temp = studentCode[k];
		studentCode[k] = studentCode[i];
		studentCode[i] = temp;
		temp = studentName[k];
		studentName[k] = studentName[i];
		studentName[i] = temp;
	}
	return;
}
void output(int studentScore[], string studentCode[], string studentName[])
{
	int i;
	cout << endl;
	cout << "ȫ��ѧ��(ѧ������):"<<endl;
	for (i = 0; i < studentNum; i++)
			cout << studentName[i] << " " << studentCode[i] << " " << studentScore[i] << endl;
	return;
}
int main()
{
	int i, studentScore[studentNum];
	string studentCode[studentNum], studentName[studentNum];
	for (i = 0; i < studentNum; i++)
		input(studentCode, studentName, studentScore, i);

	selectSort(studentScore, studentCode, studentName);
	//ð�ݷ���ʹ����ͬ�ɼ���ͬѧ˳��ı�
	output(studentScore, studentCode, studentName);
	return 0;
}