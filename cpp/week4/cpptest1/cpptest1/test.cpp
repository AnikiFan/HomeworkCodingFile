/* 2254298 ��11 ���� */
#include<iostream>//
#include<cmath>//��λΪ��,(Ǫ��ʰ)��,(Ǫ��ʰ)Բ,��,��/��
#include<iomanip>
using namespace std;
int main()
{
	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false, zero = false;//zhΪ��ʱ����,����λ����ӦblֵĬ��Ϊ��,����Ϊ��ΪΪ0
	cout << setiosflags(ios::left) << "������[0-100��)֮�������: " << endl;
	cin >> number;
	number += 0.009;
	yi = floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8));//һ�������ַ�ռ2�����
	qw = floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7));
	bw = floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6));
	sw = floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5));
	wa = floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4));
	qi = floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3));
	ba = floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2));
	sh = floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1));
	yu = floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0));
	ji = floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1));
	fe = floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2));
	//�ж��Ƿ�����
	if (fe != 0) {
		zh = false;
		febl = true;
	}
	if (ji != 0) {
		jibl = true;
	}
	//�ж���ǧԲ
	if (yi) {
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
	if (yibl) {
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
		cout << "��";
	}
	if (yibl && !(qw)) {
		zero = true;
		cout << "��";
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