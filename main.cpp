#include"qgdoublelist.h"
#include<iostream>
int main()
{
	menu();
	QGList<int> intdlist;
	cout << "由于您还未创建链表，请输入1：" << endl;
	int choice;
	while (cin >> choice)
	{
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
		{
			intdlist.Init();
			int n, i, x;
			cout << "请输入您要创建链表元素的数量：" << endl;
			cin >> n;
			cout << "请输入链表中的元素：";
			for (i = 0; i < n; i++)
			{
				cin >> x;
				intdlist.push_back(x);
			}
			cout << "该链表创建成功！" << endl;

			break;
		}
		case 2:
		{
			intdlist.destory();
			break;
		}
		case 3:
		{
			int b;
			b = intdlist.front();
			cout << "该链表的第一个元素是：" << b << endl;
			break;
		}
		case 4:
		{
			int b;
			b = intdlist.back();
			cout << "该链表的最后一个元素是：" << b << endl;
			break;
		}
		case 5:
		{
			cout << "请输入要插入在首位的元素数据：" << endl;
			int c;
			cin >> c;
			intdlist.push_front(c);
			cout << "该元素已插入链表首位。" << endl;
			break;
		}
		case 6:
		{
			intdlist.pop_front();
			cout << "已删除链表的第一个元素。" << endl;
			break;
		}
		case 7:
		{
			cout << "请输入要插入在链表尾部的元素数据：" << endl;
			int c;
			cin >> c;
			intdlist.push_back(c);
			cout << "该元素已插入链表尾部。" << endl;
			break;
		}
		case 8:
		{
			intdlist.pop_back();
			cout << "已删除链表最后一个元素。" << endl;
			break;
		}
		case 9:
		{
			cout << "在第m位后插入的元素n，请输入m，n：" << endl;
			unsigned int m; int n;
			cin >> m >> n;
			intdlist.insert(m, n);
			cout << "已在第" << m << "位元素后插入元素" << n << endl;
			break;
		}
		case 10:
		{
			cout << "请输入要删除第几位元素：" << endl;
			unsigned int b;
			cin >> b;
			intdlist.erase(b);
			cout << "该元素已删除。" << endl;
			break;
		}
		case 11:
		{
			intdlist.clear();
			cout << "已清空该链表！" << endl;
			break;
		}
		case 12:
		{
			cout << "请输入你要查找的元素：" << endl;
			int b;
			cin >> b;
			intdlist.contain(b);
			break;
		}
		case 13:
		{
			cout << "该链表中含有的元素数量为：" << intdlist.size() << endl;
			break;
		}
		case 14:
		{
			intdlist.traverse(visit);
			break;

		}
		case 15:
		{
			//intdlist.reverse();
			cout << "该链表已翻转。" << endl;
			break;
		}
		case 16:
		{
			
			break;
		}
		case 17:
		{
			//ntdlist.reverseEven();
			cout << "该链表中奇偶结点已反转。" << endl;
			break;
		}
		case 18:
		{
			//int c = intdlist.middleElem();
			//cout << "该链表的中间结点为：" << c << endl;
			break;
		}
		}
		cout << "请输入下一步要对链表操作的序号：" << endl;
	}
}