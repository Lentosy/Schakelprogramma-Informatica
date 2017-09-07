open $output , "ps -aux|" or die "$!\n";
@processes;
while(<$output>){
	chomp;
	($user, $pid, $cpu, $mem, $rest) = split;
	push @processes, [$pid, $mem];
}
close $output;

$pids=0;
for ( sort { $b->[1] <=> $a->[1] } @processes){
	print join ": ", @$_;
	print "\n";
	last if $pids == 5;
	$pids++;
}



