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

// ����set
void test01()
{
	//  Ĭ�Ϲ��캯��
	set<int>s1;
	cout << "s1 = ";
	myPrint(s1);

	// ��乹�캯��
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

//  set �Ĵ�С  ����
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	s1.insert(20);
	cout << "s1 = ";
	myPrint(s1);

	cout << "s1��СΪ: " << s1.size() << endl;
	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
	}

	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(400);
	s2.insert(200);
	cout << "s2 = ";
	myPrint(s2);

	cout << "����ǰ��"<<endl;
	cout << "s1 = ";
	myPrint(s1);
	cout << "s2 = ";
	myPrint(s2);

	s2.swap(s1);

	cout << "������"<<endl;
	cout << "s1 = ";
	myPrint(s1);
	cout << "s2 = ";
	myPrint(s2);

}

// set�Ĳ����ɾ��
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

	// ���
	s1.clear();
	cout << "s1 = ";
	myPrint(s1);
}

// ����  ��  ���� �� 0 or 1��
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
		cout << "�ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "û�ҵ�Ԫ��" << endl;
	}

	int num = s1.count(300);
	if (num)
	{
		cout << "set�д�Ԫ��" << endl;
	}
	else 
	{
		cout << "set�޴�Ԫ��" << endl;
	}
}

// set   multiset ����  set ���ɲ����ظ�Ԫ��  multiset:�ɲ����ظ���Ԫ��
void test05()
{
	set<int>s1;
	s1.insert(100);
	pair<set<int>::iterator, bool> ret = s1.insert(100);
	if (ret.second)
	{
		cout << "����ɹ�"<<endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

}

// ����   pair
void test06()
{
	pair<string, int>p1("tom", 15);
	cout << "������ " << p1.first << " ���䣺 " << p1.second << endl;
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

	//Ĭ�ϴ�С����
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//ָ���������
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