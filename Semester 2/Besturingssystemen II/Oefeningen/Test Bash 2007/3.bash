

while (( $# > 1 )); do
    key=$1;
    case $key in
	-n)N=$2;
	   last="-n";
	   shift;
	   ;;
	-b)B=$2;
	   last="-b";
	   shift;
	   ;;
    esac
    shift;
done;

origfile=$1;

lines () {
    totallines=$(wc -l < <(cat $origfile));
    (( totalfragments= $totallines / $N ));
    (( totalfragments >= 1000 )) && {
	printf "Er zijn meer dan 999 fragmenten nodig om dit bestand op te splitsen met het gegeven aantal lijnen per bestand.\n" >&2;
	exit 1;
    }

    exec 3<$origfile;
    currentline=$N;
    suffix=0;
    while read -u3 line; do
	(( currentline==$N )) && {
	    exec 4<&-;
	    formattedsuffix=$(printf ".%03d" $suffix);
	    file=$origfile$formattedsuffix;
	    exec 4>$file;
	    files+=($file);
	    (( suffix++ ));
	    currentline=0;
	}
	echo $line >&4
	(( currentline++ ));
    done;
    exec 3<&-;
    summary;
}


bytes () {
    totalbytes=$(du -b $origfile);
    (( totalfragments= $totalbytes / $B ));
    (( totalfragments >= 1000 )) && {
	printf "Er zijn meer dan 999 fragmenten nodig om dit bestand op te splitsen met het gegeven aantal bytes per bestand.\n" >&2;
	exit 1;
    }
    exec 3<$origfile;
    currentbyte=$B;
    suffix=0;

    # Effectief wegschrijven niet geïmplementeerd

    exec 3<&-;
    summary;
}


summary() {
    wc -l -c ${files[@]};
    wc -l -c $origfile;
    exit 0;
}


[[ -z $N ]] && [[ -z $B ]] && {
    N=1000;
    lines;
}

[[ $last = "-n" ]] && {
    lines;
} || {
    bytes;
}





