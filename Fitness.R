#!/usr/bin/env Rscript
args = commandArgs(trailingOnly=TRUE)

if (length(args)==0) {
  stop("At least one argument must be supplied (input file).n", call.=FALSE)
} else if (length(args)==1) {
  # default output file
  args[2] = "Fitness.jpeg"
}

tab <- read.table(args[1], header = TRUE, sep = " ",stringsAsFactors = F)

jpeg(args[2])

plot(tab$t,tab$meanA, col = "blue", type = "l",main = "Fitness moyenne des 2 types cellulaires au cours du temps", xlab = "temps",ylab = "Nombre d'individus")
lines(tab$t,tab$meanB, col = "red")
legend("topleft", legend=c("Fitness A", "Fitness B"), col=c("blue","red"),lty=c(1,1),cex=0.8)

#print(obj)
dev.off()
