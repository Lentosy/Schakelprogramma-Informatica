%hash_1 = map { chr $_ => $_ } 65..80;
%hash_2 = map { chr $_ => $_ } 70..90;

%hash_3 = map { $_ => 0 } keys %hash_1;

while(($key) = each %hash_2){
  if(exists $hash_3{$key}){
    $hash_3{$key} = 1
  }else{
    $hash_3{$key} = 0
  }
}
print "Indices that appear in both hashes:\n", join " ", grep { $hash_3{$_} == 1 } keys %hash_3;
print "\n";
print "Indices that only appear in either hash:\n", join " ", grep {$hash_3{$_} == 0 } keys %hash_3;
print "\n";
