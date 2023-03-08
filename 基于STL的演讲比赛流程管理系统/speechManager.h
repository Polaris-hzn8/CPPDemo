#pragma once//防止头文件重复编译/重复包含
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

//设计演讲比赛的管理类
class SpeechManager {
public:
	//构造函数
	SpeechManager();
	//显示菜单
	void showMenu();
	//初始化成员属性
	void initSpeech();
	//初始化创建12名选手
	void createSpeaker();
	//整个比赛流程的核心控制——开始比赛
	void startSpeech();
	//退出系统
	void exitSystem();
	//析构函数
	~SpeechManager();

	//抽签
	void speechDraw();
	//进行比赛
	void speechContest();

	//成员属性
	vector<int> v1;//保存第一轮比赛选手编号的容器
	vector<int> v2;//保存第一轮晋级选手编号的容器
	vector<int> victory;//保存胜出前三名选手编号的容器
	map<int, Speaker> m_Speaker;//存放编号以及对应选手的容器
	int count;//存放比赛的轮数
};


