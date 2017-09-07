exec 3< /etc/passwd
while IFS=$'\n': read -u3 name pass uid gid rest; do
	#[[ -z group[$gid] ]] && { group[$gid]=0 ; } || { (( group[$gid]++ )) ; } 
	(( group[$gid]++ )) # Beter manier, bovenstaand is onnodig
done;
for i in ${!group[@]}; do
	echo "$i : ${group[$i]}";
done;
exec 3<&-