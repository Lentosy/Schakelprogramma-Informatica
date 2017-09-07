@array_1 = 1..20;
@array_2 = 10..30;
%hash = ();

print "A: ", join " ", @array_1, "\n";
print "B: ", join " ", @array_2, "\n";

@hash {@array_1} = ();
delete @hash {@array_2};

print "A not B: ", join " ", sort keys %hash;

print "\n";
