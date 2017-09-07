exec 3< ping.out
declare -A list

enabled=0;
disabled=0;
while read -u3 v1 v2 v3; do
	[[ "$v1" == "Pinging" ]] && { list[$v2]=1 ; pc=$v2 ; ((disabled++)) ; }
	[[ "$v1" == "Reply" ]] && { unset list[$pc] ; ((enabled++)) ; ((disabled--)) ;}
done;
echo ${!list[@]} | xargs -n1 | sort
echo "Enabled:  $enabled"
echo "Disabled: $disabled"
exec 3<&-