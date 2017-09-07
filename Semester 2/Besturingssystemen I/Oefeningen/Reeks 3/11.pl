
$record = {
	   DESCRIPTION => "Exercise",
	   DATE => "Saturday 23:30",
	   COURSE => "Perl"
	  };





while(($key, $value) = each %$record){
  print "$key => $value\n";
}

