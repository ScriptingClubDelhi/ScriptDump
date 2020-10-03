#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

template <class T>
class sorting
{
    T *data;
    int n;
    public:
    unsigned int count;
    sorting()
    {
        n=0;
    }
    ~sorting()
    {
        delete[] data;
        n=0;
    }
    int getsize()
    {
        return n;
    }

    void insert();
    void selectionsort();
    void display();
};

template <class T> void sorting<T>::insert()
{
    count=0;
    int ch,l;
    cout<<"\nEnter the no of elements in array:";
    cin>>n;
    data=new T[n];

    srand (time(NULL));

    cout<<"\n******MENU******\n"
    <<"\n1.WORST CASE\n"
    <<"\n2.BEST CASE\n"
    <<"\n3.AVERAGE CASE\n"
    <<"\nEnter your choice:";

    cin>>ch;

    switch(ch)
    {
        case 1: cout<<"\nEnter the elements of array\n";
                    for(int i=0,l=n;i<n;i++,l--)
                    {
                        data[i]=l;
                    }
                    break;

        case 2:cout<<"\nEnter the elements of array\n";
                    for(int i=0;i<n;i++)
                    {
                        data[i]=i;
                    }
                    break;

        case 3:  cout<<"\nEnter the elements of array\n";
                    for(int i=0,l=n;i<n;i++,l--)
                    {
                        data[i]=rand()%10;
                    }
                    break;

        default:cout<<"\nWrong choice!!!";
    }
}

template <class T> void sorting<T>::selectionsort()
{
    T small,temp;
    int pos;
    cout<<"\n\nSELECTION SORTING\n";
    for(int i=0;i<n-1;i++)
    {
        small=data[i];
        pos=i;
        for(int j=i+1;j<n;j++)
        {       count++;
            if(data[j]<small)
            {
                small=data[j];
                pos=j;
            }
        }
        temp=data[i];
        data[i]=data[pos];
        data[pos]=temp;
        cout<<"\nArray after "<<(i+1)<<" pass:\n";
        display();
    }
    cout<<"\nComparisons="<<count;
}

template <class T> void sorting<T>::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<data[i]<<endl;
    }
}

int main()
{
    system("cls");
    int s,choice,n,el,index,index2;
    char ch;
    sorting<int> ob;
    do
    {
        ob.insert();
        ob.selectionsort();
        cout<<"\nWant to do more(Y/N)?";
        cin>>ch;
        system("cls");
    }while(ch=='Y'||ch=='y');

    return 0;
}
