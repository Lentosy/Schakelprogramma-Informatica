#!/bin/bash
(( $# < 1 || $# > 2 )) && { printf "Expecting at least one argument and maximum 2, were $#\n" >&2 ; exit 1 ; }
[[ -f "$1" ]] || { printf "$1 is not a file" >&2 ; exit 1 ; }

close_handler () {
	exec 3<&- 
}
trap close_handler 15


counter=0;
total=10;

exec 3< "$1"
while read -u3 line; do
	lines[(( counter % total ))]="$line"
	((counter++))
done;



i=0;
while (( i < totaal )); do
	echo ${lines[$(((counter + i) % total))]}
	((i++))
done;

exec 3<&-
#for i in ${lines[@]}; do
#	echo $i;
#done;