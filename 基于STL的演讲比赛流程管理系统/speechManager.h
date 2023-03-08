#pragma once//��ֹͷ�ļ��ظ�����/�ظ�����
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

//����ݽ������Ĺ�����
class SpeechManager {
public:
	//���캯��
	SpeechManager();
	//��ʾ�˵�
	void showMenu();
	//��ʼ����Ա����
	void initSpeech();
	//��ʼ������12��ѡ��
	void createSpeaker();
	//�����������̵ĺ��Ŀ��ơ�����ʼ����
	void startSpeech();
	//�˳�ϵͳ
	void exitSystem();
	//��������
	~SpeechManager();

	//��ǩ
	void speechDraw();
	//���б���
	void speechContest();

	//��Ա����
	vector<int> v1;//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int> v2;//�����һ�ֽ���ѡ�ֱ�ŵ�����
	vector<int> victory;//����ʤ��ǰ����ѡ�ֱ�ŵ�����
	map<int, Speaker> m_Speaker;//��ű���Լ���Ӧѡ�ֵ�����
	int count;//��ű���������
};


