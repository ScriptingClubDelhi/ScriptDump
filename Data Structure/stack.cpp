#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class stack
{
	public:
	int *s,size,top;
	stack(int n)
	{
		size=n;
		s= new int[size];
		top=-1;
	}
	void menu()
	{
		char choice;
		do
		{
			cout<<"\n::---------Stack Operations---------::"<<endl;
			cout<<"\n1. Push\n2. PoP\n3. Peek\n4. Count\n5. Change\n6. Display"<<endl;
			cout<<"\nEnter a choice: ";
			cin>>choice;
			switch(choice)
			{
				case'1':{
						int i;
						cout<<"\nEnter data: ";
						cin>>i;
						push(i);
						break;
					}
				case'2':{
						if(isempty())
						cout<<"\nStack underflow"<<endl;
						else
						cout<<"\nPoped element: "<<pop();
						break;
					}
				case'3':{
						if(isempty())
						display();
						else
						cout<<peek();
						break;
					}
				case'4':{
						cout<<count();
						break;
					}
				case'5':{
						if(isempty())
						display();
						else
						{
							int data;
							cout<<"\nEnter data to change with "<<s[top]<<" :";
							cin>>data;
							change(data);
						}
						break;
					}
				case'6':{
						display();
						break;
					}
				default:{
						cout<<"\n---Invalid choice---"<<endl;
					}
			}
			cout<<"\nDo you want to continue(y/n): ";
			choice=getch();
			cout<<endl;
		}
		while(choice=='y'||choice=='Y'||choice==13);
	}
	bool isfull()
	{
		if(top==size-1)
		return true;
		else
		return false;
	}
	bool isempty()
	{
		if(top==-1)
		return true;
		else
		return false;
	}
	void push(int el)
	{
		if(isfull())
		cout<<"\nStack overflow"<<endl;
		else
		s[++top]=el;
	}
	int pop()
	{
		if(isempty())
		return -1;
		else
		return s[top--];
	}
	int peek()
	{
		if(isempty())
		return -1;
		else
		return s[top];
	}
	int count()
	{
		return top+1;
	}
	void change(int data)
	{
		if(isempty())
		display();
		else
		s[top]=data;
	}
	void display()
	{
		if(isempty())
		cout<<"\nThe Stack is empty"<<endl;
		else
		{
			cout<<"\nThe Stack elements are:\n"<<endl;
			for(int i=top;i>-1;i--)
			cout<<s[i]<<endl;
		}
	}
};
int main()
{
	int size;
	cout<<"::Stack using Array::"<<endl;
	start:
	cout<<"\nEnter the size of Stack: ";
	cin>>size;
	if(size<1)
	{
		cout<<"\nInvalid Size of Stack"<<endl;
		goto start;
	}
	else
	{
		stack obj(size);
		obj.menu();
	}
	getch();
	return 0;
}
