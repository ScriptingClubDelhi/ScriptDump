s1 <- sample(1:6, 40, replace = TRUE)
s2 <- sample(1:6, 70, replace = TRUE)
s3 <- sample(1:6, 100, replace = TRUE)
t <- table(s1) #q13
rel <- rank(t)/length(t)

plot(s1, main = "SCATTER PLOT OF SAMPLE", xlab = "Index", ylab = "Faces of dice") 

