
for arg; do
	[[ -f "$arg" ]] && {
		files+=($arg);
	}
	[[ -d "$arg" ]] && {
		directories+=($arg);
	}
	[[ $arg =~ -l ]] || [[ $arg =~ -w ]] || [[ $arg =~ -c ]] && {
		options+=($arg);
	}
done;

[[ ${#options[@]} == 0 ]] && {
	options+=("-l");
	options+=("-w");
	options+=("-c");
}

[[ ${#files[@]} == 0 ]] && [[ ${#directories[@]} == 0 ]] && {
	directories+=("$(pwd)");
}

TEMP=$(mktemp 111tempXXXXXX)
exec 3> $TEMP

for file in ${files[@]}; do
	wc $file 2>/dev/null >&3
done;

for directory in "${directories[@]}"; do
	for file in "$(find $directory -type f 2>/dev/null)"; do
		wc $file 2>/dev/null >&3
	done;
done;
exec 3<&-

exec 3< $TEMP


# fields is a variable to use with commando cut
for opt in ${options[@]}; do
	case $opt in
		-l) { fields+="1,"; l=1; };;
		-w) { fields+="2,"; w=1; };;
		-c) { fields+="3,"; c=1; };;
	esac;
done;
fields+="4";

while read -u3 line; do
	echo $line | cut -d ' ' -f$fields;
done;


exec 3<&-


rm $TEMP;

