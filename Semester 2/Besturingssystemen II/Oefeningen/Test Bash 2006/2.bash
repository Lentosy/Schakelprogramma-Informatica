

declare -A computers

exec 3<2.txt

while read -u3 v1 v2 v3; do
    [[ $v1 =~ "Pinging" ]] && {
	computers[$v2]=0
	currentpc=$v2
	(( aantalcomputers++ ))
    }

    [[ $v1 =~ "Reply" ]] && {
	unset computers[$currentpc]
    }

done;
exec 3<&-

printf "%s\n" ${!computers[@]} | sort 
printf "Inactieve toestellen: %d\n" ${#computers[@]}
printf "Totale toestellen %d\n" $aantalcomputers;
