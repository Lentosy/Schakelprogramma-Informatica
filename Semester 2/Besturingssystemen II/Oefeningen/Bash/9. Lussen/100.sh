#!/bin/bash
declare -A freq

[[ "${1,,}" == "-i" ]] && { ignorecase=1 ; shift ;}	
for arg in $@; do
	(( ignorecase == 1 )) && { key=${arg,,} ; } || { key=$arg ; }
	(( freq[${key}]++ ));
done;

for i in ${!freq[@]}; do
	[[ ${freq[$i]} -gt 1 ]] && 	printf "%s: %d\n" $i ${freq[$i]};
done;
