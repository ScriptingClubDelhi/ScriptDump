s1 <- sample(1:6, 40, replace = TRUE)
s2 <- sample(1:6, 70, replace = TRUE)
s3 <- sample(1:6, 100, replace = TRUE)
t <- table(s1) #q13
rel <- rank(t)/length(t)



barplot(t, main = "BAR PLOT OF SAMPLE", xlab = "Faces of dice", ylab = "Frequency", border = "dark blue", col = gray(1-rel)) 

