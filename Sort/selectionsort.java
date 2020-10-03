import java.util.*;
class selectionsort
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter array in single line with space separated elements:");
		String str=sc.nextLine();
		String st[]=str.split(" ");
		int len=st.length;
		int arr[]=new int[len];
		for(int i=0;i<len;i++)
			arr[i]=Integer.parseInt(st[i]);
		int i,j,t,min;
		for(i=0;i<len-1;i++)
		{
			min=i;
			for(j=i+1;j<len;j++)
			{
				if(arr[j]<arr[min])
					min=j;
			}
			t=arr[i];
			arr[i]=arr[min];
			arr[min]=t;
		}
		System.out.println("Number arranged in ascending order are:");
		for(i=0;i<len;i++)
			System.out.print(arr[i]+" ");
	}
}