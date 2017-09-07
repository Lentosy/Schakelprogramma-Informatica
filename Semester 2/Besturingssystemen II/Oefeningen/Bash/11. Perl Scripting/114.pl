$file = "dhcp.log";

open (FILEHANDLE, "<", $file) or die "Error opening $file: $!\n";



@log;
while(<FILEHANDLE>){
	chomp;
	if($_ =~ /(\d+),.*/){
		($id, $date, $time, $description, $ip, $host, $mac, $user, $name,
			$transaction, $result, $probation, $correlation) = split ',';
		if($id == 10 || $id == 11){
			push @leases, [$date, $host, $mac];
		}
		if($id == 15){
			$denied++;
		}
	}
}
close FILEHANDLE;

print "---------------\n";
print "Devices that received a lease.\n";
for $l (@leases){
	printf "%-9s %-35s %s\n", $l->[0], $l->[1], $l->[2];
}

print "---------------\n";
print "Devices that got denied a lease: $denied.\n";
print "---------------\n";
print "Devices that were up during nighttime.\n";
