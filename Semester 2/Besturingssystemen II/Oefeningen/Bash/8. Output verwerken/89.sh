#!/bin/bash
(( $# != 1 )) && { printf "$0: Expecting one argument, was $#\n" >&2 ; exit 1 ; }
[[ -f "$1" ]] || { printf "$0: $1 is not a file\n" >&2 ; exit 1 ; }

res=( $(wc $1 ) )

l=${res[0]}
w=${res[1]}
c=${res[2]}

(( c += l / 2 ))
(( w += w / 2 ))

echo "Characters: $(( c / l ))"
echo "Words: $(( w / l ))" 