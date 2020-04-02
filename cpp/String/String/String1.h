#pragma once
#include<assert.h>
#include<cstring>
//模拟实现string类的传统写法
class String_1 {
public:
	String_1(const char* str = "") {
		assert(str != nullptr);
		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
	}
	String_1(const String_1& s)
	:_str(new char[strlen(s._str)+1]){
		strcpy(_str, s._str);
	}
	String_1& operator=(const String_1& s) {
		if (this != &s) {
			char* temp = new char[strlen(s._str)+1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}
	~String_1() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};