library(ggplot2)
tab = read.table("Rdiagram.txt", stringsAsFactors = F, header=T, sep=" ") 
qplot(factor(Ainit), factor(T), fill='val', data = tab, geom = "bin2d", main = c("Phase diagram of the system","Glucose initial", "Periode de lavages"))

ggplot( data = tab, aes(x=Ainit, y=T, fill=val),environment=environment()) + geom_tile() 
tab
