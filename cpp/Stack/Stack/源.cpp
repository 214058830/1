#include <iostream>
#include"Stack.h"
using namespace std;

int main(){
	// ���������ڵڶ���ģ���������ʹ�ò�ͬ������,Ȼ���������ɵ�stackЧ����һ���ġ� //Stack<int, deque<int>> s;
	//Stack<int, vector<int>> s;
	//Stack<int, list<int>> s;
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Size() << endl;
	cout << s.Top() << endl;
	s.Pop();
	s.Pop();
	cout << s.Size() << endl;
	cout << s.Top() << endl;
	return 0;
}