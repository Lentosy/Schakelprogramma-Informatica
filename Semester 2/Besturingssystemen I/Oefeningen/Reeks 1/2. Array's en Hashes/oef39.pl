@array = map { int rand($_); } 1..100;
%stats = ();

print join " ", sort @array;
print "\n";

for $i (@array){
  $stats{$i}++;
}

while(($key, $value) = each %stats){
  print "$key => $value\n";
}

print "\n";
