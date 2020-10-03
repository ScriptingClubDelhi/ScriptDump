import java.util.*;
class binarysearch
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter sorted array in single line with space separated elements:");
		String str=sc.nextLine();
		String st[]=str.split(" ");
		int len=st.length;
		int arr[]=new int[len];
		for(int i=0;i<len;i++)
			arr[i]=Integer.parseInt(st[i]);
		System.out.println("Enter number to be searched:");
		int x=sc.nextInt();
		int lb=0,ub=len-1,k=0,mid=0;
		while(lb<=ub) //Input array must be sorted in ascending order.
		{
			mid=(lb+ub)/2;
			if(arr[mid]<x)
				lb=mid+1;
			if(arr[mid]>x)
				ub=mid-1;
			if(arr[mid]==x)
			{
				k=1;
				break;
			}
		}
		if(k==1)
			System.out.println("Search Successful");
		else
			System.out.println("The number is not present");

		}
	}
