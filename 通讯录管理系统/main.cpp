#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//ѧ���ṹ��
struct Student {
    string s_no;
    int s_Math;
    int s_English;
    int s_Chinese;
    double sum;
};

struct Addressbooks {
    struct Student personArray[MAX];
    int s_Num;
};

//��ʾ�˵�����
void showMenu() {
    cout << "**********************" << endl;
    cout << "***** 1.���ѧ�� *****" << endl;
    cout << "***** 2.��ʾѧ�� *****" << endl;
    cout << "***** 3.����ѧ�� *****" << endl;
    cout << "***** 4.����ѧ�� *****" << endl;
    cout << "***** 5.�޸�ѧ�� *****" << endl;
    cout << "***** 6.���ѧ�� *****" << endl;
    cout << "***** 0.�˳�ϵͳ *****" << endl;
    cout << "**********************" << endl;
}

void addPerson(Addressbooks * abs) {
    //�ж�ϵͳ�Ƿ���������������Ͳ������
    if (abs->s_Num >= MAX) {
        cout << "ϵͳ�������޷���ӣ�" << endl;
    } else {
        string no;
        cout << "������ѧ�ţ� ";
        cin >> no;
        abs->personArray[abs->s_Num].s_no = no;

        int chinese;
        cout << "���������ĳɼ��� ";
        cin >> chinese;
        abs->personArray[abs->s_Num].s_Chinese = chinese;

        int english;
        cout << "������Ӣ��ɼ��� ";
        cin >> english;
        abs->personArray[abs->s_Num].s_English = english;

        int math;
        cout << "��������ѧ�ɼ��� ";
        cin >> math;
        abs->personArray[abs->s_Num].s_Math = math;

        abs->personArray[abs->s_Num].sum = abs->personArray[abs->s_Num].s_Chinese + abs->personArray[abs->s_Num].s_Math + abs->personArray[abs->s_Num].s_English + abs->personArray[abs->s_Num].s_Chinese;

        //����ѧ����¼���е�����
        abs->s_Num++;
        cout << "��ӳɹ�" << endl;
        cout << "�Ƿ�������(Y/N)?";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            addPerson(abs);
        } else {
            system("cls");
        }
    }
}

//2.��ʾѧ����Ϣ
void showPerson(Addressbooks * abs) {
    if (abs->s_Num == 0) {
        cout << "��ǰ��¼Ϊ��" << endl;
    } else {
        for (int i = 0; i < abs->s_Num; ++i) {
            double average = abs->personArray[i].sum / 3;
            cout << "ѧ�ţ� " << abs->personArray[i].s_no;
            cout << "\t���ģ� " << abs->personArray[i].s_Chinese;
            cout << "\t��ѧ�� " << abs->personArray[i].s_Math;
            cout << "\tӢ� " << abs->personArray[i].s_English;
            cout << "\t�ܷ֣� " << abs->personArray[i].sum;
            cout << "\tƽ���� " << average << endl;
        }
    }
    system("pause");
    system("cls");
}

//3.����ѧ���ɼ�
void bubbleSort(Addressbooks * abs) {
    for (int i = 0; i < abs->s_Num -1; ++i) {
        for (int j = 0; j < abs->s_Num - i - 1; ++j) {
            //����j�±��Ԫ���������j+1�±��Ԫ�ص����䣬��������Ԫ��
            if (abs->personArray[j].sum > abs->personArray[j + 1].sum) {
                struct Student temp = abs->personArray[j];
                abs->personArray[j] = abs->personArray[j + 1];
                abs->personArray[j + 1] = temp;
            }
        }
    }
   showPerson(abs);
}

//�����ϵ���Ƿ���ڣ��������ڷ�����ϵ���������еľ���λ�ã����򷵻�-1
int isExist(Addressbooks * abs, string no) {
    for (int i = 0; i < abs->s_Num; ++i) {
        //�ҵ��û������������
        if (abs->personArray[i].s_no == no) {
            return i;
        }
    }
    return -1;
}

//4.������ϵ��
void queryPerson(Addressbooks * abs) {
    string no;
    cout << "��������Ҫ���ҵ�ѧ��ѧ�ţ�";
    cin >> no;
    int res = isExist(abs, no);
    if (res == -1) {
        cout << "���޴���" << endl;
    } else {
        cout << "ѧ�ţ� " << abs->personArray[res].s_no;
        cout << "\t���ģ� " << abs->personArray[res].s_Chinese;
        cout << "\t��ѧ�� " << abs->personArray[res].s_Math;
        cout << "\tӢ� " << abs->personArray[res].s_English;
        cout << "\t�ܷ֣� " << abs->personArray[res].sum;
        cout << "\tƽ���� " << abs->personArray[res].sum / 3 << endl;
    }
    system("pause");
    system("cls");
}

int main() {
    //����ѧ����¼���ṹ�����
    Addressbooks abs;
    //��ʼ��ϵͳ�е�ǰѧ���ĸ���
    abs.s_Num = 0;

    while(true) {
        //1.�˵��ĵ���
        showMenu();

        //2.�û�����ѡ������
        int select = 0;
        cin >> select;
        switch(select) {
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                bubbleSort(&abs);
                break;
            case 4:
                queryPerson(&abs);
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "��ӭ�����´�ʹ��" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}

