#include<iostream>
#include"Queue.h"
using namespace std;

int main()
{
	// 适配体现在第二个模板参数可以使用不同的容器,然后适配生成的queue效果是一样的。 //Queue<int, deque<int>> q;
	//Queue<int, list<int>> q;
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Pop();
	q.Pop();
	cout << q.Size() << endl;
	cout << q.Front() << endl;
    cout << q.Back() << endl;
}