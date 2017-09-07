%hash = ();

$key = "key";
$val = "val";

if(exists $hash{$key}){
  print "$key exists";
}else{
  print "$key does not exist";
}
print "\n";

$hash{$key} = $val;
if(exists $hash{$key}){
  print "$key exists";
}else{
  print "$key does not exist";
}
print "\n";
