#pragma once
#include<deque>
template<class T, class Con = deque<T>>
class Queue
{
public:
	Queue() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_front(); }
	T& Back() { return _c.back(); }
	const T& Back()const { return _c.back(); }
	T& Front() { return _c.front(); }
	const T& Front()const { return _c.front(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};