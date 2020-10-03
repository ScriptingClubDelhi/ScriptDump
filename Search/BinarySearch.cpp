#include<iostream>
#include<conio.h>
using namespace std;
int BinarySearch(int a[],int el,int high,int low=0,int mid=0)
{
	mid=(high+low)/2;
	if(low>high)
	return -1;
	else
	if(el==a[mid])
	return mid+1;
	else
	if(el<a[mid])
	return BinarySearch(a,el,mid-1,low);
	else
	if(el>a[mid])
	return BinarySearch(a,el,high,mid+1);
}
int main()
{
	int *a,size,el;
	cout<<"::Binary Search Program::"<<endl;
	cout<<"\nEnter the size of array: ";
	cin>>size;
	a=new int[size];
	cout<<"\nEnter the elements in array: ";
	for(int i=0;i<size;i++)
	cin>>a[i];
	cout<<"\nEnter an element to search: ";
	cin>>el;
	int res=BinarySearch(a,el,size-1);
	if(res==-1)
	cout<<"\n\aElement not found!";
	else
	cout<<"\nElement found at position: "<<res;
	getch();
	return 0;
}
