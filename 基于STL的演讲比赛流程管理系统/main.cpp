#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main() {
	SpeechManager speechManager;
	
	//测试12名选手的创建
	//for (map<int, Speaker>::iterator it = speechManager.m_Speaker.begin(); it != speechManager.m_Speaker.end(); ++it) {
	//	cout << "选手编号：" << it->first << "	姓名：" << it->second.name << "	成绩：" << it->second.score[0] << endl;
	//}
	int choice = 0;
	while (true) {
		speechManager.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开始比赛
			speechManager.startSpeech();
			break;
		case 2://查看记录
			break;
		case 3://清空记录
			break;
		case 0://退出系统
			speechManager.exitSystem();
			break;
		default://清屏
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}



