#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <vector>

// vector是大小可变的数组序列容器 （单端数组）
// vector类的构造函数
void myPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

// 构造函数
void test01()
{
	// 默认构造函数
	vector<int> v1;
	cout << "v1 = ";
	myPrint(v1);

	// (num ,val)   para1：数目  para2：值  
	vector<int> v2(10, 1);
	cout << "v2 = ";
	myPrint(v2);
	

	vector<int> v3;
	for (int i = 0; i < 10; i++)
	{
		v3.push_back(i);
	}
	cout << "v3 = ";
	myPrint(v3);

	// 将v3的第一个元素到最后一个给v4
	vector<int>v4(v3.begin(), v3.end());
	cout << "v4 = ";
	myPrint(v4);
	
	// 拷贝构造函数
	vector<int>v5(v4);
	cout << "v5 = ";
	myPrint(v5);
}

// 赋值
void test02()
{
	//运算符重载 = 
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 = ";
	myPrint(v1);

	vector<int>v2 = v1;
	cout << "v2 = ";
	myPrint(v2);
	

	//assign：成员函数
	vector<int>v3;
	v3.assign(v2.begin() + 1, v2.end() - 1);
	cout << "v3 = ";
	myPrint(v3);

	vector <int>v4;
	v4.assign(10, 5);
	cout << "v4 = ";
	myPrint(v4);
}

// vector 容量  大小  empty()  capacity() size) 
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(2*i);
	}
	cout << "v1 = ";
	myPrint(v1);

	if (v1.empty())
	{
		cout << "v1是空数组"<<endl;
	}
	else
	{
		cout << "v1不是空数组";
	}
	
	cout << "v1大小为 = " << v1.size()<<endl;
	cout << "v1容量为 = " << v1.capacity() << endl;

	v1.resize(10);
	cout << "v1 = ";
	myPrint(v1);
	cout << "v1大小为 = " << v1.size() << endl;
	
	v1.resize(20,5);    // 将数组大小扩(缩)到20   不够的话以5补充
	cout << "v1 = ";
	myPrint(v1);
	cout << "v1大小为 = " << v1.size() << endl;
}

// 数组的插入 insert 和删除 erase
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 = ";
	myPrint(v1);


	// 插入单一元素
	v1.insert(v1.begin()+1, 555);
	cout << "v1 = ";
	myPrint(v1);

	// 插入n个元素
	v1.insert(v1.begin() + 1, 3, 666);
	cout << "v1 = ";
	myPrint(v1);

	// 插入其他vector的一个范围
	vector <int>v2(30, 1);
	v2.insert(v2.begin(), v1.begin(), v1.end());
	cout << "v2 = ";
	myPrint(v2);

	// 删除
	// 删除指定位置
	vector<int>v3(10, 2);
	v3.insert(v3.begin(), 5);
	cout << "v3 = ";
	myPrint(v3);
	v3.erase(v3.begin());
	cout << "v3 = ";
	myPrint(v3);

	// 删除范围
	v3.erase(v3.begin()+1, v3.end());
	cout << "v3 = ";
	myPrint(v3);

	v3.erase(v3.begin(), v3.end());   //删除全部元素
	v3.clear();
}

// 数组元素的存取 ： 对vector数组中的数据进行存取
void test05()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 = ";
	myPrint(v1);

	cout << v1[0] << endl;
	cout << v1.at(2) << endl;

	// 数组的第一个元素
	cout <<"数组的第一个元素为:" << v1.front() << endl;

	// 数组的第二个元素为
	cout << "数组的最后一个元素为:" << v1.back() << endl;
}

void test06()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 = ";
	myPrint(v1);

	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(2*i);
	}
	cout << "v2 = ";
	myPrint(v2);

	v2.swap(v1);
	cout << "v1 = ";
	myPrint(v1);
	cout << "v2 = ";
	myPrint(v2);
}

int main()
{
	// test01();

	//test02();

	//test03();

	//test04();

	//test05();

	test06();

	system("pause");
	return 0;
}