import java.util.*;
class rearrangearray
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
		int posarr[]=new int[len];
		int negarr[]=new int[len];
		int j=0,k=0;
		for(int i=0;i<len;i++)
		{
			if(arr[i]<0)
				{
					negarr[j]=arr[i];
					j++;
				}
			else
				{
					posarr[k]=arr[i];
					k++;
				}
		}
		int neglen=j,poslen=k;
		 j=0;k=0;
		for(int i=0;i<len;i++)
		{
			if(i<neglen)
				{
					arr[i]=negarr[j];
					j++;
				}
			else
				{
					arr[i]=posarr[k];
					k++;
				}
		}
		System.out.println("\n");
		for(int i=0;i<len;i++)
			System.out.print(arr[i]+" ");
	}
}