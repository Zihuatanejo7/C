#define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
using namespace std;
# include <queue>

// queue: һͷ��  һͷ��  
void test()
{
	queue<int> q;
	q.push(10); 
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	while (!q.empty())
	{
		cout << "���д�СΪ:"<<q.size() << endl;
		cout << q.front() << endl;
		q.pop();
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}