/* 2254298 ��11 ���� */
#include<iostream>
using namespace std;
#define line 3
#define max 128
int main()
{
	int i,j,uppercase=0,lowercase=0,digit=0,space=0,other=0;
	char str[line][max];
	for (i = 0; i < line; i++) {
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], max);
	}
	for (i = 0; i < line; i++) {
		for (j = 0; j < max; j++) {
			if (str[i][j] == 0)
				break;
			else if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				uppercase++;
			else if (str[i][j] >= 'A' && str[i][j] <= 'z')
				lowercase++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				digit++;
			else if (str[i][j] ==' ')
				space++;
			else
				other++;
		}
	}
	cout << "��д : "<<uppercase << endl;
	cout << "Сд : " << lowercase << endl;
	cout << "���� : " << digit << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << other << endl;

	return 0;
}