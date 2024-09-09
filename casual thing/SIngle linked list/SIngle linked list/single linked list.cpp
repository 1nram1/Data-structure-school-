#include<iostream>
#include"SLL.h"
using namespace std;

struct Lnode
{
	ElemType data;
	Lnode* next;
};

typedef Lnode* LinkList;

bool Initlist(LinkList& L)
{
	L = new Lnode;
	L->next = nullptr;
	return true;
}

void CreatListHead(LinkList &L, const size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = r->next;
	}
}

bool isEmpty(const LinkList &L)
{
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool DestroyList(LinkList& L)
{
	if (isEmpty(L))
	{
		cerr << "empty list \t" << " " << endl;
		return false;
	}
	while (L)
	{
		auto temp = L->next;
		delete L;
		L = temp;
	}
	return true;
}

size_t GetLength(const LinkList& L)
{
	Lnode* p;
	p = L->next;
	size_t count = 0;
	while (p)
	{
		++count;
		p = p->next;
	}
	return count;
}


//bool GetElem(const LinkList& L, const int& i, ElemType& e)
//{
//	if (i < 0)
//	{
//		cerr << " out of range" << endl;
//		return false;
//    }
//	Lnode *p = L->next;
//	for (int j = 1; j < i ; ++j)
//	{
//		p = p->next;
//		if (!p)
//		{
//			cerr << "out of range" << endl;
//			return false;
//		}
//
//	}
//	e = p->data;
//	return true;
//}

//
int GetElem(LinkList& L, int position, ElemType &e)
{
	LinkList p = L->next;
	int i = 1;
	if (position < 1 || !p)
	{
		return -1;
	}
	while (p && i < position)
	{
		p = p->next;
		i++;
	}
	e = p->data;
	return 0;
}


size_t LocateElem(LinkList& L, ElemType& e)
{
	Lnode* p = L->next;
	size_t count = 1;
	while (p)
	{
		if (p->data == e)
		{
			return count;
		}
		++count;
		p = p->next;
	}
	cerr << "not found" << endl;
	return 0;
}

bool EraseList(LinkList& L, const int& i)
{
	Lnode* p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || i < 0)
	{
		cerr << "out of range" << endl;
		return false;
	}
	Lnode* q = p->next;
	p->next = p->next->next;
	delete q;
	return true;
}

void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	Lc = La;
	Lnode* pc = Lc;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
	}
	pc->next = (pa ? pa : pb);
	delete Lb;
}

//void SPO_II(LinkList& La, LinkList& Lb, LinkList& Lc)
//{
//	Lnode* pa = La->next;
//	Lnode* pb = Lb->next;
//	Lc = La;
//	Lnode* pc = Lc;
//	while (pa && pb)
//	{
//		if(pa->nex)
//	}
//}
int main()
{
	LinkList myLinkList = nullptr;
	Initlist(myLinkList);

	CreatListHead(myLinkList,3 );
   
	//bool (*p) (const LinkList & L, const int& i, ElemType & e);
	//p = GetElem;
	int (*q)(LinkList & L, int position, ElemType &e);
	q = GetElem;
	ElemType a = 0;
	q(myLinkList, 2, a);
	cout << a << endl;
	system("pause");
	return 0;
}