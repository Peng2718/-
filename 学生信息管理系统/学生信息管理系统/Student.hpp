#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
private:
	int age = 18;//默认大一
	int id;
	string name;
	int score;
public:
	Student(string name,int score,int id);
	int get_id();
	const string& get_name();
	int get_score();
	void stortage(Student stu);  //将学生信息存到数据库中
	void show_data();  //显示信息
};
//bool operator>(Student stu1, Student stu2);
#endif // !STUDENT_H
