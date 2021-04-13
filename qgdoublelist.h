/**
 * 作者:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__
#include<iostream>
using namespace std;
 /*
  * 双向链表
  */

template <typename T>
class QGList {

protected:
	struct Node {
		T data;
		struct Node* prior;
		struct Node* next;
	};

	Node* head;
	Node* tail;
	Node* p;
	Node* q;

public:

	/*
	 * 初始化链表
	 */
	QGList();
	bool Init();
	/*
	 * 销毁链表
	 */
	~QGList();
	bool destory();
	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));
};

#endif

template<typename T>
inline QGList<T>::QGList()
{
	head = nullptr;
	tail = nullptr;
	p = nullptr;
	q = nullptr;
}

template<typename T>
inline bool QGList<T>::Init()
{
	head = new Node;
	head->next = nullptr;
	return true;
}

template<typename T>
inline QGList<T>::~QGList()
{
	destory();
}

template<typename T>
inline bool QGList<T>::destory()
{
	if (head == nullptr)
	{
		cout << "该链表未初始化。" << endl;
		return false;
	}
	else if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
		return false;
	}
	else
	{
		p = head;
		while (p->next != nullptr)
		{
			q = p->next;
			delete(p);
			p = q;
		}
		head = nullptr;
		p = nullptr;
		q = nullptr;
		tail = nullptr;
		cout << "该链表已销毁。" << endl;
		return true;
	}
}

template<typename T>
inline T& QGList<T>::front()
{
	T& t = head->next->data;
	return t;
	// TODO: 在此处插入 return 语句
}

template<typename T>
inline T& QGList<T>::back()
{
	p = head->next;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	tail = p;
	T& t = tail->data;
	return t;
	// TODO: 在此处插入 return 语句
}

template<typename T>
inline bool QGList<T>::push_front(T& e)
{
	p = new Node;
	p->data = e;
	p->next = head->next;
	head->next = p;
	p->prior = head;
	return true;
}

template<typename T>
inline bool QGList<T>::pop_front()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
		return false;
	}
	else
	{
		p = head->next;
		head->next = p->next;
		p->next->prior = head;
		delete(p);
		return true;
	}
}

template<typename T>
inline bool QGList<T>::push_back(T& e)
{
	q = new Node;
	p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return true;
}

template<typename T>
inline bool QGList<T>::pop_back()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
		return false;
	}
	else
	{
		q = head;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		p = head;
		while (p->next != q)
		{
			p = p->next;
		}
		p->next = nullptr;
		delete(q);
		return true;
	}
}

template<typename T>
inline bool QGList<T>::insert(unsigned int index, T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
		return false;
	}
	else
	{
		q = new Node;
		q->data = e;
		p = head;
		while (index--)
		{
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
		q->prior = p;
		return true;
	}
}

template<typename T>
inline bool QGList<T>::erase(unsigned int index)
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
		return false;
	}
	else
	{
		index--;
		p = head;
		while (index--)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		delete(q);
		return true;
	}
}

template<typename T>
inline bool QGList<T>::clear()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
		return false;
	}
	else
	{
		p = head->next;
		while (p->next != nullptr)
		{
			q = p->next;
			delete(p);
			p = q;
		}
		head->next = nullptr;
		p = nullptr;
		tail = nullptr;
		q = nullptr;
		return true;
	}
}

template<typename T>
inline bool QGList<T>::contain(T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
		return false;
	}
	else
	{
		p = head->next;
		bool a = false;
		while (p != nullptr)
		{
			if (p->data == e)
			{
				a = true;
			}
			p = p->next;
		}
		if (a)
		{
			cout << "元素存在于链表当中" << endl;
		}
		else
		{
			cout << "元素不存在于链表当中" << endl;
		}

		return true;
	}
}

template<typename T>
inline unsigned int QGList<T>::size()
{
	p = head->next;
	int counter = 0;
	while (p != nullptr)
	{
		p = p->next;
		counter++;
	}
	return counter;
}


//遍历链表
template <class T>
void visit(T& e)
{
	cout << e << "  ";
}
template<class T>
bool QGList<T>::traverse(void (*visit)(T& e))
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
		return false;
	}
	else
	{
		p = head->next;
		while (p != nullptr)
		{
			visit(p->data);
			p = p->next;
		}
		cout << endl;
		cout << "遍历打印完毕！" << endl;
		return true;
	}
}

void menu();
