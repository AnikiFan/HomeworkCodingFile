/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
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
#define screenWidth 3*columnWidth
#define screenHeight (itemNum/2+discountNum+12)
#define showcaseNum 2
#define maxOrderNum 1000000
int main()
{
	struct {
		char name[infoLength];
		int price;
	} item[maxNum] = {
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
		{"ӭ����",1919810},
		//7
		{"˫��֥ʿ����",10},
		{"���ʺ��",6},
		//2
		{"���˫�㰲��˹��ţ��",45},
		{"��ŨĨ��ѩ��",23},
		//2
		{"���⿾Ģ������",33},
		{"����÷÷��",15},
		{"�����������",22},
		{"�ɿڿ���",15}
		//4
	};
	struct {
		int totalNum;//�Ż��漰��Ʒ����
		int eachNum[maxNum];//������Ʒ�漰������
		int eachCode[maxNum];//������Ʒ��Ӧ�Ĵ���
		double discount;//��������Żݽ��
		char name[infoLength];
	}discount[maxNum] = {
		{5,{1,1,1,1,1},{0,1,2,3,4},1,"�����"},
		{7,{1,1,1,1,1,1,1},{5,6,7,8,9,10,11},114514,"��Ա���ײ�"},
		{1,{2},{7},5,"Ѽ��ĪѼ��"},
		{1,{2},{8},6,"ĵ��Īĵ��"},
		{2,{1,1},{12,13},13.9,"����ײ�"},
		{2,{1,1},{14,15},50,"�����ײ�"},
		{4,{1,1,1,1},{16,17,18,19},66,"Genshin�����ײ�"}
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
	int i, j, sum;
	char command[100];
	sprintf(command, "mode con cols=%d lines=%d", screenWidth, screenHeight);
	system(command);
	while (1) {
		char order[maxOrderNum];
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ') << endl;
		cout << setw(columnWidth + titleLength / 2 + 2) << boardTitle << endl;
		cout << setw(boardWidth) << setfill('=') << " " << setfill(' ') << endl;
		for (i = 0; i < itemNum; i++) {
			cout << setw(codeLength - 1) << (char)('A' + i) << " " << setw(infoLength) << setiosflags(ios::left) << item[i].name << resetiosflags(ios::left) << setw(priceLength) << item[i].price;
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
		cin.getline(order, maxOrderNum, );
		system("cls");
	}
	return 0;
}