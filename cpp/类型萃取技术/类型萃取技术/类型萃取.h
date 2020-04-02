#pragma once
// 代表内置类型 
struct TrueType {
	static bool Get()
	{
		return true;
	}
};
// 代表自定义类型 
struct FalseType {
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;//结构体typedef别名声明
};

// ... 所有内置类型都特化一下
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};			