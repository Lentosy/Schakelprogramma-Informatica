$filename = "file";



open(FILEHANDLE, "<", $filename) or die "Can not open $filename: $!";
@lines = <FILEHANDLE>;
close(FILEHANDLE);

open(FILEHANDLE, "<", $filename) or die "Can not open $filename: $!";
$/ = "";
@paragraphs = <FILEHANDLE>;
close(FILEHANDLE);
print "--REVERSED BY LINE--\n";
print reverse @lines;

print "\n\n\n";

print "--REVERSED BY PARAGRAPH--\n";
print reverse @paragraphs;
