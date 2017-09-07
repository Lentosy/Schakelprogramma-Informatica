program="./74b.sh"

$program $*
$program $@
$program "$*"
$program "$@"
IFS=:
$program $*
$program $@
$program "$*"
$program "$@"