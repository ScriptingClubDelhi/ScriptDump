class smallestpositivenumber
{
	public static void main(String[] args)
	{
		int x=0;
		int i=1;
		while(i>0)
		{
			for(int j=1;j<=20;j++)
			{
				if(i%j!=0)
					{
						x=0;
						break;
					}
				else
					x=1;
			}
			if(x==1)
				break;
			i++;
		}
		System.out.println("result: "+i);
	}
}