load 'para1.plt'
load 'para2.plt'

set key outside right
set grid
data='./data.txt'

f1=v1+p
f2=v2+p
set terminal push
set terminal lua tikz fulldoc createstyle
outfiletex = 'fig_d_'.v1.'_'.v2.'.tex'
set output outfiletex
set xlabel 'y'.v1
set ylabel 'y'.v2
set title 'Dependency of y'.v1.' and y'.v2
plot data using f1:f2 with lines title 'dependency' lt rgb 'blue'

set terminal pdf
outfilepdf = 'fig_d_'.v1.'_'.v2.'.pdf'
set output  outfilepdf
replot

e=d+p
set terminal wxt e persist
set output
replot
