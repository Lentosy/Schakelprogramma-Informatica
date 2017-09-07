[[ $# -gt 2 ]] && { printf "Too many arguments.\n" >&2 ; exit 1 ; }

[[ -d $1 ]] && {
    dir=$1
    shift
} || {
    dir=$(pwd)
}

n=${1:-1}

find "$dir" -printf "%p:%Ts\n" 2>/dev/null | sort -t ':' -nr -k2 | head -n$n | cut -d ':' -f1

