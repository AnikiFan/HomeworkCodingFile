/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
#define codeLength 3
#define seperateLength 3
#define infoLength 40
#define priceLength 10
#define columnWidth (infoLength+priceLength+codeLength)
#define boardWidth (2*columnWidth+seperateLength)
#define boardTitle "������ѧ 2023�����˵�"
#define titleLength 21
#define maxNum 26
#define itemNum 20
#define discountNum 7
#define screenWidth boardWidth
#define screenHeight (itemNum/2+discountNum+30)
#define showcaseNum 2
#define maxOrderNum 1000000
int main()
{
	struct ITEM {
		char name[infoLength];
		double price;
		int count = 0;
	};
	struct DISCOUNT {
		int totalNum;//�Ż��漰��Ʒ��������
		int eachNum[maxNum];//������Ʒ�漰������
		int eachCode[maxNum];//������Ʒ��Ӧ�Ĵ���
		double discount;//��������ܽ��
		char name[infoLength];
		int eachcount[maxNum] = { 0 };//������Ʒ���������Żݸ���
	};
	struct {
		int totalNum;//�漰��Ʒ��������
		int eachCode[maxNum];//������Ʒ����
		int eachNum[maxNum];
		int showcase[50];
	}showcase[showcaseNum] = {
		{3,{7,8,9},{1,1,1},{8,9,7}},
		{2,{3,4},{3,4},{3,4,3,4,3,4,4}}
	};
	int i, j, k;
	double sum;
	bool valid;
	char command[100];
	sprintf(command, "mode con cols=%d lines=%d", screenWidth, screenHeight);
	system(command);
	system("cls");
	while (1) {
		ITEM item[maxNum] = {
		{"��ϲ����",6},
		{"��Ҭ��",5},
		{"������ͷ",4},
		{"�������",7},
		{"�h��ţ",2},
		//5
		{"��ଷ�",1},
		{"�������",1},
		{"Ѽ��",4},
		{"ĵ��",5},
		{"���",1},
		{"����",4},
		{"ӭ����",1919.810},
		//7
		{"˫��֥ʿ����",10.5},
		{"���ʺ��",6},
		//2
		{"���˫�㰲��˹��ţ��",45},
		{"��ŨĨ��ѩ��",23.5},
		//2
		{"���⿾Ģ������",33},
		{"����÷÷��",15},
		{"�����������",22.5},
		{"�ɿڿ���",15}
		//4
		};
		DISCOUNT discount[maxNum] = {
		{5,{1,1,1,1,1},{0,1,2,3,4},1,"�����"},
		{5,{1,1,1,1,1},{5,6,9,10,11},1145.14,"��Ա���ײ�"},
		{1,{2},{7},5,"Ѽ��ĪѼ��"},
		{1,{2},{8},6,"ĵ��Īĵ��"},
		{2,{1,1},{12,13},13.9,"����ײ�"},
		{2,{1,1},{14,15},50,"�����ײ�"},
		{4,{1,1,1,1},{16,17,18,19},66,"Genshin�����ײ�"}
		};
		char order[maxOrderNum] = { 0 }, * p = order;
		int temp = 0;
		double tempdiscount = 0;
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ');
		cout << setw(columnWidth + titleLength / 2 + 2) << boardTitle << endl;
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ');
		for (i = 0; i < itemNum; i++) {
			cout << setw(codeLength - 1) << (char)('A' + i) << " " << setw(infoLength) << setiosflags(ios::left) << item[i].name << resetiosflags(ios::left)
				<< setw(priceLength) << setiosflags(ios::left) << item[i].price << resetiosflags(ios::left);
			if (i % 2 == 0)
				cout << setw(seperateLength - 1) << "|";
			if (i % 2 == 1)
				cout << endl;
		}
		cout << endl;
		cout << "[�Ż���Ϣ] :" << endl;
		for (i = 0; i < discountNum; i++) {
			cout << discount[i].name << "=";
			for (j = 0; j < discount[i].totalNum; j++) {
				cout << item[discount[i].eachCode[j]].name;
				if (discount[i].eachNum[j] != 1)
					cout << "*" << discount[i].eachNum[j];
				if (j != discount[i].totalNum - 1)
					cout << "+";
			}
			cout << "=" << discount[i].discount << endl;
		}
		cout << endl;
		cout << "[�������˵��] : " << endl;
		for (i = 0; i < showcaseNum; i++) {
			sum = 0;
			if (i % 2 == 0) {
				for (j = 0; j < showcase[i].totalNum; j++)
					sum += showcase[i].eachNum[j];
				for (j = 0; j < sum; j++)
					cout << (char)('A' + showcase[i].showcase[j]);
			}
			else {
				for (j = 0; j < showcase[i].totalNum; j++)
					sum += showcase[i].eachNum[j];
				for (j = 0; j < sum; j++)
					cout << (char)('a' + showcase[i].showcase[j]);
			}
			cout << "=";
			for (j = 0; j < showcase[i].totalNum; j++) {
				cout << item[showcase[i].eachCode[j]].name;
				if (showcase[i].eachNum[j] != 1)
					cout << "*" << showcase[i].eachNum[j];
				if (j != showcase[i].totalNum - 1)
					cout << "+";
			}
			if (i != showcaseNum - 1 && i % 2 == 0)
				cout << " / ";
			else if (i != showcaseNum - 1 && i % 2 == 1)
				cout << endl;
		}
		cout << endl;
		cout << "��ĸ���ִ�Сд,����˳��,��������0���˳�����" << endl << endl << "��㵥:";
		cin.getline(order, maxOrderNum);
		if (order[0] == '0' && order[1] == '\0') {
			cout << endl;
			return 0;
		}
		valid = true;
		while (*p != '\0') {
			if (*p > 'a' + itemNum - 1 || (*p < 'a' && *p>'A' + itemNum - 1) || *p < 'A') {
				cout << "�������,�����������" << endl;
				_getch();
				valid = false;
				break;
			}
			if (*p >= 'A' && *p <= 'A' + itemNum - 1) {
				*p -= 'A' - 'a';//ȫ��ת��ΪСд
				item[*p - 'a'].count++;
				p++;
			}
			else {
				item[*p - 'a'].count++;
				p++;
			}

		}
		if (valid) {
			sum = 0;
			cout << "���ĵ㵥=";
			for (i = 0; i < itemNum; i++) {
				if (item[i].count == 1)
					cout << item[i].name << "+";
				else if (item[i].count > 1)
					cout << item[i].name << "*" << item[i].count << "+";
				if (item[i].count != 0)
					sum += item[i].count * item[i].price;
			}
			for (j = 0; j < discountNum; j++) {
				temp = 0;
				tempdiscount = 0;
				for (k = 0; k < discount[j].totalNum; k++)
					discount[j].eachcount[k] = item[discount[j].eachCode[k]].count / discount[j].eachNum[k];
				for (k = 0; k < discount[j].totalNum; k++) {
					temp = discount[j].eachcount[0];
					if (discount[j].eachcount[k] < temp)
						temp = discount[j].eachcount[k];
				}
				for (k = 0; k < discount[j].totalNum; k++)
					tempdiscount += discount[j].eachNum[k] * item[discount[j].eachCode[k]].price;
				tempdiscount = tempdiscount - discount[j].discount;//�����Żݽ��
				sum -= tempdiscount * temp;
			}
			cout << '\b' << " ";
			cout << endl;
			cout << "����: " << sum << "Ԫ" << endl;
			cout << "�㵥���,�����������" << endl;
			_getch();
		}
		system("cls");
	}
	return 0;
}