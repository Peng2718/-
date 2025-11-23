#include "System.hpp"
#include <functional>
#include <iostream>
#include <cstdlib>
using namespace std;
System::System() {
	this->isRunning = true;
	this->state = Menu;
}
State System::get_state() {
	return state;
}
void System::set_state(State newstate) {
	state = newstate;
}
bool System::is_run() {
	return isRunning;
}
void System::set_run() {
	isRunning = false;
}
void System::close() {
	set_run();
	set_state(isexit);
}
Student System::build(string name,int score,int id) {
	Student stu(name, score,id);
	return stu;
}
void System::menu() {
	cout << "这是菜单，欢迎来到我制作的管理系统！" << endl;
	cout << "以下功能可供选择！" << endl;
	cout << "1 添加学生信息" << endl;
	cout << "2 查询学生信息" << endl;
	cout << "3 修改学生信息" << endl;
	cout << "4 排名学生成绩" << endl;
	cout << "5 删除学生信息" << endl;
	cout << "6 显示所有学生信息" << endl;
	cout << "0 退出系统" << endl;
}