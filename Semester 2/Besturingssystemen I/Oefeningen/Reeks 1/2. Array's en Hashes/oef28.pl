@array = map { $_ % 10 } 0..500;
%hash = ();


for $i (@array){
  $hash{$i} = undef unless $hash{$i};
}

print join " ", sort keys %hash;
