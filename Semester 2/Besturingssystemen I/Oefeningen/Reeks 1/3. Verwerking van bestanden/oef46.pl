@ARGV = "file";

@lines = <>;

for($i = 0; $i < @lines; $i++){
  print "$i: $lines[$i]" if int rand(5) == 1;
}
