@records;


for $i (1..10){
  $record = {
	     DESCRIPTION => "This is record $i",
	     INFO => "Generic Info",
	     MULTIPLIED => $i * $i
  };

  push @records, $record;
}


$file = "records.csv";
open (WRITE, ">", $file) or die "Can not write to $file: $!\n";

for $r (@records){
  $DESCRIPTION = %$r{DESCRIPTION};
  $INFO = %$r{INFO};
  $MULTIPLIED = %$r{MULTIPLIED};
  print WRITE "$DESCRIPTION,$INFO;$MULTIPLIED\n";
}
close WRITE;

@records = [];

open (READ, "<", $file) or die "Can not read $file: $!\n";

while(<READ>){
  chomp;
  ($description, $info, $multiplied) = split ",";
  $record = {
	     DESCRIPTION => $description,
	     INFO => $info,
	     MULTIPLIED => $multiplied
  };
  push @records, $record;
}

for $r (@records){
  print join ",", reverse sort values $r, "\n";
}

