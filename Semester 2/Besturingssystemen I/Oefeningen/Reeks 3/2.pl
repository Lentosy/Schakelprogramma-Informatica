$scalar = [0..9];

print "Specific element: $scalar->[5]\n";
printf "Last indexnumber: %d\n", $#$scalar;
printf "Amount of elements: %d\n", scalar @{$scalar};
