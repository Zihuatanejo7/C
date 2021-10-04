#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <set>

void myPrint(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout <<*it<< "  ";
	}
	cout << endl;
}

// 构造set
void test01()
{
	//  默认构造函数
	set<int>s1;
	cout << "s1 = ";
	myPrint(s1);

	// 填充构造函数
	set<int>s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(40);
	s2.insert(20);
	cout << "s2 = ";
	myPrint(s2);

	set<int>s3(s2.begin(),s2.end());
	cout << "s3 = ";
	myPrint(s3);

	set<int>s4(s3);
	cout << "s4 = ";
	myPrint(s4);

	set<int>s5= s4;
	cout << "s5 = ";
	myPrint(s5);
}

//  set 的大小  容量
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	s1.insert(20);
	cout << "s1 = ";
	myPrint(s1);

	cout << "s1大小为: " << s1.size() << endl;
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
	}

	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(400);
	s2.insert(200);
	cout << "s2 = ";
	myPrint(s2);

	cout << "交换前："<<endl;
	cout << "s1 = ";
	myPrint(s1);
	cout << "s2 = ";
	myPrint(s2);

	s2.swap(s1);

	cout << "交换后："<<endl;
	cout << "s1 = ";
	myPrint(s1);
	cout << "s2 = ";
	myPrint(s2);

}

// set的插入和删除
void test03()
{
	set<int>s1;
	s1.insert(100);
	s1.insert(300);
	s1.insert(400);
	s1.insert(200);
	cout << "s1 = ";
	myPrint(s1);

	set<int>::iterator it = s1.begin();
	s1.erase(it);
	cout << "s1 = ";
	myPrint(s1);


	s1.erase(500);
	cout << "s1 = ";
	myPrint(s1);

	// 清空
	s1.clear();
	cout << "s1 = ";
	myPrint(s1);
}

// 查找  和  计数 （ 0 or 1）
void test04()
{
	set<int>s1;
	s1.insert(100);
	s1.insert(300);
	s1.insert(400);
	s1.insert(200);
	cout << "s1 = ";
	myPrint(s1);

	set<int>::iterator it = s1.find(100);
	if (it != s1.end())
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "没找到元素" << endl;
	}

	int num = s1.count(300);
	if (num)
	{
		cout << "set有此元素" << endl;
	}
	else 
	{
		cout << "set无此元素" << endl;
	}
}

// set   multiset 区别：  set 不可插入重复元素  multiset:可插入重复的元素
void test05()
{
	set<int>s1;
	s1.insert(100);
	pair<set<int>::iterator, bool> ret = s1.insert(100);
	if (ret.second)
	{
		cout << "插入成功"<<endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}

}

// 对组   pair
void test06()
{
	pair<string, int>p1("tom", 15);
	cout << "姓名： " << p1.first << " 年龄： " << p1.second << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void test07()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	
	//test02();

	//test03();

	//test04();

	//test05();
	
	// test06();

	//test07();

	system("pause");
	return 0;
}