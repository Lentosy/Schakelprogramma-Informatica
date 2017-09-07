$filename = "file";


open(FILEHANDLE, "<", $filename) or die "Can not open file $filename: $!";
$lines = 0;
$paragraphs = 0;
$lines++ while <FILEHANDLE>;
close FILEHANDLE;

open(FILEHANDLE, "<", $filename) or die "Can not open file $filename: $!";
$/ = ""; #splitten op lijnen met een lege string
$paragraphs++ while <FILEHANDLE>;
print "Lines: $lines\nParagraphs: $paragraphs\n";
close FILEHANDLE;
