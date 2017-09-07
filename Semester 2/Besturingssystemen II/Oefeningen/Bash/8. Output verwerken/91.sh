#!/bin/bash
(( $# != 1 )) && { printf "Expecting one argument, was $#\n" >&2 ; exit 1 ; }
name=$(grep -E "^([^:]*:){2}$1" /etc/passwd | cut -d : -f1)
[[ -z "$name" ]] && { printf "No user with uid=$1 found\n" >&2 ; exit 1 ; }
printf "%s\n" $name

