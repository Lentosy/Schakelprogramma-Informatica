
@array = qw (10 5 6 4 9 1 3 2 7 8);


print join " ", sort {$a <=> $b} @array;

print "\n";
