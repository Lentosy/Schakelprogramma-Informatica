exec 3< /etc/group
while IFS=$'\n': read -u3 naam pass gid rest; do
	echo $gid $(grep -E "^([^:]*:){3}$gid:" /etc/passwd | wc -l)
	#exec 4< /etc/passwd
	#while IFS=$'\n': read -u4 naamu passu uidu gidu restu; do
	#	[[ "$gidu" == "$gid" ]] && group[$gid]+="$naamu ";	
	#done;
	#exec 4<&-
done; sort -n -k1,1

exec 3<&-