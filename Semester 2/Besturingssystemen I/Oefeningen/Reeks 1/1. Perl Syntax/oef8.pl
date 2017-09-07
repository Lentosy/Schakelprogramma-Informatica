@numbers = 0..9;

for (@numbers) {
  print sprintf "%3d", $_;
}

print "\n";

for $n (@numbers){
  print sprintf "%3d", $n;
}

print "\n";

for ($n = 0; $n < scalar @numbers; $n++){
  print sprintf "%3d", @numbers[$n];
}

print "\n";
