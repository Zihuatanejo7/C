#define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
using namespace std;
# include <deque>

// deque 的构造函数
//打印数据
void myPrint(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout<<*it<<"  ";
	}
	cout << endl;
}

void test01()
{
	// 默认构造
	deque<int> d1;
	cout << "d1 = ";
	myPrint(d1);

	// 构造2  填充
	deque<int>d2(10,100);
	cout << "d2 = ";
	myPrint(d2);

	// push 构造
	deque<int>d3;
	for (int i = 0; i < 10; i++)
	{
		d3.push_back(2 * i);
	}
	cout << "d3 = ";
	myPrint(d3);

	// 拷贝构造1
	deque<int>d4(d3.begin()+1,d3.end()-1);
	cout << "d4 = ";
	myPrint(d4);

	// 拷贝构造2
	deque<int>d5(d4);
	cout << "d5 = ";
	myPrint(d5);
}

// deque  赋值
void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	// operator=   运算符重载
	deque<int>d2 = d1;
	cout << "d2 = ";
	myPrint(d2);

	// assign  1
	deque<int>d3;
	d3.assign(d2.begin() + 1, d2.end() - 1);
	cout << "d3 = ";
	myPrint(d3);
	
	// assign 2
	deque<int>d4;
	d4.assign(10, 100);
	cout << "d4 = ";
	myPrint(d4);
}

// empty() size()  resize()
void test03()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	int ret = d1.empty();
	if (!ret)
	{
		cout<<"d1不为空" << endl;
	}
	else
	{
		cout << "d1为空" << endl;
	}
	cout << "d1 大小为:" << d1.size() << endl;

	// 对d1进行尺寸调整   大了 用默认值(这里是10)填充 小了就保存d1中的前x个数据
	d1.resize(d1.size() + 10,10);
	cout << "d1 = ";
	myPrint(d1);

	d1.resize(5);
	cout << "d1 = ";
	myPrint(d1);
}

// 插入 insert  删除erase
void test04()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	// 尾部插入
	d1.push_back(1111111);
	cout << "d1 = ";
	myPrint(d1);
	// 头部插入
	d1.push_front(111111);
	cout << "d1 = ";
	myPrint(d1);
	//尾部删除
	d1.pop_back();
	cout << "d1 = ";
	myPrint(d1);
	//头部删除
	d1.pop_front();
	cout << "d1 = ";
	myPrint(d1);

	// 插入1  ：插入单个元素
	d1.insert(d1.begin(), 111);
	cout << "d1 = ";
	myPrint(d1);

	// 插入2： 填充n个元素
	deque<int>d2 = d1;
	d2.insert(d2.begin() + 1, 3, 555);
	cout << "d2 = ";
	myPrint(d2);

	// 插入3：在d3的begin()位置  放入d1
	deque<int>d3 = d2;
	d3.insert(d3.begin(), d1.begin(), d1.end());
	cout << "d3 = ";
	myPrint(d3);

	d3.erase(d3.begin());
	cout << "d3 = ";
	myPrint(d3);

	// 删除d3的全部元素
	d3.erase(d3.begin(), d3.end());
	cout << "d3 = ";
	myPrint(d3);

	d3.clear();
}

//数据读取   []  at()  front()  back()
void test05()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	cout << "第一个元素为:" << d1[0] << endl;
	cout << "第一个元素为:" << d1.at(0) << endl;
	cout << "第一个元素为:" << d1.front() << endl;
	cout << "最后一个元素为:" << d1.back() << endl;
}

int main()
{
	//test01();

	//test02();

	//test03();

	//test04();

	test05();
	system("pause");
	return 0;
}