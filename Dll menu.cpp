#include<iostream>
#include<conio.h>
#include"DLL.h"
using namespace std;
template <class t>
void menu(DLL<t> &list)
{

	int choice,on;
	do{
		cout<<"Enter your choice"<<endl;
		cout<<"01. Insert at beginning"<<endl;
		cout<<"02. Insert at middle"<<endl;
		cout<<"03. Insert at end"<<endl;
		cout<<"04. Delete from beginning"<<endl;
		cout<<"05. Delete from middle"<<endl;
		cout<<"06. Delete from end"<<endl;
		cout<<"07. Search an element"<<endl;
		cout<<"08. Reverse the list"<<endl;
		cout<<"09. Add 2 lists"<<endl;
		cout<<"10. Concatenate 2 lists"<<endl;
		cout<<"11. Display Alternate Elements"<<endl;
		cout<<"12. Display the list"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:{list.InsertionStart();
			list.display();
				break;
			}
			case 2:{cout<<"Enter position of element to be inserted : ";
			int index;
			cin>>index;
			list.InsetionMiddle(index);
			list.display();
				break;
			}
			case 3:{list.InsertionEnd();
			list.display();
				break;
			}
			case 4:{list.DeletionStart();
			list.display();
				break;
			}
			case 5:{cout<<"Enter position of element to be deleted : ";
			int index;
			cin>>index;
			list.DeletionMiddle(index);
			list.display();
				break;
			}
			case 6:{list.DeletionEnd();
			list.display();
				break;
			}
			case 7:{cout<<"Enter element to be searched : ";
			t el;
			cin>>el;
			int index=list.search(el);
			if(index==-1)
			cout<<"Element not found"<<endl;
			else
			cout<<"element is present at "<<index<<" position"<<endl;
				break;
			}
			case 8:{list.reverse();
			list.display();
				break;
			}
			case 9:{int c;
				DLL<t> l2;
			do{
				cout<<"Enter elements in 2nd list"<<endl;
				cout<<"01. Insert at beginning"<<endl;
				cout<<"02. Insert at middle"<<endl;
				cout<<"03. Insert at end"<<endl;
				int ch;
				cin>>ch;
				switch(ch)
				{
					case 1:{l2.InsertionStart();
					l2.display();
						break;
					}
					case 2:{cout<<"Enter position of element to be inserted : ";
					int index;
					cin>>index;
					l2.InsetionMiddle(index);
					l2.display();
						break;
					}
					case 3:{l2.InsertionEnd();
					l2.display();
						break;
					}
					default:cout<<"Invalid choice"<<endl;
				}
				cout<<"To continue: Type 1 ";
				cin>>c;
			}while(c==1);
			list+l2;
			cout<<"Addition is \n";
			list.display();
				break;
			}
			case 10:{int c;
				DLL<t> l2;
			do{
				cout<<"Enter elements in 2nd list"<<endl;
				cout<<"01. Insert at beginning"<<endl;
				cout<<"02. Insert at middle"<<endl;
				cout<<"03. Insert at end"<<endl;
				int ch;
				cin>>ch;
				switch(ch)
				{
					case 1:{l2.InsertionStart();
					l2.display();
						break;
					}
					case 2:{cout<<"Enter position of element to be inserted : ";
					int index;
					cin>>index;
					l2.InsetionMiddle(index);
					l2.display();
						break;
					}
					case 3:{l2.InsertionEnd();
					l2.display();
						break;
					}
					default:cout<<"invalid choice"<<endl;
				}
				cout<<"To continue: Type 1 ";
				cin>>c;
			}while(c==1);
			list.concat(l2);
			list.display();
				break;
			}
			case 11:{list.alternate();
				break;
			}
			case 12:{list.display();
				break;
			}
			default:cout<<"Invalid choice\n";
		}
		cout<<"To continue : Type 1 ";
		cin>>on;
	}while(on==1);
}
int main()
{
	DLL<int> l1;
	menu(l1);
	getch();
	return 0;
}