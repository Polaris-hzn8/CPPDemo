#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//学生结构体
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

//显示菜单界面
void showMenu() {
    cout << "**********************" << endl;
    cout << "***** 1.添加学生 *****" << endl;
    cout << "***** 2.显示学生 *****" << endl;
    cout << "***** 3.排序学生 *****" << endl;
    cout << "***** 4.查找学生 *****" << endl;
    cout << "***** 5.修改学生 *****" << endl;
    cout << "***** 6.清空学生 *****" << endl;
    cout << "***** 0.退出系统 *****" << endl;
    cout << "**********************" << endl;
}

void addPerson(Addressbooks * abs) {
    //判断系统是否已满，如果已满就不再添加
    if (abs->s_Num >= MAX) {
        cout << "系统已满，无法添加！" << endl;
    } else {
        string no;
        cout << "请输入学号： ";
        cin >> no;
        abs->personArray[abs->s_Num].s_no = no;

        int chinese;
        cout << "请输入语文成绩： ";
        cin >> chinese;
        abs->personArray[abs->s_Num].s_Chinese = chinese;

        int english;
        cout << "请输入英语成绩： ";
        cin >> english;
        abs->personArray[abs->s_Num].s_English = english;

        int math;
        cout << "请输入数学成绩： ";
        cin >> math;
        abs->personArray[abs->s_Num].s_Math = math;

        abs->personArray[abs->s_Num].sum = abs->personArray[abs->s_Num].s_Chinese + abs->personArray[abs->s_Num].s_Math + abs->personArray[abs->s_Num].s_English + abs->personArray[abs->s_Num].s_Chinese;

        //更新学生记录本中的人数
        abs->s_Num++;
        cout << "添加成功" << endl;
        cout << "是否继续添加(Y/N)?";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            addPerson(abs);
        } else {
            system("cls");
        }
    }
}

//2.显示学生信息
void showPerson(Addressbooks * abs) {
    if (abs->s_Num == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->s_Num; ++i) {
            double average = abs->personArray[i].sum / 3;
            cout << "学号： " << abs->personArray[i].s_no;
            cout << "\t语文： " << abs->personArray[i].s_Chinese;
            cout << "\t数学： " << abs->personArray[i].s_Math;
            cout << "\t英语： " << abs->personArray[i].s_English;
            cout << "\t总分： " << abs->personArray[i].sum;
            cout << "\t平均： " << average << endl;
        }
    }
    system("pause");
    system("cls");
}

//3.排序学生成绩
void bubbleSort(Addressbooks * abs) {
    for (int i = 0; i < abs->s_Num -1; ++i) {
        for (int j = 0; j < abs->s_Num - i - 1; ++j) {
            //若果j下标的元素年龄大于j+1下标的元素的年龄，交换两个元素
            if (abs->personArray[j].sum > abs->personArray[j + 1].sum) {
                struct Student temp = abs->personArray[j];
                abs->personArray[j] = abs->personArray[j + 1];
                abs->personArray[j + 1] = temp;
            }
        }
    }
   showPerson(abs);
}

//检查联系人是否存在，若果存在返回联系人在数组中的具体位置，否则返回-1
int isExist(Addressbooks * abs, string no) {
    for (int i = 0; i < abs->s_Num; ++i) {
        //找到用户输入的姓名了
        if (abs->personArray[i].s_no == no) {
            return i;
        }
    }
    return -1;
}

//4.查找联系人
void queryPerson(Addressbooks * abs) {
    string no;
    cout << "请输入您要查找的学生学号：";
    cin >> no;
    int res = isExist(abs, no);
    if (res == -1) {
        cout << "查无此人" << endl;
    } else {
        cout << "学号： " << abs->personArray[res].s_no;
        cout << "\t语文： " << abs->personArray[res].s_Chinese;
        cout << "\t数学： " << abs->personArray[res].s_Math;
        cout << "\t英语： " << abs->personArray[res].s_English;
        cout << "\t总分： " << abs->personArray[res].sum;
        cout << "\t平均： " << abs->personArray[res].sum / 3 << endl;
    }
    system("pause");
    system("cls");
}

int main() {
    //创建学生记录本结构体变量
    Addressbooks abs;
    //初始化系统中当前学生的个数
    abs.s_Num = 0;

    while(true) {
        //1.菜单的调用
        showMenu();

        //2.用户进行选择功能项
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
                cout << "欢迎您的下次使用" << endl;
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

