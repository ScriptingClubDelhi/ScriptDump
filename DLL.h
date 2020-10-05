#include<iostream>
#include<conio.h>
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
		}
		node(t in,node* ne=NULL,node* pre=NULL)
		{
			info=in;
			next=ne;
			prev=pre;
		}
};
template <class t>
class DLL
{
	public:
		node<t>* head;
		DLL()
		{
			head=NULL;
		}
		void InsertionStart();
		void InsertionEnd();
		void InsetionMiddle(int index);
		void DeletionStart();
		void DeletionEnd();
		void DeletionMiddle(int index);
		int search(t el);
		void reverse();
		void operator +(DLL<t> &l2);
		void concat(DLL<t> &l2);
		void display();
		void alternate();
};
template <class t>
void DLL<t>::InsertionStart()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	if(head==NULL)
	{
		head=ins;
	}else
	{
		ins->next=head;
		head->prev=ins;
		head=ins;
	}
	ins=NULL;
	delete ins;
}
template <class t>
void DLL<t>::InsertionEnd()
{
	t el;
	cout<<"Enter element to be inserted ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	node<t>* temp=head;
	if(head==NULL)
	{
		head=ins;
	}else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ins;
		ins->prev=temp;
	}
	temp=NULL;
	ins=NULL;
	delete temp;
	delete ins;	
}
template <class t>
void DLL<t>::InsetionMiddle(int index)
{
	t el;
	int count=1;
	cout<<"Enter element to be entered ";
	cin>>el;
	node<t>* ins=new node<t>(el);
	node<t>* temp=head;
	if(head==NULL)
	{
		head=ins;
	}else
	{
		while(count<index-1)
		{
			count++;
			temp=temp->next;
		}
		ins->next=temp->next;
		//ins->prev=temp;
		temp->next=ins;
		ins->prev=temp;
	}
	ins=NULL;
	temp=NULL;
	delete ins;
	delete temp;
}
template <class t>
void DLL<t>::DeletionStart()
{
	if(head==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		node<t>* temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		//temp=NULL;
		delete temp;
	}
}
template <class t>
void DLL<t>::DeletionEnd()
{
	if(head==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		node<t>* temp=head;
		node<t>* delnode;
		while(temp->next->next!=NULL)
		{
		//	delnode=delnode->next;
			temp=temp->next;
			delnode=temp->next;
		}
		temp->next=NULL;
		delnode->prev=NULL;
		temp=NULL;
		delete delnode;
		delete temp;
	}
}
template <class t>
void DLL<t>::DeletionMiddle(int index)
{
	node<t>* temp=head;
	if(index==1)
	{
		head->next->prev=NULL;
		head=head->next;
		delete temp;
	}else
	{
		node<t>* delnode;
		for(int i=1;i<(index-1);i++)
		{
		//	temp=temp->next;

			if(temp->next->next!=NULL)
			{
				//node<t>* delnode=temp->next;
				temp=temp->next;
				delnode=temp->next;
				//delete delnode;
			}
			//delete delnode;
		}
		temp->next=delnode->next;
		delnode->next->prev=temp;
		delnode->next=NULL;
		delnode->prev=NULL;
		delete delnode;
	}
	temp=NULL;
	delete temp;
}
template <class t>
int DLL<t>::search(t el)
{
	node<t>* temp=head;
	int count=1;
	int totalEl=0;
	while(temp!=NULL)
	{
		totalEl++;
		temp=temp->next;
	}
	temp=head;
	while(temp->info!=el&&temp->next!=NULL)
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
template <class t>
void DLL<t>::reverse()
{
	node<t>* temp=head->next;
	node<t>* p=head;
	head->next=NULL;
	while(temp->next!=NULL)
	{
		head=temp->next;
		p->prev=temp;
		temp->next=p;
		p=temp;
		temp=head;
	}
	temp->next=p;
	temp->prev=NULL;
	p=NULL;
	temp=NULL;
	delete p;
	delete temp;
}
template <class t>
void DLL<t>::operator +( DLL<t> &l2)
{
	node<t>* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=l2.head;
	l2.head->prev=temp;
	temp=NULL;
	delete temp;
}
template <class t>
void DLL<t>::concat( DLL<t> &l2)
{
	node<t>* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=l2.head;
	l2.head->prev=temp;
	temp=NULL;
	delete temp;
}
template <class t>
void DLL<t>::display()
{
	cout<<"List is "<<endl;
	node<t>* temp=head;
	if(head==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		while(temp!=NULL)
		{
			cout<<temp->info<<"\t";
			temp=temp->next;
		}
		cout<<endl;
	}
	temp=NULL;
	delete temp;
}
template <class t>
void DLL<t>::alternate()
{
	node<t>* temp=head;
	if(head==NULL)
	{
		cout<<"Empty List"<<endl;
	}else
	{
		while(temp->next!=NULL)
		{
				cout<<temp->info<<"\t";
				if(temp->next->next!=NULL)
					temp=temp->next->next;
				else
					break;
		}
		if(temp!=NULL&&temp->next==NULL)
			cout<<temp->info<<"\t";
		cout<<endl;
	}
	temp=NULL;
	delete temp;
}