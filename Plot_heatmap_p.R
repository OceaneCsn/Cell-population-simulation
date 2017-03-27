#!/usr/bin/env Rscript
args = commandArgs(trailingOnly=TRUE)

if (length(args)==0) {
  stop("At least one argument must be supplied (input file).n", call.=FALSE)
} else if (length(args)==1) {
  # default output file
  args[2] = "out.pdf"
}

library("ggplot2")

data <- read.table(args[1], header = TRUE, sep = " ")

# extinct <- data[data[,3]==0,]
# cohab <- data[data[,3]==2,]
# exclu <- data[data[,3]==1,]

pdf(args[2])
# plot(extinct[,1],extinct[,2], col="yellow", pch=15, cex=3, main="Etat final du système en fonction de Ainit et T" )
# points(cohab[,1],cohab[,2], col="royalblue", pch=15, cex=3)# add=TRUE)
# points(exclu[,1],exclu[,2], col="firebrick", pch=15, cex=3)# add=TRUE)
# legend("topright", leg=c("Ext","Cohab", "Exclu"), col=c("yellow", "royalblue", "firebrick"), pch=15)

obj <- ggplot(data =  data, aes(x = Ainit, y = T)) + 
  geom_tile(aes(fill = val))# +
#  scale_fill_manual(name="Etat final \n du système")

print(obj)
dev.off()
