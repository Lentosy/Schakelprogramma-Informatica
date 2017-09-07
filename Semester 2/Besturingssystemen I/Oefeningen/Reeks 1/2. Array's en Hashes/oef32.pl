%hash = map { chr $_ => undef} 65..90;

print join " ", sort keys %hash;
print "\n";

delete @hash{'O', 'A', "\Ub"};

print join " ", sort keys %hash;
print "\n";
