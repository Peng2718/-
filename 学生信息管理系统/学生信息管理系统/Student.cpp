#include "Student.hpp"
#include <fstream>
#include <iostream>
using namespace std;
Student::Student(string name, int score,int id) :name(name), score(score),id(id) {};
void Student::stortage(Student stu) {
	ifstream file1("Student.txt");  //判断文件是否正常打开
	if (!file1.is_open()) {
		cerr << "can not open file" << endl;
		return ;
	}
	file1.seekg(0, ios::end);  //将文件指针定位到末尾
	file1.close();
	ofstream file2("Student.txt", ios::app);//以追加形式写入数据
	file2 << stu.id << " " << stu.name << " " << stu.score << endl;
	file2.close();
}
int Student::get_id() {
	return id;
}
const string& Student::get_name() {
	return name;
}
int Student::get_score() {
	return score;
}
void Student::show_data() {
	cout <<"学号： "<< id << endl;
	cout <<"姓名： "<< name << endl;
	cout <<"成绩： "<< score << endl;
}
//bool operator>(const Student& stu1, const Student& stu2) {
//	return stu1.get_score() > stu2.get_score();
//}