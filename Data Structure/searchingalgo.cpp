#include <iostream>
using namespace std;
bool linearsearch(int [],int,int);
bool binarysearch(int [],int ,int);
void bubblesort(int [],int );
int main()
{
    cout << "Enter the size of the array: ";
    int size,opt,choice,ele;
    bool found=false;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin >> arr[i];
    do
    {
        cout << "Choose an option" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cin >> opt;
        switch(opt)
        {
            case 1: cout << "Enter the element to search: ";
                    cin >> ele;
                     found=linearsearch(arr,size,ele);
                    if(found)
                        cout << "Element found" << endl;
                    else
                        cout << "element not found" << endl;
                    break;
            case 2: cout << "Enter the element to search: ";
                    cin >> ele;
                    bubblesort(arr,size);
                     found=binarysearch(arr,size,ele);
                    if(found)
                        cout << "Element found" << endl;
                    else
                        cout << "Element not found" << endl;
                    break;
        }
        cout << "Enter 1 for again 0 for exit" << endl;
        cin >> choice;

    }while(choice!=0);
}
bool linearsearch(int arr[],int size,int ele)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==ele)
            return true;
    }
    return false;
}
void bubblesort(int arr[],int size)
{
    int flag=0;
    bool f=false;
    for(int i=0;i<size;i++)
    {
        f=false;
        for(int j=0;j<size-1-i;j++)
        {
            flag++;
            if(arr[j]>arr[j+1])
            {
                f=true;
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        if(!f)
            break;
    }
}
bool binarysearch(int arr[],int size,int ele )
{
    int start=0;
    int end=size-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==ele)
            return true;
        else if(arr[mid] < ele)
        {
            start=mid+1;
            continue;
        }
        else
            end=mid-1;
    }
    return false;
}
