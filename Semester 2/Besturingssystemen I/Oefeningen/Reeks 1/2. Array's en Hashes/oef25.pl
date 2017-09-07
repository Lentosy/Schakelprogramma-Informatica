@array = map { $_ * 3 } 1..30;

print join "\n", grep { $_ % 4 == 2 } @array;
print "\n";
