library(gdata)
student_data <- read.xls("st_data.xls")

midterm_score <- student_data$Midterm
breaks <- seq(0, 100, 10)
midterm_score.cut <- cut(midterm_score, breaks, right=FALSE)
midterm_score.freq <- cbind(table(midterm_score.cut))
print(midterm_score.freq)
readline()

hist(midterm_score, right=FALSE, main="Histogram of midterm", xlab="midterm", ylab="Frequency")
readline()

final_score <- student_data$Final
plot(midterm_score, final_score, xlab="Midterm Exam", ylab="Final Exam")
readline()

print(mean(midterm_score))
print(var(midterm_score))
print(sd(midterm_score))
readline()
