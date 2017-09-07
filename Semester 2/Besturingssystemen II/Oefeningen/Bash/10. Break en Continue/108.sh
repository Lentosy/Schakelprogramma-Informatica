exec 3< stud.txt


while IFS=$'\n': read -u3 id name rest; do

	first=${name:0:1};
	firstname=$(cut -d ' ' -f1 <<< $name);
	for n in $name; do
		[[ "$n" == "$firstname" ]] && { continue ; }
		[[ "${n,,}" =~ "van|de|den|der" ]] && { continue ; }
		last=${n:0:1};
	done;
	number=${id:2:6};
	printf "%s%s%s\n" $first $last $number;

done;

exec 3<&-