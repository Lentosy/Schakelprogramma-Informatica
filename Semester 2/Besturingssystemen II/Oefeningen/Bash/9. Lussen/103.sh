exec 3< <(ps -e);

kill_process () {
	pattern=$1
	shift;
	for arg in $@; do
		pattern+="|$arg";
	done;

	while read -u3 pid tty time cmd; do
		[[ $(echo $cmd | grep -E $pattern) ]] && {
			printf "Killing %s: %s\n" $pid $cmd;
		}
	done;
}

print_list () {
	declare -A cmds
	while read -u3 pid tty time cmd; do
		cmds[$cmd]=0 #waarde is onbelangrijk
	done;
	printf "%s\n" "${!cmds[@]}" | sort
}

[[ $# == 0 ]] && print_list || kill_process  "$@"

exec 3<&-