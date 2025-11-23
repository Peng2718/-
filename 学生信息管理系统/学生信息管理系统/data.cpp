#include "data.hpp"
#include <fstream>
#include <iostream>
#include <string>
list<Student>& DataList::get() {
	return List;
}
void DataList::add_data(Student stu) {
	List.push_back(stu);
}
void DataList::load_data() {
	ifstream file("Student.txt");
	if (!file.is_open()) {  //判断文件是否正常打开
		cerr << "can not open file" << endl;
		return ;
	}
	string word; //按块读取数据库中的数据（即遇到空格停止）
	while (file>>word) {
		string name;
		int id;
		int score;
		id = stoi(word); //将数据库中以字符串类型存储的id转换成int
		file >> word;
		name = word;
		file >> word;
		score = stoi(word);
		Student stu(name, score, id);//创建一个学生对象
		add_data(stu); //并加入链表
	}
}
void DataList::del_data(int Count_Num) {
	ofstream file("Student.txt");
	if (!file.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	auto it2 = List.begin();
	for (int i=0; ; ) {
		if (i==Count_Num) {  //在指定位置删除数据
			List.erase(it2);  //删除数据
			for (auto it3 = List.begin(); it3 != List.end(); it3++) {
				file << (*it3).get_id() << " " << (*it3).get_name() << " " << (*it3).get_score() << endl;
			}  //操作后重写数据库信息，更新内容
			return;
		}
		i++;
		if (it2 != List.end()) {
			it2++;
		}
		else {
			List.pop_back();//删除链表最后剩下的一个数据
		}
	}
}
void DataList::change_data(int Count_Num,Student stu) {
	ofstream file("Student.txt");
	if (!file.is_open()) {
		cerr << "can not open file" << endl;
		return;
	}
	auto it2 = List.begin();
	for (int i = 0; ; ) {
		if (i == Count_Num) {
			int dis = distance(List.begin(), it2); //获得迭代器的位置
			List.erase(it2);
			auto it4 = List.begin(); //进行删除操作后，旧迭代器不可继续使用
			for (int i = 0; i < dis;i++) { //将该位置赋给新的迭代器
				it4++;
			}
			List.insert(it4, stu); //插入新数据
			for (auto it3 = List.begin(); it3 != List.end(); it3++) {
				file << (*it3).get_id() << " " << (*it3).get_name() << " " << (*it3).get_score() << endl;
			}  //操作后重写数据库信息，更新内容
			return;
		}
		i++;
		if (it2 != List.end()) {
			it2++;
		}
		else {
			cerr << "overflow" << endl;//提醒溢出
		}
	}
}
void DataList::show() {
	for (auto it = List.begin(); it != List.end(); it++) {
		(*it).show_data();
		cout << endl;
	}
}
bool compare(Student stu1, Student stu2) {
	return stu1.get_score() > stu2.get_score();
}

//废弃的代码
//for (auto it2 = List.begin(); it2 != List.end(); it2++) {
//	if (it2 == it) {
//		file << stu.get_id() << " " << stu.get_name() << " " << stu.get_score() << endl;
//		auto dis = distance(List.begin(), it2);
//		List.erase(it2);
//		auto it3 = List.begin();
//		for (int i = 0; i < dis; i++) {
//			it3++;
//		}
//		List.insert(it3, stu);
//		continue;
//	}
//	file << (*it2).get_id() << " " << (*it2).get_name() << " " << (*it).get_score() << endl;
//}
//if (!file1.is_open()) {
//	cerr << "can not open file" << endl;
//	return;
//}
//for (int i = 0; i < index; i++) {
//
//}
//file1.close();
//ifstream file2("Student.txt");
//if (!file2.is_open()) {
//	cerr << "can not open file" << endl;
//	return;
//}
//if (movetoLine(file2, index + 1)) {
//	file2.close();
//	ofstream file3("Student.txt");
//	if (!file3.is_open()) {
//		cerr << "can not open file" << endl;
//		return;
//	}
//	for (int i = 0; i < List.size() - index - 1; i++) {
//
//	}
//}
//bool movetoLine(ifstream& file, int lineNum) {
//	if (lineNum < 0) {
//		cerr << "lineNum Error" << endl;
//		return false;
//	}
//	string line;
//	for (int i = 0; i < lineNum; i++) {
//		if (!getline(file, line)) {
//			return false;
//		}
//	}
//	return true;
//}
//	int index = distance(List.begin(), it);
//	ofstream file("Student.txt");
//	for (int i = 0; i < List.size(); i++) {
//		if (i == index + 1) {
//			continue;
//		}
//		file <<
//	}
//}