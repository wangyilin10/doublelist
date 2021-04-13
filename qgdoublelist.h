/**
 * ����:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__
#include<iostream>
using namespace std;
 /*
  * ˫������
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
	 * ��ʼ������
	 */
	QGList();
	bool Init();
	/*
	 * ��������
	 */
	~QGList();
	bool destory();
	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
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
		cout << "������δ��ʼ����" << endl;
		return false;
	}
	else if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
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
		cout << "�����������١�" << endl;
		return true;
	}
}

template<typename T>
inline T& QGList<T>::front()
{
	T& t = head->next->data;
	return t;
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
		cout << "������Ϊ�ա�" << endl;
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
		cout << "������Ϊ�ա�" << endl;
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
		cout << "����δ��ʼ����" << endl;
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
		cout << "������Ϊ�ա�" << endl;
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
		cout << "������Ϊ�ա�" << endl;
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
		cout << "����δ��ʼ����" << endl;
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
			cout << "Ԫ�ش�����������" << endl;
		}
		else
		{
			cout << "Ԫ�ز�������������" << endl;
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


//��������
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
		cout << "����δ��ʼ����" << endl;
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
		cout << "������ӡ��ϣ�" << endl;
		return true;
	}
}

void menu();
