
[[ $# != 1 ]] && {
	printf "Expecting one argument, were $#\n" >&2 ; 
	exit 1 ; 
}

[[ -d $1 ]] && {
	printf "$1 already exists\n" >&2 ;
	exit 1 ;
}

echo "$1" | while IFS=$'/' read directory; do
	echo $directory;
done;