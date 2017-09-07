@array = 1..5;

while(1){
  push @array, $i = shift @array;
  print "$i\n";
  sleep 1;
}
