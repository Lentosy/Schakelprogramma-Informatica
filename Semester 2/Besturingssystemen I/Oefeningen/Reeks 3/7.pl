%hash = ();

for ($i = 1; $i < 10; $i++){
  $hash{$i} = [$i * 2, $i * 4];
}

while(($key, $value) = each %hash){
  print "$key => [@{$value}]\n";
}
