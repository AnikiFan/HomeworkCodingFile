/* 2254298 ��11 ���� */
#include <iostream>
#include<cmath>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */

public:
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	Days(int y, int m, int d);
};

/* --- �˴��������Ա����������ʵ�� --- */
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Days::calc_days()
{
	if (month > 0 && month <= 12) {//�ж��·��Ƿ�Ϸ�
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//���������
			if (month == 2 && !(1 <= day && day <= 29) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))
				;
			else
				return month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 1 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day;
		}
		else {//��������
			if (month == 2 && !(1 <= day && day <= 28) ||
				month == 1 && !(1 <= day && day <= 31) ||
				month == 3 && !(1 <= day && day <= 31) ||
				month == 5 && !(1 <= day && day <= 31) ||
				month == 7 && !(1 <= day && day <= 31) ||
				month == 8 && !(1 <= day && day <= 31) ||
				month == 10 && !(1 <= day && day <= 31) ||
				month == 12 && !(1 <= day && day <= 31) ||
				month == 4 && !(1 <= day && day <= 30) ||
				month == 6 && !(1 <= day && day <= 30) ||
				month == 9 && !(1 <= day && day <= 30) ||
				month == 11 && !(1 <= day && day <= 30))
				;
			else
				return  month / 2 * 31 + (month - 1) / 2 * 30 - int(month >= 3) * 2 + int(month >= 9) * 1 - int(month >= 10) * 1 + int(month >= 11) * 1 - int(month >= 12) * 1 + int(month >= 13) * 1 + day;
		}
	}
	else
		cout << "�������-�·ݲ���ȷ" << endl;//TODO:�������ͬʱ�����ж��£�����˾�
	return -1;
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
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
