
declare -A computers

exec 3<2.txt
while read -u3 line; do
    [[ $line =~ "Directory of" ]] && {
	currentpc=$(echo $line | grep -Eo "[A-Z0-9]{2,}")
	computers[$currentpc]=-1
    }

    [[ $line =~ "bytes free" ]] && {
	free=$(echo $line | grep -Eo "([0-9]{3}.)*" | tr -d '.')
	computers[$currentpc]=$free
    }
done;


(( twentymb=20*1024*1024 ))
for computer in ${!computers[@]}; do
    [[  ${computers[$computer]} -lt  $twentymb ]] && {
	printf "%-10s 10%s\n" $computer ${computers[$computer]}
    }
done;
exec 3<&-
