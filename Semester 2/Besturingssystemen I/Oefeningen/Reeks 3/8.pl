%hash = map{ $_ =>  $_ % 5 } 1..10;
%reversedhash = ();

while(($key, $value) = each %hash){
  $reversedhash{$value} = [] unless $reversedhash{$value};
  push @{$reversedhash{$value}}, $key;
}

while(($key, $value) = each %reversedhash){
  print "$key => [@{$value}]\n";
}
