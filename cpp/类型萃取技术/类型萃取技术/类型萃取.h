#pragma once
// ������������ 
struct TrueType {
	static bool Get()
	{
		return true;
	}
};
// �����Զ������� 
struct FalseType {
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;//�ṹ��typedef��������
};

// ... �����������Ͷ��ػ�һ��
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