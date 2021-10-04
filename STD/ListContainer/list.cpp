#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <list>

// list的构造函数
void myPrint(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it<<"  ";
	}
	cout << endl;
}

void test01()
{
	// 默认构造函数
	list<int> L1;
	cout << "L1 = ";
	myPrint(L1);

	// 3个默认值
	list<int>L2(3);
	cout << "L2 = ";
	myPrint(L2);

	// 
	list<int>L3(10,5);
	cout << "L3 = ";
	myPrint(L3);

	list<int>L4(L3.begin(),L3.end());
	cout << "L4 = ";
	myPrint(L4);


	list<int>L5(L4);
	cout << "L5 = ";
	myPrint(L5);
}

// list中的赋值操作
void test02()
{
	list<int>L1;
	for (int i = 0; i < 10; i++)
	{
		L1.push_back(2 * i);
	}
	cout << "L1 = ";
	myPrint(L1);

	list<int>L2;
	L2.assign(L1.begin(), L1.end());
	cout << "L2 = ";
	myPrint(L2);

	list<int>L3 = L2;
	cout << "L3 = ";
	myPrint(L3);

	list<int>L4(10,55);
	L4.swap(L3);
	cout << "L3 = ";
	myPrint(L3);
	cout << "L4 = ";
	myPrint(L4);
}

// 大小操作    empty() size()   resize()   
void test03()
{
	list<int>L1;
	for (int i = 0; i < 10; i++)
	{
		L1.push_back(2 * i);
	}
	cout << "L1 = ";
	myPrint(L1);

	cout << "L1的大小为:" << L1.size() <<endl;

	L1.resize(20);
	cout << "L1 = ";
	myPrint(L1);

	L1.resize(5);
	cout << "L1 = ";
	myPrint(L1);
}


// 插入 删除   push pop insert erase  remove
void test04()
{
	list<int>L1;
	for (int i = 0; i < 10; i++)
	{
		L1.push_back(2 * i);
	}
	cout << "L1 = ";
	myPrint(L1);

	// 表尾插入222
	L1.push_back(222);
	cout << "L1 = ";
	myPrint(L1);

	// 表头插入222
	L1.push_front(222);
	cout << "L1 = ";
	myPrint(L1);

	// 指定位置 插入单个元素
	list<int>::iterator it = L1.begin();
	L1.insert(++it,333);
	cout << "L1 = ";
	myPrint(L1);

	L1.insert(it, 3,444);
	cout << "L1 = ";
	myPrint(L1);

	list<int>L2 = L1;
	it = L2.begin();
	L2.insert(it, L1.begin(), L1.end());
	cout << "L2 = ";
	myPrint(L2);

	// 删除元素
	L2.pop_back();
	L2.pop_front();

	
	L2.erase(L2.begin(), L2.end());
	cout << "L2 = ";
	myPrint(L2);

	//删除链表中的55
	L2.remove(55);

	L2.clear();

}

// 随机存取
void test05()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;
}

// 反转  排序
bool cmp (int val1, int val2)
{
	return val1 > val2;
}


void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(40);
	L1.push_back(90);
	L1.push_back(70);
	cout << "L1 = ";
	myPrint(L1);

	L1.reverse();
	cout << "L1 = ";
	myPrint(L1);

	L1.sort();
	cout << "L1 = ";
	myPrint(L1);


	L1.sort(cmp);
	cout << "L1 = ";
	myPrint(L1);
}

//int main()
//{
//	// test01();
//
//	//test02();
//
//	// test03();
//
//	//test04();
//
//	//test05();
//
//	test06();
//
//	system("pause");
//	return 0;
//}