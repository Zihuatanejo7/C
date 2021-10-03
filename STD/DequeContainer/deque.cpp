#define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
using namespace std;
# include <deque>

// deque �Ĺ��캯��
//��ӡ����
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
	// Ĭ�Ϲ���
	deque<int> d1;
	cout << "d1 = ";
	myPrint(d1);

	// ����2  ���
	deque<int>d2(10,100);
	cout << "d2 = ";
	myPrint(d2);

	// push ����
	deque<int>d3;
	for (int i = 0; i < 10; i++)
	{
		d3.push_back(2 * i);
	}
	cout << "d3 = ";
	myPrint(d3);

	// ��������1
	deque<int>d4(d3.begin()+1,d3.end()-1);
	cout << "d4 = ";
	myPrint(d4);

	// ��������2
	deque<int>d5(d4);
	cout << "d5 = ";
	myPrint(d5);
}

// deque  ��ֵ
void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	// operator=   ���������
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
		cout<<"d1��Ϊ��" << endl;
	}
	else
	{
		cout << "d1Ϊ��" << endl;
	}
	cout << "d1 ��СΪ:" << d1.size() << endl;

	// ��d1���гߴ����   ���� ��Ĭ��ֵ(������10)��� С�˾ͱ���d1�е�ǰx������
	d1.resize(d1.size() + 10,10);
	cout << "d1 = ";
	myPrint(d1);

	d1.resize(5);
	cout << "d1 = ";
	myPrint(d1);
}

// ���� insert  ɾ��erase
void test04()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	// β������
	d1.push_back(1111111);
	cout << "d1 = ";
	myPrint(d1);
	// ͷ������
	d1.push_front(111111);
	cout << "d1 = ";
	myPrint(d1);
	//β��ɾ��
	d1.pop_back();
	cout << "d1 = ";
	myPrint(d1);
	//ͷ��ɾ��
	d1.pop_front();
	cout << "d1 = ";
	myPrint(d1);

	// ����1  �����뵥��Ԫ��
	d1.insert(d1.begin(), 111);
	cout << "d1 = ";
	myPrint(d1);

	// ����2�� ���n��Ԫ��
	deque<int>d2 = d1;
	d2.insert(d2.begin() + 1, 3, 555);
	cout << "d2 = ";
	myPrint(d2);

	// ����3����d3��begin()λ��  ����d1
	deque<int>d3 = d2;
	d3.insert(d3.begin(), d1.begin(), d1.end());
	cout << "d3 = ";
	myPrint(d3);

	d3.erase(d3.begin());
	cout << "d3 = ";
	myPrint(d3);

	// ɾ��d3��ȫ��Ԫ��
	d3.erase(d3.begin(), d3.end());
	cout << "d3 = ";
	myPrint(d3);

	d3.clear();
}

//���ݶ�ȡ   []  at()  front()  back()
void test05()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(2 * i);
	}
	cout << "d1 = ";
	myPrint(d1);

	cout << "��һ��Ԫ��Ϊ:" << d1[0] << endl;
	cout << "��һ��Ԫ��Ϊ:" << d1.at(0) << endl;
	cout << "��һ��Ԫ��Ϊ:" << d1.front() << endl;
	cout << "���һ��Ԫ��Ϊ:" << d1.back() << endl;
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