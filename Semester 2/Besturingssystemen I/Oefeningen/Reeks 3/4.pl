$scalar;


for ($i = 1; $i < 5; $i++){
  $scalar->{$i} = [$i, $i * 2, $i * 4, $i * 8];
}

while(($key, $value) = each %{$scalar}){
  print "$key => @$value\n";
}

print "\n";
