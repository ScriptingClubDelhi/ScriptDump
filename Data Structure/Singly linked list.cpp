#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
class node
{
	public:
	T info;
	node *next;
};
template<class T>
class list
{
	public:
		node<T> *head,*n,*temp;
		list()
		{
			head=NULL;
		}
	void menu()
	{
		cout<<"\n::Linked list program::"<<endl;
		char choice;
		do
		{
			cout<<"\n1. Insert a node in start\n2. Insert a node at last\n3. Delete first node\n4. Delete last node\n5. Search\n6. Reverse\n7. Display"<<endl;
			cout<<"\nEnter your choice: ";
			cin>>choice;
			switch(choice)
			{
				case '1':{
							T x;
							cout<<"\nEnter data: ";
							cin>>x;
							insert_beg(x);
							break;
				}
				case '2':{
							T x;
							cout<<"\nEnter data: ";
							cin>>x;
							insert_last(x);
							break;
				}
				case '3':{
							delete_first();
							break;
				}
				case '4':{
							delete_last();
							break;
				}
				case '5':{
							T el;
							cout<<"\nEnter data to search: ";
							cin>>el;
							if(search(el)==-1)
							cout<<"\nData not found!"<<endl;
							else
							cout<<"\nData found in node "<<search(el)<<endl;
							break;
				}
				case '6':{
							reverse();
							break;
				}
				case '7':{
							display();
							break;
				}
				default:{
							cout<<"\nIncorrect choice!";
				}
			}
			cout<<"\nDo You want to continue(y/n): ";
			cin>>choice;
		}
		while(choice=='y'||choice=='Y');
	}
	void insert_beg(T data)
	{
		if(head==NULL)
		{
			head=new node<T>;
			head->info=data;
			head->next=NULL;
		}
		else
		{
			n=new node<T>;
			n->info=data;
			n->next=head;
			head=n;
		}
	}
	void insert_last(T data)
	{
		if(head==NULL)
		insert_beg(data);
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			n=new node<T>;
			n->info=data;
			n->next=NULL;
			temp->next=n;
			temp=NULL;
		}
	}
	void delete_first()
	{
		if(head==NULL)
		display();
		else
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			temp=head;
			head=head->next;
			delete temp;
			temp=NULL;
		}
	}
	void delete_last()
	{
		if(head==NULL)
		display();
		else
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			n=NULL;
			temp=head;
			while(temp->next->next!=NULL)
			temp=temp->next;
			n=temp->next;
			delete n;
			temp->next=NULL;
			n=NULL;
			temp=NULL;
		}
	}
	int search(T el)
	{
		if(head==NULL)
		{
		display();
		return -1;
		}
		else
		{
			int i=0;
			temp=NULL;
			temp=head;
			while(temp!=NULL)
			{
				i++;
				if(temp->info==el)
				{
					return i;
					break;
				}
				temp=temp->next;
			}
			temp=NULL;
			return -1;
		}
	}
	void display()
	{
		if(head==NULL)
		cout<<"\nLinked list is Empty"<<endl;
		else
		{
			temp=head;
			cout<<"\nThe linked list:\n"<<endl;
			while(temp!=NULL)
			{
				cout<<temp->info;
				cout<<"\t";
				temp=temp->next;
			}
			temp=NULL;
			cout<<endl;
		}
	}
	void reverse()
	{
		if(head==NULL)
		display();
		else
		{
			temp=n=head;
			temp=temp->next;
			head->next=NULL;
			while(temp!=NULL)
			{
				head=temp;
				temp=temp->next;
				head->next=n;
				n=head;
			}
		}
	}
};
int main()
{
	list<int>obj;
	obj.menu();
	return 0;
}
