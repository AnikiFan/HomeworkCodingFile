/* 2254298 ��11 ���� */
#include <iostream>
using namespace std;

int main()
{
	int x,state;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		state=cin.rdstate();
		if (x >= 0 && x <= 100&& !state)
			break;
		else if (state) {
			cin.clear(0);	
			cin.sync();
			cin.ignore(10000000,'\n');//ɾ������Ժ����ѭ��
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}