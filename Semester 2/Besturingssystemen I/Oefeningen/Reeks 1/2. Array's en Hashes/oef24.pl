@array = map { $_ * 3 } 1..100;

for ($i = 0; $i < @array; $i++){
  if ($array[$i] % 4 == 2){
    print "Index: $i\n";
    print "Value: $array[$i]\n";
    last;
  }
}
