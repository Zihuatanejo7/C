#define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
using namespace std;
# include <queue>

// queue: 一头入  一头出  
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
		cout << "队列大小为:"<<q.size() << endl;
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