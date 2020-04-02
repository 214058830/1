#pragma once
#include<cstring>
//模拟实现string类的现代写法
class String {
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(nullptr)
	{
		String strTmp(s._str);
		std::swap(_str, strTmp._str);
	}
	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
