#include <iostream>
using namespace std;
int main()
{
    int score;
    cout << "������ɼ�[0-100]" << endl;
    cin >> score;
    switch (score / 10+int(score>100)-int(score<0)) {
    case 10:
    case 9:
        cout << "��" << endl;
        break;
    case 8:
        cout << "��" << endl;
        break;
    case 7:
        cout << "��" << endl;
        break;
    case 6:
        cout << "����" << endl;
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        cout << "������" << endl;
        break;
    default:
        cout << "�������" << endl;
        break;
    }

    return 0;
}
