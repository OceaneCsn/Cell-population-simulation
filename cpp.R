library(ggplot2)
tab = read.table("Rdiagram.txt", stringsAsFactors = F, header=T, sep=" ") 
qplot(factor(Ainit), factor(T), fill='val', data = tab, geom = "bin2d", main = c("Phase diagram of the system","Glucose initial", "Periode de lavages"))


ggplot( data = tab, aes(x=Ainit, y=T, fill=val),environment=environment()) + geom_tile() 

ggplot(data =  data, aes(x = Ainit, y = T)) + 
  geom_tile(aes(fill = factor(val))) +
  scale_fill_manual(name="Etat final \n du système",labels=c("Extinction", "Exclusion", "Cohabitation"), values = c("darkblue", "royalblue", "lightgrey"))

tab
ggplot(data =  tab, aes(x = Ainit, y = T)) + 
  geom_tile(aes(fill = factor(val)))
