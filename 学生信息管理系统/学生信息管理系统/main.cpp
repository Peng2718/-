#include <iostream>
#include "System.hpp"
#include "data.hpp"
#include <vector>
#include <algorithm>
using namespace std;
int user_input = -1;
System sys;
DataList L;
int main() {
	L.load_data(); //加载之前已有的数据
	while (sys.is_run()) { //判断程序是否结束
		if (sys.get_state() == Menu) {
			system("cls");//清屏
			sys.menu();
			while (1) {
				cin >> user_input; //切换功能页面
				if (user_input == 0) {
					sys.close();
					break;
				}
				if (user_input == 1) {
					sys.set_state(req_add);
					break;
				}
				if (user_input == 2) {
					sys.set_state(req_find);
					break;
				}
				if (user_input == 3) {
					sys.set_state(req_change);
					break;
				}
				if (user_input == 4) {
					sys.set_state(syssort);
					break;
				}
				if (user_input == 5) {
					sys.set_state(req_del);
					break;
				}
				if (user_input == 6) {
					sys.set_state(show);
					break;
				}
			}
		}
		if (sys.get_state() == req_add) {
			system("cls");
			while (1) {
				cout << "输入学生学号：" << endl;
				int id;
				cin >> id;
				cout << "输入姓名：" << endl;
				string name;
				cin >> name;
				cout << "输入成绩：" << endl;
				int score;
				cin >> score;
				Student stu = sys.build(name, score, id); //创建学生对象
				stu.stortage(stu); //将学生对象的信息写入数据库
				L.add_data(stu); //将学生的信息加入程序运行时的链表里
				cout << "是否继续添加？是：1 否：0" << endl;
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {//判断是否结束
					sys.set_state(Menu);
					break;
				}
			}
		}
		if (sys.get_state() == req_find) {
			system("cls");
			while (1) {
				cout << "输入要查询的学生的学号：" << endl;
				int id;
				cin >> id;
				list<Student> List = L.get();//创建一个副本来查询数据
				auto it = List.begin();
				while (it!=List.end()) {
					if (id == (*it).get_id()) { //利用id匹配目标
						break;
					}
					it++;
				}
				if (it == List.end()) {
					cout << "没有找到" << endl;
				}
				else {
					(*it).show_data();
				}
				cout << "是否继续查询？是：1 否：0" << endl;
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {
					sys.set_state(Menu);
					break;
				}
			}
		}
		if (sys.get_state() == req_change) {
			system("cls");
			list<Student> List = L.get();
			int Count_Num = 0;//记录迭代器迭代次数
			while (1) {
				cout << "输入要修改的学生学号：" << endl;
				int id;
				Count_Num = 0;//每次修改重置次数
				cin >> id;
				auto it = List.begin();
				while (it != List.end()) {
					if (id == (*it).get_id()) {
						break;
					}
					it++;
					Count_Num++;
				}
				if (it == List.end()) {
					cout << "没有找到要修改的学生" << endl;
				}
				else {
					cout << "已找到，输入要修改的数据" << endl;
					cout << "学号：";
					int id2;
					cin >> id2;
					cout << "姓名：";
					string name;
					cin >> name;
					cout << "成绩：";
					int score;
					cin >> score;
					Student stu(name, score, id2);
					L.change_data(Count_Num,stu);
					cout << "已修改" << endl;
				}
				cout << "是否继续修改？是：1 否：0" << endl;
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {
					sys.set_state(Menu);
					break;
				}
			}
		}
		if (sys.get_state() == req_del) {
			system("cls");
			list<Student> List = L.get();//通过副本来找到删除的位置，而不能通过副本删除
			int Count_Num = 0;
			while (1) {
				cout << "输入要删除的学生学号：" << endl;
				int id;
				Count_Num = 0;
				cin >> id;
				auto it = List.begin();
				while (it != List.end()) {
					if (id == (*it).get_id()) {
						break;
					}
					it++;
					Count_Num++;
				}
				if (it == List.end()) {
					cout << "没有找到要删除的学生" << endl;
				}
				else {
					L.del_data(Count_Num);
					cout << "已删除" << endl;
				}
				cout << "是否继续删除？是：1 否：0" << endl;
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {
					sys.set_state(Menu);
					break;
				}
			}
		}
		if (sys.get_state() == syssort) {
			system("cls");
			list<Student> List = L.get();
			List.sort(compare); //STL算法，排序
			int i = 1;
			for (auto it = List.begin(); it != List.end(); it++) {
				cout << "第" <<i<< "名" << " " << (*it).get_name() << endl;
				i++;
			}
			cout << "退出：0" << endl;
			while (1) {
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {
					sys.set_state(Menu);
					break;
				}
			}
		}
		if (sys.get_state() == show) {
			system("cls");
			L.show();
			cout << "退出：0" << endl;
			while (1) {
				int is_goon = 1;
				cin >> is_goon;
				if (is_goon == 0) {
					sys.set_state(Menu);
					break;
				}
			}
		}
	}
	system("cls");
	cout << "谢谢使用！感谢支持！" << endl;
	return 0;
}

//废弃代码
//vector<int> score;
//for (int i = 0; i < List.size(); i++) {
//	auto it = List.begin();
//	score.push_back((*it).get_score());
//	it++;
//}
//sort(score.begin(), score.end());
//score.reserve(score.size());
//auto dis = distance(List.begin(), it);
//List.erase(it);
//auto it2 = List.begin();
//for (int i = 0; i < dis; i++) {
//	it2++;
//}
//List.insert(it2, stu);
//list<Student> List = L.get();
			/*for (auto it = List.begin(); it != List.end(); it++) {
				(*it).show_data();
				cout << endl;
			}*/