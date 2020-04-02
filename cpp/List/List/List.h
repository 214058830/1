#pragma once
// List的节点类 
template<class T> struct ListNode {
ListNode(const T& val = T())
	: _pPre(nullptr)
	, _pNext(nullptr)
	, _val(val)
	{}
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _val;
};
template<class T, class Ref, class Ptr>
class ListIterator
{
	typedef ListNode<T>* PNode;
	typedef ListIterator<T, Ref, Ptr> Self;
public:
	ListIterator(PNode pNode = nullptr)
		: _pNode(pNode)
	{}
		ListIterator(const Self& l)
		: _pNode(l._pNode)
	{}
	T& operator*()
	{
		return _pNode->_val;
	}
	T* operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		_pNode = _pNode->_pNext;
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		_pNode = _pNode->_pNext;
		return temp;
	}
	bool operator!=(const Self& l)
	{
		return _pNode != l._pNode;
	}
	bool operator==(const Self& l)
	{
		return _pNode == l._pNode;
	}
	PNode _pNode;
};
/*
List 的反向迭代器,反向迭代器与正向迭代器刚好是相反的,反向迭代器++,迭代器往前移动,反向迭代 器--, 迭代器往后移动,因此反向迭代器可以在正向迭代器的基础之上来实现
*/
template<class T, class Ref, class Ptr, class Iterator>
class ListReverseIterator
{
	typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
public:
	ListReverseIterator(const Iterator& it)
		: _it(it)
	{}
		ListReverseIterator(const Self& s)
		: _it(s._it)
	{}
	T& operator*()
	{
		return *_it;
	}
	Ptr operator->()
	{
		return &operator*();
	}
	// 反向迭代器的--,就是正向迭代器的++ 
	Self& operator--()
	{
		++_it;
		return *this;
	}
	Self operator--(int)
	{
		Iterator temp(_it);
		++_it;
		return temp;
	}
	// 反向迭代器的++,就是正向迭代器的-- 
	Self& operator++()
	{
		--_it;
		return *this;
	}
	Self operator++(int)
	{
		Iterator temp(_it);
		--_it;
		return temp;
	}
	
	bool operator!=(const Self& s)
	{
		return _it != s._it;
	}
	bool operator==(const Self& s)
	{
		return _it == s._it;
	}
private:
	Iterator _it;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
	typedef Node* PNode;
public:
	typedef ListIterator<T, T&, T*> Iterator;
	typedef ListIterator<T, const T&, const T&> ConstIterator;
	typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
	typedef ListReverseIterator<T, const T&, const T*, ConstIterator>
		ConstReverseIterator;
public:
	///////////////////////////////////////////////////////////////
	// List的构造
	List()
	{
		CreateHead();
	}
	List(int n, const T& value = T())
	{
		CreateHead();
		for (int i = 0; i < n; ++i)
			PushBack(value);
	}
	template <class Iterator>
	List(Iterator first, Iterator last)
	{
		CreateHead();
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}
	List(const List<T>& l)
	{
		CreateHead();
		// 用l中的元素构造临时的temp,然后与当前对象交换
		List<T> temp(l.CBegin(), l.CEnd());
		this->Swap(temp);
	}
	List<T>& operator=(const List<T>& l)
	{
		if (this != &l)
		{
			List<T> temp(l);
			this->Swap(temp);
		}
		return *this;
	}
	~List() {
		Clear();
		delete _pHead;
		_pHead = nullptr;
	}
	///////////////////////////////////////////////////////////////
	// List Iterator
	Iterator Begin()
	{
		return Iterator(_pHead->_pNext);
	}
	Iterator End()
	{
		return Iterator(_pHead);
	}
	ReverseIterator RBegin()
	{
		return ReverseIterator(_pHead->_pPre);
	}
	ReverseIterator REnd()
	{
		return ReverseIterator(_pHead);
	}
	ConstIterator CBegin()const
	{
		return ConstIterator(_pHead->_pNext);
	}
	ConstIterator CEnd()const
	{
		return ConstIterator(_pHead);
	}
	ConstReverseIterator CRBegin()const
	{
		return ConstReverseIterator(_pHead->_pPre);
	}
	ConstReverseIterator CREnd()const
	{
		return ConstReverseIterator(-_pHead);
	}
	///////////////////////////////////////////////////////////////
	// List Capacity
	size_t Size()const
	{
		size_t count = 0;
		PNode pCur = _pHead->_pNext;
		while (pCur != _pHead)
		{
			++count;
			pCur = pCur->_pNext;
		}
		return count;
	}
	bool Empty()const
	{
		return _pHead->_pNext == _pHead;
	}
	void ReSize(size_t newSize, const T& val = T())
	{
		size_t oldSize = Size();
		if (oldSize <= newSize)
		{
			for (size_t i = oldSize; i < newSize; ++i)
				PushBack(val);
		}
		else
		{
			for (size_t i = newSize; i < oldSize; ++i)
				PopBack();
		}
	}
	////////////////////////////////////////////////////////////
	// List Access
	T& Front()
	{
		return _pHead->_pNext->_val;
	}
	const T& Front()const
	{
		return _pHead->_pNext->_val;
	}
	T& Back()
	{
		return _pHead->_pPre->_val;
	}
	const T& Back()const
	{
		return _pHead->_pPre->_val;
	}
	////////////////////////////////////////////////////////////
	// List Modify
	void PushBack(const T& val)
	{
		PNode pNewNode = new Node(val);
		// 先把新节点尾插进去 
		pNewNode->_pNext = _pHead; 
		pNewNode->_pPre = _pHead->_pPre; // 再链接剩余两个指针
		_pHead->_pPre = pNewNode; 
		pNewNode->_pPre->_pNext = pNewNode;
	}
	// 尾删
	void PopBack() {
		// 找到待删除节点
		PNode pDel = _pHead->_pPre; 
		if (pDel != _pHead)
		{
			_pHead->_pPre = pDel->_pPre;
			pDel->_pPre->_pNext = _pHead;
			delete pDel;
		}
	}
	// 头插
	void PushFront(const T& val) {
		PNode pNewNode = new Node(val);
		// 先把新节点尾插进去 
		pNewNode->_pNext = _pHead->_pNext; 
		pNewNode->_pPre = _pHead;
		// 再链接剩余两个指针
		_pHead->_pNext = pNewNode; 
		pNewNode->_pNext->_pPre = pNewNode;
	}
	// 头删
	void PopFront() {
		// 找到待删除节点
		PNode pDel = _pHead->_pNext;
		if (pDel != _pHead)
		{
			_pHead->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = _pHead;
			delete pDel;
		}
	}
	// 在pos位置前插入值为val的节点
	Iterator Insert(Iterator pos, const T& val) {
		PNode pNewNode = new Node(val); 
		PNode pCur = pos._pNode;
		// 先将新节点插入
		pNewNode->_pPre = pCur->_pPre; 
		pNewNode->_pNext = pCur; 
		pNewNode->_pPre->_pNext = pNewNode;
		pCur->_pPre = pNewNode;
		return Iterator(pNewNode);
	}
	// 删除pos位置的节点,返回该节点的下一个位置 
	Iterator Erase(Iterator pos)
	{
		// 找到待删除的节点
		PNode pDel = pos._pNode;
		PNode pRet = pDel->_pNext;
		// 将该节点从链表中拆下来并删除 
		pDel->_pPre->_pNext = pDel->_pNext;
		pDel->_pNext->_pPre = pDel->_pPre; 
		delete pDel;
		return Iterator(pRet);
	}
	void Clear()
	{
		PNode pCur = _pHead->_pNext;
		while (pCur != _pHead)
		{
			_pHead->_pNext = pCur->_pNext;
			delete pCur;
			pCur = _pHead->_pNext;
		}
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}
	void Swap(List<T>& l)
	{
		swap(_pHead, l._pHead);
	}
private:
	void CreateHead()
	{
		_pHead = new Node;
		_pHead->_pPre = _pHead;
		_pHead->_pNext = _pHead;
	} 
private:
	PNode _pHead;
};
