l<-c(rep(95.5,5),rep(105.5,8),rep(115.5,22),rep(125.5,27),rep(135.5,17),rep(145.5,9),rep(155.5, 5),rep(165.5,5),rep(175.5,2))
myfun <- function()
{
  ul <- unique(l)
  n <- length(ul)
  m <- mean(l)
  
  cat("\nMean : ", m)
  cat("\nStandard deviation : ", sd(l))
  cat("\nRange is (", min(l), ",", max(l), ")")
  
  for(i in 1:n)
  {
    cat("\nDeviation from mean of ", ul[i], " is : ", ul[i]-m) 
  }
}

myfun()