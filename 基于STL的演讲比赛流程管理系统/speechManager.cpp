#include<algorithm>
#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager() {
	//��ʼ������������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
}

//��ʾ�˵�
void SpeechManager::showMenu() {
	cout << "****************************************" << endl;
	cout << "************��ӭ�μ��ݽ�����*************" << endl;
	cout << "*************1.��ʼ�ݽ�����**************" << endl;
	cout << "*************2.�鿴�����¼**************" << endl;
	cout << "*************3.��ձ�����¼**************" << endl;
	cout << "*************0.�˳���������**************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//��ʼ����Ա����
void SpeechManager::initSpeech() {
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	//��ʼ������
	this->count = 1;
}

//��ʼ������12��ѡ��
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i) {
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker speaker;
		speaker.name = name;//��ʼ������
		for (int j = 0; j < 2; ++j) speaker.score[j] = 0;//��ʼ������
		this->v1.push_back(i + 10001);//��ʼ��ѡ�ֱ�� ������v1������
		this->m_Speaker.insert(make_pair(i + 10001, speaker));//��ʼ��ѡ����Ϣ ������map������
	}
}

//�����������̵ĺ��Ŀ��ơ�����ʼ����
void SpeechManager::startSpeech() {
	//��һ�ֱ���
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ�������


	//�ڶ��ֱ���
	//1.��ǩ


	//2.����



	//3.��ʾ���ս��


	//4.�������



}

//�˳�ϵͳ
void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��������
SpeechManager::~SpeechManager() {

}

//��ǩ
void SpeechManager::speechDraw() {
	cout << "�� << " << this->count << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->count == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) cout << *it << " ";//����ݽ�shuffle����ݽ�˳��
		cout << endl;
	} else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) cout << *it << " ";
		cout << endl;
	}
	cout << "-----------------------" << endl;
	system("pause");
}

//���б���
void SpeechManager::speechContest() {
	cout << "--------------��" << this->count << "�ֱ�����ʽ��ʼ��------------" << endl;
	multimap<double, int, greater<double>> groupScore;//��ʱ���� ���ڱ���key:���� value:ѡ�ֱ��
	int num = 0;//��¼��Ա�� 6��Ϊ1��
	
	//��������Ա����
	vector<int> src;
	if (this->count == 1) {
		src = v1;
	} else {
		src = v2;
	}

	//�������еĲ���ѡ��
	for (vector<int>::iterator it = src.begin(); it != src.end(); ++it) {
		num++;
		//��ί���
	}
}





