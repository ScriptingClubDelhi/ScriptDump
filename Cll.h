#include<iostream>
//#include<conio.h>
using namespace std;
template <class t>
class node
{
	public:
		t info;
		node* next;
		node()
		{
			next=NULL;
		}
		node(t in,node* ne=NULL)
		{
			info=in;
			next=ne;
		}
};
template <class t>
class CLL
{
	public:
		node<t>* tail;
		CLL()
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
		void operator +(CLL<t> &l2);
		void concat(CLL<t> &l2);
		void display();
		void alternate();
};
template<class t>
void CLL<t>::InsertionStart()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	if(tail==NULL)
	{
		tail=ins;
		tail->next=tail;
	}else
	{
		ins->next=tail->next;
		tail->next=ins;
	}
	ins=NULL;
	delete ins;
}
template<class t>
void CLL<t>::InsertionEnd()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	if(tail==NULL)
	{
		tail=ins;
		tail->next=tail;
	}else
	{
		node<t>* temp=tail->next;
		if(tail->next==tail)
		{
			tail->next=ins;
			ins->next=tail;
			tail=ins;
		}else
		{
			while(temp->next!=tail->next)
				temp=temp->next;
			ins->next=temp->next;
			temp->next=ins;
			tail=ins;
		}
		temp=NULL;
		delete temp;
	}
	ins=NULL;
	delete ins;
}
template<class t>
void CLL<t>::InsertionMiddle(int index)
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
	}else
	{
		node<t>* temp=tail->next;
		if(index==1)
		{
			ins->next=tail->next;
			tail->next=ins;
		}else
		{
			while(count<index-1)
			{
				temp=temp->next;
				count++;
			}
			ins->next=temp->next;
			temp->next=ins;
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
void CLL<t>::DeletionStart()
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
			temp->next=NULL;
			delete temp;
		}
	}
}
template <class t>
void CLL<t>::DeletionEnd()
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
			tail->next=NULL;
			tail=temp;
			delete delnode;
			temp=NULL;
			delete temp;
		}
	}
}
template <class t>
void CLL<t>::DeletionMiddle(int index)
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
			temp->next=NULL;
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
		if(delnode==tail)
			tail=temp;
		delnode->next=NULL;
		delete delnode;
	}
	temp=NULL;
	delete temp;
}
template <class t>
int CLL<t>::search(t el)
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
void CLL<t>::reverse()
{
	node<t>* temp=tail->next->next;
	node<t>* prev=tail->next;
	node<t>* temp2=temp->next;
	prev->next=tail;
	tail=tail->next;
	while(temp2!=tail)
	{
		//head=temp->next;
		temp->next=prev;
		prev=temp;
		temp=temp2;
		temp2=temp->next;
	}
	temp->next=prev;
	prev=NULL;
	temp=NULL;
	temp2=NULL;
	delete temp2;
	delete prev;
	delete temp;
}
template<class t>
void CLL<t>::operator +(CLL &l2)
{
	node<t>* temp=tail->next;
	tail=tail->next;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	temp->next=l2.tail->next;
	l2.tail->next=tail;
	tail=l2.tail;
	temp=NULL;
	delete temp;
}
template<class t>
void CLL<t>::concat(CLL<t> &l2)
{
	node<t>* temp=tail->next;
	tail=tail->next;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	temp->next=l2.tail->next;
	l2.tail->next=tail;
	tail=l2.tail;
	temp=NULL;
	delete temp;
}
template<class t>
void CLL<t>::display()
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
void CLL<t>::alternate()
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