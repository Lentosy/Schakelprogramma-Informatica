%hash_1 = map { chr $_ => $_ } 65..80;
%hash_2 = map { chr $_ => $_ } 70..90;

%hash_3 = (%hash_1, %hash_2);

print "A: ", join " ", sort keys %hash_1;
print "\n";

print "B: ", join " ", sort keys %hash_2;
print "\n";

print "C: ", join " ", sort keys %hash_3;
print "\n";
