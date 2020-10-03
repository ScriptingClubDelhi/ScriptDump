#include<iostream>
//#include<conio.h>
using namespace std;
template <class t>
class node
{
	public:
		t info;
		node* next;
		node* prev;
		node()
		{
			next=NULL;
			prev=NULL;
		}
		node(t in,node* ne=NULL,node* pe=NULL)
		{
			info=in;
			next=ne;
			prev=pe;
		}
};
template <class t>
class CDLL
{
	public:
		node<t>* tail;
		CDLL()
		{
			tail=NULL;
		}
		void InsertionStart();
		void InsertionEnd();
		void InsertionMiddle(int index);
		void DeletionStart();
		void DeletionEnd();
		void DeletionMiddle(int index);
		int search(t el);
		void reverse();
		void operator +(CDLL<t> &l2);
		void concat(CDLL<t> &l2);
		void display();
		void alternate();
};
template<class t>
void CDLL<t>::InsertionStart()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	if(tail==NULL)
	{
		tail=ins;
		tail->next=tail;
		tail->prev=tail;
	}else
	{
		ins->next=tail->next;
		tail->next=ins;
		ins->prev=tail;
		ins->next->prev=ins;
	}
	ins=NULL;
	delete ins;
}
template<class t>
void CDLL<t>::InsertionEnd()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	if(tail==NULL)
	{
		tail=ins;
		tail->next=tail;
		tail->prev=tail;
	}else
	{
		node<t>* temp=tail->next;
		if(tail->next==tail)
		{
			tail->next=ins;
			ins->next=tail;
			tail->prev=ins;
			ins->prev=tail;
			tail=ins;
		}else
		{
			while(temp->next!=tail->next)
				temp=temp->next;
			ins->next=temp->next;
			temp->next=ins;
			ins->prev=temp;
			ins->next->prev=ins;
			tail=ins;
		}
		temp=NULL;
		delete temp;
	}
	ins=NULL;
	delete ins;
}
template<class t>
void CDLL<t>::InsertionMiddle(int index)
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	int count=1;
	if(tail==NULL)
	{
		tail=ins;
		tail->next=tail;
		tail->prev=tail;
	}else
	{
		node<t>* temp=tail->next;
		if(index==1)
		{
			ins->next=tail->next;
			tail->next=ins;
			ins->prev=tail;
			ins->next->prev=ins;
		}else
		{
			while(count<index-1)
			{
				temp=temp->next;
				count++;
			}
			ins->next=temp->next;
			temp->next=ins;
			ins->prev=temp;
			ins->next->prev=ins;
			if(temp==tail)
				tail=ins;
		}
		temp=NULL;
		delete temp;
	}
	ins=NULL;
	delete ins;
}
template <class t>
void CDLL<t>::DeletionStart()
{
	if(tail==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		if(tail->next==tail)
		{
			tail=NULL;
		}else
		{
			node<t>* temp=tail->next;
			tail->next=temp->next;
			tail->next->prev=tail;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
	}
}
template <class t>
void CDLL<t>::DeletionEnd()
{
	if(tail==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		if(tail->next==tail)
		{
			tail=NULL;
		}else
		{
			node<t>* temp=tail->next;
			while(temp->next!=tail)
				temp=temp->next;
			node<t>* delnode=tail;
			temp->next=tail->next;
			tail->next->prev=temp;
			tail->next=NULL;
			tail->prev=NULL;
			tail=temp;
			delete delnode;
			temp=NULL;
			delete temp;
		}
	}
}
template <class t>
void CDLL<t>::DeletionMiddle(int index)
{
	node<t>* temp=tail->next;
	int count=1;
	if(index==1)
	{
		if(tail->next==tail)
		{
			tail=NULL;
			delete temp;
		}else
		{
			tail->next=temp->next;
			tail->next->prev=tail;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
	}else
	{
		node<t>* delnode=temp->next;
		while(count<index-1)
		{
			count++;
			temp=temp->next;
			delnode=temp->next;
		}
		temp->next=delnode->next;
		temp->next->prev=temp;
		if(delnode==tail)
			tail=temp;
		delnode->next=NULL;
		delnode->prev=NULL;
		delete delnode;
	}
	temp=NULL;
	delete temp;
}
template <class t>
int CDLL<t>::search(t el)
{
	node<t>* temp=tail->next;
	int count=1;
	int totalEl=1;
	while(temp!=tail)
	{
		totalEl++;
		temp=temp->next;
	}
	temp=tail->next;
	while(temp->info!=el&&temp!=tail)
	{
		count++;
		temp=temp->next;
	}
	if(temp->info!=el)
	count++;
	temp=NULL;
	delete temp;
	if(count<=totalEl)
	return count;
	else
	return -1;
}
template<class t>
void CDLL<t>::reverse()
{
	node<t>* temp=tail->next->next;
	node<t>* p=tail->next;
	node<t>* temp2=temp->next;
	p->next=tail;
	tail->prev=p;
	tail=tail->next;
	while(temp2!=tail)
	{
		//head=temp->next;
		temp->next=p;
		temp->prev=temp2;
		p=temp;
		temp=temp2;
		temp2=temp->next;
	}
	temp->next=p;
	temp->prev=tail;
	p=NULL;
	temp=NULL;
	temp2=NULL;
	delete temp2;
	delete p;
	delete temp;
}
template<class t>
void CDLL<t>::operator +(CDLL &l2)
{
	node<t>* temp=tail->next;
	tail=tail->next;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	temp->next=l2.tail->next;
	temp->next->prev=temp;
	l2.tail->next=tail;
	tail->prev=l2.tail;
	tail=l2.tail;
	temp=NULL;
	delete temp;
}
template<class t>
void CDLL<t>::concat(CDLL<t> &l2)
{
	node<t>* temp=tail->next;
	tail=tail->next;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	temp->next=l2.tail->next;
	temp->next->prev=temp;
	l2.tail->next=tail;
	tail->prev=l2.tail;
	tail=l2.tail;
	temp=NULL;
	delete temp;
}
template<class t>
void CDLL<t>::display()
{
	if(tail==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		node<t>* temp=tail->next;
		if(tail->next==tail)
			cout<<tail->info<<endl;
		else
		{
			while(temp->next!=tail->next)
			{
					cout<<temp->info<<"\t";
					temp=temp->next;
			}
			cout<<temp->info;
			cout<<endl;
		}
		temp=NULL;
		delete temp;
	}
}
template<class t>
void CDLL<t>::alternate()
{
	if(tail==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		node<t>* temp=tail->next;
		while(temp->next!=tail->next)
		{
			cout<<temp->info<<"\t";
				if(temp->next->next!=tail->next)
					temp=temp->next->next;
				else
					break;
		}
		if(temp->next==tail->next)
			cout<<temp->info<<"\t";
		cout<<endl;
		temp=NULL;
		delete temp;
	}
}