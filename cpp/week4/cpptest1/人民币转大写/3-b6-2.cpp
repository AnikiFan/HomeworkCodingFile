/* 2254298 ��11 ���� */
#include<iostream>//
#include<math.h>//��λΪ��,(Ǫ��ʰ)��,(Ǫ��ʰ)Բ,��,��/��
#include<iomanip>
using namespace std;
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

	if (by) {//�Ƿ�Ϊ��
		switch (by) {
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
		}
		cout << "��";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sy || yi)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}


	if (sy) {//�Ƿ�Ϊ��
		switch (sy) {
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
		}
		cout << "ʰ";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yi)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}


	if (yi) {//�Ƿ�Ϊ��
		switch (yi) {
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
		}
		zero = false;
		nozero = true;
	}


	if (yibl) {
		cout << "��";
		zero = false;
	}


	if (qw) {//�Ƿ�Ϊ��
		switch (qw) {
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
		}
		cout << "Ǫ";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (bw || sw || wa)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}



	if (bw) {//�Ƿ�Ϊ��
		switch (bw) {
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
		}
		cout << "��";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sw || wa)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}



	if (sw) {//�Ƿ�Ϊ��
		switch (sw) {
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
		}
		cout << "ʰ";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (wa)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}

	if (wa) {//�Ƿ�Ϊ��
		switch (wa) {
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
		}
		zero = false;
		nozero = true;
	}


	if (wabl) {
		cout << "��";
		zero = false;
	}


	if (qi) {//�Ƿ�Ϊ��
		switch (qi) {
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
		}
		cout << "Ǫ";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (ba || sh || yu)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}


	if (ba) {//�Ƿ�Ϊ��
		switch (ba) {
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
		}
		cout << "��";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sh || yu)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}


	if (sh) {//�Ƿ�Ϊ��
		switch (sh) {
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
		}
		cout << "ʰ";
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yu)) {//֮ǰ�Ƿ��з�����
			cout << "��";
			zero = true;
		}
	}


	if (yu) {//�Ƿ�Ϊ��
		switch (yu) {
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
		}
		zero = false;
		nozero = true;
	}


	if (!nozero && (!jibl && !febl)) {
		cout << "��Բ";
	}

	if (yibl || wabl || yubl) {
		cout << "Բ";
	}
	//�Ǻͷ�
	if (jibl) {
		switch (ji) {
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
		}
		cout << "��";
	}
	else if (febl && nozero) {
		cout << "��";
	}
	if (febl) {
		switch (fe) {
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
		}
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