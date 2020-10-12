n <- as.numeric(readline("Enter the value of n : "))
cat("Multiplication table of ",n," is : \n")

for (i in 1:10)
{
  cat(n," * ",i," = ",n*i,"\n")
}

