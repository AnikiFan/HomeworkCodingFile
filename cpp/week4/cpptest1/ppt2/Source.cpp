#include <iostream>
using namespace std;
int main()
{
    int score;
    cout << "������ɼ�[0-100]" << endl;
    cin >> score;
    switch (int(score>100)+int(score>=85)+int(score>=70)+int(score>=60)+int(score>=0)) {
    case 4:
        cout << "��" << endl;
        break;
    case 3:
        cout << "��" << endl;
        break;
    case 2:
        cout << "����" << endl;
        break;
    case 1:
        cout << "������" << endl;
        break;
    default:
        cout << "�������" << endl;
        break;
    }
    return 0;
}
