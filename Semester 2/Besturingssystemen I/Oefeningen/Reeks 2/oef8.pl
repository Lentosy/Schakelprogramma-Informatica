$filename = "file";
open FILEHANDLE, "<", $filename or die "Could not open $filename: $!";


%frequency = ();
while(<FILEHANDLE>){
  while (/(\w[\w'-]*)/g){
    $frequency{$1}++
  }
}

for $word (sort {$frequency{$b} <=> $frequency{$a}} keys %frequency){
  printf "%5d %s\n", $frequency{$word}, $word;
}
