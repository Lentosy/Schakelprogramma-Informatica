exec 3< pagefile.out

declare -A computers

while IFS=$'\n' read -u3 line; do

	[[ "$line" =~  "Directory" ]] && {
		pc=$(echo $line | cut -d ' ' -f3);
		pc=${pc#\\};
		pc=${pc%c$};
	}

	[[ "$line" =~ "bytes free" ]] && {
		bytes=$(echo $line | cut -d ' ' -f1 | tr -d '.');
		computers[$pc]=$bytes;
	}

done;

for pc in ${!computers[@]}; do
	(( ${computers[$pc]}  < 80000000 )) && {
		printf "%s: %s\n" $pc ${computers[$pc]};
	}
done;

exec 3<&-