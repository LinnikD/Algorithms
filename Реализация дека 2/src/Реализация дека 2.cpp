//============================================================================
// Name        : Реализация.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class dek_f
{
public:
	int data;
	dek_f * prev;
	dek_f* next;
};

class dek
{
public:
	dek()
{
		head = NULL;
		tail = NULL;
}
	~dek()
	{
		if(Head != NULL)

	}
	void push_back(int a);
	void push_front(int a);
	int pop_back();
	int pop_front();
private:
	dek_f * head;
	dek_f * tail;
};

void dek::push_back(int a)
{
	if(tail != NULL)
	{
		tail->prev = new dek_f;
		tail->prev->data = a;
		tail->prev->next = tail;
		tail->prev->prev = NULL;
		tail = tail->prev;
	}
	else
	{
		tail=head=new dek_f;
		tail->data=a;
		tail->next=NULL;
		tail->prev=NULL;
	}
}
void dek::push_front(int a)
{
	if(head != NULL)
	{
		head->next = new dek_f;
		head->next->data = a;
		head->next->prev = head;
		head->next->next = NULL;
		head = head->next;
	}
	else
	{
		tail= head = new dek_f;
		tail->data=a;
		tail->next=NULL;
		tail->prev=NULL;
	}
}
int dek::pop_back()
{
	int a = 0;
	if(tail != NULL)
	{
		a = tail->data;
		if(tail != head)
		{
		tail = tail->next;
		delete tail->prev;
		tail->prev = NULL;
		}
		else
		{
			delete tail;
			tail = head =NULL;
		}
	}
	else
	{
		a =-1;
	}
	return a;
}
int dek::pop_front()
{
	int a = 0;
	if(head != NULL)
	{
		a = head->data;
		if(tail != head)
		{
		head = head->prev;
		delete head->next;
		head->next = NULL;
		}
		else
		{
			delete head;
			tail = head =NULL;
		}
	}
	else
	{
		a =-1;
	}
	return a;
}

int main() {
	dek d;
	int i, a, b, j=0, k=0;
	cin>>i;
	while(i!=0)
	{
		cin>>a>>b;
		switch(a)
		{
		case 1:
			d.push_back(b);
			break;
		case 2:
			j++;
			if(d.pop_back()==b)
			k++;
			break;
		case 3:
			d.push_front(b);
			break;
		case 4:
			j++;
			if(d.pop_front()==b)
			k++;
		}
		i--;
	}
	if(j == k)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
