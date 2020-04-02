#include <iostream>
#include"Stack.h"
using namespace std;

int main(){
	// 适配体现在第二个模板参数可以使用不同的容器,然后适配生成的stack效果是一样的。 //Stack<int, deque<int>> s;
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