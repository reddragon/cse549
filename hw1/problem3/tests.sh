#!/bin/bash
# time calcs
N=32
M=8
L=8

for (( n=$N; n<1024; n=$(($n*2)) ))
do
	for (( m=$M; m<1024; m=$(($m*2)) ))
	do
		for (( l=$L; l<$(($n)); l=$(($l*2)) ))
		do
			./gen $n $m $l > inp.3pm
			./ig < inp.3pm > out.3pm
			ttaken=$( ( time ./3 <out.3pm > fin.3pm )2>&1 )
			tim=$(echo $ttaken | cut -d ' ' -f 2)
			echo -n "N = $n, M = $m, L = $l, "
			cover=$(echo "scale=4;$m*$l/$n" | bc -q)
			echo -n "Coverage = $cover, "
			orig=$(tail -n 1 inp.3pm)
			found=$(tail -n 1 fin.3pm)
			rat=$(echo "scale=4;${#orig}/${#found}" | bc -q)
			echo "Len(original)/Len(found) = $rat, Time = $tim"
			# echo "original = $orig"
			# echo "found = $found"
			# echo "**************************"
		done
	done
done

