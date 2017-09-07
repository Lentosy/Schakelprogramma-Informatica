[[ $# != 3 ]] && { printf "Expecting three arguments, were $#.\n" >&2 ; exit 1 ; }
[[ -d $1 ]] || { printf "$1 is not a directory.\n" >&2 ; exit 1 ; }


#TODO: herschrijven
dirs=(); # Een lijst van nog te doorlopen directories
for entry in $(find "$1" -maxdepth 1 -type d -printf "%f\n"); do
	dirs+=($entry);
done;
unset 'dirs[0]' # De directory waarin we zoeken is niet belangrijk
declare -p dirs;

index=${#dirs[@]}; # Het laatste element

while [[ ${#dirs[@]} != 0 ]]; do
	for entry in $(find $1"${dirs[index]}" -maxdepth 1 -type d -printf "%f\n"); do
		echo $entry;
	done;
	unset 'dirs[$index]';
	(( index-- ));
	declare -p dirs;
done;

