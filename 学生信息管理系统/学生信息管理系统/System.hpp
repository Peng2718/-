#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include "Student.hpp"
using namespace std;
enum State //系统的状态界面
{
	Menu ,req_add ,req_find ,req_change ,req_del ,syssort ,show ,isexit
};
class System {
private:
	bool isRunning; //运行与否
	State state; //状态
public:
	State get_state(); 
	bool is_run(); 
	void close(); //关闭菜单界面
	void set_run(); 
	void set_state(State newstate); 
	Student build(string name,int score,int id); 
	void menu(); //显示菜单
	System();
};
#endif // !SYSTEM_H
