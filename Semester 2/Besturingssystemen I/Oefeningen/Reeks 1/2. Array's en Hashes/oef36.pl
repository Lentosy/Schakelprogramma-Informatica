%hash = map { chr $_ => $_ } 65..90;

print join " ", sort keys %hash;

print "\n";

print join " ", sort { $a <=> $b } values %hash;

print "\n";
