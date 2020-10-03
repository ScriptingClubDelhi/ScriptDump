#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
class Queue
{
 public:
		T *arr;
		int front,rear,size;
		Queue(int s)
		{
			size=s;
			arr=new T[size];
			rear=-1;
			front=-1;
		}
		void menu()
		{
			char choice;
			do{
				cout<<"\n\n::Queue using Array Program::"<<endl;
				cout<<"\n1. EnQueue\n2. DeQueue\n3. Display\n4. Exit"<<endl;
				cout<<"\nEnter a choice: ";
				cin>>choice;
				switch(choice)
				{
					case'1':{
						if(isfull())
						cout<<"\n\aThe Queue is Full!"<<endl;
						else
						{
							T data;
							cout<<"\nEnter data: ";
							cin>>data;
							enqueue(data);
						}
							break;
					}
					case'2':{
						 if(isempty())
			  		 	 display();
			  		 	 else
						 cout<<"\n"<<dequeue()<<endl;
						 break;
					}
					case'3':{
						display();
						break;
					}
					case'4':{
						exit(0);
						break;
					}
					default:{
						cout<<"\n\aInvalid Choice!"<<endl;
      				}
				}
				cout<<"\nDo You want to continue(Y/N): ";
				cin>>choice;
			}
			while(choice=='y'||choice=='y');
		}
		bool isempty()
		{
			if(rear==-1)
			return true;
			else
			return false;
		}
		bool isfull()
		{
			if(rear==size-1)
			return true;
			else
			return false;
		}
		void enqueue(T data)
		{
			if(isfull())
			{
				cout<<"\n\aStack Overflow!"<<endl;
			}
			else
			{
				rear++;
				arr[rear]=data;
				if(front==-1)
				front=0;
			}
		}
		T dequeue()
		{
			T data;
			if(isempty())
			display();
			else
			{
				data=arr[front];
				arr[front]='\0';
				if(front==rear)
				front=rear=-1;
				else
				front++;
				return data;
			}
		}
		void display()
		{
			if(isempty())
			cout<<"\n\aThe Queue is Empty!"<<endl;
			else
			{
				int i=front;
				cout<<"\nThe Queue is:\n"<<endl;
				do
				{
					cout<<arr[i++];
					if(i-1==rear)
					continue;
					cout<<" <-- ";
				}
				while(i-1!=rear);
				cout<<endl;
			}
		}
};
int main()
{
	int size;
	cout<<"\nEnter the size of Queue: ";
	cin>>size;
	Queue<int>obj(size);
	obj.menu();
	getch();
	return 0;
}
