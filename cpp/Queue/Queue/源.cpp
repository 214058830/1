#include<iostream>
#include"Queue.h"
using namespace std;

int main()
{
	// ���������ڵڶ���ģ���������ʹ�ò�ͬ������,Ȼ���������ɵ�queueЧ����һ���ġ� //Queue<int, deque<int>> q;
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