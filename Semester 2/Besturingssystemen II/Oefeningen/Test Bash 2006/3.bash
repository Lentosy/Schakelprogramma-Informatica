while [[ $# -gt 1 ]]; do
    key=$1
    case $key in
	-n)N=$2; shift;;
	-k)K=$2; shift;;
	-w)W=$2; shift;;
    esac
    shift;
done;

N=${N:-100}
K=${K:-5}
W=${W:-16}

namen=($(cat 3.txt | shuf | head -n$N | sort))

(( rijen=N/K+1 ))

for ((i=0; i < $rijen; i++));do
    for ((j=0; j < $K; j++));do
	(( key=i+j*$rijen ))
	naam=${namen[$key]}
	[[ ${#naam} -gt $W ]] && {
	    naam=${naam:0:$W - 1}
	    naam+="."
	}
	printf "%-${W}s" $naam

    done;
    printf "\n";
done;
