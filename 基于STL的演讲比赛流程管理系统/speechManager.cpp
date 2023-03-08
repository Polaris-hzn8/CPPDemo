#include<algorithm>
#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager() {
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
}

//显示菜单
void SpeechManager::showMenu() {
	cout << "****************************************" << endl;
	cout << "************欢迎参加演讲比赛*************" << endl;
	cout << "*************1.开始演讲比赛**************" << endl;
	cout << "*************2.查看往届记录**************" << endl;
	cout << "*************3.清空比赛记录**************" << endl;
	cout << "*************0.退出比赛程序**************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//初始化成员变量
void SpeechManager::initSpeech() {
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	//初始化参数
	this->count = 1;
}

//初始化创建12名选手
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i) {
		string name = "选手";
		name += nameSeed[i];

		Speaker speaker;
		speaker.name = name;//初始化姓名
		for (int j = 0; j < 2; ++j) speaker.score[j] = 0;//初始化分数
		this->v1.push_back(i + 10001);//初始化选手编号 并放入v1容器中
		this->m_Speaker.insert(make_pair(i + 10001, speaker));//初始化选手信息 并放入map容器中
	}
}

//整个比赛流程的核心控制——开始比赛
void SpeechManager::startSpeech() {
	//第一轮比赛
	//1.抽签
	speechDraw();
	//2.比赛
	speechContest();
	//3.显示晋级结果


	//第二轮比赛
	//1.抽签


	//2.比赛



	//3.显示最终结果


	//4.保存分数



}

//退出系统
void SpeechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//析构函数
SpeechManager::~SpeechManager() {

}

//抽签
void SpeechManager::speechDraw() {
	cout << "第 << " << this->count << " >> 轮比赛选手正在抽签" << endl;
	cout << "----------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->count == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) cout << *it << " ";//输出演讲shuffle后的演讲顺序
		cout << endl;
	} else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) cout << *it << " ";
		cout << endl;
	}
	cout << "-----------------------" << endl;
	system("pause");
}

//进行比赛
void SpeechManager::speechContest() {
	cout << "--------------第" << this->count << "轮比赛正式开始：------------" << endl;
	multimap<double, int, greater<double>> groupScore;//临时容器 用于保存key:分数 value:选手编号
	int num = 0;//记录人员数 6个为1组
	
	//比赛的人员容器
	vector<int> src;
	if (this->count == 1) {
		src = v1;
	} else {
		src = v2;
	}

	//遍历所有的参赛选手
	for (vector<int>::iterator it = src.begin(); it != src.end(); ++it) {
		num++;
		//评委打分
	}
}





