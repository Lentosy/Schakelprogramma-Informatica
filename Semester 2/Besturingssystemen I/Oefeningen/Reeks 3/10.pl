$filename = "regios.csv";
open(FILEHANDLE, "<", $filename) or die "Could not open $filename: $!";

%regions = ();

while(<FILEHANDLE>){
  chomp;
  ($name, $parent, $population, $area) = split m<;>, $_;

  $regions{$name} = {
    name            => $name,
    parent          => $regions{$parent},
    children        => [],
    municipalities  => 0,
    level           => 0,
    population      => $population,
    area            => $area,
  };

  push @{$regions{$parent}->{children}}, $regions{$name};
  $parent = $regions{$name}->{parent};
  $regions{$name}{level} = $parent->{level} + 1;
  next unless $population;

  while($parent){
    $parent->{municipalities}   += 1;
    $parent->{population}       += $population;
    $parent->{area}             += $area;
    $parent = $parent->{parent};
  }
}

$root = $regions{Belgie};
@refqueue = ($root);
%regions = ();

while($root){
  printf "\n\nName: %-10s\n\n", $root->{name};
  printf "%10sMunicipalities: %d\n", "", $root->{municipalities};
  printf "%10sChildren: %s\n", "", join " ", map {$_->{name}} sort { $a{name} cmp $b{name}} @{$root->{children}};
  printf "%10sPopulation: %d\n", "",  $root->{population};
  printf "%10sArea: %d km²\n", "", $root->{area};

  ($root) = sort{ $b->{population} <=> $a->{population}} @{$root->{children}};
}

while($root = shift @refqueue){
  printf "%s %-41s %8d %6d\n",
    " "x($root->{level} * 3),
    $root->{name},
    $root->{population},
    $root->{area};

  unshift @refqueue, sort { $a->{name} cmp $b->{name}} @{$root->{children}};
}
