(( $# != 1 )) && { printf "Expected one argument, was $#\n" >&2 ; exit 1 ; }


echo $(grep -w $1 /etc/group | cut -d ':' -f4)