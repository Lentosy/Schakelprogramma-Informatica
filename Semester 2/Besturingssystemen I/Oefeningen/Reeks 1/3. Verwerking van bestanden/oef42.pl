$read = "oef42file";
$write = "oef42filenew";

open(READ , "<", $read) or die "Could not open file: $!";
open(WRITE, ">", $write) or die "Could not open file: $!";

while(<READ>){
  chomp;
  print WRITE $_ . " a\n" or die "Could not write to file: $!";
}


close(READ);
close(WRITE);

rename $write, $read;
