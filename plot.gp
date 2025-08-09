set view map
set size ratio -1
unset key
set colorbox

set log cb

set format cb "10^{%L}"
set cblabel "E [V/m]"

set xlabel "X [m]"
set ylabel "Y [m]"

plot "out.tsv" using 1:2:3 with image
pause -1