#pragma once
#include<deque>

template<class T, class Con = deque<T>>
class Stack
{
public:
	Stack() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_back(); }
	T& Top() { return _c.back(); }
	const T& Top()const { return _c.back(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};