%hash_1 = map { $_ => $_ * 2 } 1..10;
%hash_2 = map { $_ => $_ * 2 } 5..15;
%hash_3 = ();

for $hash (\%hash_1,\%hash_2){
  while(($key, $value) = each %{$hash}){
    if(exists $hash_3{$key}){
      print "$key already exists\n";
    }else{
      $hash_3{$key} = $value;
    }
  }
}


print "--HASH 1--\n";
printhash(\%hash_1);
print "--HASH 2--\n";
printhash(\%hash_2);
print "--HASH 3--\n";
printhash(\%hash_3);

sub printhash {
  %hash = %{$_[0]};
  while(($key, $value) = each %hash){
    print "$key => $value\n";
  }
}
