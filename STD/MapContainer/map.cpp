#define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
using namespace std;
# include <map>

void myPrint(const map<int, int> &m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "  " << "value = " << it->second << endl;
	}
}

// 构造函数
void test01()
{
	map<int,int>m1;
	m1.insert(pair<int, int>(1,10));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(5, 50));
	m1.insert(pair<int, int>(4, 20));
	cout << " m1 :"<<endl;
	myPrint(m1);

	map<int, int>m2(m1.begin(), m1.end());
	cout << " m2 :"<<endl;
	myPrint(m2);

	map<int, int>m3(m2);
	cout << " m3 :" << endl;
	myPrint(m3);
}

// map中的 size  empty  swap
void test02()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(5, 50));
	m1.insert(pair<int, int>(4, 20));
	cout << " m1 :" << endl;
	myPrint(m1);

	if (m1.empty())
	{
		cout << " m1 为空 "<<endl;
	}
	else
	{
		cout << " m1不为空 " << endl;
		cout << " m1 的大小为:" << m1.size() << endl;
	}
	

	map<int, int>m2(m1);
	m2.erase(3);
	cout << " m2 :" << endl;
	myPrint(m2);

	cout << "交换前:" << endl;
	cout << " m1 :" << endl;
	myPrint(m1);
	cout << " m2 :" << endl;
	myPrint(m2);

	m2.swap(m1);
	cout << "交换后:" << endl;
	cout << " m1 :" << endl;
	myPrint(m1);
	cout << " m2 :" << endl;
	myPrint(m2);

}

class MyCmp 
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

// 排序
void test03()
{
	map<int, int, MyCmp>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 10));

	for (map<int, int, MyCmp>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << " key = " << it->first << "  " << "value = " << it->second << endl;
	}
}

int main()
{
	test01();

	//test02();

	//test03();

	system("pause");
	return 0;
}