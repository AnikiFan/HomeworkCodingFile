/* 2254298 ��11 ���� */
#include <iostream>
#include <string>
#include<math.h>
#include<iomanip>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero) {
				result += chnstr[0];
				result += chnstr[1];
			}
			break;
		case 1:
			result += chnstr[2];
			result += chnstr[3];
			break;
		case 2:
			result += chnstr[4];
			result += chnstr[5];
			break;
		case 3:
			result += chnstr[6];
			result += chnstr[7];
			break;
		case 4:
			result += chnstr[8];
			result += chnstr[9];
			break;
		case 5:
			result += chnstr[10];
			result += chnstr[11];
			break;
		case 6:
			result += chnstr[12];
			result += chnstr[13];
			break;
		case 7:
			result += chnstr[14];
			result += chnstr[15];
			break;
		case 8:
			result += chnstr[16];
			result += chnstr[17];
			break;
		case 9:
			result += chnstr[18];
			result += chnstr[19];
			break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* --���������Ҫ������ --*/
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zhΪ��ʱ����,����λ����ӦblֵĬ��Ϊ��,����Ϊ��ΪΪ0
	bool zero = false, nozero = false;
	cout << setiosflags(ios::left);
	cout << "������[0-100��)֮�������:" << endl;
	while (1) {
		cin >> number;
		if ((0.01 <= number && number <= 9999999999.99 || number == 0) && !cin.rdstate())
			break;
		else {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		}
		cout << "������[0 - 100��)֮�������:" << endl;
	}
	number += 0.009;
	by = int(floor(number / pow(10, 10)));
	sy = int(floor((number -= floor(number / pow(10, 10)) * pow(10, 10)) / pow(10, 9)));
	yi = int(floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//һ�������ַ�ռ2�����
	qw = int(floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	bw = int(floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	sw = int(floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	wa = int(floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	qi = int(floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	ba = int(floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	sh = int(floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	yu = int(floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	ji = int(floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	fe = int(floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
	//�ж��Ƿ�����
	if (fe != 0) {
		zh = false;
		febl = true;
	}
	if (ji != 0) {
		jibl = true;
	}
	//�ж���ǧԲ 
	if (yi || sy || by) {
		yibl = true;
	}
	if (wa || sw || bw || qw) {
		wabl = true;
	}
	if (yu || sh || ba || qi) {
		yubl = true;
	}




	//
	//���
	//
	cout << "��д�����:" << endl;

	daxie(by, nozero && !zero && (sy || yi));
	if (by) {//�Ƿ�Ϊ��
		result += "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sy || yi))
		zero = true;

	daxie(sy, nozero && !zero && (yi));
	if (sy) {//�Ƿ�Ϊ��
		result += "ʰ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (yi))
		zero = true;

	daxie(yi, 0);
	if (yi) {//�Ƿ�Ϊ��
		zero = false;
		nozero = true;
	}


	if (yibl) {
		result += "��";
		zero = false;
	}

	daxie(qw, nozero && !zero && (bw || sw || wa));
	if (qw) {//�Ƿ�Ϊ��
		result += "Ǫ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (bw || sw || wa))
		zero = true;

	daxie(bw, nozero && !zero && (sw || wa));
	if (bw) {//�Ƿ�Ϊ��
		result += "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sw || wa))
		zero = true;


	daxie(sw, nozero && !zero && (wa));
	if (sw) {//�Ƿ�Ϊ��
		result += "ʰ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (wa))
		zero = true;


	daxie(wa, 0);
	if (wa) {//�Ƿ�Ϊ��
		zero = false;
		nozero = true;
	}


	if (wabl) {
		result += "��";
		zero = false;
	}

	daxie(qi, nozero && !zero && (ba || sh || yu));
	if (qi) {//�Ƿ�Ϊ��
		result += "Ǫ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (ba || sh || yu))
		zero = true;



	daxie(ba, nozero && !zero && (sh || yu));
	if (ba) {//�Ƿ�Ϊ��
		result += "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sh || yu))
		zero = true;


	daxie(sh, nozero && !zero && (yu));
	if (sh) {//�Ƿ�Ϊ��
		result += "ʰ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (yu))
		zero = true;



	daxie(yu, 0);
	if (yu) {//�Ƿ�Ϊ��
		zero = false;
		nozero = true;
	}

	if (!nozero && (!jibl && !febl)) {
		daxie(0, 1);
		result += "Բ";
	}

	if (yibl || wabl || yubl) {
		result += "Բ";
	}
	//�Ǻͷ�

	daxie(ji, febl && nozero);
	if (jibl) {
		result += "��";
	}

	daxie(fe, 0);
	if (febl) {
		result += "��";
	}
	//��
	if (zh) {
		result += "��";
	}

	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}