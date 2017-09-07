%hash = map { chr $_ => $_ } 65..90;

print join " ", sort keys %hash;
print "\n";

while(($key, $value) = each %hash){
  print "$key => $value\n";
}
