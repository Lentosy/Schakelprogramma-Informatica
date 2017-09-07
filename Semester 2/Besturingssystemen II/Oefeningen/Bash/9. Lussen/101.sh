#!/bin/bash
word_count() {
	files=("$@");
	for f in ${files[@]}; do
	exec 3< $f;
	lines=0;
	while read -u3 line; do
		(( lines++ ));
	done;
	printf "%d %s\n" $lines $f;
	exec 3<&-;
	done;
}

[[ ${#@} == 0 ]] && word_count $(ls "$(pwd)") || word_count "$@"  
