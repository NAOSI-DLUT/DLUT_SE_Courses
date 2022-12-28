library(ISLR)
write.csv(Hitters, "hitter.csv")

write.csv(College, "shit.csv")
college = read.csv("shit.csv")
# rownames(college)=college[,1]
# fix(college)
Elite = rep("No", nrow(college))
Elite[college$Top10perc>50] = "Yes"
# Elite = as.factor(Elite)
college = data.frame(college, Elite)
summary(college$Elite)
# plot(college$Elite, college$Outstate)e
