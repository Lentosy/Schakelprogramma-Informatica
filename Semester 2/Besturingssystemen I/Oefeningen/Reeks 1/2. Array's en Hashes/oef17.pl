@array = 1..10;

print join (", ", @array[0 .. $#array-1]);
print " en $array[-1]\n";
