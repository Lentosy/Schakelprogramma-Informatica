#!/bin/bash
(( $# != 2 )) && { printf "$0: Expected two arguments, were $#\n" >&2 ; exit 1 ; }
[[ -d $1 ]] || { printf "$1 is not a directory\n" >&2 ; exit 1 ; }
find $1 -type f -size +$2c -printf "%p %s\n" 2>/dev/null;