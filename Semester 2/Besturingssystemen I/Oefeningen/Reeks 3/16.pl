if (scalar @ARGV == 0){
  print "No arguments\n";
  exit 1;
}


{
  local $/ = undef;   # input record seperator tijdelijk uitschakelen
  $raw = <> or die "Could not open and read: $!";  # bestand inlezen
}
$raw =~ s/.* w$//ms;                          # Irrelevante data weghalen, alles dat voor de laatste w komt
$raw =~ s/^endstream.*//ms;                   # Irrelevante data weghalen, alles dat na endstream komt

$data = $raw;  # De relevante data

$iscurly = ($data =~ /^\d+(?:\.\d*)? \d+(?:\.\d*)? \d+(?:\.\d*)? \d+(?:\.\d*)? \d+(?:\.\d*)? \d+(?:\.\d*)? c$/gms ? 1 : 0);
print "Is curly: $iscurly\n";
while ( $data =~ /^(\d+)(?:\.\d*)? (\d+)(?:\.\d*)? m.(\d+)(?:\.\d*)? (\d+)(?:\.\d*)? l$/gms ){
  # Voor elke lijn de begin en eind coördinaten bijhouden
  $X{$1} = undef;   #start-x
  $Y{$2} = undef;   #start-y
  
  $X{$3} = undef;   #eind-x
  $Y{$4} = undef;   #eind-y

  # Undef omdat de kolom of rij voor deze waarden nog niet bepaald zijn, gebeurt in volgende stap
}

$cols = 0; # De huidige kolom
for ( sort { $a <=> $b } keys %X){
  $X{$_} = $cols++;
}

$rows = 0; # De huidige rij
for ( sort { $a <=> $b } keys %Y ){
  $Y{$_} = $rows++;
}

$rows -= 1; # De laatste rij
$cols -= 1; # De laatste kolom

print "Rows    : $rows\n";
print "Columns : $cols\n";

for (my $i = 0; $i <= $rows * 2; $i++){  # Tweemaal het aantal rijen voor verbindingstekens
  for (my $j = 0; $j <= $cols * 2; $j++){ # Hetzelfde
    $maze[$i][$j] = ($i % 2 != 0 || $j % 2 != 0 ? "  " : "++");  # + op oneven en een spatie op even posities. De spaties kunnen later overschreven worden door --
  }
}

while( $data =~/(\d+)(?:\.\d*)? (\d+)(?:\.\d*)? m.(\d+)(?:\.\d*)? (\d+)(?:\.\d*)? l$/gms){
  my $x1 = ($X{$1}); # start-x
  my $y1 = ($Y{$2}); # start-y
  
  my $x2 = ($X{$3}); # end-x
  my $y2 = ($Y{$4}); # end-y

  if($x1 == $x2){ # Verticaal | y1 en y2 zijn hier verschillend
    $maze[2 * ($rows - $y2) - 1][2 * $x1] = "||";
  }elsif($y1 == $y2){ # Horizontaal | x1 en x2 zijn hier verschillend
    $maze[2 * ($rows - $y1)][2 * $x1 + 1] = "--";
  }
}


for (@maze){
  print @$_;
  print "\n";
}



