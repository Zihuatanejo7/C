#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <vector>

// vector�Ǵ�С�ɱ�������������� ���������飩
// vector��Ĺ��캯��
void myPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

// ���캯��
void test01()
{
	// Ĭ�Ϲ��캯��
	vector<int> v1;
	cout << "v1 = ";
	myPrint(v1);

	// (num ,val)   para1����Ŀ  para2��ֵ  
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

	// ��v3�ĵ�һ��Ԫ�ص����һ����v4
	vector<int>v4(v3.begin(), v3.end());
	cout << "v4 = ";
	myPrint(v4);
	
	// �������캯��
	vector<int>v5(v4);
	cout << "v5 = ";
	myPrint(v5);
}

// ��ֵ
void test02()
{
	//��������� = 
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
	

	//assign����Ա����
	vector<int>v3;
	v3.assign(v2.begin() + 1, v2.end() - 1);
	cout << "v3 = ";
	myPrint(v3);

	vector <int>v4;
	v4.assign(10, 5);
	cout << "v4 = ";
	myPrint(v4);
}

// vector ����  ��С  empty()  capacity() size) 
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
		cout << "v1�ǿ�����"<<endl;
	}
	else
	{
		cout << "v1���ǿ�����";
	}
	
	cout << "v1��СΪ = " << v1.size()<<endl;
	cout << "v1����Ϊ = " << v1.capacity() << endl;

	v1.resize(10);
	cout << "v1 = ";
	myPrint(v1);
	cout << "v1��СΪ = " << v1.size() << endl;
	
	v1.resize(20,5);    // �������С��(��)��20   �����Ļ���5����
	cout << "v1 = ";
	myPrint(v1);
	cout << "v1��СΪ = " << v1.size() << endl;
}

// ����Ĳ��� insert ��ɾ�� erase
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 = ";
	myPrint(v1);


	// ���뵥һԪ��
	v1.insert(v1.begin()+1, 555);
	cout << "v1 = ";
	myPrint(v1);

	// ����n��Ԫ��
	v1.insert(v1.begin() + 1, 3, 666);
	cout << "v1 = ";
	myPrint(v1);

	// ��������vector��һ����Χ
	vector <int>v2(30, 1);
	v2.insert(v2.begin(), v1.begin(), v1.end());
	cout << "v2 = ";
	myPrint(v2);

	// ɾ��
	// ɾ��ָ��λ��
	vector<int>v3(10, 2);
	v3.insert(v3.begin(), 5);
	cout << "v3 = ";
	myPrint(v3);
	v3.erase(v3.begin());
	cout << "v3 = ";
	myPrint(v3);

	// ɾ����Χ
	v3.erase(v3.begin()+1, v3.end());
	cout << "v3 = ";
	myPrint(v3);

	v3.erase(v3.begin(), v3.end());   //ɾ��ȫ��Ԫ��
	v3.clear();
}

// ����Ԫ�صĴ�ȡ �� ��vector�����е����ݽ��д�ȡ
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

	// ����ĵ�һ��Ԫ��
	cout <<"����ĵ�һ��Ԫ��Ϊ:" << v1.front() << endl;

	// ����ĵڶ���Ԫ��Ϊ
	cout << "��������һ��Ԫ��Ϊ:" << v1.back() << endl;
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