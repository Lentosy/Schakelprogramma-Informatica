print "int Sedgewickinc[]={";
my $amount = (int log $ARGV[0])+ 1;
for(0 .. $amount ){
	my $n;
	if($_ & 1){
		$n = (8 * (2 ** $_))  - 6 * (2 ** (($_ + 1)/2)) + 1;		
	}else{
		$n = (9 * (2 ** $_))  - (9 * (2 ** ($_/2))) + 1;
	}
	print "$n,"
}
print "};"; 










