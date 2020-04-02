#include "List.h"
#include<vector>
#include<iostream>
using namespace std;

// 正向打印链表
template<class T>
void PrintList(List<T>& l) {
	auto it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
// 反向打印链表
template<class T>
void PrintListReverse(const List<T>& l) {
	auto it = l.CRBegin();
	while (it != l.CREnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestList1() {
	List<int> l1;
	List<int> l2(10, 5);
	PrintList(l2);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	List<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);
	List<int> l4(l3);
	PrintList(l4);
	l1 = l4;
	PrintList(l1);
	PrintListReverse(l1);
}