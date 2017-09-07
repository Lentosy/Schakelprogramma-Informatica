@array = qw(test array with 5 elements);
printf "Count: %d\n", scalar @array;

$#array = 9;

printf "Count: %d\n", scalar @array;
