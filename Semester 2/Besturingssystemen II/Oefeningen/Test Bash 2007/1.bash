[[ $# -gt 1 ]] && {
    printf "Expected one or zero arguments, were %d\n" $# >&2;
    exit 1;
}

[[ $# -eq 1 ]] && {
    [[ -d $1 ]] && {
	dir=$1
    } || {
	printf "%s it not a directory, taking current working directory.\n" $1
	dir=$(pwd)
    }
}

[[ $# -eq 0 ]] && {
    dir=$(pwd)
}


directories=($(find  "$dir" -maxdepth 1 -type d 2>/dev/null))
directories=(${directories[@]:1}) # De parentdirectory verwijderen


totalfiles=0
totalbytes=0
for directory in ${directories[@]}; do
    files=($(find "$directory" -type f -printf "%s\n" 2>/dev/null))
    (( totalfiles+=${#files[@]} ))
    bytes=0
    for filesize in ${files[@]}; do
	((bytes+=$filesize));
    done;
    (( totalbytes+=$bytes ))
    printf "%-25s %5d %10d\n" $directory ${#files[@]} $bytes
done;


printf "\n"
printf "%-25s %5d %10d\n" $dir $totalfiles $totalbytes
