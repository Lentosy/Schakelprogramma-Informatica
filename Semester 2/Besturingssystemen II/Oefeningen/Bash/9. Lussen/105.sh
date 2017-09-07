[[ $# != 2 ]] && { printf "Expected two arguments, were $#.\n" >&2 ; exit 1 ; }
[[ -f $1 ]] || { printf "$1 is not a file.\n" >&2 ; exit 1 ; }

exec 3< $1
declare -A strings

while IFS=$'\n' read -u3 line; do
	[[ $line =~ ^\<$2\> ]] && {
		line=${line##<$2>};
		line=${line%%<\/$2>};

		for word in $line; do
			strings[$word]=0;
		done;
		
	}
done;
exec 3<&-


printf "%s\n" ${!strings[@]} | sort;