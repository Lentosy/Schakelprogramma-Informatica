@chars = ('A' .. 'Z', 'a' .. 'z', 0..9);
$password = join "", @chars[map {rand @chars} (1 .. 8)];


print "$password\n";
