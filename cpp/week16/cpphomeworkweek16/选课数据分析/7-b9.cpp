/* 2254298 ��11 ���� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include<string.h>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
#define NoLength 5
#define codeLength 9
#define nameLength 32
#define roundLength 7
#define roundOneLength roundLength
#define roundTwoLength roundLength
#define seperatorLength (NoLength +codeLength +nameLength+roundOneLength+roundTwoLength)
#define seperator 	cout << setw(seperatorLength) << setfill('=')<<"=" << setfill(' ') << endl;
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend  class stu_list;
	bool round1 = 0;
	bool round2 = 0;


public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */





public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	void print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void merge();








};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{

}

void stu_list::merge()
{
	student* p1 = list_round_1;
	student* p2 = list_round_2;
	stu_merge* p = list_merge;
	stu_merge temp;
	temp.stu_no = p1->no;
	strcpy(temp.stu_name, p1->name);
	p->stu_no = p1->no;
	strcpy(p->stu_name, p1->name);
	p->round1 = 1;
	while (p1 - list_round_1 < list_num_1) {
		if (p1->no != temp.stu_no) {
			p->stu_no = temp.stu_no;
			strcpy(p->stu_name, temp.stu_name);
			p->round1 = 1;
			p++;
			temp.stu_no = p1->no;
			strcpy(temp.stu_name, p1->name);
		}
		p1++;
	}
	if ((p - 1)->stu_no != (p1 - 1)->no) {
		p->stu_no = temp.stu_no;
		strcpy(p->stu_name, temp.stu_name);
		p->round1 = 1;
		p++;
	}
	temp.stu_no = p2->no;
	strcpy(temp.stu_name, p2->name);
	p->stu_no = p2->no;
	strcpy(p->stu_name, p2->name);
	p->round2 = 1;
	//cout << p->stu_name << endl << endl;
	while (p2 - list_round_2 < list_num_2) {
		if (p2->no != temp.stu_no) {
			p->stu_no = temp.stu_no;
			strcpy(p->stu_name, temp.stu_name);
			p->round2 = 1;
			p++;
			temp.stu_no = p2->no;
			strcpy(temp.stu_name, p2->name);
		}
		p2++;
	}
	if ((p - 1)->stu_no != (p2 - 1)->no) {
		p->stu_no = temp.stu_no;
		strcpy(p->stu_name, temp.stu_name);
		p->round2 = 1;
		p++;
	}
//	cout << (p-1)->stu_name << endl << endl;
	//��ʱÿһ�������ظ�,�������������ظ�
	list_merge_num = p - list_merge;
	int i, j, k;
	char nametemp[MAX_NAME_LEN];
	int notemp, roundtemp1, roundtemp2;
	for (i = 0; i < list_merge_num - 1; i++) {
		k = i;
		for (j = i + 1; j < list_merge_num; j++)
			if (list_merge[j].stu_no < list_merge[k].stu_no)
				k = j;
		notemp = list_merge[k].stu_no;
		list_merge[k].stu_no = list_merge[i].stu_no;
		list_merge[i].stu_no = notemp;
		strcpy(nametemp, list_merge[k].stu_name);
		strcpy(list_merge[k].stu_name, list_merge[i].stu_name);
		strcpy(list_merge[i].stu_name, nametemp);
		roundtemp1 = list_merge[k].round1;
		list_merge[k].round1 = list_merge[i].round1;
		list_merge[i].round1 = roundtemp1;
		roundtemp2 = list_merge[k].round2;
		list_merge[k].round2 = list_merge[i].round2;
		list_merge[i].round2 = roundtemp2;
	}
	//����
	return;
}







/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
void stu_list::print(const char* prompt)
{
	int sum = 1;
	cout << prompt << endl;
	seperator
		cout << setw(NoLength) << setiosflags(ios::left) << "���"
		<< setw(codeLength) << "ѧ��"
		<< setw(nameLength) << "����"
		<< setw(roundOneLength) << "��һ��"
		<< setw(roundTwoLength) << "�ڶ���" << endl;
	seperator
		stu_merge* p = list_merge;
	//cout << p->stu_name << endl << endl;
	for (; p - list_merge < list_merge_num; p++) {
		if (p->stu_no == 0) {
			seperator
				return;
		}
		else if (p - list_merge == list_merge_num - 1) {
			cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name;
			if (p->round1)
				cout << setw(roundOneLength) << "Y" << setw(roundTwoLength) << "�˿�" << endl;
			else
				cout << setw(roundTwoLength) << "/" << setw(roundTwoLength) << "��ѡ" << endl;
			seperator
				return;
		}
		else {
			if (p->round1 == 0 && ((p + 1)->stu_no != p->stu_no))
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "/" << setw(roundTwoLength) << "��ѡ" << endl;
			else if ((p + 1)->stu_no == p->stu_no) {
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "Y" << setw(roundTwoLength) << "Y" << endl;
				p++;
			}
			else
				cout << setw(NoLength) << sum << setw(codeLength) << p->stu_no << setw(nameLength) << p->stu_name << setw(roundTwoLength) << "Y" << setw(roundTwoLength) << "�˿�" << endl;
			sum++;
		}
	}
	seperator
		return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */

	list.merge();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

