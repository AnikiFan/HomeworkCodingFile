/* 2254298 ��11 ���� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3������������һ������������Ҫ����Ҫ��
   ---------------------------------------------------------------------
*/
#define noLength 5
#define codeLength 8
#define nameLength 9
#define GPALength 6
#define weightLength 6
#define averageGPALength 8
#define averageGPAPrecision 3
#define lessonNum 3
#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
	int   gpa;		//ĳ�γ̵ļ��㣨ͬ�ù���[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5��
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	double averageGPA;                     //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����˴�����������һ���������Һ������βΡ��Զ������ȶ������Ǽ򵥱�������������[]��ʽ��
***************************************************************************/



/***************************************************************************
  �������ƣ�
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* �����������ͱ����⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int k=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;
	for (i = 0; i < num; i++) {
		cout << "�������" << setw(2) << i + 1 << "��ѧ������Ϣ : ";
		cin >> stu->no;
		cin >> stu->name;
		for (j = 0; j < 3; j++) {
			cin >> (stu->score + j)->value;
			cin >> (stu->score + j)->weight;
			if ((stu->score + j)->value >= 0 && (stu->score + j)->value < 60)
				(stu->score + j)->gpa = 0;
			else if ((stu->score + j)->value >= 60 && (stu->score + j)->value < 70)
				(stu->score + j)->gpa = 2;
			else if ((stu->score + j)->value >= 70 && (stu->score + j)->value < 80)
				(stu->score + j)->gpa = 3;
			else if ((stu->score + j)->value >= 80 && (stu->score + j)->value < 90)
				(stu->score + j)->gpa = 4;
			else if ((stu->score + j)->value >= 90 && (stu->score + j)->value <= 100)
				(stu->score + j)->gpa = 5;
		}
		stu->averageGPA = (stu->score->gpa * stu->score->weight + (stu->score + 1)->gpa * (stu->score + 1)->weight + (stu->score + 2)->gpa * (stu->score + 2)->weight) / (stu->score->weight + (stu->score + 1)->weight + (stu->score + 2)->weight);
		stu++;
	}
	cout << endl;
	return;
	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* ��������ָ������⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* ps;
	struct course* pc;
	cout << num << "��ѧ���ĳɼ�" << endl;
	cout << setiosflags(ios::left) << setw(noLength) << "���" << setw(codeLength) << "ѧ��" << setw(nameLength) << "����"
		<< setw(GPALength) << "����1" << setw(weightLength) << "Ȩ��1"
		<< setw(GPALength) << "����2" << setw(weightLength) << "Ȩ��2"
		<< setw(GPALength) << "����3" << setw(weightLength) << "Ȩ��3"
		<< setw(averageGPALength) << "ƽ������" << endl;
	cout << setw(noLength + codeLength + nameLength + lessonNum * (GPALength + weightLength) + averageGPALength) << setfill('=') << "=" << setfill(' ') << endl;
	ps = stu;
	while (ps != stu + num) {
		cout << setw(noLength) << ps - stu + 1 << setw(codeLength) << ps->no << setw(nameLength) << ps->name;
		pc = ps->score;
		while (pc != ps->score + lessonNum) {
			cout << setw(GPALength) << pc->gpa << setw(weightLength) << pc->weight;
			pc++;
		}
		cout << setiosflags(ios::fixed) << setprecision(averageGPAPrecision) << ps->averageGPA << resetiosflags(ios::fixed) << endl;
		ps++;
	}
	cout << endl;
	return;
	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	cout << "������ߵ�ѧ��Ϊ" << endl;
	cout << setiosflags(ios::left) << setw(noLength) << "���" << setw(codeLength) << "ѧ��" << setw(nameLength) << "����"
		<< setw(GPALength) << "����1" << setw(weightLength) << "Ȩ��1"
		<< setw(GPALength) << "����2" << setw(weightLength) << "Ȩ��2"
		<< setw(GPALength) << "����3" << setw(weightLength) << "Ȩ��3"
		<< setw(averageGPALength) << "ƽ������" << endl;
	cout << setw(noLength + codeLength + nameLength + lessonNum * (GPALength + weightLength) + averageGPALength) << setfill('=') << "=" << setfill(' ') << endl;
	int i;
	double maxGPA;
	bool max = true;
	student* ps = stu;
	struct course* pc;
	maxGPA = ps->averageGPA;
	for (i = 0; i < num; i++) {
		if (ps->averageGPA > maxGPA)
			maxGPA = ps->averageGPA;
		ps++;
	}
	ps = stu;
	for (i = 0; i < num; i++) {
		if (ps->averageGPA == maxGPA) {
			cout << setw(noLength) << ps - stu + 1 << setw(codeLength) << ps->no << setw(nameLength) << ps->name;
			pc = ps->score;
			while (pc != ps->score + lessonNum) {
				cout << setw(GPALength) << pc->gpa << setw(weightLength) << pc->weight;
				pc++;
			}
			cout << setiosflags(ios::fixed) << setprecision(averageGPAPrecision) << ps->averageGPA << resetiosflags(ios::fixed) << endl;
			ps++;
		}
		ps++;
	}
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, N);		//����10��ѧ������Ϣ
	output_base(stu, N);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, N);	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2150844 ���ں� 76.5 4 82 5 52 2
2154284 �� 63 4 49 1 87 6
2253105 �Ժ��� 56 3 76 4 69 5
2254319 ��ϣ�� 44.5 2 83.5 4 87 6
2251754 ��ҫ�� 91 4 43.5 1 66 3
2250269 ˾ͽ�ɂ� 79 6 85.5 3 62 2
2252558 ������ 86 3 63 3 77.5 4
1951475 �Բ��� 49.5 3 86 6 93.5 3
2153879 ��¬��� 81.5 2 64.5 3 87 4
2253636 ������ 73 3 62 2 85 5

*/