/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include<math.h>
int main()//TODO:���Ϊ����������δָ����ʽ�ģ���Ҫ�� double �ͣ�C++Ϊ cout ȱʡ�����C Ϊ%lf ��ȱʡ���
{

	double number;
	int  sh, ba, qi, wa, sw, bw, qw, yi, sy, by, yu, ji, fe;
	bool zh = true, febl = false, jibl = false, wabl = false, yubl = false, yibl = false;//zhΪ��ʱ����,����λ����ӦblֵĬ��Ϊ��,����Ϊ��ΪΪ0
	bool zero = false, nozero = false;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &number);
	number += 0.009;
	by = (int)(floor(number / pow(10, 10)));
	sy = (int)(floor((number -= floor(number / pow(10, 10)) * pow(10, 10)) / pow(10, 9)));
	yi = (int)(floor((number -= floor(number / pow(10, 9)) * pow(10, 9)) / pow(10, 8)));//һ�������ַ�ռ2�����
	qw = (int)(floor((number -= floor(number / pow(10, 8)) * pow(10, 8)) / pow(10, 7)));
	bw = (int)(floor((number -= floor(number / pow(10, 7)) * pow(10, 7)) / pow(10, 6)));
	sw = (int)(floor((number -= floor(number / pow(10, 6)) * pow(10, 6)) / pow(10, 5)));
	wa = (int)(floor((number -= floor(number / pow(10, 5)) * pow(10, 5)) / pow(10, 4)));
	qi = (int)(floor((number -= floor(number / pow(10, 4)) * pow(10, 4)) / pow(10, 3)));
	ba = (int)(floor((number -= floor(number / pow(10, 3)) * pow(10, 3)) / pow(10, 2)));
	sh = (int)(floor((number -= floor(number / pow(10, 2)) * pow(10, 2)) / pow(10, 1)));
	yu = (int)(floor((number -= floor(number / pow(10, 1)) * pow(10, 1)) / pow(10, 0)));
	ji = (int)(floor((number -= floor(number / pow(10, 0)) * pow(10, 0)) / pow(10, -1)));
	fe = (int)(floor((number -= floor(number / pow(10, -1)) * pow(10, -1)) / pow(10, -2)));
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
	printf("��д�����:\n");

	if (by) {//�Ƿ�Ϊ��
		switch (by) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sy || yi)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}


	if (sy) {//�Ƿ�Ϊ��
		switch (sy) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yi)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}


	if (yi) {//�Ƿ�Ϊ��
		switch (yi) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		zero = false;
		nozero = true;
	}


	if (yibl) {
		printf("��");
		zero = false;
	}


	if (qw) {//�Ƿ�Ϊ��
		switch (qw) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (bw || sw || wa)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}



	if (bw) {//�Ƿ�Ϊ��
		switch (bw) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sw || wa)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}



	if (sw) {//�Ƿ�Ϊ��
		switch (sw) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (wa)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}

	if (wa) {//�Ƿ�Ϊ��
		switch (wa) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		zero = false;
		nozero = true;
	}


	if (wabl) {
		printf("��");
		zero = false;
	}


	if (qi) {//�Ƿ�Ϊ��
		switch (qi) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (ba || sh || yu)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}


	if (ba) {//�Ƿ�Ϊ��
		switch (ba) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (sh || yu)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}


	if (sh) {//�Ƿ�Ϊ��
		switch (sh) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
		zero = false;
		nozero = true;
	}
	else {
		if (nozero && !zero && (yu)) {//֮ǰ�Ƿ��з�����
			printf("��");
			zero = true;
		}
	}


	if (yu) {//�Ƿ�Ϊ��
		switch (yu) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		zero = false;
		nozero = true;
	}


	if (!nozero && (!jibl && !febl)) {
		printf("��Բ");
	}

	if (yibl || wabl || yubl) {
		printf("Բ");
	}
	//�Ǻͷ�
	if (jibl) {
		switch (ji) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else if (febl && nozero) {
		printf("��");
	}
	if (febl) {
		switch (fe) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	//��
	if (zh) {
		printf("��\n");
	}
	else {
		printf("\n");
	}
	return 0;
}