$difference = 11097;

$now = time();
$when = $now + $difference;
print scalar localtime($when) , "\n";
$then = $now - $difference;
print scalar localtime($then) , "\n";
