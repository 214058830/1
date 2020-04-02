#pragma once
// 代表内置类型
struct __true_type {};
// 代表自定义类型
struct __false_type {};
template <class type>
struct __type_traits
{
	typedef __false_type is_POD_type;
};
// 对所有内置类型进行特化 
template<>
struct __type_traits<char> {
	typedef __true_type    is_POD_type;
};
template<>
struct __type_traits<signed char>
{
	typedef __true_type    is_POD_type;
};
template<>
struct __type_traits<unsigned char>
{
	typedef __true_type    is_POD_type;
};
template<>
struct __type_traits<int>
{
	typedef __true_type    is_POD_type;
};
template<>
struct __type_traits<float>
{
	typedef __true_type    is_POD_type;
};
template<>
struct __type_traits<double>
{
	typedef __true_type    is_POD_type;
};
template<class T>
void _copy(T* dst, T* src, size_t n, __true_type)
{
	memcpy(dst, src, n*sizeof(T));
}
template<class T>
void _copy(T* dst, T* src, size_t n, __false_type)
{
	for (size_t i = 0; i < n; ++i)
		dst[i] = src[i];
}
template<class T>
void Copy(T* dst, T* src, size_t n)
{
	_copy(dst, src, n, __type_traits<T>::is_POD_type());
}