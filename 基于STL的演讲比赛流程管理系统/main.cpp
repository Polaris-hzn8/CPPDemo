#include <iostream>
#include <string>
#include "speechManager.h"
using namespace std;

int main() {
	SpeechManager speechManager;
	
	//����12��ѡ�ֵĴ���
	//for (map<int, Speaker>::iterator it = speechManager.m_Speaker.begin(); it != speechManager.m_Speaker.end(); ++it) {
	//	cout << "ѡ�ֱ�ţ�" << it->first << "	������" << it->second.name << "	�ɼ���" << it->second.score[0] << endl;
	//}
	int choice = 0;
	while (true) {
		speechManager.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			speechManager.startSpeech();
			break;
		case 2://�鿴��¼
			break;
		case 3://��ռ�¼
			break;
		case 0://�˳�ϵͳ
			speechManager.exitSystem();
			break;
		default://����
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}



