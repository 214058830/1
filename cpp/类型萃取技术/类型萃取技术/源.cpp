#include<iostream>
#include"类型萃取.h"
#include"STL中类型萃取.h"
using namespace std;
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
void test(int) {
	cout << endl;
}
void test(char*) {
	cout << "1" << endl;
}
int main() {
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int a2[10];
	Copy(a2, a1, 10);
	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy(s2, s1, 4);
	test(5);
	return 0;
}