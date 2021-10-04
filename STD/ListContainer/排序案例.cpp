#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <list>
# include <string>

class Person
{
public:
	Person(string name, int age, double height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

	string m_Name;
	int m_Age;
	double m_Height;
};

bool Age_cmp(Person& p1, Person& p2)
{
	if (p1.m_Age > p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Height_cmp(Person& p1, Person& p2)
{
	if (p1.m_Height > p2.m_Height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Name_cmp(Person& p1, Person& p2)
{
	if (p1.m_Name.compare(p2.m_Name) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test()
{
	// 创建几个对象
	Person p1("liubei", 33, 175.0);
	Person p2("guanyu", 28, 190.0);
	Person p3("zhangfei", 25, 169.0);
	Person p4("zhaoyun", 27, 177.0);
	Person p5("machao", 45, 173.0);

	list<Person> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) 
	{
		cout << "姓名： " << it->m_Name 
			<< " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
	cout << "*******************************" << endl;
	// L.sort(Age_cmp);     年龄排序
	// L.sort(Height_cmp);    身高排序
	L.sort(Name_cmp);        // 名字排序
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name
			<< " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
}


int main()
{
	test();
	system("pause");
	return 0;
}