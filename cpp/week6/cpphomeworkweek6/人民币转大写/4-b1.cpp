/* 2254298 ��11 ���� */
#include<iostream>//
#include<math.h>//��λΪ��,(Ǫ��ʰ)��,(Ǫ��ʰ)Բ,��,��/��
#include<iomanip>
using namespace std;
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}
int main()
{
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zhΪ��ʱ����,����λ����ӦblֵĬ��Ϊ��,����Ϊ��ΪΪ0
	bool zero = false, nozero = false;
	cout << setiosflags(ios::left) << "������[0-100��)֮�������:" << endl;
	cin >> number;
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
		cout << "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sy || yi))
		zero = true;

	daxie(sy, nozero && !zero && (yi));
	if (sy) {//�Ƿ�Ϊ��
		cout << "ʰ";
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
		cout << "��";
		zero = false;
	}

	daxie(qw, nozero && !zero && (bw || sw || wa));
	if (qw) {//�Ƿ�Ϊ��
		cout << "Ǫ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (bw || sw || wa))
		zero = true;

	daxie(bw, nozero && !zero && (sw || wa));
	if (bw) {//�Ƿ�Ϊ��
		cout << "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sw || wa))
		zero = true;


	daxie(sw, nozero && !zero && (wa));
	if (sw) {//�Ƿ�Ϊ��
		cout << "ʰ";
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
		cout << "��";
		zero = false;
	}

	daxie(qi, nozero && !zero && (ba || sh || yu));
	if (qi) {//�Ƿ�Ϊ��
		cout << "Ǫ";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (ba || sh || yu))
		zero = true;



	daxie(ba, nozero && !zero && (sh || yu));
	if (ba) {//�Ƿ�Ϊ��
		cout << "��";
		zero = false;
		nozero = true;
	}
	else if (nozero && !zero && (sh || yu))
		zero = true;


	daxie(sh, nozero && !zero && (yu));
	if (sh) {//�Ƿ�Ϊ��
		cout << "ʰ";
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
		cout << "Բ";
	}

	if (yibl || wabl || yubl) {
		cout << "Բ";
	}
	//�Ǻͷ�

	daxie(ji, febl && nozero);
	if (jibl) {
		cout << "��";
	}

	daxie(fe, 0);
	if (febl) {
		cout << "��";
	}
	//��
	if (zh) {
		cout << "��" << endl;
	}
	else {
		cout << endl;
	}
	return 0;
}