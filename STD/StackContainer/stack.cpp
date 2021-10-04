#define _CRT_SECURE_NO_WARNINGS 1

# include <iostream>
using namespace std;
# include <stack>

// stack:   pop  push top size 
void test01()
{
	stack<int>s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);

	cout << "s1大小为:" << s1.size()<<endl;
	while (!s1.empty())
	{
		cout << s1.top() << endl;
		s1.pop();
	}
	cout << "s1大小为:" << s1.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}