%hash = map { $_ => [$_, $_*2, $_*4]} 1..5;

for $key (sort keys %hash){
  push @{$hash{$key}}, $key * 8;
  print join " ", @{$hash{$key}};
  print "\n";
}
