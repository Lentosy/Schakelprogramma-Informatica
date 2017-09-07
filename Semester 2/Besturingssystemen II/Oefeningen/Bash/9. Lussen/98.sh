(( $# < 2 )) && { printf "Expects at least two arguments, were $#\n" >&2 ; exit 1 ; }
[[ -f $1 ]] || { printf "$1 is not a file\n" >&2 ; exit 1 ; }

path=$1
shift 1;
for arg in $@; do
	cat $path | grep $arg
done;
