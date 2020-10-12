palindrome <- function(s) s==paste(rev(strsplit(s, NULL)[[1]]), collapse='')

palindrome("ashihsa")
