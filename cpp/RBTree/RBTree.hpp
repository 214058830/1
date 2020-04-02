#pragma once
#include <iostream>
using namespace std;

enum Color{RED, BLACK};
// 红黑树结点结构
template<class V>
struct RBTreeNode
{
	RBTreeNode(const V& data = V(), const Color color = RED)
		: _pLeft(nullptr)
		  , _pRight(nullptr)
		  , _pParent(nullptr)
		  , _data(data)
		  , _color(color)
	{}

	RBTreeNode<V>* _pLeft;
	RBTreeNode<V>* _pRight;
	RBTreeNode<V>* _pParent;
	V _data;
	Color _color;
};

template<class V>
class RBTree
{
	typedef RBTreeNode<V> Node;
	typedef Node* PNode;
	public:
	RBTree()
	{
		_pHead = new Node; // RBTree默认含有的头结点
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
		_pHead->_pParent = nullptr;
	}

	~RBTree()
	{
		_Destroy(GetRoot());
	}

	bool Insert(const V& data)
	{
		PNode& pRoot = GetRoot();
		// 按照二叉搜索树方式插入新结点
		if (nullptr == pRoot)
		{
			// 跟的双亲为头结点
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else
		{
			// 按照二叉搜索树的特性，找结点在红黑树中的插入位置。
			PNode pCur = pRoot;
			PNode pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->_pLeft;
				else if (data > pCur->_data)
					pCur = pCur->_pRight;
				else
					return false;
			}


			// 插入新节点
			pCur = new Node(data);
			if (data < pParent->_data)
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;

			pCur->_pParent = pParent;

			// 更新节点的颜色
			while (pParent != _pHead && RED == pParent->_color)
			{
				PNode grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)
				{
					PNode uncle = grandFather->_pRight;
					// 叔叔节点存在，且为红
					if (uncle && RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else
					{
						// 情况三
						if (pCur == pParent->_pRight)
						{
							RotateL(pParent);
							swap(pCur, pParent);
						}

						// 情况二
						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateR(grandFather);
					}
				}
				else
				{
					PNode uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else
					{
						if (pCur == pParent->_pLeft)
						{
							RotateR(pParent);
							swap(pCur, pParent);
						}

						pParent->_color = BLACK;
						grandFather->_color = RED;
						RotateL(grandFather);
					}
				}
			}
		}
		// 根节点的颜色可以被修改，将其改回黑色。
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost(); // 头结点左指向最左结点
		_pHead->_pRight = RightMost(); // 头结点右指向最右结点
		return true;
	}
	// 中序遍历
	void InOrder()
	{
		_InOrder(GetRoot());
	}

	bool IsRBTRee()
	{
		PNode pRoot = GetRoot();
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;
		// 检查跟节点是否满足
		if (RED == pRoot->_color)
		{
			cout << "违反性质2:根节点的颜色为红色" << endl;
			return false;
		}
		// 获取任意一条路径上的黑色节点个数
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;

			pCur = pCur->_pLeft;
		}
		// 检查是否满足红黑树的性质，pathBlack用来记录路径中黑色节点的个数
		size_t pathBlack = 0;
		return _IsRBTree(pRoot, blackCount, pathBlack);
	}

private:
	PNode& GetRoot() // 获取红黑树根结点
	{
		return _pHead->_pParent;
	}

	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void _Destroy(PNode& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}

	bool _IsRBTree(PNode pRoot, size_t blackCount, size_t pathBlack)
	{
		// 走到null之后，判断blackCout和pathBlack是否相等 
		if (nullptr == pRoot){
			if(blackCount != pathBlack){
				cout << "违反性质4:每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色结点的个数
		if (BLACK == pRoot->_color)
			pathBlack++;

		// 检测当前结点与其双亲是否为红色
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pRoot->_color && RED == pParent->_color)
		{
			cout << "违反性质3:有连在一起的红色节点" << endl;
			return false;
		}

		return _IsRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsRBTree(pRoot->_pRight, blackCount, pathBlack);
	}
	// 获取红黑树中最小结点，即是最左侧结点。
	PNode LeftMost()
	{
		PNode pRoot = GetRoot();
		if (nullptr == pRoot)
			return _pHead;

		PNode pCur = pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}
	// 获取红黑树中最大结点，即是最右侧结点。
	PNode RightMost()
	{
		PNode pRoot = GetRoot();
		if (nullptr == pRoot)
			return _pHead;

		PNode pCur = pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}

	void RotateL(PNode pParent)
	{
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;

		PNode pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		PNode& pRoot = GetRoot();
		if (pRoot == pParent)
		{
			pRoot = pSubR;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
	}

	void RotateR(PNode pParent)
	{
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;
		PNode pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		PNode& pRoot = GetRoot();
		if (pParent == pRoot)
			pRoot = pSubL;
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}

private:
	PNode _pHead;
};

void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	//{ 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : a)
		t.Insert(e);

	t.InOrder();

	if (t.IsRBTRee())
	{
		cout << "t is RBTree" << endl;
	}
	else
	{
		cout << "t not is RBTree" << endl;
	}
}

// 红黑树的迭代器
template<class ValueType, class Ptr, class Ref>
struct RBTreeIterator
{
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
	typedef RBTreeIterator<ValueType, Ptr, Ref> Self;
public:
	RBTreeIterator()
		: _pNode(nullptr)
	{}
	RBTreeIterator(PNode pNode)
		: _pNode(pNode)
	{}
	RBTreeIterator(const Self& s)
		: _pNode(s._pNode)
	{}
	Ref operator*()
	{
		return _pNode->_data;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		Increasement();
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		Increasement();
		return temp;
	}
	Self& operator--()
	{
		Decreasement();
		return *this;
	}
	Self operator--(int)
	{
		Self temp(*this);
		Decreasement();
		return temp;
	}
	bool operator!=(const Self& s)
	{
		return _pNode != s._pNode;
	}
	bool operator==(const Self& s)
	{
		return _pNode == s._pNode;
	}
	// 找迭代器的下一个节点，下一个节点肯定比其大 
	void Increasement()
	{
		/*
		分两种情况讨论:
		1. _pNode的右子树存在 
		2. _pNode的右子树不存在
		*/
		// 1. _pNode的右子树存在，则在右子树中找最小(最左侧)的节点
		if(_pNode->_pRight)
		{
			// 右子树中最小的节点，即右子树中最左侧节点
			_pNode = _pNode->_pRight;
			while(_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
		} 
		// 2. _pNode的右子树不存在，分一般情况和特殊情况。
		else{
			// 向上查找，直到_pNode != pParent->right
			PNode pParent = _pNode->_pParent; 
			while(pParent->_pRight == _pNode){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			// 特殊情况:根节点没有右子树
			if(_pNode->_pRight != pParent)
				_pNode = pParent;
		}
	}
	// 获取迭代器指向节点的前一个节点
	void Decreasement()
	{
		/*
		分三种情况讨论:
		1. _pNode 在head的位置
		2. _pNode 左子树存在
		3. _pNode 左子树不存在
		*/
		// 1.情况
		if(_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			_pNode = _pNode->_pRight;
		// 2.情况
		else if(_pNode->_pLeft)
		{
			_pNode = _pNode->_pLeft;
			while(_pNode->_pRight)
				_pNode = _pNode->_pRight;
		}
		// 3.情况
		else{
			PNode pParent = _pNode->_pParent;
			while(_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
		}
	}
private:
	PNode _pNode;
};
