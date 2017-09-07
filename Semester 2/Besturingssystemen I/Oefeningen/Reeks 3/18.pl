# ... invullen door een getal
# buren moeten opeenvolgende getallen zijn (links rechts boven en onder)
# Er is maar één oplossing
# OPL
#  kolommen en rijen bepalen
#LUS
#|LUS
#||LUS
#||| FILTEREN KANDIDATEN
#||| 
#|||	Voor elke cel kijken welk getal er in zou kunnen zitten
#||| 	lijst bijhouden per cel met mogelijke getalen
#||| 	Drievoudige lus over alle rijen, kolommen en kandidaten
#||| 	$kand[rij][kolom]{nummer}   <- structuur
#||| 
#|||BLIJVEN DOEN TOT DAT ER GEEN POSITIEF RESULTAAT MEER IS
#||LUS
#||| CEL MET ENKELE KANDIDATEN
#|||
#||| 	Als cel met één kandidaat => die cel krijgt waarde en alle andere cellen die 
#|||    deze waarden hebben moeten deze waarden verwijderen
#||| 
#|||BLIJVEN DOEN TOT DAT ER GEEN POSITIEF RESULTAAT MEER IS
#|LUS  
#||
#|| WAARDE DAT MAAR KANDIDAAT IS VOOR 1 CEL
#||    Alle getallen dat kandidaat waren komen dan ook vrij voor andere cellen
#||


@ARGV[0] = "numbrix/A.numbrix";

my @numbrix; # The numbrix puzzle
my %candidates; # The possible candidates for a given cell
my $cols; # The amount of columns;
my $rows; # The amount of rows;


while(<>){
  chomp;
  push @numbrix, [split /\s/, $_];
}

$rows = scalar @numbrix;
$cols = $rows; # The amount of columns is always the same as the amount of rows 
print "$rows by $cols\n";



init_numbrix();
filter_candidates();
print_possibilities();


sub init_numbrix {
  my $index = 0;
  for (my $i = 1; $i <= $cols; $i++){
    for(my $j = 1; $j <= $rows; $j++){
      my $cell = @numbrix[$i - 1]->[$j - 1]; # The current cell index
      my $value; # The value of a cell
      if($cell =~ /\.\.\./){
	$value = undef;
      }elsif($cell =~ /(\d+)/){
	$value = $1;
      }

      my @possibilities = [1.. ($cols * rows)] if !$value;
      $candidates{$index++} = {
			       value => $value,
			       index => $index,
			       col => $j,
			       row => $i,
			       possibilities => @possibilities
			      }
    }
  }

}

sub filter_candidates {
  for (keys %candidates){
    if(defined $candidates{$_}->{value}){
      # For the cell left, top, right and bottom of this cell, we add this cells value +1 and -1 as a possibility.
      my $row = $candidates{$_}->{row};
      my $col = $candidates{$_}->{col};
      my $value = $candidates{$_}->{value};
      my $index = $candidates{$_}->{index};

      # Left
      if($col != 1){ # Not the leftmost column
	push @{$candidates{$index - 1}->{possibilities}}, $value - 1;
	push @{$candidates{$index - 1}->{possibilities}}, $value + 1;
      }

      # Top
      if($row != 1){ # Not the top row
	push @{$candidates{$index - $cols}->{possibilities}}, $value - 1;
	push @{$candidates{$index - $cols}->{possibilities}}, $value + 1;
      }

      # Right
      if($col != $cols){ # Not the rightmost column
	push @{$candidates{$index + 1}->{possibilities}}, $value - 1;
	push @{$candidates{$index + 1}->{possibilities}}, $value + 1;
      }

      # Bottom
      if($row != $rows){ # Not the bottom row
	push @{$candidates{$index + $cols}->{possibilities}}, $value - 1;
	push @{$candidates{$index + $cols}->{possibilities}}, $value + 1;
      }
    }
  }


}


sub clean_possibilities {
  for (keys %candidates){
    my %possibilities = map { $_ => undef } @{$candidates{$_}->{possibilities}};
    delete $possibilities{0};
    @{$candidates{$_}->{possibilities}} = keys %possibilities;
  }
}

sub print_possibilities{
  for ( sort { $candidates{$a}->{row} <=> $candidates{$b}->{row} or $candidates{$a}->{col} <=> $candidates{$b}->{col} } keys %candidates){
    print $candidates{$_}->{row};
    print ".";
    print $candidates{$_}->{col};
    print ":     ";
    print join "  ", sort {$a <=> $b } @{$candidates{$_}->{possibilities}};
    print "\n";

  }
}
