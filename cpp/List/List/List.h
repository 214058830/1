#pragma once
// List�Ľڵ��� 
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
List �ķ��������,���������������������պ����෴��,���������++,��������ǰ�ƶ�,������� ��--, �����������ƶ�,��˷������������������������Ļ���֮����ʵ��
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
	// �����������--,���������������++ 
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
	// �����������++,���������������-- 
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
	// List�Ĺ���
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
		// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
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
		// �Ȱ��½ڵ�β���ȥ 
		pNewNode->_pNext = _pHead; 
		pNewNode->_pPre = _pHead->_pPre; // ������ʣ������ָ��
		_pHead->_pPre = pNewNode; 
		pNewNode->_pPre->_pNext = pNewNode;
	}
	// βɾ
	void PopBack() {
		// �ҵ���ɾ���ڵ�
		PNode pDel = _pHead->_pPre; 
		if (pDel != _pHead)
		{
			_pHead->_pPre = pDel->_pPre;
			pDel->_pPre->_pNext = _pHead;
			delete pDel;
		}
	}
	// ͷ��
	void PushFront(const T& val) {
		PNode pNewNode = new Node(val);
		// �Ȱ��½ڵ�β���ȥ 
		pNewNode->_pNext = _pHead->_pNext; 
		pNewNode->_pPre = _pHead;
		// ������ʣ������ָ��
		_pHead->_pNext = pNewNode; 
		pNewNode->_pNext->_pPre = pNewNode;
	}
	// ͷɾ
	void PopFront() {
		// �ҵ���ɾ���ڵ�
		PNode pDel = _pHead->_pNext;
		if (pDel != _pHead)
		{
			_pHead->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = _pHead;
			delete pDel;
		}
	}
	// ��posλ��ǰ����ֵΪval�Ľڵ�
	Iterator Insert(Iterator pos, const T& val) {
		PNode pNewNode = new Node(val); 
		PNode pCur = pos._pNode;
		// �Ƚ��½ڵ����
		pNewNode->_pPre = pCur->_pPre; 
		pNewNode->_pNext = pCur; 
		pNewNode->_pPre->_pNext = pNewNode;
		pCur->_pPre = pNewNode;
		return Iterator(pNewNode);
	}
	// ɾ��posλ�õĽڵ�,���ظýڵ����һ��λ�� 
	Iterator Erase(Iterator pos)
	{
		// �ҵ���ɾ���Ľڵ�
		PNode pDel = pos._pNode;
		PNode pRet = pDel->_pNext;
		// ���ýڵ�������в�������ɾ�� 
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
