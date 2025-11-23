#pragma once
#ifndef DATA_H
#define DATA_H
#include "Student.hpp"
#include <list>
class DataList {
private:
	list<Student> List; //程序运行时储存学生信息的地方
public:
	list<Student>& get();//获得List副本
	void add_data(Student stu);//添加学生信息
	void load_data(); //加载之前数据库中已有的学生信息
	void del_data(int Count_Num); //删除
	void change_data(int Count_Num,Student stu);//修改
	void show();
};
bool compare(Student stu1, Student stu2);//定义sort函数比较规则
#endif // !DATA_H

