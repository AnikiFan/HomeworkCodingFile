/* 2254298 ��11 ���� */
#include<iostream>//TODO:��������������������Ƿ��ַ��������涨��Χ��С�������λ���ϵȣ�
#include<iomanip>
using namespace std;
int main()
{
	double num;

	int wsy = 0, esy = 0, sy = 0, wy = 0, yy = 0, wj = 0, yj = 0, wf = 0, ef = 0, yf = 0;//���������
	cout << "����������ֵ��" << endl;//TODO:������ð�ţ�
	cin >> num;
	num += 0.0001;

	if (int(num / 50)) {
		wsy = int(num / 50);
		num -= 50 * wsy;
	}
	if (int(num / 20)) {
		esy = int(num / 20);
		num -= 20 * esy;
	}
	if (int(num / 10)) {
		sy = int(num / 10);
		num -= 10 * sy;
	}
	if (int(num / 5)) {
		wy = int(num / 5);
		num -= 5 * wy;
	}
	if (int(num / 1)) {
		yy = int(num / 1);
		num -= 1 * yy;
	}
	if (int(num / 0.5)) {
		wj = int(num / 0.5);
		num -= 0.5 * wj;
	}
	if (int(num / 0.1)) {
		yj = int(num / 0.1);
		num -= 0.1 * yj;
	}
	if (int(num / 0.05)) {
		wf = int(num / 0.05);
		num -= 0.05 * wf;
	}
	if (int(num / 0.02)) {
		ef = int(num / 0.02);
		num -= 0.02 * ef;
	}
	if (int(num / 0.01)) {
		yf = int(num / 0.01);
		num -= 0.01 * yf;
	}
	//
	//���
	//
	cout << setiosflags(ios::left) << "��" << wsy + esy + sy + wy + yy + wj + yj + wf + ef + yf << "�����㣬�������£�" << endl;//TODO:�����Ķ��ż�ð�ţ�
	if (wsy) {
		cout << setw(4) << "50Ԫ" << " : " << wsy << "��" << endl;//TODO:ÿ��ֽ�ҵı�ֵ��������Ӣ��ð�ţ�ǰ��Ӣ�Ŀո����¶��룬����Ϊ 0 �������
	}
	if (esy) {
		cout << setw(4) << "20Ԫ" << " : " << esy << "��" << endl;
	}
	if (sy) {
		cout << setw(4) << "10Ԫ" << " : " << sy << "��" << endl;
	}
	if (wy) {
		cout << setw(4) << "5Ԫ" << " : " << wy << "��" << endl;
	}
	if (yy) {
		cout << setw(4) << "1Ԫ" << " : " << yy << "��" << endl;
	}
	if (wj) {
		cout << setw(4) << "5��" << " : " << wj << "��" << endl;
	}
	if (yj) {
		cout << setw(4) << "1��" << " : " << yj << "��" << endl;
	}
	if (wf) {
		cout << setw(4) << "5��" << " : " << wf << "��" << endl;
	}
	if (ef) {
		cout << setw(4) << "2��" << " : " << ef << "��" << endl;
	}
	if (yf) {
		cout << setw(4) << "1��" << " : " << yf << "��" << endl;
	}
	return 0;
}