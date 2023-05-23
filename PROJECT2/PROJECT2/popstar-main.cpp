/* 2254298 信11 范潇 */
#include"popstar.h"
/***************************************************************************
  函数名称：menu
  功    能：
  输入参数：
  返 回 值：
  说    明：负责处理选项的输入以及行列数的输入
***************************************************************************/
int menu(int *row,int*column)
{
	char input;
	srand((unsigned int)(time(0)));
	cout << "--------------------------------------------" << endl;
	cout << "A.命令行找出可消除项并标识" << endl;
	cout << "B.命令行完成一次消除（分步骤显示）" << endl;
	cout << "C.命令行完成一关（分步骤显示）" << endl;
	cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
	cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
	cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
	cout << "G.伪图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout <<"--------------------------------------------" << endl;
	cout << "[请选择:] ";
	while (1) {
		input = _getch();
		if (input =='a'|| input == 'A' || input == 'b' || input == 'B' ||
			input == 'c' || input == 'C' || input == 'd' || input == 'D' ||
			input == 'e' || input == 'E' || input == 'f' || input == 'F' ||
			input == 'g' || input == 'G' || input == 'q' || input == 'Q' ) {
			cout << input ;
			break;
		}
	}
	switch (input) {
		case'A':
			input = 'a';
			break;
		case'B':
			input = 'b';
			break;
		case'C':
			input = 'c';
			break;
		case'D':
			input = 'd';
			break;
		case'E':
			input = 'e';
			break;
		case'F':
			input = 'f';
			break;
		case'G':
			input = 'g';
			break;
		case'Q':
			input = 'q';
			break;
		default:
			break;
	}
	cct_cls();
	cout << "请输入行数(8-10)：" << endl;
	while (1) {
		cin >> *row;
		if (*row >=8 && *row <= 10 && !cin.rdstate()) 
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "请输入行数(8-10)：" << endl;
	}
	cout << "请输入列数(8-10)：" << endl;
	while (1) {
		cin >> *column;
		if (*column >= 8 && *column <= 10 && !cin.rdstate())
			break;
		else if (cin.rdstate()) {
			cin.clear();
			cin.ignore(10000000, '\n');//删了这个以后会死循环
		}
		cout << "请输入列数(8-10)：" << endl;
	}
	return input;
}
int main()
{
	char option;
	int row, column,matrix[10][10],i, j;;
	while (1) {
		option = menu(&row,&column);
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				matrix[i][j] = (rand() % 9) + 1;
		if (option == 'q')
			break;
			switch (option) {
				case 'a':
					break;
				case 'b':
					break;
				case 'c':
					break;
				case 'd':
					break;
				case 'e':
					break;
				case 'f':
					break;
				case 'g':
					break;
			}
		reload();
	}
	return 0;
}