@ARGV[0] = "labyrinths/80.svg";

# -- GLOBAL VARIABLES -- #
my $filename = @ARGV[0]; # The name of the file

my $svg;  # The raw input file
my $cols; # The columns of the maze
my $rows; # The rows of the maze
my $cells; # The amount of cells (cols * rows)

my @path; # The path of the maze
%maze;    # The maze. The key is the numerical identification of the cell. The value is an anonymous array containing the neighbours

# -- PROCEDURES -- #
read_file();
determine_dimension();
init_maze();
interpret_lines();
remove_undefs();
solve_maze();
write_output();

# Read the svg file
sub read_file {
  print "Reading file.\n";
  $/ = undef;
  $svg = <>;
}

# Determine the columns and the rows of the maze
sub determine_dimension {
  $svg =~ /\<title.*\>(\d+) by (\d+).*\<\/title\>/;
  $cols = $1;
  $rows = $2;
  $cells = $cols * $rows;
  print "$cols by $rows orthogonal maze\n";
}

# Initialize the maze in memory
sub init_maze {
  print "Initializing maze\n";
  for (1 .. $cells){
    my $top    = $_ <= $cols         ? 0 : $_ - $cols;
    my $right  = $_ % $cols == 0     ? 0 : $_ + 1;
    my $bottom = $_ > $cells - $cols ? 0 : $_ + $cols;
    my $left   = $_ % $cols == 1     ? 0 : $_ - 1;

    $maze{$_} = [$top, $right, $bottom, $left];
  }
}

# Print the neighbours of each cell for verification
sub print_neighbours {
  for $cell (sort { $a <=> $b } keys %maze){
    print "$cell =>  ";
    print join "  ", @{$maze{$cell}};
    print "\n";
  }
}

# Interprets the lines in the maze and adjusts neighbours accordingly
sub interpret_lines {
    print "Interpreting lines\n";
  while( $svg =~ /\<line x1="(\d+)" y1="(\d+)" x2="(\d+)" y2="(\d+)"\/\>/g){
    my $x1 = $1 / 16;
    my $y1 = $2 / 16;
    my $x2 = $3 / 16;
    my $y2 = $4 / 16;

     my $index; # The index that will be used as a key the maze
     my $length; # The length of a line

     if($y1 == $y2){ # Horizontal lines
       ($x2, $x1) = ($x1, $x2) if $x1 > $x2;
       $length = $x2 - $x1;
       for (0 .. ($length - 1)){
	 $index = (($y2 - 1)  * $cols) + $x1 + $_;

	  # The cell above index is unaccesible
	  @{$maze{$index}->[0] = undef} if exists $maze{$index};
	  # The cell below index - cols is unaccesible
	  @{$maze{$index - $cols}->[2] = undef} if exists $maze{$index - $cols};
	}
      }elsif($x1 == $x2) { # Vertical lines
	($y2, $y1) = ($y1, $y2) if $y1 > $y2;
	$length = $y2 - $y1;

	if($x1 == 1){ # Leftmost line
	  for(0 .. ($length - 1)){
	    $index = (($_ + $y1) * $cols) + 1 - $cols;
	    # The cell left of index is unaccesible
	    @{$maze{$index}->[3] = undef} if exists $maze{$index};
	  }
	}elsif($x1 == ($cols + 1)){ # Rightmost line
	  for(0 .. ($length - 1)){
	    $index = ($_ + $y1) * $cols;
	    # The cell right of index is unaccesible
	    @{$maze{$index}->[1] = undef} if exists $maze{$index};
	  }
	}else{
	  for(0 .. ($length - 1)){ # Inner lines
	    $index = (($y2 - 2) * $cols) + $x1 + $_;
	    # The cell left of index is unaccesible
	    @{$maze{$index}->[3] = undef} if exists $maze{$index};
	    # The cell right of index - 1 is unaccesible
	    @{$maze{$index - 1}->[1] = undef} if exists $maze{$index};
        }
      }
    }
  }
}

# Removing undefined values from the neighbours of each cell
sub remove_undefs(){
  for (values %maze){
    @$_ = grep defined, @$_;
  }
}

# Finding a path for the maze
sub solve_maze(){
  print "Solving maze\n";

  my %visited; # Holds all the visited cells
  my @queue;   # The queue for visiting cells
  my %pathmap; # A map containing the parent for each child. Used for backtracking
  my $startcell; # The value of the starting cell. We will need this when we are backtracking

  # First step is finding the start point
  for $cell (keys %maze){
    my %neighbours = map { $_ => undef } @{$maze{$cell}};
    if(exists $neighbours{0}){
      delete $neighbours{0}; # Delete so we cannot push this on the queue
      $startcell = $cell;
      push @queue, $cell;
      @{$maze{$cell}} = keys %neighbours;
      last;
    }
  }

  
  while (scalar @queue != 0){
    my $current = pop @queue;
    last if $current == 0;
    $visited{$current} = undef;

    my @neighbours = @{$maze{$current}};
    for $n (@neighbours){
      next if exists $visited{$n};
      push @queue, $n;
      $pathmap{$n} = $current;
    }
  }

  my $child = 0;
  my $found = 0;

  while ( $found != 1 ){
    my $parent = $pathmap{$child};
    $found = 1 if $parent == $startcell;
    push @path, $parent;
    $child = $parent;
  }
}


sub write_output {

  $solution = (split /\./, $filename)[0] . "-solution.svg";
  print "Writing to $solution\n";
  $output = "<g fill=\"red\" stroke=\"none\">\n";

  for $cell (@path){
    my $col = $cell % $cols == 0 ? $cols : $cell % $cols;
    my $row = (($cell - $col) / $cols) + 1;

    $startX = $col * 16;
    $startY = $row * 16;

    my $x = "$startX,$startY";
    my $y = ($startX + 16) . ",$startY";
    my $z = ($startX + 16) . "," . ($startY + 16);
    my $w = "$startX," . ($startY + 16);

    $output .= "\t\<polygon points=\"$x $y $z $w\"\/>\n";
  }

  $output .= "</g>\n";

  $svg =~ s/(\<\/title\>)/$1 $output/;
  open SOLUTION, ">", $solution or die "$!\n";
  print SOLUTION $svg;

  
}
