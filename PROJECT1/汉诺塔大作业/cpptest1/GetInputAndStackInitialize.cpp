
int main()
{
	int n, i;
	char src, tmp, dst;
	cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
	while (1) {
		cin >> n;
		if (n >= 0 && n <= 16 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
	}
	cout << "��������ʼ��(A-C)" << endl;
	while (1) {
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && !cin.rdstate()) {
			switch (src) {
				case 'a':
					src = 'A';
					break;
				case 'b':
					src = 'B';
					break;
				case 'c':
					src = 'C';
					break;
			}
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "��������ʼ��(A-C)" << endl;
	}
	cout << "������Ŀ����(A-C)" << endl;
	while (1) {
		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && !cin.rdstate()
			&& dst != src && dst != (src - 32) && dst != (src + 32)) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		if (dst == src || dst == (src - 32) || dst == (src + 32))
			cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
		cout << "������Ŀ����(A-C)" << endl;
	}
	switch (dst) {
		case 'a':
			dst = 'A';
			break;
		case 'b':
			dst = 'B';
			break;
		case 'c':
			dst = 'C';
			break;
	}
	tmp = 'A' + 'B' + 'C' - src - dst;
	switch (src) {
		case('A'):
			Atop = n;
			for (i = 0; i < n; i++)
				Astack[i] = n - i;
			break;
		case('B'):
			Btop = n;
			for (i = 0; i < n; i++)
				Bstack[i] = n - i;
			break;
		case('C'):
			Ctop = n;
			for (i = 0; i < n; i++)
				Cstack[i] = n - i;
			break;
	}
	cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
	while (1) {
		cin >> speed;
		if (speed >= 0 && speed <= 5 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
	}
	cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
	while (1) {
		cin >> display;
		if (display >= 0 && display <= 1 && !cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
			break;
		}
		cin.clear();
		cin.ignore(10000000, '\n');//ɾ������Ժ����ѭ��
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
	}