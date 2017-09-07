


@strings = ("this", "is", "an", "array", "of", "strings");

print join " ", @strings , "\n";

@strings = qw(this is an array of strings using qw);

print join " ", @strings, "\n";


@strings = ();
open(FILEHANDLE, "<", "oef16file") or die "Coulnt open file: $!";

while(<FILEHANDLE>){
  chomp;
  push @strings, $_;
}

print join " ", @strings, "\n";
