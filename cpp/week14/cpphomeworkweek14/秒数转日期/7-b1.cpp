/* 2254298 ��11 ���� */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */
#define secondPerMinute 60
#define minutePerHour 60
#define secondPerHour (secondPerMinute*minutePerHour)
#define hourPerDay 24
#define secondPerDay (secondPerHour*hourPerDay)
#define dayPerLeapYear 366
#define secondPerLeapYear (dayPerLeapYear*secondPerDay)
#define dayPerNonLeapYear 365
#define secondPerNonLeapYear (dayPerNonLeapYear*secondPerDay)
#define srcYear 1970
#define srcMonth 1
#define srcDay 1
#define srcHour 0
#define srcMinute 0
#define srcSecond 0
#define maxday {31,28,31,30,31,30,31,31,30,31,30,31}
#define febMaxDayInLeapYear 29
#define febMaxDayInNonLeapYear 28
#define timeZone 8

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	cout << setfill('0') << setw(4) << tt->tm_year + 1900 << '-'
		<< setw(2) << tt->tm_mon + 1 << '-'
		<< setw(2) << tt->tm_mday << ' '
		<< setw(2) << tt->tm_hour << ':'
		<< setw(2) << tt->tm_min << ':'
		<< setw(2) << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	cout << setfill('0') << setw(4) << tp->tj_year << '-'
		<< setw(2) << tp->tj_month << '-'
		<< setw(2) << tp->tj_day << ' '
		<< setw(2) << tp->tj_hour << ':'
		<< setw(2) << tp->tj_minute << ':'
		<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	int year, month, day, hour, minute, second, remainder, maxDay[12] = maxday;
	input_time += timeZone * secondPerHour;
	second = srcSecond;
	minute = srcMinute;
	hour = srcHour;
	day = srcDay;
	month = srcMonth;
	year = srcYear;
	second += (input_time % secondPerMinute);
	input_time -= second;
	minute += ((input_time / secondPerMinute) % minutePerHour);
	input_time -= minute * secondPerMinute;
	hour += ((input_time / secondPerHour) % hourPerDay);
	input_time -= hour * secondPerHour;
	remainder = (input_time / secondPerDay);
	while (1) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//������
			maxDay[1] = febMaxDayInLeapYear;
			if (remainder >= dayPerLeapYear) {
				year++;
				remainder -= dayPerLeapYear;
			}
			else {
				while (1) {
					if (remainder >= maxDay[month - 1]) {
						remainder -= maxDay[month - 1];
						month++;
					}
					else {
						day += remainder;
						break;
					}
				}
				break;
			}
		}
		else {
			maxDay[1] = febMaxDayInNonLeapYear;
			if (remainder >= dayPerNonLeapYear) {
				year++;
				remainder -= dayPerNonLeapYear;
			}
			else {
				while (1) {
					if (remainder >= maxDay[month - 1]) {
						remainder -= maxDay[month - 1];
						month++;
					}
					else {
						day += remainder;
						break;
					}
				}
				break;
			}
		}
	}
	result.tj_year = year;
	result.tj_month = month;
	result.tj_day = day;
	result.tj_hour = hour;
	result.tj_minute = minute;
	result.tj_second = second;
	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
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
	int read_time;
	struct tj_time* tp;

	for (;;) {
		cin >> read_time; //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "����             : " << read_time << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(read_time);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��     : " << t << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(t);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}