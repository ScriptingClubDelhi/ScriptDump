age <- c(rep(20,5),rep(21,3),rep(22,4),rep(23,3))
count <- table(age)
modeAge <- names(count)[count==max(count)]

cat("AGES : ",sort(age))
cat("AGES under 22 : ",sort(age[age<22]))
cat("Median Age of all students under 22 years : ",median(age[age<22]))
cat("Median Age is : ",median(age))
cat("Mean Age is : ",mean(age))
cat("Mode Age is : ",modeAge)

age <- c(age,c(23,23))
cat("NEW AGES : ",sort(age))
cat("Median Age is : ",median(age))
cat("Mean Age is : ",mean(age))
cat("Mode Age is : ",modeAge)