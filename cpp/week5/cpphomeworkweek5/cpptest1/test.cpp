/* 2254298 ��11 ���� */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (x >= 0 && x <= 100 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();//������������cin.sync()�Ļ�����vs����û����,������dev��������ĳ�������Ϊ��ĸʱ���Ҫ��һ������
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			cout << "\0x8";
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}