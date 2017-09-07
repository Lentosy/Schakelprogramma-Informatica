



$now = time();

$interval = 5 * 60 * 60 * 24;

$ago = $now - $interval;
$ahead = $now + $interval;

$difference = $ahead - $ago;

$seconds    =  $difference % 60;
$difference = ($difference - $seconds) / 60;
$minutes    =  $difference % 60;
$difference = ($difference - $minutes) / 60;
$hours      =  $difference % 24;
$difference = ($difference - $hours)   / 24;
$days       =  $difference % 7;
$weeks      = ($difference - $days)    /  7;



print $difference, "\n";
