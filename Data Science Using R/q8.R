linearSearch <- function(list, element)
{
  pos = 1;
  flag = FALSE; 
  for (x in list)
  {
    if (x==element)
    {
      flag = TRUE;
      break;
    }
    pos = pos+1;
  }
  if(flag) 
  {
    print(paste("Element found at",pos),quote = FALSE);
  }
  else 
  {
    print("Element not found",quote=FALSE);
  }
}

linearSearch(c(23,1,13,463,540,2),2)
