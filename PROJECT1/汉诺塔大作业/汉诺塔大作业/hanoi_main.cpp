/* ��11 2254298 ���� */

/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
   //TODO:������������ʹ��ȫ�ֱ�����¼�������������ȫ�� const ����/#define �궨��� �����������ƣ�����ʹ�ã�
   //TODO:���ƶ����� ��1��ȫ�ּ򵥱���;Բ��������Բ�̵ı�ţ�3��ȫ��һά����� 1 ��ȫ�ֶ�ά����;Բ��������Բ�̵�������3��ȫ�ּ򵥱����� 1 ��ȫ��һά����;��ʱ ��1��ȫ�ּ򵥱���

#include"hanoi.h"

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	char inputnumber, dst, src, tmp;
	int level;
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		inputnumber = Menu();
		if (inputnumber == '0')
			break;
		if (inputnumber != '5') {
			initializevariable(inputnumber, &src, &dst, &tmp, &level);
			switch (inputnumber) {
				case '1':
					hanoi(level, src, tmp, dst, '1');
					break;
				case '2':
					hanoi(level, src, tmp, dst, '2');
					break;
				case '3':
					hanoi(level, src, tmp, dst, '3');
					break;
				case '4':
					module4(src, dst, tmp, level);
					break;
				case '6':
					module6(src, dst, tmp, level);
					break;
				case '7':
					module7(src, dst, tmp, level);
					break;
				case '8':
					module8(src, dst, tmp, level);
					break;
				case '9':
					module9(src, dst, tmp, level);
					break;
			}
		}
		else {
			cct_cls();
			column();
		}
		reload();
	}
	return 0;
}
