#include<iostream>
#include<conio.h>
using namespace std;
template<class type>
struct Node
 {
 	 Node*previous;
 	 type data;
 	Node*next;
 };
  template<class type>
 class DLL
  {
   	public:
   	 	 struct Node<int>*head,head1;
   	 	 type e;
   	 	 DLL()
   	 	  { 
   	 	    head=NULL;
		  }
  void traverse()
	{ 
	  struct Node<int>*temp=head; 
	  if(head==NULL)
		{ 
		 cout<<"\n List is empty\n";
		  return ;
		}
		 else
		  {
			while(temp->next!=NULL)
			    {
			      temp=temp->next;
			      cout<<"\n traversing element from the list\n";
			      cout<<temp->data;
				}
		cout<<temp->data;
		cout<<endl;
		  }
	}
  void Insertionbeg(type el)
	{		    
	  struct Node<int>*temp=new Node<int>;    	
	  temp->data=el;
	  temp->next=head;
	  temp->previous=NULL;
	  head=temp;  
	}
	void Insertionend(type el)
	 { 
	  if(head==NULL)
	   { 
	     struct Node<int>*t=new Node<int>;
	     t->data=el;
	     head=t->next;
	     t->previous=NULL;
	     delete t;
	   }
		  else
			{ 
			 struct Node<int>*p=head;
			 while(p->next!=NULL)
				{
				 p=p->next;
				}
			struct Node<int>*temp=new Node<int>;
			temp->data=el;
			p->next=temp->previous;
		    temp->next=NULL;
			delete p;
			 }
	 }
  void display()
	{
	  if(head==NULL)
	    {
	      cout<<"\n List empty\n";
	      return;
		}
		 else
		  {
			cout<<"\n List is :";
			struct Node<int>*p=head;
			while(p->next!=NULL)
			 {
			  cout<<p->data<<"    ";
			  p=p->next;
			 }
		cout<<p->data;
		  }
	}
  void Concatination()
   {
	 int size;
	 struct Node<int>*p=head;
	 cout<<" data of first list\n";
	 while(p!=NULL)
		{
		  cout<<p->data<<" ";
		  p=p->next;    
		}
		 cout<<"Enter the number of elements want to insert in second list\n";
		 cin>>size;
		 cout<<"Enter the element of the secod list\n";
		 for(int i=0;i<size;i++)
		  {
		    cin>>e;
		    Instertionend(e);
		  }
   }
 void Alternate()
  {
	if(head==NULL)
	 {
	  cout<<"List empty\n";
	  return;
	 }
	  struct Node<int>*temp=head;
	  struct Node<int>*c=head->next;
	  if(temp->next==NULL)
	   {
		 cout<<"Alternating element:"<<endl;
		 cout<<temp->data<<" ";
		 return;
	   }
		 cout<<"Alternating element are: "<<endl;
		 while(temp->next!=NULL)
		  {
		   cout<<temp->data<<"  ";
		   if(c->next==NULL)
		    {
		     return;
		    }
		     else
		      {
		       temp=temp->next->next;
		      }
		  }
		    cout<<temp->data<<" "<<endl;
  }  
  void reverse()
	{
	  struct Node<int>*c=head;
	  struct Node<int>*p=NULL;
	  struct Node<int>*n;
		 while(c->next!=NULL)
		  {
		    n=c->next;
		    c->next=p;
		    p=c;
		    c=n;
		  }
		   c->next=p;
		   head=c;
	}
  void Search(type d)
	 {
	   struct Node<int>*p=head;
	   int count=1;
	   cout<<"Searching the elements list\n";
	     while(p->next!=NULL)
		         {
		            if(p->data==d)
		              {
		                cout<<"data found  at   "<<count<< "  node"<<"\n";
		                return;
		              }
		                count++;
		                p=p->next;
		          }
		              if(p->data==d)
		                {
		                  cout<<"data found  at   "<<count<<"     node"<<"\n";
		                  return;
		                 }
		                  else
		                   {
		                     cout<<"Element not found\n";
		                    }
	 }
     void Deletionbeg()
	   {
	      if(head==NULL)
	      {
		       cout<<" List empty\n";
		       return;
	      }
	        struct Node<int>*p=head;
	        head=head->next;
	        p->next=NULL;
	        delete p;
	   }
	 void Deletionend()
		 {
			if(head==NULL)
			  return;
			  struct Node<int>*p=head;
			  struct Node<int>*temp;
	     	  while(p->next!=NULL)
	     	     {  
                  temp=p;
	    	      p=p->next;
			      }
		   struct Node<int>*delete_node=temp->next;
		   delete delete_node;
	        temp->next=NULL;
		     delete p;
		  }
   };
