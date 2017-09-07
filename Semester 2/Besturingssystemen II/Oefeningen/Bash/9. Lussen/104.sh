
opts=();
for arg in $@; do

	[[ $arg =~ ^-.* ]] && {
		count=${#arg};
		index=1;
		while [ $index -lt $count ]; do
			opts+=(${arg:index:1});
			((index++))
		done;
	}
done;

echo ${opts[@]};