#include"qgdoublelist.h"
#include<iostream>
int main()
{
	menu();
	QGList<int> intdlist;
	cout << "��������δ��������������1��" << endl;
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
			cout << "��������Ҫ��������Ԫ�ص�������" << endl;
			cin >> n;
			cout << "�����������е�Ԫ�أ�";
			for (i = 0; i < n; i++)
			{
				cin >> x;
				intdlist.push_back(x);
			}
			cout << "���������ɹ���" << endl;

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
			cout << "������ĵ�һ��Ԫ���ǣ�" << b << endl;
			break;
		}
		case 4:
		{
			int b;
			b = intdlist.back();
			cout << "����������һ��Ԫ���ǣ�" << b << endl;
			break;
		}
		case 5:
		{
			cout << "������Ҫ��������λ��Ԫ�����ݣ�" << endl;
			int c;
			cin >> c;
			intdlist.push_front(c);
			cout << "��Ԫ���Ѳ���������λ��" << endl;
			break;
		}
		case 6:
		{
			intdlist.pop_front();
			cout << "��ɾ������ĵ�һ��Ԫ�ء�" << endl;
			break;
		}
		case 7:
		{
			cout << "������Ҫ����������β����Ԫ�����ݣ�" << endl;
			int c;
			cin >> c;
			intdlist.push_back(c);
			cout << "��Ԫ���Ѳ�������β����" << endl;
			break;
		}
		case 8:
		{
			intdlist.pop_back();
			cout << "��ɾ���������һ��Ԫ�ء�" << endl;
			break;
		}
		case 9:
		{
			cout << "�ڵ�mλ������Ԫ��n��������m��n��" << endl;
			unsigned int m; int n;
			cin >> m >> n;
			intdlist.insert(m, n);
			cout << "���ڵ�" << m << "λԪ�غ����Ԫ��" << n << endl;
			break;
		}
		case 10:
		{
			cout << "������Ҫɾ���ڼ�λԪ�أ�" << endl;
			unsigned int b;
			cin >> b;
			intdlist.erase(b);
			cout << "��Ԫ����ɾ����" << endl;
			break;
		}
		case 11:
		{
			intdlist.clear();
			cout << "����ո�����" << endl;
			break;
		}
		case 12:
		{
			cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
			int b;
			cin >> b;
			intdlist.contain(b);
			break;
		}
		case 13:
		{
			cout << "�������к��е�Ԫ������Ϊ��" << intdlist.size() << endl;
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
			cout << "�������ѷ�ת��" << endl;
			break;
		}
		case 16:
		{
			
			break;
		}
		case 17:
		{
			//ntdlist.reverseEven();
			cout << "����������ż����ѷ�ת��" << endl;
			break;
		}
		case 18:
		{
			//int c = intdlist.middleElem();
			//cout << "��������м���Ϊ��" << c << endl;
			break;
		}
		}
		cout << "��������һ��Ҫ�������������ţ�" << endl;
	}
}