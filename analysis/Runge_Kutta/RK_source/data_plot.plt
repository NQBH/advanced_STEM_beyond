load 'para1.plt'

set key outside right
set grid
data='./data.txt'

if (p==2) {
set terminal push
set terminal lua tikz fulldoc createstyle
outfiletex = 'fig_ts.tex'
set output outfiletex
set title 'Timestep (h at time t)'
set xlabel 't'
set ylabel 'h'
plot data using 1:2 with lines title 'timestep' lt rgb 'blue'

set terminal pdf
outfilepdf = 'fig_ts.pdf'
set output  outfilepdf
replot

set terminal wxt 1 persist
set output
replot
}

do for [i=1:d] {
j=i+p-1
k=i+p
set terminal push
set terminal lua tikz fulldoc createstyle
outfiletex = 'fig_'.i.'.tex'
set output outfiletex
set xlabel 't'
set ylabel 'y'.i
set title 'Numerical solution of y'.i
plot data using 1:k with lines title 'y'.i lt rgb 'blue'

set terminal pdf
outfilepdf = 'fig_'.i.'.pdf'
set output  outfilepdf
replot

set terminal wxt j persist
set output 
replot
}
