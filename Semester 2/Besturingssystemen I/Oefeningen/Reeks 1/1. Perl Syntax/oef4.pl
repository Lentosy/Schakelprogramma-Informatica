$string = "dit is een willekeurige zin";

print $string;
print "\n";

$reversechar = reverse $string;
print $reversechar;
print "\n";

$reverseword = join " ", reverse split " ", $string;
print $reverseword;
print "\n";
