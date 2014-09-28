//============================================================================
// Name        : Анаграммы.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <strings.h>
using namespace std;

class st
{
public:
	char data;
	st * prev;
};

class stek
{
public:
	stek()
{
		head = NULL;
}
	void push(char a);
	char pop();
	char po()
	{
		if (head != NULL)
		return head->data;
		return '\0';
	}
private:
	st * head;
};

void stek::push(char a)
{
	if(head != NULL)
	{
		st * tmp = head;
		head = new st;
		head->data = a;
		head->prev = tmp;
	}
	else
	{
		head = new st;
		head->data = a;
		head->prev = NULL;
	}
}

char stek::pop()
{
	if(head != NULL)
	{
		char tmp = head->data;
		if(head->prev != NULL)
		{
			st * tp;
			tp = head;
			head = head->prev;
			delete tp;
		}
		else
			delete head;
		return tmp;
	}
	else
	{
		return '\0';
	}
}

void foo(string s1, string s2)
{
	stek s;
	string s3(s1);
	unsigned i = 0, j = 0;
	while(i < s1.length())
	{
		s.push(s1[i]);
		if(s.po()==s2[j])
			s3[j++]=s.pop();
		i++;
	}
	while(j < s2.length())
	{
		s3[j]=s.pop();
		j++;
	}
	if(s2==s3)
		cout<<"YES";
	else
		cout<<"NO";
}

int main() {
	string s1, s2;
	cin>> s1;
	cin>> s2;
	foo(s1,s2);
	return 0;
}
